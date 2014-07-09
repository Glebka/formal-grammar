#include "matrixbuilder.h"

MatrixBuilder::MatrixBuilder(QObject *parent) :
    QObject(parent)
{
    pFIRST=0;
    pLAST=0;
    pEQUAL=0;
    pLT=0;
    pGT=0;
    matrixSize=0;
}

MatrixBuilder::~MatrixBuilder()
{
    clear();
}

void MatrixBuilder::process(GramScanner *scanner)
{
    const QList<SimpleRelationPair> pairs=scanner->getSimpleRelationPairs();
    const QStringList * fullDictionary=scanner->getFullDictionary();
    clear();
    this->matrixSize=fullDictionary->size();
    /*FIRST = new int * [matrixSize];
    LAST = new int * [matrixSize];
    EQUAL = new int * [matrixSize];
    LT = new int * [matrixSize];
    GT = new int * [matrixSize];

    for(int i=0;i<matrixSize; i++)
    {
        FIRST[i]=new int[matrixSize];
        memset(FIRST[i], 0, matrixSize*sizeof(int));
        LAST[i]=new int[matrixSize];
        memset(LAST[i], 0, matrixSize*sizeof(int));
        EQUAL[i]=new int[matrixSize];
        memset(EQUAL[i], 0, matrixSize*sizeof(int));
        LT[i]=new int[matrixSize];
        memset(LT[i], 0, matrixSize*sizeof(int));
        GT[i]=new int[matrixSize];
        memset(GT[i], 0, matrixSize*sizeof(int));
    }*/

    pFIRST = new Matrix(matrixSize);
    pLAST = new Matrix(matrixSize);
    pEQUAL = new Matrix(matrixSize);

    Matrix & FIRST=*pFIRST;
    Matrix & LAST=*pLAST;
    Matrix & EQUAL=*pEQUAL;
    //Matrix & LT=*pLT;
    //Matrix & GT=*pGT;

    foreach(SimpleRelationPair pair, pairs)
    {
        int i=scanner->getFullDictionary()->indexOf(pair.element1);
        int j=scanner->getFullDictionary()->indexOf(pair.element2);
        if(i==-1||j==-1)
        {
            qDebug()<<"Index errror: "<< pair.element1<<" "<<pair.element2;
            continue;
        }
        //Matrix & selectedMatrix=FIRST;

        switch(pair.relation)
        {
            case SimpleRelationType::First:
                FIRST[i][j]=1;
                break;
            case SimpleRelationType::Last:
                LAST[i][j]=1;
                break;
            case SimpleRelationType::Equal:
                EQUAL[i][j]=1;
                break;
            default:
                break;
        }
    }
    FIRST.transitiveClosure();
    pLT = new Matrix(EQUAL*FIRST);
    FIRST.reflexiveClosure();
    LAST.transitiveClosure();
    LAST.transpon();
    pGT=new Matrix(LAST*EQUAL*FIRST);
    /*relations=new int *[matrixSize];
    for(int i=0;i<matrixSize;i++)
    {
        relations[i]=new int[matrixSize];
        memset(relations[i],0,matrixSize*sizeof(int));
    }*/

    //FIRST.reflexiveClosure();
    delete pLAST;
    pLAST=0;
    delete pFIRST;
    pFIRST=0;
    pGT->toHtml("GT.html",fullDictionary);
    pLT->toHtml("LT.html",fullDictionary);
    pEQUAL->toHtml("EQUAL.html",fullDictionary);

    //writeMatrix(SimpleRelationType::First,scanner);
    //transitiveClosure(scanner);
    //writeMatrix(SimpleRelationType::First,scanner);
    //writeMatrix(SimpleRelationType::Last,scanner);
    //writeMatrix(SimpleRelationType::Equal,scanner);
    //*/
}



void MatrixBuilder::clear()
{
    /*for(int i=0;i<matrixSize;i++)
    {
        delete[] FIRST[i];
        delete[] LAST[i];
        delete[] EQUAL[i];
        delete[] GT[i];
        delete[] LT[i];
    }*/
    /*delete[] FIRST;
    delete[] LAST;
    delete[] EQUAL;
    delete[] LT;
    delete[] GT;*/

    delete pFIRST;
    delete pLAST;
    delete pEQUAL;
    delete pLT;
    delete pGT;

    pFIRST=0;
    pLAST=0;
    pEQUAL=0;
    pLT=0;
    pGT=0;

    matrixSize=0;
}
