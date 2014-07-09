#ifndef SEARCHDIALOG_H
#define SEARCHDIALOG_H

#include <QDialog>
#include <QTextEdit>
#include <QString>
#include <QMessageBox>
#include <QDebug>

namespace Ui {
class SearchDialog;
}

class SearchDialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit SearchDialog(QTextEdit *grammar,QWidget *parent = 0);
    void setSearchString(QString search);
    ~SearchDialog();
    
public slots:

    void on_btnSearch_clicked();

private:
    Ui::SearchDialog *ui;
    QTextEdit * grammar;
    bool isNewCircle;
};

#endif // SEARCHDIALOG_H
