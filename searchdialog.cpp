#include "searchdialog.h"
#include "ui_searchdialog.h"

SearchDialog::SearchDialog(QTextEdit * grammar, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SearchDialog)
{
    ui->setupUi(this);
    this->grammar=grammar;
    this->setLayout(ui->horizontalLayoutMain);
    ui->horizontalLayoutMain->setMargin(10);
    QSize newsize(this->sizeHint().width()+50,this->sizeHint().height());
    this->setFixedSize(newsize);
    this->setWindowTitle("Найти");
}

void SearchDialog::setSearchString(QString search)
{
    ui->txtSearch->setText(search);
}

SearchDialog::~SearchDialog()
{
    //qDebug()<<"Destructor";
    delete ui;
}

void SearchDialog::on_btnSearch_clicked()
{
    //qDebug()<<"On EXIT!";
    //searchString=;
    //grammar->moveCursor(QTextCursor::Start);
    if(ui->txtSearch->text().length()==0) return;
    bool result;
    if(ui->checkBox->isChecked())
        result=grammar->find(ui->txtSearch->text(),QTextDocument::FindCaseSensitively);
    else
        result=grammar->find(ui->txtSearch->text());
    if(result==false)
        if(isNewCircle==true)
        {
            QMessageBox::information(this,"Formal Grammar","Не удается найти \""+ui->txtSearch->text()+"\"");
            isNewCircle=false;
        }
        else
        {
            isNewCircle=true;
            grammar->moveCursor(QTextCursor::Start,QTextCursor::MoveAnchor);
            on_btnSearch_clicked();
        }
    //grammar->moveCursor(QTextCursor::EndOfWord,QTextCursor::KeepAnchor);
}
