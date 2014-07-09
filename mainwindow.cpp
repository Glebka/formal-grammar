#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    grmName="Безымянный.grm";
    progName="Formal Grammar";
    star="*";
    isSaved=false;
    isRecursionCheckEnabled=true;

    ui->setupUi(this);

    searchDialog=new SearchDialog(ui->txtGrammar,this);
    gotoDialog=new GotoDialog(ui->txtGrammar,this);
    replaceDialog=new ReplaceDialog(ui->txtGrammar,searchDialog,this);

    scanner=new GramScanner(this);
    depTree=new DependencyTree(this);
    matrixBuilder=new MatrixBuilder2(this);
    matrixView=new MatrixViewForm(scanner,matrixBuilder);

    connect(scanner,SIGNAL(message(int,QString,Position,uint,uint)),this,SLOT(onValidatorMessage(int,QString,Position,uint,uint)));
    connect(depTree,SIGNAL(message(int,QString,Position,uint,uint)),this,SLOT(onValidatorMessage(int,QString,Position,uint,uint)));
    connect(this,SIGNAL(refreshMessagesList()),this,SLOT(onRefreshMessagesList()));

    connect(ui->mnuUndo,SIGNAL(triggered()),ui->txtGrammar,SLOT(undo()));
    connect(ui->mnuRedo,SIGNAL(triggered()),ui->txtGrammar,SLOT(redo()));
    connect(ui->mnuCopy,SIGNAL(triggered()),ui->txtGrammar,SLOT(copy()));
    connect(ui->mnuPaste,SIGNAL(triggered()),ui->txtGrammar,SLOT(paste()));
    connect(ui->mnuCut,SIGNAL(triggered()),ui->txtGrammar,SLOT(cut()));
    connect(ui->mnuSelectAll,SIGNAL(triggered()),ui->txtGrammar,SLOT(selectAll()));
    connect(ui->txtGrammar,SIGNAL(copyAvailable(bool)),ui->mnuCopy,SLOT(setEnabled(bool)));
    connect(ui->txtGrammar,SIGNAL(copyAvailable(bool)),ui->mnuCut,SLOT(setEnabled(bool)));
    connect(ui->txtGrammar,SIGNAL(copyAvailable(bool)),ui->mnuDelete,SLOT(setEnabled(bool)));
    connect(ui->txtGrammar,SIGNAL(undoAvailable(bool)),ui->mnuUndo,SLOT(setEnabled(bool)));
    connect(ui->txtGrammar,SIGNAL(redoAvailable(bool)),ui->mnuRedo,SLOT(setEnabled(bool)));

    highlighter = new Highlighter(ui->txtGrammar->document());

    this->setWindowTitle(grmName+star+" - "+progName);
    QVBoxLayout * layout = new QVBoxLayout();
    layout->addWidget(ui->splitter);
    ui->centralWidget->setLayout(layout);
    layout->setMargin(0);
    layout->setSpacing(0);

    QStringList hlist;
    hlist<<" "<<" "<<" "<<"Описание"<<"Строка"<<"Столбец";
    QTreeWidgetItem *headItem= new QTreeWidgetItem(hlist);
    ui->listMessages->setHeaderItem(headItem);
    ui->listMessages->setRootIsDecorated(false);


    QFont font;
    font.setFamily("Courier");
    font.setFixedPitch(true);
    font.setPointSize(10);
    ui->txtGrammar->setFont(font);
    QStringList sample;
    sample<<"S = H A ! B \"aa\""<<"H = A \"a\" ! A"<<"A = \"bb\" A ! \"b\""<<"B = \"c\" A ! A \"b\" ! H \"c\"";
    ui->txtGrammar->setText(sample.join("\n"));
}

MainWindow::~MainWindow()
{
    delete ui;
}

bool MainWindow::event(QEvent *event)

{
   int returnValue = QWidget::event(event);
   if (event->type() == QEvent::Polish)
   {
      prepareControls();
      return true;
   }
   if (event->type() == QEvent::Resize)
   {
      prepareControls();
      return true;
   }
   return returnValue;
}

void MainWindow::prepareControls()
{



    QList<int> list;
    list<<this->height()*0.8;
    list<<this->height()*0.2;
    ui->splitter->setSizes(list);
    ui->listMessages->setColumnWidth(0,25);
    ui->listMessages->setColumnWidth(1,25);
    ui->listMessages->setColumnWidth(2,25);
    ui->listMessages->setColumnWidth(3,(this->size().width()-75)*0.7);
    ui->listMessages->setColumnWidth(4,(this->size().width()-75)*0.15);
    ui->listMessages->setColumnWidth(5,(ui->listMessages->width()-75)*0.15);
}

void MainWindow::updateTitle()
{
    if(isSaved==true)
        star="";
    else
        star="*";
    this->setWindowTitle(grmName+star+" - "+progName);
}

/*
S = "b" B "b"
B = "(" C ! "a"
C = B "a" ")"
*/

void MainWindow::onValidatorMessage(int type, QString text, Position pos, unsigned int cls, unsigned int id)
{
    qDebug()<<text;
    Message msg;
    msg.text=text;
    msg.pos=pos;
    msg.cls=cls;
    msg.id=id;
    msg.type=type;
    if(cls=ErrorClass::Syntax) hasSyntaxErrors=true;
    messages.append(msg);
    emit refreshMessagesList();
}

void MainWindow::onRefreshMessagesList()
{
    ui->listMessages->clear();
    foreach (Message msg, messages)
    {
        QStringList lst;
        //Message msg=messages.value(key);
        lst<<" "<<QString::number(msg.cls)<<QString::number(msg.id)<<msg.text;
        lst<<QString::number(msg.pos.line)<<QString::number(msg.pos.col);
        if(ui->btnErrors->isChecked() && msg.type==MessageType::Error)
        {
            QTreeWidgetItem * item=new QTreeWidgetItem(lst,0);
            item->setData(6,1,msg.pos.length);
            ui->listMessages->addTopLevelItem(item);
            QIcon icon(":/icons/icons/error.png");
            item->setIcon(0,icon);
        }
        if(ui->btnWarnings->isChecked() && msg.type==MessageType::Warning)
        {
            QTreeWidgetItem * item=new QTreeWidgetItem(lst,0);
            ui->listMessages->addTopLevelItem(item);
            item->setData(6,1,msg.pos.length);
            QIcon icon(":/icons/icons/warning.png");
            item->setIcon(0,icon);
        }
    }
}

void MainWindow::on_listMessages_currentItemChanged(QTreeWidgetItem *current, QTreeWidgetItem *previous)
{
    unsigned int line;
    unsigned int col;
    if(current==0) return;
    line=current->data(4,0).toUInt();
    col=current->data(5,0).toUInt();

    QTextCursor cur=ui->txtGrammar->textCursor();
    cur.setPosition(0,QTextCursor::MoveAnchor);
    cur.movePosition(QTextCursor::Down,QTextCursor::MoveAnchor,line-1);
    cur.movePosition(QTextCursor::NextCharacter,QTextCursor::MoveAnchor,col-1);
    cur.movePosition(QTextCursor::NextCharacter,QTextCursor::KeepAnchor,current->data(6,1).toUInt());
    ui->txtGrammar->setTextCursor(cur);
    ui->txtGrammar->setFocus();
}

void MainWindow::on_mnuCreate_triggered()
{
    if(!isSaved)
    {
        int answer=QMessageBox::question(this,"Formal Grammar","Сохранить изменения в "+grmName+"?","Да","Нет","Отмена");
        switch(answer)
        {
            case 0:
                on_mnuSave_triggered();
                break;
            case 1:
                break;
            case 2:
                return;
                break;
        }
    }
    ui->txtGrammar->setText("");
    grmName="Безымянный.grm";
    isSaved=true;
    filePath="";
    updateTitle();
}

void MainWindow::on_mnuOpen_triggered()
{
    if(!isSaved)
    {
        int answer=QMessageBox::question(this,"Formal Grammar","Сохранить изменения в "+grmName+"?","Да","Нет","Отмена");
        switch(answer)
        {
            case 0:
                on_mnuSave_triggered();
                break;
            case 1:
                break;
            case 2:
                return;
                break;
        }
    }
    QString fileName = QFileDialog::getOpenFileName(this, "Открыть файл","","Файлы грамматик (*.grm)");
    if(fileName.isNull()) return;
    QFile file(fileName);
    if(!file.open(QFile::ReadOnly))
        QMessageBox::critical(this,"Ошибка открытия файла", "Не удалось открыть файл грамматики.");
    else
    {
        ui->txtGrammar->setText(file.readAll());
        filePath=fileName;
        isSaved=true;
        QFileInfo info(fileName);
        grmName=info.fileName();
        updateTitle();
    }
}

void MainWindow::on_mnuSave_triggered()
{
    if(filePath.length()==0)
        on_mnuSaveAs_triggered();
    else
    {
        QFile file(filePath);
        if(!file.open(QFile::WriteOnly))
            QMessageBox::critical(this,"Ошибка открытия файла", "Не удалось открыть файл грамматики для сохранения.");
        else
        {
            file.write(ui->txtGrammar->toPlainText().toLocal8Bit());
            file.close();
            isSaved=true;
            updateTitle();
        }
    }
}

void MainWindow::on_mnuSaveAs_triggered()
{
    QString fileName = QFileDialog::getSaveFileName(this, "Сохранить файл как",grmName,"Файлы грамматик (*.grm)");
    if(fileName.isNull()) return;
    QFile file(fileName);
    if(!file.open(QFile::WriteOnly))
        QMessageBox::critical(this,"Ошибка открытия файла", "Не удалось открыть файл грамматики для сохранения.");
    else
    {
        file.write(ui->txtGrammar->toPlainText().toLocal8Bit());
        filePath=fileName;
    }
    QFileInfo info(fileName);
    grmName=info.fileName();
    isSaved=true;
    updateTitle();
}

void MainWindow::on_mnuExit_triggered()
{
    this->close();
}

void MainWindow::on_mnuDelete_triggered()
{
    QTextCursor cursor=ui->txtGrammar->textCursor();
    cursor.deleteChar();
}

void MainWindow::on_mnuWordWrap_toggled(bool arg1)
{
    ui->txtGrammar->setWordWrapMode((arg1)?QTextOption::WordWrap:QTextOption::NoWrap);
}

void MainWindow::on_txtGrammar_textChanged()
{
    isSaved=false;
    updateTitle();
}

void MainWindow::closeEvent(QCloseEvent *event)
{
    if(!isSaved)
    {
        int answer=QMessageBox::question(this,"Formal Grammar","Сохранить изменения в "+grmName+"?","Да","Нет","Отмена");
        switch(answer)
        {
            case 0:
                on_mnuSave_triggered();
                break;
            case 1:
                break;
            case 2:
                event->ignore();
                return;
                break;
        }
    }
    event->accept();
}

void MainWindow::on_mnuFind_triggered()
{
    searchDialog->show();
}

void MainWindow::on_mnuFindNext_triggered()
{
    searchDialog->on_btnSearch_clicked();
}

void MainWindow::on_mnuGoto_triggered()
{
    gotoDialog->show();
}

void MainWindow::on_mnuReplace_triggered()
{
    replaceDialog->show();
}

void MainWindow::on_mnuRecursionCheck_toggled(bool arg1)
{
    isRecursionCheckEnabled=arg1;
}

void MainWindow::on_mnuBuildMatrixSimple_triggered()
{
    /*if(matrixView->isVisible())
    {
        QMessageBox::information(this,"Formal Grammar","Закройте текущее окно просмотра матрицы простого предшествования.");
        return;
    }*/
    hasSyntaxErrors=false;
    // очистка таблиц
    ui->listMessages->clear();
    messages.clear();
    scanner->clear();
    depTree->clear();
    scanner->process(ui->txtGrammar->toPlainText(),depTree);
    // анализ рекурсивности
    if(!hasSyntaxErrors)
    {
        if(isRecursionCheckEnabled)
            depTree->process(scanner);
        matrixBuilder->process(scanner);
        if(matrixView->isVisible())
            matrixView->onUpdateMatrix();
        else
            matrixView->exec();
    }
}

void MainWindow::on_mnuPrint_triggered()
{
    QPrinter printer;

    QPrintDialog *dialog = new QPrintDialog(&printer, this);
    dialog->setWindowTitle("Печать грамматики");
    if (ui->txtGrammar->textCursor().hasSelection())
        dialog->addEnabledOption(QAbstractPrintDialog::PrintSelection);
    if (dialog->exec() != QDialog::Accepted)
            return;
    ui->txtGrammar->setDocumentTitle(grmName);
    ui->txtGrammar->print(&printer);
}

void MainWindow::on_mnuAbout_triggered()
{
    QMessageBox::information(this,"О программе","Конструктор грамматик Formal Grammar v 1.0\nАвтор: Романов Глеб Евгеньевич (rgewebppc@gmail.com)");
}

void MainWindow::on_mnuHelp_triggered()
{
    QDesktopServices::openUrl(QUrl("file:///"+QApplication::applicationDirPath()+"/Help.chm"));
}
