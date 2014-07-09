#include "gotodialog.h"
#include "ui_gotodialog.h"

GotoDialog::GotoDialog(QTextEdit * grammar,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::GotoDialog)
{
    ui->setupUi(this);
    this->setLayout(ui->horizontalLayout);
    ui->horizontalLayout->setMargin(10);
    this->setFixedSize(this->sizeHint().width()+40,this->sizeHint().height());
    connect(this,SIGNAL(accepted()),this,SLOT(onaccept()));
    this->grammar=grammar;
    this->setWindowTitle("Перейти");
}

GotoDialog::~GotoDialog()
{
    delete ui;
}

void GotoDialog::showEvent(QShowEvent *e)
{
    ui->line->setMaximum(grammar->document()->lineCount());
    ui->line->setValue(1);
}

void GotoDialog::onaccept()
{
    grammar->moveCursor(QTextCursor::Start,QTextCursor::MoveAnchor);
    QTextCursor cursor=grammar->textCursor();
    cursor.movePosition(QTextCursor::Down,QTextCursor::MoveAnchor,ui->line->value()-1);
    grammar->setTextCursor(cursor);
}
