#ifndef MATRIXBUILDER_H
#define MATRIXBUILDER_H

#include <QObject>
#include <QString>
#include <QStringList>
#include "common.h"
#include "scanner.h"
#include "matrix.h"

class MatrixBuilder : public QObject
{
    Q_OBJECT
public:
    explicit MatrixBuilder(QObject *parent = 0);
    ~ MatrixBuilder();
    void process(GramScanner * scanner);
    void clear();
signals:
    
public slots:
private:
    Matrix * pFIRST;
    Matrix * pLAST;
    Matrix * pEQUAL;
    Matrix * pLT;
    Matrix * pGT;
    int ** relations;
    int matrixSize;

};

#endif // MATRIXBUILDER_H
