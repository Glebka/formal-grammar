#ifndef MATRIXVIEWFORM_H
#define MATRIXVIEWFORM_H

#include <QWidget>
#include <QDesktopServices>
#include <QShowEvent>
#include <QItemDelegate>
#include <QTreeWidgetItem>
#include <QFlags>
#include <QStyle>
#include <QState>
#include <QPainter>
#include <QPrinter>
#include <QPrintDialog>
#include <QTextDocument>
#include <QFileDialog>
#include <QMessageBox>
#include "scanner.h"
#include "matrixbuilder2.h"
#include "simpleprecedencematrixtablemodel.h"

namespace Ui {
class MatrixViewForm;
}

class Delegate : public QItemDelegate
 {
 Q_OBJECT
 public:
 Delegate(QWidget *parent = 0) : QItemDelegate(parent) {}
 void paint(QPainter *painter, const QStyleOptionViewItem &option,
                const QModelIndex &index) const
    {
     QString val;
     bool isConflict=false;
     if (qVariantCanConvert<QString>(index.data()))
         val = qVariantValue<QString>(index.data());
     if(qVariantCanConvert<bool>(index.data(Qt::UserRole)))
         isConflict=qVariantValue<bool>(index.data(Qt::UserRole));
     QStyleOptionViewItem newopt=option;
     newopt.state|=QStyle::State_Active;
     if (isConflict && !option.state.testFlag(QStyle::State_Selected))
         {
            QBrush brush(Qt::red);
            painter->fillRect(option.rect,brush);
            QTextOption o(Qt::AlignCenter);
            painter->drawText(option.rect,val,o);
         }
     else
       QItemDelegate::paint(painter, newopt, index);
    }
 };

class MatrixViewForm : public QDialog
{
    Q_OBJECT
    
public:
    explicit MatrixViewForm(GramScanner * scanner, MatrixBuilder2 * builder,QWidget *parent = 0);
    ~MatrixViewForm();
public slots:
    void onUpdateMatrix();
private slots:    
    void on_actionSaveAs_triggered();

    void on_actionPrint_triggered();

    void on_actionHelp_triggered();

    void on_matrixView_activated(const QModelIndex &index);

    void on_comboA_currentIndexChanged(int index);

    void on_comboB_currentIndexChanged(int index);


    void on_listMessages_currentItemChanged(QTreeWidgetItem *current, QTreeWidgetItem *previous);

private:
    Ui::MatrixViewForm *ui;
    GramScanner * scanner;
    MatrixBuilder2 * builder;
    SimplePrecedenceMatrixTableModel * model;
    Delegate * delegate;
    void showEvent(QShowEvent *e);
    void showRelation(const QModelIndex & index);
    bool event(QEvent *event);
    void prepareControls();
    int drawFromTo(QPainter & painter,QAbstractItemModel * model,QHeaderView* hHeader,QHeaderView* vHeader,int fromRow,int fromCol, int & toRow, int & toCol,int startY);
};

#endif // MATRIXVIEWFORM_H
