#ifndef REPLACEDIALOG_H
#define REPLACEDIALOG_H

#include <QDialog>
#include <QTextEdit>
#include <QDebug>
#include <QMessageBox>
#include "searchdialog.h"

namespace Ui {
class ReplaceDialog;
}

class ReplaceDialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit ReplaceDialog(QTextEdit * grammar,SearchDialog * search,QWidget *parent = 0);
    ~ReplaceDialog();
    
private slots:
    void on_btnFindNext_clicked();

    void on_btnReplace_clicked();

    void on_btnReplaceAll_clicked();

private:
    Ui::ReplaceDialog *ui;
    QTextEdit * grammar;
    SearchDialog * search;
    bool isNewCircle;
};

#endif // REPLACEDIALOG_H
