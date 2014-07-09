#ifndef GOTODIALOG_H
#define GOTODIALOG_H

#include <QDialog>
#include <QTextEdit>
#include <QShowEvent>

namespace Ui {
class GotoDialog;
}

class GotoDialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit GotoDialog(QTextEdit *grammar, QWidget *parent);
    ~GotoDialog();
protected:
    void showEvent(QShowEvent *e);
private slots:
    void onaccept();
private:
    Ui::GotoDialog *ui;
    QTextEdit * grammar;
};

#endif // GOTODIALOG_H
