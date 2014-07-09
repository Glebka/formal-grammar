#ifndef MATRIXBUILDER2_H
#define MATRIXBUILDER2_H

#include <QObject>
#include <QStringList>
#include <QString>
#include "scanner.h"
#include "memory.h"
#include <Eigen/Dense>
#include <iostream>

using namespace Eigen;

class MatrixBuilder2 : public QObject
{
    Q_OBJECT
public:
    explicit MatrixBuilder2(QObject *parent = 0);
    ~MatrixBuilder2();
    void clear();
    void process(GramScanner * scanner);
    MatrixXi & getSimplePrecMatrix();

signals:
    
public slots:
protected:

    MatrixXi * FIRST;
    MatrixXi * LAST;
    MatrixXi * EQUAL;
    MatrixXi * LT;
    MatrixXi * GT;
    MatrixXi * RLT;

    int size;

    void clearMatrix(MatrixXi * matrix);

    void transitiveClosure(MatrixXi *matrix);
    void reflexiveClosure(MatrixXi * matrix);

    MatrixXi* allocMatrix();
    void MultiplyMatrix(MatrixXi &result,MatrixXi &A,MatrixXi &B);
    void writeHTML(GramScanner * scanner,QString filename,MatrixXi * matrix);

};

#endif // MATRIXBUILDER2_H
