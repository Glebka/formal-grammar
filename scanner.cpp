#include "scanner.h"

GramScanner::GramScanner(QObject *parent) :
    QObject(parent)
{
}

void GramScanner::clear()
{
    simpleRelations.clear();
    fullDictionary.clear();
    clearNonTerms();
    clearTerms();
}

void GramScanner::process(QString text, DependencyTree *depTree)
{
    this->clear();

    QRegExp delimiter("[\\s!""]");

    // разбивка кода на строки-правила
    QStringList textlines=text.split('\n');
    QStringListIterator it(textlines);
    unsigned int ln=0;
    unsigned int col=0;
    QString currentLeftPart;
    int leftIndex=-1;
    int first=-1;
    int element1=-1;
    int element2=-1;
    int last=-1;
    bool nonrec;
    //цикл по строкам-правилам
    while(it.hasNext())
    {
        nonrec=true;
        ln++;
        QString line=it.next();
        //qDebug()<<cursor.position();
        //если встретился комментарий или строка пустая, то пропустить её

        if(line.startsWith("//")||line.length()==0)
            continue;

        // состояние сканера
        int state=0;

        // буфер для накопления лексем
        QString buffer="";

        // перебор каждого символа строки правила
        int i;
        for(i=0;i<line.length();i++)
        {
            //qDebug()<<line.at(i);
            col=i;
            switch(state)
            {
            case 0: // левая часть, определение нетерминала
            {
                int indexof=line.indexOf('=');
                if(indexof<0)
                {
                    // ошибка, в строке не записано правило
                    i=line.length();
                    break;
                }
                buffer=line.left(indexof);
                i=line.indexOf('=');
                leftIndex=registerNonTerm(ln,col,buffer);
                currentLeftPart=buffer.trimmed(); // запоминаем нетерминал, который будет определятся далее в правиле
                depTree->append("",currentLeftPart);
                //appendDepTree("",currentLeftPart);
                buffer="";
                state=1; // переход к разбору правой части правила
            }
                break;
             case 1:
                if(line.at(i).isSpace()) break; // игнорировать пробелы
                if(line.at(i).isLetter()) // если символ, то сохранить его в буфер, перейти к разбору нетерминала
                {
                    registeEqualRelation(element1,element2);
                    buffer.append(line.at(i));
                    state=2; //non-term
                    //qDebug()<<"New nonterm begining. State "<<state;
                    break;
                }
                if(line.at(i)=='"') // если открывающаяся двойная кавычка, то перейти к накоплению терминала
                {
                    state=3;
                    registeEqualRelation(element1,element2);
                    //qDebug()<<"New term begining. State "<<state;
                    break;
                }
                if(line.at(i)=='!') // альтернатива в правиле
                {
                    // todo: new rule path
                    //qDebug()<<"New rule alternative. State "<<state;

                    //register relation pair
                    registerFirstLastRelation(leftIndex,first,last);
                    registeEqualRelation(element1,element2);
                    element1=-1;
                    element2=-1;

                    if(nonrec)
                    {
                        nonRecNonTerm<<currentLeftPart;
                        infRecNonTerm.remove(currentLeftPart);
                    }
                    depTree->createRule(currentLeftPart);
                    //createDepTreeRule(currentLeftPart);
                    nonrec=true;
                    state=1;
                    break;
                }

                //qDebug()<<"Sysntax error after equal sign: unexpected symbol '"<<line.at(i);
                Position pos;
                pos.definedHere=false;
                pos.length=1;
                pos.col=col;
                pos.line=ln;
                emit message(MessageType::Error,MSG_WRONG_SYMBOL,pos,ErrorClass::Syntax,SyntaxError::WrongSymbol);
                break;
            case 2: // non-term
            {
                nonrec=false;
                QChar c=line.at(i);
                if(c==' ') // нетерминал закончился, поиск новой лексемы
                {
                    //qDebug()<<"Completed nonterm: "<<buffer;

                    int rindex=registerNonTerm(ln,col-buffer.length(),buffer,false,!(currentLeftPart==buffer));

                    if(first==-1)
                    {
                        first=rindex;
                        element1=first;
                    }
                    else
                        element2=rindex;
                    last=rindex;

                    registeEqualRelation(element1,element2);

                    //appendDepTree(currentLeftPart,buffer);
                    depTree->append(currentLeftPart,buffer);
                    buffer="";
                    state=1;
                    //qDebug()<<"State:"<<state;
                }
                else
                    if(c=='"') // закончился нетерминал и начался терминал
                    {
                        //qDebug()<<"Completed nonterm: "<<buffer;

                        int rindex=registerNonTerm(ln,col-buffer.length(),buffer,false,!(currentLeftPart==buffer));

                        if(first==-1)
                        {
                            first=rindex;
                            element1=first;
                        }
                        else
                            element2=rindex;

                        last=rindex;

                        registeEqualRelation(element1,element2);

                        //appendDepTree(currentLeftPart,buffer);
                        depTree->append(currentLeftPart,buffer);
                        buffer="";
                        state=3;
                        //qDebug()<<"New term begining. State "<<state;
                    }
                else
                        if(c=='!') // закончился нетерминал, начинается новая альтернатива правила
                        {
                            // todo: new rule path
                            //qDebug()<<"Completed nonterm: "<<buffer;

                            int rindex=registerNonTerm(ln,col-buffer.length(),buffer,false,!(currentLeftPart==buffer));

                            if(first==-1)
                            {
                                first=rindex;
                                element1=first;
                            }
                            else
                                element2=rindex;

                            last=rindex;

                            registeEqualRelation(element1,element2);
                            element1=-1;
                            element2=-1;

                            depTree->append(currentLeftPart,buffer);
                            depTree->createRule(currentLeftPart);

                            //register relation pair
                            registerFirstLastRelation(leftIndex,first,last);

                            //appendDepTree(currentLeftPart,buffer);
                            //createDepTreeRule(currentLeftPart);
                            if(nonrec)
                            {
                                nonRecNonTerm<<currentLeftPart;
                                infRecNonTerm.remove(currentLeftPart);
                            }
                            nonrec=true;

                            buffer="";
                            state=1;
                            //qDebug()<<"New rule alternative. State "<<state;
                        }
                else
                        {
                            QString substring=line.mid(i,line.indexOf(delimiter,i)-i);
                            buffer.append(substring); //накопление нетерминала
                            i+=substring.length()-1;
                        }

             }
                break;
            case 3: // term
            {
                buffer=line.mid(i,line.indexOf('"',i)-i);
                i+=buffer.length();
                //qDebug()<<"Completed term: "<<buffer;
                state=1;
                int rindex=registerTerm(ln,col-1,buffer);

                if(first==-1)
                {
                    first=rindex;
                    element1=first;
                }
                else
                    element2=rindex;

                last=rindex;

                registeEqualRelation(element1,element2);

                buffer="";
            }
                break;
            default:
                break;
            }
        }
        // если закончилась строка, необходимо проверить состояние
        switch(state)
        {
            case 0:
            {
                Position pos;
                pos.definedHere=false;
                pos.length=line.length();
                pos.col=col;
                pos.line=ln;
                emit message(MessageType::Error,MSG_NOT_RULE,pos,ErrorClass::Syntax,SyntaxError::NotRule);
            }
                break;
            case 1:
            {
                registerFirstLastRelation(leftIndex,first,last);
                if(nonrec)
                {
                    nonRecNonTerm<<currentLeftPart;
                    infRecNonTerm.remove(currentLeftPart);
                }
                nonrec=true;
                //QChar c=line.at(i-1);
                //if(c=='=')
            }
                break;
            case 2:
            {
                int rindex=registerNonTerm(ln,col-1,buffer,false,!(currentLeftPart==buffer));
                if(first==-1)
                {
                    first=rindex;
                    element1=first;
                }
                else
                    element2=rindex;
                last=rindex;

                registeEqualRelation(element1,element2);
                registerFirstLastRelation(leftIndex,first,last);

                depTree->append(currentLeftPart,buffer);

                //appendDepTree(currentLeftPart,buffer);
                //qDebug()<<"EndLine";
            }
                break;
            case 3:
                //qDebug()<<"Unexpected end of terminal";
            {
                Position pos;
                pos.definedHere=false;
                pos.length=line.length();
                pos.col=col;
                pos.line=ln;
                emit message(MessageType::Error,MSG_UNCLOSED_TERM,pos,ErrorClass::Syntax,SyntaxError::UnclosedTerminal);
            }
                break;
           default:;
            // требует проверки
            //qDebug()<<"EndLine";
        }
        element1=-1;
        element2=-1;
        //index++;
    }

    //fullDictionary.append(nonTerminals);
    //fullDictionary.append(terminals);
    /*foreach(SimpleRelationPair pair, simpleRelations)
    {
        QString relation;
        switch(pair.relation)
        {
            case SimpleRelationType::First:
                relation="FIRST";
                break;
            case SimpleRelationType::Last:
                relation="LAST";
                break;
            default:
                relation="UNDEF";
        }
        qDebug()<<pair.element1<<" "<<relation<<pair.element2;
    }

    foreach(QString name, fullDictionary)
        qDebug()<<name;*/

    nonTeriminalAttr.at(0)->used=true;
    for(int i=0;i<nonTeriminalAttr.count();i++)
    {
        QString key=nonTerminals.at(i);
        if(nonTeriminalAttr.at(i)->defined==false)
        {
            QMap<QString, Position>::const_iterator j = locations.find(key);
             while (j != locations.end() && j.key() == key)
             {
                 Position pos=j.value();
                 emit message(MessageType::Error,QString::fromAscii(MSG_UNDEFINED_SYMBOL).arg(key),pos,ErrorClass::Grammar,GrammarError::UndefinedNonTerm);
                 ++j;
             }
        }
        if(nonTeriminalAttr.at(i)->used==false)
        {
             QMap<QString, Position>::const_iterator j = locations.find(key);
             while (j != locations.end() && j.key() == key) {
                 Position pos=j.value();
                 if(pos.definedHere)
                 {
                    emit message(MessageType::Error,QString::fromAscii(MSG_UNUSED_SYMBOL).arg(key),pos,ErrorClass::Grammar,GrammarError::UnusedNonTerm);
                    break;
                 }
                 ++j;
             }
        }
    }
}

bool GramScanner::markNonTermAsNonRec(QVariant name)
{
    QString mname=name.toString();
    //qDebug()<<"Mark as nonrec: "<<mname;
    int index=nonTerminals.indexOf(mname);
    if(index==-1) return false;
    qDebug()<<"Mark as nonrec: "<<name;
    nonTeriminalAttr.at(index)->noLoop=true;
    infRecNonTerm.remove(mname);
    nonRecNonTerm<<mname;
    return true;
}

QString GramScanner::getInfRecNonTermsString()
{
    QStringList list=infRecNonTerm.toList();
    return list.join("|");
}

const QStringList *GramScanner::getTerms()
{
    return &terminals;
}

const QStringList *GramScanner::getNonTerms()
{
    return &nonTerminals;
}

const QSet<QString> GramScanner::getInfRecNonTerms()
{
    return infRecNonTerm;
}

const QSet<QString> GramScanner::getNonRecNonTerms()
{
    return nonRecNonTerm;
}

const QList<NonTerminal *> *GramScanner::getNonTermAttrs()
{
    return &nonTeriminalAttr;
}

const QMultiMap<QString, Position> *GramScanner::getLocations()
{
    return &locations;
}

const QList<SimpleRelationPair> GramScanner::getSimpleRelationPairs()
{
    return simpleRelations;
}

const QList<SimpleRelationPair> * GramScanner::getSimpleRelationPairs2()
{
    return &simpleRelations;
}

const QStringList *GramScanner::getFullDictionary()
{
    return &fullDictionary;
}

int GramScanner::registerNonTerm(unsigned int line, unsigned int col, QString name, bool define, bool use)
{
    QRegExp nonTermNameRegExp("[\\w][\\w\\d]*");
    name=name.trimmed(); // trim external spaces
    Position pos;
    pos.line=line;
    pos.col=col+1;
    pos.length=name.length();
    pos.definedHere=define;
    //pos.isTerm=false;
    locations.insert(name,pos);
    if(!nonRecNonTerm.contains(name))
        infRecNonTerm<<name; // добавляем нетерминал в список бесконечно рекурсивных, далее это будет проверено сканером
    if(!nonTermNameRegExp.exactMatch(name)) // if nonterm name not match
    {
        emit message(MessageType::Error,MSG_INVALID_NAME,pos,ErrorClass::Syntax,SyntaxError::InvalidName);
        return -1;
    }
    int index=fullDictionary.indexOf(name);
    //int tmp=this->nonTerminals.indexOf(name); // if nonterm already exist
    if(index!=-1)
    {
        int tmp=this->nonTerminals.indexOf(name); // if nonterm already exist
        if(this->nonTeriminalAttr.at(tmp)->defined && define)
        {
            emit message(MessageType::Error,QString::fromAscii(MSG_REDEFINITION).arg(name),pos,ErrorClass::Syntax,SyntaxError::Redefinition);
            return -1;
        }
        if(define)
            this->nonTeriminalAttr.at(tmp)->defined=true;
        if(use)
            this->nonTeriminalAttr.at(tmp)->used=true;
    }
    else
    {
        index=fullDictionary.size();
        this->nonTerminals.append(name);
        fullDictionary.append(name);

        NonTerminal * nonterm=new NonTerminal();
        if(define)
            nonterm->defined=true;
        if(use)
            nonterm->used=true;
        nonterm->noLoop=false;
        this->nonTeriminalAttr.append(nonterm);
    }
    return index;
}

int GramScanner::registerTerm(unsigned int line, unsigned int col, QString name)
{
    Position pos;
    pos.line=line;
    pos.col=col+1;
    pos.length=name.length();
    locations.insert(""""+name+"""",pos);
    int index=this->fullDictionary.indexOf("\""+name+"\"");
    if(index==-1)
    {
        index=this->fullDictionary.size();
        this->terminals.append("\""+name+"\"");
        this->fullDictionary.append("\""+name+"\"");
    }
    return index;
}

void GramScanner::clearNonTerms()
{
    foreach(NonTerminal * t, this->nonTeriminalAttr)
        delete t;
    this->nonTeriminalAttr.clear();
    this->nonTerminals.clear();
    this->locations.clear();
    this->infRecNonTerm.clear();
    this->nonRecNonTerm.clear();
}

void GramScanner::clearTerms()
{
    this->terminals.clear();
}

void GramScanner::registerFirstLastRelation(int &leftPartIndex, int &first, int &last)
{
    if(first==-1 || last==-1)
    {
        qDebug()<<"Can't register FIRST-LAST relation";
        return;
    }
    SimpleRelationPair pair;
    pair.relation=SimpleRelationType::First;
    pair.element1=leftPartIndex;
    pair.element2=first;
    simpleRelations<<pair;
    first=-1;
    pair.relation=SimpleRelationType::Last;
    pair.element1=leftPartIndex;
    pair.element2=last;
    simpleRelations<<pair;
    last=-1;
}

void GramScanner::registeEqualRelation(int &element1, int &element2)
{
    if(element1==-1 || element2==-1)
    {
        return;
    }
    SimpleRelationPair pair;
    pair.element1=element1;
    pair.element2=element2;
    pair.relation=SimpleRelationType::Equal;
    simpleRelations<<pair;
    element1=element2;
    element2=-1;
}
