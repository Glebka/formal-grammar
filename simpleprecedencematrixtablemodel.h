#ifndef SIMPLEPRECEDENCEMATRIXTABLEMODEL_H
#define SIMPLEPRECEDENCEMATRIXTABLEMODEL_H

#include <QAbstractTableModel>
#include <QStandardItemModel>
#include <Eigen/Dense>
#include <QList>
#include "common.h"
#include "scanner.h"
#include "matrixbuilder2.h"

class SimplePrecedenceMatrixTableModel : public QAbstractTableModel
{
    Q_OBJECT
public:
    explicit SimplePrecedenceMatrixTableModel(GramScanner * scanner, MatrixBuilder2 * builder, QObject *parent = 0);
    QList<Conflict> * getConflicts();
public slots:
protected:
    int rowCount(const QModelIndex &parent) const;
    int columnCount(const QModelIndex &parent) const;
    QVariant data(const QModelIndex &index, int role) const;
    QVariant headerData(int section, Qt::Orientation orientation, int role) const;

    QList<Conflict> conflicts;
    GramScanner * scanner;
    MatrixBuilder2 * builder;
    MatrixXi relations;
};

#endif // SIMPLEPRECEDENCEMATRIXTABLEMODEL_H
