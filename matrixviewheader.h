#ifndef MATRIXVIEWHEADER_H
#define MATRIXVIEWHEADER_H

#include <QHeaderView>
#include <QPainter>
#include <QVariant>
#include <QDebug>

class MatrixViewHeader : public QHeaderView
{
    Q_OBJECT
public:
    MatrixViewHeader(Qt::Orientation orientation, QWidget *parent);

protected:
    void paintSection(QPainter *painter, const QRect &rect, int logicalIndex) const;
};

#endif // MATRIXVIEWHEADER_H
