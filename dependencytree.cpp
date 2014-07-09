#include "dependencytree.h"

DependencyTree::DependencyTree(QObject *parent) :
    QObject(parent)
{
    webview=new QWebView();
    QFileInfo tmp("xmlprocessor.html");
    webview->load(QUrl(QString("file:///"+tmp.absoluteFilePath())));
    xmlprocessor=webview->page()->mainFrame();
}

DependencyTree::~DependencyTree()
{
    delete webview;
}

void DependencyTree::append(QString parent, QString child)
{
    parent=parent.trimmed();
    child=child.trimmed();
    xmlprocessor->evaluateJavaScript("window.appendNode('"+parent+"','"+child+"');");
    //qDebug()<<"window.appendNode('"<<parent<<"','"<<child<<"');";
    /*if(parent.length()==0)
    {
        if(dependencyTree.elementsByTagName(child).count()==0)
        {
            QDomElement element=dependencyTree.createElement(child);
            element.appendChild(dependencyTree.createTextNode("bbb"));
            dependencyTree.appendChild(element);
        }
        return;
    }
    QDomNode elem=dependencyTree.elementsByTagName(parent).item(0);
    QDomNodeList rules=elem.toElement().elementsByTagName("rule");
    if(rules.count()==0)
    {
        QDomElement element=dependencyTree.createElement("rule");
        element.appendChild(dependencyTree.createTextNode("bbb"));
        elem.toElement().appendChild(element);
    }
    QDomNode lastRule=rules.item(rules.count()-1);
    if(lastRule.toElement().elementsByTagName(child).count()==0)
    {
        QDomElement element=dependencyTree.createElement(child);
        element.appendChild(dependencyTree.createTextNode("bbb"));
        lastRule.appendChild(element);
    }*/
}

void DependencyTree::createRule(QString parent)
{
    parent=parent.trimmed();
    //qDebug()<<"window.createRule('"<<parent<<"');";
    xmlprocessor->evaluateJavaScript("window.createRule('"+parent+"');");
    /*
    QDomNode elem=dependencyTree.elementsByTagName(parent).item(0);
    QDomElement element=dependencyTree.createElement("rule");
    element.appendChild(dependencyTree.createTextNode("bbb"));
    elem.toElement().appendChild(element);*/
}

void DependencyTree::process(GramScanner *scanner)
{
    // необходимо пометить узлы нерекурсивных нетерминалов
    //QDomAttr attr=dependencyTree.createAttribute("noinfrec");
    //attr.setValue("true");
    foreach(QString name, scanner->getNonRecNonTerms())
    {
        xmlprocessor->evaluateJavaScript("window.markNoinfrec('"+name+"');");
        /*QDomNodeList nodelist=dependencyTree.elementsByTagName(name);
        for(int i=0;i<nodelist.count();i++)
        {
            nodelist.item(i).toElement().setAttributeNode(attr);
        }*/
    }
    /*QFile outFile( "deptree.xml" );
      if( !outFile.open( QIODevice::WriteOnly | QIODevice::Text ) )
      {
        qDebug( "Failed to open file for writing." );
        return;
      }

      QTextStream stream( &outFile );
      stream << dependencyTree.toString();

      outFile.close();*/
    // анализ рекурсивности

    //QEventLoop wait;
   // QObject::connect(this, SIGNAL(notify()), &wait, SLOT(quit()));

    //xmlprocessor=webview->page()->mainFrame();
    //QString xml=dependencyTree.toString();
    //QString expression="document.getElementsByTagName('body')[0].innerHTML='"+xml+"';\nwindow.process();";
    xmlprocessor->addToJavaScriptWindowObject(QString("scanner"),scanner);
    xmlprocessor->addToJavaScriptWindowObject(QString("processor"),this);
    //Stringer sxml(xml);
   // xmlprocessor->addToJavaScriptWindowObject(QString("xml"),&sxml);
    xmlprocessor->evaluateJavaScript("window.process();");
    //qDebug()<<xmlprocessor->evaluateJavaScript("document.getElementsByTagName('body')[0].innerHTML='bbbb';");
    //qDebug()<<xml;
    //wait.exec();

    /*QXmlQuery query;
    QDomNodeModel model(query.namePool(), dependencyTree);
    query.setFocus(QXmlItem(model.fromDomNode(dependencyTree.documentElement())));
    //qDebug()<<"Debug";
    while(true)
    {
        // удаление всех нерекурсивных нетерминалов, не имеющих потомков в дереве
        query.setQuery("//*[@noinfrec]");
        QXmlResultItems res;
        query.evaluateTo(&res);
        while (!res.next().isNull())
        {
                //QXmlItem cur=res.current();
                //if(!cur.isNode()) continue;
                QDomNode node=model.toDomNode(res.current().toNodeModelIndex());
                if(node.childNodes().count()>0) continue;
                //qDebug()<<"Del: "<<node.toElement().tagName();
                scanner->markNonTermAsNonRec(node.toElement().tagName());
                node.parentNode().removeChild(node);
                node.attributes().namedItem("noinfrec").setNodeValue("1");
                if(dependencyTree.childNodes().count()==0) break;
                //qDebug()<<dependencyTree.childNodes().count();
                //qDebug()<<dependencyTree.toString();


                query.setFocus(QXmlItem(model.fromDomNode(dependencyTree.documentElement())));
                query.evaluateTo(&res);
        }
        if(dependencyTree.childNodes().count()==0) break;

        // set attr noinfrec to nodes with empty rules, delete empty rules
        // установить атрибут noinfrec для узлов с пустыми правилами, удалить пустые правила

        query.setQuery("//rule[not(.//*)]");
        query.evaluateTo(&res);
        bool deleteOnce=false;
        while (!res.next().isNull())
        {
            deleteOnce=true;
            QDomNode node=model.toDomNode(res.current().toNodeModelIndex());
            QDomElement parentEl=node.parentNode().toElement();
            QDomNodeList nodelist=dependencyTree.elementsByTagName(parentEl.tagName());
            for(int i=0;i<nodelist.count();i++)
                nodelist.item(i).toElement().setAttributeNode(attr);
                //qDebug()<<"Mark: "<<nodelist.item(i).toElement().tagName();

            //parentEl.setAttribute("noinfrec","true");
            //qDebug()<<"Mark: "<<node.parentNode().toElement().tagName();
            node.parentNode().removeChild(node);
            if(dependencyTree.childNodes().count()==0) break;
            query.setFocus(QXmlItem(model.fromDomNode(dependencyTree.documentElement())));
            query.evaluateTo(&res);
        }
        if(dependencyTree.childNodes().count()==0) break;
        if(!deleteOnce) break;
    }*/
    foreach(QString name, scanner->getInfRecNonTerms())
    {
        QMap<QString, Position>::const_iterator j = scanner->getLocations()->find(name);
        while (j != scanner->getLocations()->end() && j.key() == name) {
            Position pos=j.value();
            if(pos.definedHere)
            {
               emit message(MessageType::Error,QString::fromAscii(MSG_INFINITE_RECURSION).arg(name),pos,ErrorClass::Grammar,GrammarError::InfiniteRecursion);
               break;
            }
            ++j;
        }
    }
}

void DependencyTree::clear()
{
    //dependencyTree.clear();
}

/*void DependencyTree::notifyMe(QString html)
{
    //qDebug()<<"Notified";
    //qDebug()<<html;
    //emit notify();
}*/

Stringer::Stringer(QString str, QObject *parent)
{
    this->str=str;
}

QString Stringer::getString()
{
    return str;
}
