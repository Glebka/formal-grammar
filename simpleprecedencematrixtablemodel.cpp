#include "simpleprecedencematrixtablemodel.h"

bool isConflict[]={false,false,false,true,false,true,true,true};

SimplePrecedenceMatrixTableModel::SimplePrecedenceMatrixTableModel(GramScanner *scanner, MatrixBuilder2 *builder, QObject *parent) :
    QAbstractTableModel(parent)
{
    this->scanner=scanner;
    this->builder=builder;
    relations=builder->getSimplePrecMatrix();

    //fillHeaderModel(_horizontalHeaderModel);
    //fillHeaderModel(_verticalHeaderModel);
}

QList<Conflict> *SimplePrecedenceMatrixTableModel::getConflicts()
{
    if (conflicts.size()>0) return &conflicts;
    for(int row=0;row<relations.rows();row++)
        for(int col=0;col<relations.cols();col++)
        {
            int relation=relations(row,col);
            if(isConflict[relation])
            {
                Conflict c(row,col,relation);
                conflicts<<c;
            }
                //emit conflictDetected(row,col,relation);
        }
    return &conflicts;
}

int SimplePrecedenceMatrixTableModel::rowCount(const QModelIndex &parent) const
{
    return relations.rows();
}

int SimplePrecedenceMatrixTableModel::columnCount(const QModelIndex &parent) const
{
    return relations.cols();
}

QVariant SimplePrecedenceMatrixTableModel::data(const QModelIndex &index, int role) const
{
    char * relStrings[]={"","<",">","<>","=","<=",">=","<>="};

    if (role == Qt::DisplayRole)
    {
        if(index.isValid())
        {
            int row=index.row();
            int col=index.column();
            int relation=relations(row,col);
            QString result=relStrings[relation];
            return QVariant(result);
        }
    }
    if(role==Qt::UserRole)
    {
        if(index.isValid())
            return QVariant(isConflict[relations(index.row(),index.column())]);
    }
    if(role==Qt::TextAlignmentRole)
    {
        return Qt::AlignCenter;
    }
    return QVariant();
}

QVariant SimplePrecedenceMatrixTableModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (role != Qt::DisplayRole)
           return QVariant();
    if(section>=scanner->getFullDictionary()->size()) return QVariant();
    return QVariant(scanner->getFullDictionary()->at(section));
}
