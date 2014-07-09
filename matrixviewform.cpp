#include "matrixviewform.h"
#include "ui_matrixviewform.h"

MatrixViewForm::MatrixViewForm(GramScanner *scanner, MatrixBuilder2 *builder, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MatrixViewForm)
{
    ui->setupUi(this);
    Qt::WindowFlags flags = 0;
    flags |= Qt::WindowMaximizeButtonHint;
    flags |= Qt::WindowContextHelpButtonHint;
    setWindowFlags( flags );
    setWindowModality(Qt::WindowModal);
    this->setWindowTitle("Матрица простого предшествования");
    this->setLayout(ui->verticalLayout);
    this->scanner=scanner;
    this->builder=builder;
    QStringList hlist;
    hlist<<" "<<" "<<"Описание"<<"Строка"<<"Столбец";
    QTreeWidgetItem *headItem= new QTreeWidgetItem(hlist);
    ui->listMessages->setHeaderItem(headItem);
    ui->listMessages->setRootIsDecorated(false);
    model=0;
    delegate=0;
    ui->comboA->setSizeAdjustPolicy(QComboBox::AdjustToContents);
    ui->comboB->setSizeAdjustPolicy(QComboBox::AdjustToContents);
    ui->matrixView->verticalHeader()->setResizeMode(QHeaderView::Fixed);
    ui->matrixView->horizontalHeader()->setResizeMode(QHeaderView::Fixed);
}

MatrixViewForm::~MatrixViewForm()
{
    /*if(delegate!=0)
        delete delegate;*/
    if(model!=0)
        delete model;
    delete ui;
}

void MatrixViewForm::onUpdateMatrix()
{
    ui->comboA->clear();
    ui->comboB->clear();
    ui->listMessages->clear();
    if(model!=0)
    {
        delete model;
        model=0;
    }
    model=new SimplePrecedenceMatrixTableModel(this->scanner,this->builder);
    delegate=new Delegate();
    //connect(model,SIGNAL(conflictDetected(int,int,int)),this,SLOT(onConflictDetected(int,int,int)));
    QList<Conflict> & list=*model->getConflicts();
    ui->listMessages->clear();
    char * conflictDescription[]={"","","","Конфликт типа <,>","","Конфликт типа <,=","Конфликт типа >,=","Конфликт типа <,>,="};
    foreach (Conflict c, list) {
        QStringList lst;

        lst<<" "<<QString::number(c.relation)<<conflictDescription[c.relation];
        lst<<QString::number(c.row+1)<<QString::number(c.col+1);
        QTreeWidgetItem * item=new QTreeWidgetItem(lst,0);
        ui->listMessages->addTopLevelItem(item);
        QIcon icon(":/icons/icons/error.png");
        item->setIcon(0,icon);
    }
    ui->matrixView->setModel(model);
    ui->matrixView->resizeColumnsToContents();
    ui->matrixView->resizeRowsToContents();
    ui->matrixView->setItemDelegate(delegate);
    const QStringList * dict=this->scanner->getFullDictionary();
    ui->comboA->addItems(*dict);
    ui->comboB->addItems(*dict);
}

void MatrixViewForm::on_actionSaveAs_triggered()
{
    QString fileName = QFileDialog::getSaveFileName(this, "Сохранить файл как","","HTML страница (*.html)");
    if(fileName.isNull()) return;
    QFile file(fileName);
    if(!file.open(QFile::WriteOnly))
        QMessageBox::critical(this,"Ошибка открытия файла", "Не удалось открыть файл для сохранения.");
    else
    {
        QList<Conflict> & list=*model->getConflicts();
        char * conflictDescription[]={"","","","Конфликт типа <,>","","Конфликт типа <,=","Конфликт типа >,=","Конфликт типа <,>,="};
        const QStringList * fullDictionary=this->scanner->getFullDictionary();
        file.write(QString("<html><head><style type='text/css'>"
                   ".vertical{-webkit-transform: rotate(-90deg);-moz-transform: rotate(-90deg);-ms-transform: rotate(-90deg);-o-transform: rotate(-90deg);transform: rotate(-90deg);}"
                   "td{border-width:1px;border-style:solid;border-color:black;border-right:none;border-bottom:none;}"
                   "table{border-width:1px;border-style:solid;border-color:black;border-top:none;border-left:none}"
                   ".conflict{background-color:red}"
                   "</style>"
                   "<title>Матрица предшествования</title></head><body>"
                   "<h1>"
                   +QString((list.size()>0)?"Матрица предшествования исходой грамматики":"Матрица предшествования бесконфликтной грамматики")+
                   "</h1>"
                   "<br><br>"
                   "<table cellspacing='0' cellpadding='5'><tr><td>&nbsp;</td>").toAscii());
        for(int i=0;i<fullDictionary->size();i++)
            file.write("<td>"+fullDictionary->at(i).toAscii()+"</td>");
        file.write("</tr>");
        for(int i=0;i<fullDictionary->size();i++)
        {
            QString str;
            file.write("<tr><td>"+fullDictionary->at(i).toAscii()+"</td>");
            for(int j=0;j<fullDictionary->size();j++)
            {
                file.write(QString("<td"+QString((ui->matrixView->model()->data(ui->matrixView->model()->index(i,j),Qt::UserRole).toBool())?" class='conflict'":"")+">&nbsp;"+ui->matrixView->model()->data(ui->matrixView->model()->index(i,j),Qt::DisplayRole).toString()+"</td>").toAscii());
            }
            file.write("</tr>");
        }
        file.write("</table><br>");
        QString text;
        if(list.size()>0)
        {
            file.write("<h3>Примечания</h3><br><ol>");
            foreach (Conflict c, list) {
                text=QString(conflictDescription[c.relation])+" между символом "+this->scanner->getFullDictionary()->at(c.row)+" и "+this->scanner->getFullDictionary()->at(c.col);
                file.write(QString("<li>"+text+"</li>").toAscii());
            }
            file.write("</ol>");
        }
        file.write("</body></html>");
        file.close();
    }
}



void MatrixViewForm::on_actionHelp_triggered()
{
    QDesktopServices::openUrl(QUrl("file:///"+QApplication::applicationDirPath()+"/Help.chm"));
}


void MatrixViewForm::showEvent(QShowEvent *e)
{
    onUpdateMatrix();
    e->accept();
}

void MatrixViewForm::showRelation(const QModelIndex &index)
{
    QString rel=index.data().toString();
    if(rel.length()==0)
    {
        ui->relation->setText("Нет отношения");
        ui->relation->setStyleSheet("background-color:none;border-width:1px;border-style:solid;border-color:black;");
    }
    else
    {
        if(index.data(Qt::UserRole).toBool())
            ui->relation->setStyleSheet("background-color:red;border-width:1px;border-style:solid;border-color:black;");
        else
            ui->relation->setStyleSheet("background-color:none;border-width:1px;border-style:solid;border-color:black;");
        ui->relation->setText(rel);
    }
}

bool MatrixViewForm::event(QEvent *event)
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

void MatrixViewForm::prepareControls()
{
    QList<int> list;
    list<<this->height()*0.75;
    list<<this->height()*0.25;
    ui->splitter->setSizes(list);
    ui->listMessages->setColumnWidth(0,25);
    ui->listMessages->setColumnWidth(1,25);
    ui->listMessages->setColumnWidth(2,(this->size().width()-50)*0.7);
    ui->listMessages->setColumnWidth(3,(this->size().width()-50)*0.15);
    ui->listMessages->setColumnWidth(4,(ui->listMessages->width()-50)*0.15);
}

void MatrixViewForm::on_actionPrint_triggered()
{
    QPrinter printer;

    QPrintDialog *dialog = new QPrintDialog(&printer, this);
    dialog->setWindowTitle("Печать матрицы простого предшествования");
    if (dialog->exec() != QDialog::Accepted)
            return;
    QPainter painter;
    painter.begin(&printer);
    QAbstractItemModel* model = ui->matrixView->model();
    QHeaderView* hHeader = ui->matrixView->horizontalHeader();
    QHeaderView* vHeader = ui->matrixView->verticalHeader();
    QList<Conflict> & list=*(this->model->getConflicts());
    if (model) {

        // Check that there is a valid device to print to.
        if (!painter.isActive())
            return;
        int fromRow=0,fromCol=0,toRow=0,toCol=0;
        int pageHeight = painter.device()->height()-50;
        int colHeaderHeight=vHeader->sectionSize(0);
        int startY=25;
        int realY;
        painter.save();
        QFont font;
        font.setBold(true);
        font.setFamily("Arial");
        font.setPixelSize(20);
        painter.setFont(font);
        if(list.size()>0)
            painter.drawText(25,25,painter.device()->width()-25,25,Qt::AlignCenter,"Матрица предшествования исходной грамматики");
        else
            painter.drawText(25,25,painter.device()->width()-25,25,Qt::AlignCenter,"Матрица предшествования бесконфликтной грамматики");
        painter.restore();
        startY+=50;
        while(true)
        {
            realY=drawFromTo(painter,model,hHeader,vHeader,fromRow,fromCol,toRow,toCol,startY);
            startY=25;
            while(toCol<model->columnCount())
            {
                printer.newPage();
                fromCol=toCol;
                toCol=0;
                //toRow=0;
                realY=drawFromTo(painter,model,hHeader,vHeader,fromRow,fromCol,toRow,toCol,startY);
            }
            if(toRow<model->rowCount())
            {
                fromRow=toRow;
                toRow=0;
                fromCol=0;
                toCol=0;
                printer.newPage();
            }
            else
                break;
        }
        if(list.size()>0)
        {
            printer.newPage();
            painter.save();
            painter.setFont(font);
            painter.drawText(25,25,painter.device()->width()-25,25,Qt::AlignCenter,"Примечания");
            painter.restore();
            int x=50;
            int y=25+colHeaderHeight+25;
            char * conflictDescription[]={"","","","Конфликт типа <,>","","Конфликт типа <,=","Конфликт типа >,=","Конфликт типа <,>,="};
            QString text;
            int number=1;
            foreach (Conflict c, list) {
                text=QString::number(number)+".\t"+QString(conflictDescription[c.relation])+" между символом "+this->scanner->getFullDictionary()->at(c.row)+" и "+this->scanner->getFullDictionary()->at(c.col);
                painter.drawText(x,y,painter.device()->width()-25,20,Qt::AlignLeft,text);
                y+=25;
                if(y>=pageHeight)
                {
                    printer.newPage();
                    y=25;
                }
                number++;
            }
            /*QTextDocument doc;
            QStringList lst;
            lst<<"<html><head><title>tttt</title></head>"
            <<"<body>"
            <<"<h4>Примечания</h4>"
            <<"<ol>";
            char * conflictDescription[]={"","","","Конфликт типа <,>","","Конфликт типа <,=","Конфликт типа >,=","Конфликт типа <,>,="};
            QString text;
            foreach(Conflict c, list)
            {
                text=QString(conflictDescription[c.relation])+" между символом "+this->scanner->getFullDictionary()->at(c.row)+" и "+this->scanner->getFullDictionary()->at(c.col);
                lst<<"<li>"<<text<<"</li>";
            }
            lst<<"</ol>"<<"</body></html>";
            doc.setHtml(lst.join(""));
            doc.print(&printer);*/
        }
        /*qDebug()<<model->rowCount()<<" ; "<<toRow;
        qDebug()<<model->columnCount()<<" ; "<<toCol;*/
    }
    painter.end();
}

int MatrixViewForm::drawFromTo(QPainter &painter, QAbstractItemModel *model, QHeaderView *hHeader, QHeaderView *vHeader, int fromRow, int fromCol, int &toRow, int &toCol,int startY=25)
{
    int pageLeft = 25;
    int pageHeight = painter.device()->height()-50;
    int pageWidth = painter.device()->width()-50;
    int x;
    int y;
    int rowHeaderWidth=vHeader->size().width();
    int colHeaderHeight=vHeader->sectionSize(0);
    //print page
    // draw row headers
    x=pageLeft;
    y=startY;
    painter.drawRect(x,y,rowHeaderWidth,colHeaderHeight);
    y+=colHeaderHeight;
    int row=fromRow;
    int col=fromCol;
    int maxRow;
    int maxCol;
    if(toRow==0)
        maxRow=model->rowCount();
    else
        maxRow=toRow;
    if(toCol==0)
        maxCol=model->columnCount();
    else
        maxCol=toCol;
    while(row<maxRow)
    {
        if(y+colHeaderHeight>pageHeight)
            break;
        painter.drawRect(x,y,rowHeaderWidth,colHeaderHeight);
        painter.drawText(x, y, rowHeaderWidth, colHeaderHeight
                         , Qt::TextWordWrap
                         | Qt::AlignVCenter
                         | Qt::AlignHCenter
                         , model->headerData(row,Qt::Vertical,Qt::DisplayRole).toString()
                         );
        y+=colHeaderHeight;
        row++;
    }
    if(toRow==0) toRow=row;
    // draw column headers
    y=startY;
    x+=rowHeaderWidth;
    while(col<maxCol)
    {
        int sectWidth=hHeader->sectionSize(col);
        if(x+sectWidth>pageWidth)
            break;
        painter.drawRect(x,y,sectWidth,colHeaderHeight);
        painter.drawText(x, y, sectWidth, colHeaderHeight
                         , Qt::TextWordWrap
                         | Qt::AlignVCenter
                         | Qt::AlignHCenter
                         , model->headerData(col,Qt::Horizontal,Qt::DisplayRole).toString()
                         );
        x+=sectWidth;
        col++;
    }
    if(toCol==0) toCol=col;
    // draw table content
    y=startY+colHeaderHeight;
    int cellWidth=0;
    int cellHeight=colHeaderHeight;
    for(int i=fromRow;i<toRow;i++)
    {
        x=pageLeft+rowHeaderWidth;
        for(int j=fromCol;j<toCol;j++)
        {
            cellWidth=hHeader->sectionSize(j);
            if(model->data(model->index(i,j),Qt::UserRole).toBool())
                painter.fillRect(x,y,cellWidth,cellHeight,Qt::lightGray);
            painter.drawRect(x,y,cellWidth,cellHeight);
            painter.drawText(x, y, cellWidth, cellHeight
                             , Qt::TextWordWrap
                             | Qt::AlignVCenter
                             | Qt::AlignHCenter
                             , model->data(model->index(i,j),Qt::DisplayRole).toString()
                             );
            x+=cellWidth;
        }
        y+=cellHeight;
    }
    return y;
}

void MatrixViewForm::on_matrixView_activated(const QModelIndex &index)
{
    ui->comboA->setCurrentIndex(index.row());
    ui->comboB->setCurrentIndex(index.column());

}

void MatrixViewForm::on_comboA_currentIndexChanged(int index)
{
    QModelIndex ind=model->index(index,ui->comboB->currentIndex());
    ui->matrixView->setCurrentIndex(ind);
    showRelation(ind);
}

void MatrixViewForm::on_comboB_currentIndexChanged(int index)
{
    QModelIndex ind=model->index(ui->comboA->currentIndex(),index);
    ui->matrixView->setCurrentIndex(ind);
    showRelation(ind);
}

void MatrixViewForm::on_listMessages_currentItemChanged(QTreeWidgetItem *current, QTreeWidgetItem *previous)
{
    if(current==0) return;
    unsigned int line;
    unsigned int col;
    line=current->data(3,0).toUInt()-1;
    col=current->data(4,0).toUInt()-1;
    QModelIndex ind=model->index(line,col);
    ui->matrixView->setCurrentIndex(ind);
    on_matrixView_activated(ind);
}

/*QList<QVector<QLine> > linePages;
QVector<QLine> verticalLines;
QList<QList<int> > sectionPages;
QList<int> sections;
QList<QList<int> > widthPages;
QList<int> widths;
QList<int> pageRights;
QList<QStringList> pageLabels;
QStringList labels;
int logicalIndex;

// Перечисляем столбцы
for (int i = 0; i < hHeader->count(); ++i) {
  logicalIndex = hHeader->logicalIndex(i);

  // Если столбец не скрыт
  if (!hHeader->isSectionHidden(logicalIndex)) {
    // Если уже не помещаемся на страницу пошем новую страницу
    if (pageWidth <= x + hHeader->sectionSize(logicalIndex)) {
      verticalLines.append(QLine(x, pageTop, x, pageHeight));
      pageRights.append(x);
      x = pageLeft;
      sectionPages.append(sections);
      sections.clear();
      linePages.append(verticalLines);
      verticalLines.clear();
      widthPages.append(widths);
      widths.clear();
      pageLabels.append(labels);
      labels.clear();
    }

    // Добавляем, так как колонка видимая
    sections.append(logicalIndex);
    widths.append(hHeader->sectionSize(logicalIndex));
    labels.append(model->headerData(logicalIndex, Qt::Horizontal).toString());
    verticalLines.append(QLine(x, pageTop, x, pageHeight));
    // Смещаемся правее на ширину колонки
    x += hHeader->sectionSize(logicalIndex);
  }
}

if (!sections.isEmpty()) {
  verticalLines.append(QLine(x, pageTop, x, pageHeight));
  pageRights.append(x);
  x = pageLeft;
  sectionPages.append(sections);
  sections.clear();
  linePages.append(verticalLines);
  verticalLines.clear();
  widthPages.append(widths);
  widths.clear();
  pageLabels.append(labels);
  labels.clear();
}

int columnPageCount = sectionPages.count();
int columnCount = sections.count();
int rowCount = model->rowCount(ui->matrixView->rootIndex());
int rowHeight;
int columnWidth;
QModelIndex currentIndex;
int row = 0;
int lastPageRow = 0;
int columnPageIndex = 0;
int rightColumn;

while (true) {
  // Получаем колонки текущей страницы
  sections = sectionPages.at(columnPageIndex);
  widths = widthPages.at(columnPageIndex);
  verticalLines = linePages.at(columnPageIndex);
  // Количество колонок текущей страницы
  columnCount = sections.count();
  rightColumn = pageRights.at(columnPageIndex);
  labels = pageLabels.at(columnPageIndex);
  // Перемещаемся в левый верхний угол страницы
  x = pageLeft;
  y = pageTop;
  rowHeight = hHeader->height();

  // Рисуем колонки
  for (int i = 0; i < columnCount; ++i) {
    // Текущее значение
    columnWidth = widths.at(i);
    painter.drawText(x, y, columnWidth, rowHeight
                     , currentIndex.data(Qt::TextAlignmentRole).toInt()
                     | Qt::TextWordWrap
                     | Qt::AlignVCenter
                     | Qt::AlignHCenter
                     , labels.at(i)
                    );
    painter.drawLine(pageLeft, y, rightColumn, y);
    // Перемащаемся правее
    x += widths.at(i);
  }

  y += rowHeight;
  x = pageLeft;

  // Пока можем рисовать на текущей странице
  while (true) {
    // Высота текущей строки
    rowHeight = vHeader->sectionSize(row);

    if (y + rowHeight > pageHeight) {
      //--row;
      break;
    }

    // Рисуем колонки
    for (int i = 0; i < columnCount; ++i) {
      // Текущее значение
      currentIndex = model->index(row, sections.at(i), ui->matrixView->rootIndex());
      columnWidth = widths.at(i);

      if (!currentIndex.data().isNull())
        painter.drawText(x, y, columnWidth, rowHeight
                         , currentIndex.data(Qt::TextAlignmentRole).toInt()
                         | Qt::TextWordWrap
                         | Qt::AlignVCenter
                         | Qt::AlignHCenter
                         , currentIndex.data().toString()
                        );

      painter.drawLine(pageLeft, y, rightColumn, y);
      // Перемащаемся правее
      x += widths.at(i);
    }

    x = pageLeft;
    // Перемещаемся ниже
    y += rowHeight;
    // Берем следующую строку
    ++row;

    // Если строки кончились
    if (row >= rowCount)
      break;
  }

  // Рисуем завершающую горизонтальную линию
  painter.drawLine(pageLeft, y, rightColumn, y);
  // Рисуем вертикальные линии
  painter.drawLines(verticalLines);
  // Вытираем лишние концы
  // TODO: hard-coded background color for page
  painter.fillRect(pageLeft, y + 1, pageWidth, pageHeight - (y + 1), QBrush(Qt::white));

  // Если предыдущие колонки не поместились
  if (columnPageIndex < columnPageCount - 1) {
    ++columnPageIndex;
    row = lastPageRow;
  // Предыдущие колонки поместились
  } else {
    columnPageIndex = 0;
    lastPageRow = row;

    // Строки закончились
    if (row >= rowCount)
      break;
  }

  // Создаем новую страницу
  printer.newPage();
}
}*/
