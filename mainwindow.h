#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>
#include <QLayout>
#include <QRegExp>
#include <QSet>
#include <QList>
#include <QMap>
#include <QHash>
#include <QTreeWidgetItem>
#include <QFile>
#include <QFileDialog>
#include <QMessageBox>
#include <QCloseEvent>
#include <QPrinter>
#include <QPrintDialog>
#include <QDesktopServices>

#include "highlighter.h"
#include "common.h"
#include "scanner.h"
#include "dependencytree.h"
#include "matrixbuilder2.h"
#include "searchdialog.h"
#include "gotodialog.h"
#include "replacedialog.h"
#include "matrixviewform.h"
//#include "matrix.h"


namespace Ui {
class MainWindow;
}


class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
signals:
    void refreshMessagesList();

private slots:

    void onValidatorMessage(int type, QString text,Position pos, unsigned int cls, unsigned int id);
    void onRefreshMessagesList();
    void on_listMessages_currentItemChanged(QTreeWidgetItem *current, QTreeWidgetItem *previous);

    void on_mnuCreate_triggered();

    void on_mnuOpen_triggered();

    void on_mnuSave_triggered();

    void on_mnuSaveAs_triggered();

    void on_mnuExit_triggered();

    void on_mnuDelete_triggered();

    void on_mnuWordWrap_toggled(bool arg1);

    void on_txtGrammar_textChanged();

    void on_mnuFind_triggered();

    void on_mnuFindNext_triggered();

    void on_mnuGoto_triggered();

    void on_mnuReplace_triggered();

    void on_mnuRecursionCheck_toggled(bool arg1);

    void on_mnuBuildMatrixSimple_triggered();

    void on_mnuPrint_triggered();

    void on_mnuAbout_triggered();

    void on_mnuHelp_triggered();

protected:
    void closeEvent(QCloseEvent *event);
private:

    bool hasSyntaxErrors;
    bool isRecursionCheckEnabled;

    GramScanner * scanner;
    DependencyTree * depTree;
    MatrixBuilder2 * matrixBuilder;
    QString progName;
    QString grmName;
    QString filePath;
    QString star;
    SearchDialog * searchDialog;
    GotoDialog * gotoDialog;
    ReplaceDialog * replaceDialog;
    MatrixViewForm * matrixView;

    bool isSaved;

    Ui::MainWindow *ui;

    QList<Message> messages; // список ошибок и предупреждений.
    Highlighter * highlighter;
    bool event(QEvent *event);
    void prepareControls();
    void updateTitle();

};

#endif // MAINWINDOW_H
