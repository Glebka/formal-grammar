#include "matrixbuilder2.h"

MatrixBuilder2::MatrixBuilder2(QObject *parent) :
    QObject(parent)
{
    FIRST=0;
    LAST=0;
    EQUAL=0;
    LT=0;
    GT=0;
    RLT=0;
}

MatrixBuilder2::~MatrixBuilder2()
{
    clear();
}

void MatrixBuilder2::clear()
{
    clearMatrix(FIRST);
    clearMatrix(LAST);
    clearMatrix(EQUAL);
    clearMatrix(LT);
    clearMatrix(GT);
    clearMatrix(RLT);
    FIRST=0;
    LAST=0;
    GT=0;
    LT=0;
    EQUAL=0;
    RLT=0;
}

/*
void MatrixBuilder2::process(GramScanner *scanner)
{
    clear();
    const QList<SimpleRelationPair> * pairs=scanner->getSimpleRelationPairs2();
    const QStringList * fullDictionary=scanner->getFullDictionary();
    size=fullDictionary->size();
    FIRST=allocMatrix();
    LAST=allocMatrix();
    EQUAL=allocMatrix();

    for(int k=0;k<pairs->size();k++)
    {

        SimpleRelationPair pair=pairs->at(k);
        MatrixXi * selected=0;
        switch(pair.relation)
        {
            case SimpleRelationType::First:
                selected=FIRST;
                break;
            case SimpleRelationType::Last:
                selected=LAST;
                break;
            case SimpleRelationType::Equal:
                selected=EQUAL;
                break;
            default:
                break;
        }
        MatrixXi & link=*selected;
        link(pair.element1,pair.element2)=1;
    }
    writeHTML(scanner,"FIRST.html",FIRST);
    writeHTML(scanner,"LAST.html",LAST);



    transitiveClosure(FIRST);
    writeHTML(scanner,"LEFT.html",FIRST);
    LT=allocMatrix();
    MatrixXi & lLT=*LT;
    MatrixXi & lEQ=*EQUAL;
    MatrixXi & lFirst=*FIRST;
    MatrixXi & lLast=*LAST;
    MultiplyMatrix(*LT,*EQUAL,*FIRST);
    GT=allocMatrix();
    MatrixXi & lGT=*GT;
    transitiveClosure(LAST);
    writeHTML(scanner,"RIGHT.html",LAST);

    for(int i=0;i<size;i++)
    {
        for(int j=0;j<size;j++)
        {
            if(lEQ(i,j)==1)
            {
                for(int k=0;k<size;k++)
                    if(lLast(i,k)==1)
                        lGT(k,j)=1;
            }
        }
    }

    //EQUAL Correct
    writeHTML(scanner,"EQUAL.html",EQUAL);

    //LT Correct
    writeHTML(scanner,"LT.html",LT);

    writeHTML(scanner,"GT.html",GT);

    int ** matr =new int * [size];
    for(int i=0;i<size;i++)
    {
        matr[i]=new int[size];
        memset(matr[i],0,size);
    }
    for(int i=0;i<size;i++)
        for(int j=0;j<size;j++)
        {
            int relation=0;
            if(lLT(i,j)>0)
                relation|=RelationType::LT;
            if(lEQ(i,j)>0)
                relation|=RelationType::EQ;
            if(lGT(i,j)>0)
                relation|=RelationType::GT;
            matr[i][j]=relation;
        }
    QFile file("relations.html");
    char * relStrings[]={"","<",">","<>","=","<=",">=","<>="};
    if(file.open(QIODevice::WriteOnly))
    {
        const QStringList * fullDictionary=scanner->getFullDictionary();
        file.write("<html><head><title>Relations.html</title></head><body><table border='1'><tr><td>&nbsp;</td>");
        for(int i=0;i<size;i++)
            file.write("<td>"+fullDictionary->at(i).toAscii()+"</td>");
        file.write("</tr>");
        for(int i=0;i<size;i++)
        {
            QString str;
            file.write("<tr><td>"+fullDictionary->at(i).toAscii()+"</td>");
            for(int j=0;j<size;j++)
            {
                str=relStrings[matr[i][j]];
                file.write("<td>"+str.toAscii()+"</td>");
            }
            file.write("</tr>");
        }
        file.write("</table></body></html>");
        file.close();
    }
    for(int i=0;i<size;i++)
        delete [] matr[i];
    delete[] matr;
    //std::cout<<"LT\n";
    //std::cout<<lLT;
}
*/


void MatrixBuilder2::process(GramScanner *scanner)
{
    clear();
    const QList<SimpleRelationPair> * pairs=scanner->getSimpleRelationPairs2();
    const QStringList * fullDictionary=scanner->getFullDictionary();
    size=fullDictionary->size();
    FIRST=allocMatrix();
    LAST=allocMatrix();
    EQUAL=allocMatrix();
    LT=allocMatrix();
    GT=allocMatrix();
    RLT=allocMatrix();
    for(int k=0;k<pairs->size();k++)
    {

        SimpleRelationPair pair=pairs->at(k);
        MatrixXi * selected=0;
        switch(pair.relation)
        {
            case SimpleRelationType::First:
                selected=FIRST;
                break;
            case SimpleRelationType::Last:
                selected=LAST;
                break;
            case SimpleRelationType::Equal:
                selected=EQUAL;
                break;
            default:
                break;
        }
        MatrixXi & link=*selected;
        link(pair.element1,pair.element2)=1;
    }
    //writeHTML(scanner,"FIRST.html",FIRST);
    //writeHTML(scanner,"LAST.html",LAST);

    transitiveClosure(FIRST);
    //writeHTML(scanner,"LEFT.html",FIRST);
    MatrixXi & lLT=*LT;
    MatrixXi & lEQ=*EQUAL;
    MatrixXi & lFirst=*FIRST;
    MatrixXi & lLast=*LAST;
    MatrixXi & lRLT=*RLT;
    //MultiplyMatrix(*LT,*EQUAL,*FIRST);
    lLT=lEQ * lFirst;
    reflexiveClosure(FIRST);

    MatrixXi & lGT=*GT;
    transitiveClosure(LAST);
    //writeHTML(scanner,"RIGHT.html",LAST);
    //MatrixXi tmp=lLast.transpose();
    //lGT=tmp*lEQ*lFirst;
    lGT=lLast.transpose()*lEQ*lFirst;
    for(int i=0;i<size;i++)
        for(int j=0;j<size;j++)
            if (lGT(i,j)>=1 && scanner->getTerms()->contains(fullDictionary->at(j))) lGT(i,j)=1;
                else lGT(i,j)=0;

    //EQUAL Correct
    //writeHTML(scanner,"EQUAL.html",EQUAL);

    //LT Correct
    //writeHTML(scanner,"LT.html",LT);

    //writeHTML(scanner,"GT.html",GT);

    /*int ** matr =new int * [size];
    for(int i=0;i<size;i++)
    {
        matr[i]=new int[size];
        memset(matr[i],0,size);
    }*/
    for(int i=0;i<size;i++)
        for(int j=0;j<size;j++)
        {
            int relation=0;
            if(lLT(i,j)>0)
                relation|=RelationType::LT;
            if(lEQ(i,j)>0)
                relation|=RelationType::EQ;
            if(lGT(i,j)>0)
                relation|=RelationType::GT;
            lRLT(i,j)=relation;
        }
    /*
    QFile file("relations.html");
    char * relStrings[]={"","<",">","<>","=","<=",">=","<>="};
    if(file.open(QIODevice::WriteOnly))
    {
        const QStringList * fullDictionary=scanner->getFullDictionary();
        file.write("<html><head><title>Relations.html</title></head><body><table border='1'><tr><td>&nbsp;</td>");
        for(int i=0;i<size;i++)
            file.write("<td>"+fullDictionary->at(i).toAscii()+"</td>");
        file.write("</tr>");
        for(int i=0;i<size;i++)
        {
            QString str;
            file.write("<tr><td>"+fullDictionary->at(i).toAscii()+"</td>");
            for(int j=0;j<size;j++)
            {
                str=relStrings[matr[i][j]];
                file.write("<td>"+str.toAscii()+"</td>");
            }
            file.write("</tr>");
        }
        file.write("</table></body></html>");
        file.close();
    }
    for(int i=0;i<size;i++)
        delete [] matr[i];
    delete[] matr;*/
}

MatrixXi &MatrixBuilder2::getSimplePrecMatrix()
{
    return *RLT;
}

void MatrixBuilder2::clearMatrix(MatrixXi *matrix)
{
    delete matrix;
}

void MatrixBuilder2::transitiveClosure(MatrixXi * matrix)
{
    MatrixXi & m=*matrix;  // -O2
    for (int k=0;k<size;k++)
            for (int i=0;i<size;i++)
              if (m(i,k)==1)
                 for (int j=0;j<size;j++)
                     m(i,j)=(m(i,j)||m(k,j));
}

void MatrixBuilder2::reflexiveClosure(MatrixXi *matrix)
{
    MatrixXi & m=*matrix;
    for(int i=0;i<size;i++)
        m(i,i)=1;
}

MatrixXi *MatrixBuilder2::allocMatrix()
{
    MatrixXi * matrix=new MatrixXi(size,size);
    matrix->setZero(size,size);
    return matrix;
}

void MatrixBuilder2::writeHTML(GramScanner *scanner, QString filename, MatrixXi *matrix)
{
    MatrixXi & m=*matrix;
    QFile file(filename);
    if(file.open(QIODevice::WriteOnly))
    {
        const QStringList * fullDictionary=scanner->getFullDictionary();
        file.write("<html><head><title>"+filename.toAscii()+"</title></head><body><table border='1'><tr><td>&nbsp;</td>");
        for(int i=0;i<size;i++)
            file.write("<td>"+fullDictionary->at(i).toAscii()+"</td>");
        file.write("</tr>");
        for(int i=0;i<size;i++)
        {
            file.write("<tr><td>"+fullDictionary->at(i).toAscii()+"</td>");
            for(int j=0;j<size;j++)
                file.write("<td>"+QString::number(m(i,j)).toAscii()+"</td>");
            file.write("</tr>");
        }
        file.write("</table></body></html>");
        file.close();
    }
}
void MatrixBuilder2::MultiplyMatrix(MatrixXi &result,MatrixXi &A,MatrixXi &B)
{
      for(int i=0;i<size;i++)
        for(int j=0;j<size;j++)
        {
          result(i,j)=0;
          for (int k=0;k<size;k++) result(i,j)|=A(i,k)*B(k,j);
        }
}
