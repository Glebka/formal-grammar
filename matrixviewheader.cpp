#include "matrixviewheader.h"

MatrixViewHeader::MatrixViewHeader(Qt::Orientation orientation, QWidget * parent = 0) :
    QHeaderView(orientation,parent)
{
}

void MatrixViewHeader::paintSection(QPainter *painter, const QRect &rect, int logicalIndex) const
{
    qDebug()<<"LLLLLL!!!!";
    QHeaderView::paintSection (painter,rect,logicalIndex );
}
