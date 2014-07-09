#include "replacedialog.h"
#include "ui_replacedialog.h"

ReplaceDialog::ReplaceDialog(QTextEdit *grammar, SearchDialog *search, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ReplaceDialog)
{
    ui->setupUi(this);
    this->search=search;
    this->grammar=grammar;
    this->setLayout(ui->horizontalLayout);
    ui->horizontalLayout->setMargin(10);
    this->setFixedSize(this->sizeHint().width()+50,this->sizeHint().height());
    this->setWindowTitle("Заменить");
}

ReplaceDialog::~ReplaceDialog()
{
    delete ui;
}

void ReplaceDialog::on_btnFindNext_clicked()
{
    if(ui->txtWhat->text().length()==0) return;
    search->setSearchString(ui->txtWhat->text());
    bool result;
    if(ui->checkBox->isChecked())
        result=grammar->find(ui->txtWhat->text(),QTextDocument::FindCaseSensitively);
    else
        result=grammar->find(ui->txtWhat->text());
    if(result==false)
        if(isNewCircle==true)
        {
            QMessageBox::information(this,"Formal Grammar","Не удается найти \""+ui->txtWhat->text()+"\"");
            isNewCircle=false;
        }
        else
        {
            isNewCircle=true;
            grammar->moveCursor(QTextCursor::Start,QTextCursor::MoveAnchor);
            on_btnFindNext_clicked();
        }
}

void ReplaceDialog::on_btnReplace_clicked()
{
    if(grammar->textCursor().hasSelection())
    {
        grammar->textCursor().deleteChar();
        grammar->textCursor().insertText(ui->txtReplace->text());
    }
    on_btnFindNext_clicked();
}

void ReplaceDialog::on_btnReplaceAll_clicked()
{
    if(ui->txtWhat->text().length()==0) return;
    search->setSearchString(ui->txtWhat->text());
    QString text=grammar->toPlainText();
    if(ui->checkBox->isChecked())
        grammar->setText(text.replace(ui->txtWhat->text(),ui->txtReplace->text(),Qt::CaseSensitive));
    else
        grammar->setText(text.replace(ui->txtWhat->text(),ui->txtReplace->text(),Qt::CaseInsensitive));
}
