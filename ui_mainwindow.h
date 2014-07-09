/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Mon 9. Sep 19:18:10 2013
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QSplitter>
#include <QtGui/QStatusBar>
#include <QtGui/QTextEdit>
#include <QtGui/QToolBar>
#include <QtGui/QTreeWidget>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *mnuCreate;
    QAction *mnuOpen;
    QAction *mnuSave;
    QAction *mnuSaveAs;
    QAction *mnuPrint;
    QAction *mnuExit;
    QAction *mnuUndo;
    QAction *mnuRedo;
    QAction *mnuCut;
    QAction *mnuCopy;
    QAction *mnuPaste;
    QAction *mnuDelete;
    QAction *mnuFind;
    QAction *mnuFindNext;
    QAction *mnuReplace;
    QAction *mnuGoto;
    QAction *mnuSelectAll;
    QAction *mnuHelp;
    QAction *mnuAbout;
    QAction *mnuWordWrap;
    QAction *mnuOptions;
    QAction *mnuRecursionCheck;
    QAction *mnuBuildMatrixSimple;
    QWidget *centralWidget;
    QSplitter *splitter;
    QTextEdit *txtGrammar;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QPushButton *btnErrors;
    QPushButton *btnWarnings;
    QSpacerItem *horizontalSpacer;
    QTreeWidget *listMessages;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menu;
    QMenu *menuAjhvfn;
    QMenu *menu_2;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(676, 467);
        mnuCreate = new QAction(MainWindow);
        mnuCreate->setObjectName(QString::fromUtf8("mnuCreate"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icons/icons/newfile.png"), QSize(), QIcon::Normal, QIcon::Off);
        mnuCreate->setIcon(icon);
        mnuOpen = new QAction(MainWindow);
        mnuOpen->setObjectName(QString::fromUtf8("mnuOpen"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/icons/icons/open.png"), QSize(), QIcon::Normal, QIcon::Off);
        mnuOpen->setIcon(icon1);
        mnuSave = new QAction(MainWindow);
        mnuSave->setObjectName(QString::fromUtf8("mnuSave"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/icons/icons/save.png"), QSize(), QIcon::Normal, QIcon::Off);
        mnuSave->setIcon(icon2);
        mnuSaveAs = new QAction(MainWindow);
        mnuSaveAs->setObjectName(QString::fromUtf8("mnuSaveAs"));
        mnuSaveAs->setIcon(icon2);
        mnuPrint = new QAction(MainWindow);
        mnuPrint->setObjectName(QString::fromUtf8("mnuPrint"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/icons/icons/print.png"), QSize(), QIcon::Normal, QIcon::Off);
        mnuPrint->setIcon(icon3);
        mnuExit = new QAction(MainWindow);
        mnuExit->setObjectName(QString::fromUtf8("mnuExit"));
        mnuUndo = new QAction(MainWindow);
        mnuUndo->setObjectName(QString::fromUtf8("mnuUndo"));
        mnuUndo->setEnabled(false);
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/icons/icons/undo.png"), QSize(), QIcon::Normal, QIcon::Off);
        mnuUndo->setIcon(icon4);
        mnuRedo = new QAction(MainWindow);
        mnuRedo->setObjectName(QString::fromUtf8("mnuRedo"));
        mnuRedo->setEnabled(false);
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/icons/icons/redo.png"), QSize(), QIcon::Normal, QIcon::Off);
        mnuRedo->setIcon(icon5);
        mnuCut = new QAction(MainWindow);
        mnuCut->setObjectName(QString::fromUtf8("mnuCut"));
        mnuCut->setEnabled(false);
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/icons/icons/cut.png"), QSize(), QIcon::Normal, QIcon::Off);
        mnuCut->setIcon(icon6);
        mnuCopy = new QAction(MainWindow);
        mnuCopy->setObjectName(QString::fromUtf8("mnuCopy"));
        mnuCopy->setEnabled(false);
        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/icons/icons/copy.png"), QSize(), QIcon::Normal, QIcon::Off);
        mnuCopy->setIcon(icon7);
        mnuPaste = new QAction(MainWindow);
        mnuPaste->setObjectName(QString::fromUtf8("mnuPaste"));
        QIcon icon8;
        icon8.addFile(QString::fromUtf8(":/icons/icons/paste.png"), QSize(), QIcon::Normal, QIcon::Off);
        mnuPaste->setIcon(icon8);
        mnuDelete = new QAction(MainWindow);
        mnuDelete->setObjectName(QString::fromUtf8("mnuDelete"));
        mnuDelete->setEnabled(false);
        QIcon icon9;
        icon9.addFile(QString::fromUtf8(":/icons/icons/delete.png"), QSize(), QIcon::Normal, QIcon::Off);
        mnuDelete->setIcon(icon9);
        mnuFind = new QAction(MainWindow);
        mnuFind->setObjectName(QString::fromUtf8("mnuFind"));
        QIcon icon10;
        icon10.addFile(QString::fromUtf8(":/icons/icons/find.png"), QSize(), QIcon::Normal, QIcon::Off);
        mnuFind->setIcon(icon10);
        mnuFindNext = new QAction(MainWindow);
        mnuFindNext->setObjectName(QString::fromUtf8("mnuFindNext"));
        mnuFindNext->setIcon(icon10);
        mnuReplace = new QAction(MainWindow);
        mnuReplace->setObjectName(QString::fromUtf8("mnuReplace"));
        QIcon icon11;
        icon11.addFile(QString::fromUtf8(":/icons/icons/replace.png"), QSize(), QIcon::Normal, QIcon::Off);
        mnuReplace->setIcon(icon11);
        mnuGoto = new QAction(MainWindow);
        mnuGoto->setObjectName(QString::fromUtf8("mnuGoto"));
        QIcon icon12;
        icon12.addFile(QString::fromUtf8(":/icons/icons/goto.png"), QSize(), QIcon::Normal, QIcon::Off);
        mnuGoto->setIcon(icon12);
        mnuSelectAll = new QAction(MainWindow);
        mnuSelectAll->setObjectName(QString::fromUtf8("mnuSelectAll"));
        mnuHelp = new QAction(MainWindow);
        mnuHelp->setObjectName(QString::fromUtf8("mnuHelp"));
        QIcon icon13;
        icon13.addFile(QString::fromUtf8(":/icons/icons/help.png"), QSize(), QIcon::Normal, QIcon::Off);
        mnuHelp->setIcon(icon13);
        mnuAbout = new QAction(MainWindow);
        mnuAbout->setObjectName(QString::fromUtf8("mnuAbout"));
        QIcon icon14;
        icon14.addFile(QString::fromUtf8(":/icons/icons/about.png"), QSize(), QIcon::Normal, QIcon::Off);
        mnuAbout->setIcon(icon14);
        mnuWordWrap = new QAction(MainWindow);
        mnuWordWrap->setObjectName(QString::fromUtf8("mnuWordWrap"));
        mnuWordWrap->setCheckable(true);
        mnuWordWrap->setChecked(true);
        mnuOptions = new QAction(MainWindow);
        mnuOptions->setObjectName(QString::fromUtf8("mnuOptions"));
        mnuRecursionCheck = new QAction(MainWindow);
        mnuRecursionCheck->setObjectName(QString::fromUtf8("mnuRecursionCheck"));
        mnuRecursionCheck->setCheckable(true);
        mnuRecursionCheck->setChecked(true);
        QIcon icon15;
        icon15.addFile(QString::fromUtf8(":/icons/icons/check.png"), QSize(), QIcon::Normal, QIcon::Off);
        mnuRecursionCheck->setIcon(icon15);
        mnuBuildMatrixSimple = new QAction(MainWindow);
        mnuBuildMatrixSimple->setObjectName(QString::fromUtf8("mnuBuildMatrixSimple"));
        QIcon icon16;
        icon16.addFile(QString::fromUtf8(":/icons/icons/matrix-simple.png"), QSize(), QIcon::Normal, QIcon::Off);
        mnuBuildMatrixSimple->setIcon(icon16);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        splitter = new QSplitter(centralWidget);
        splitter->setObjectName(QString::fromUtf8("splitter"));
        splitter->setGeometry(QRect(10, 10, 651, 401));
        splitter->setOrientation(Qt::Vertical);
        txtGrammar = new QTextEdit(splitter);
        txtGrammar->setObjectName(QString::fromUtf8("txtGrammar"));
        splitter->addWidget(txtGrammar);
        layoutWidget = new QWidget(splitter);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        btnErrors = new QPushButton(layoutWidget);
        btnErrors->setObjectName(QString::fromUtf8("btnErrors"));
        QIcon icon17;
        icon17.addFile(QString::fromUtf8(":/icons/icons/error.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnErrors->setIcon(icon17);
        btnErrors->setCheckable(true);
        btnErrors->setChecked(true);

        horizontalLayout->addWidget(btnErrors);

        btnWarnings = new QPushButton(layoutWidget);
        btnWarnings->setObjectName(QString::fromUtf8("btnWarnings"));
        QIcon icon18;
        icon18.addFile(QString::fromUtf8(":/icons/icons/warning.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnWarnings->setIcon(icon18);
        btnWarnings->setCheckable(true);
        btnWarnings->setChecked(true);

        horizontalLayout->addWidget(btnWarnings);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        verticalLayout->addLayout(horizontalLayout);

        listMessages = new QTreeWidget(layoutWidget);
        QTreeWidgetItem *__qtreewidgetitem = new QTreeWidgetItem();
        __qtreewidgetitem->setText(0, QString::fromUtf8("1"));
        listMessages->setHeaderItem(__qtreewidgetitem);
        listMessages->setObjectName(QString::fromUtf8("listMessages"));

        verticalLayout->addWidget(listMessages);

        splitter->addWidget(layoutWidget);
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 676, 21));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        menu = new QMenu(menuBar);
        menu->setObjectName(QString::fromUtf8("menu"));
        menuAjhvfn = new QMenu(menuBar);
        menuAjhvfn->setObjectName(QString::fromUtf8("menuAjhvfn"));
        menu_2 = new QMenu(menuBar);
        menu_2->setObjectName(QString::fromUtf8("menu_2"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menu->menuAction());
        menuBar->addAction(menuAjhvfn->menuAction());
        menuBar->addAction(menu_2->menuAction());
        menuFile->addAction(mnuCreate);
        menuFile->addAction(mnuOpen);
        menuFile->addAction(mnuSave);
        menuFile->addAction(mnuSaveAs);
        menuFile->addSeparator();
        menuFile->addAction(mnuPrint);
        menuFile->addSeparator();
        menuFile->addAction(mnuExit);
        menu->addAction(mnuUndo);
        menu->addAction(mnuRedo);
        menu->addSeparator();
        menu->addAction(mnuCut);
        menu->addAction(mnuCopy);
        menu->addAction(mnuPaste);
        menu->addAction(mnuDelete);
        menu->addSeparator();
        menu->addAction(mnuFind);
        menu->addAction(mnuFindNext);
        menu->addAction(mnuReplace);
        menu->addAction(mnuGoto);
        menu->addSeparator();
        menu->addAction(mnuSelectAll);
        menuAjhvfn->addAction(mnuWordWrap);
        menu_2->addAction(mnuHelp);
        menu_2->addSeparator();
        menu_2->addAction(mnuAbout);
        mainToolBar->addAction(mnuCreate);
        mainToolBar->addAction(mnuSave);
        mainToolBar->addSeparator();
        mainToolBar->addAction(mnuRecursionCheck);
        mainToolBar->addAction(mnuBuildMatrixSimple);
        mainToolBar->addSeparator();
        mainToolBar->addAction(mnuHelp);

        retranslateUi(MainWindow);
        QObject::connect(btnErrors, SIGNAL(toggled(bool)), MainWindow, SLOT(onRefreshMessagesList()));
        QObject::connect(btnWarnings, SIGNAL(toggled(bool)), MainWindow, SLOT(onRefreshMessagesList()));

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0, QApplication::UnicodeUTF8));
        mnuCreate->setText(QApplication::translate("MainWindow", "\320\235\320\276\320\262\320\260\321\217 \320\263\321\200\320\260\320\274\320\274\320\260\321\202\320\270\320\272\320\260", 0, QApplication::UnicodeUTF8));
        mnuCreate->setShortcut(QApplication::translate("MainWindow", "Ctrl+N", 0, QApplication::UnicodeUTF8));
        mnuOpen->setText(QApplication::translate("MainWindow", "\320\236\321\202\320\272\321\200\321\213\321\202\321\214...", 0, QApplication::UnicodeUTF8));
        mnuOpen->setShortcut(QApplication::translate("MainWindow", "Ctrl+O", 0, QApplication::UnicodeUTF8));
        mnuSave->setText(QApplication::translate("MainWindow", "\320\241\320\276\321\205\321\200\320\260\320\275\320\270\321\202\321\214", 0, QApplication::UnicodeUTF8));
        mnuSave->setShortcut(QApplication::translate("MainWindow", "Ctrl+S", 0, QApplication::UnicodeUTF8));
        mnuSaveAs->setText(QApplication::translate("MainWindow", "\320\241\320\276\321\205\321\200\320\260\320\275\320\270\321\202\321\214 \320\272\320\260\320\272...", 0, QApplication::UnicodeUTF8));
        mnuPrint->setText(QApplication::translate("MainWindow", "\320\237\320\265\321\207\320\260\321\202\321\214...", 0, QApplication::UnicodeUTF8));
        mnuPrint->setShortcut(QApplication::translate("MainWindow", "Ctrl+P", 0, QApplication::UnicodeUTF8));
        mnuExit->setText(QApplication::translate("MainWindow", "\320\222\321\213\321\205\320\276\320\264", 0, QApplication::UnicodeUTF8));
        mnuExit->setShortcut(QApplication::translate("MainWindow", "Ctrl+Q", 0, QApplication::UnicodeUTF8));
        mnuUndo->setText(QApplication::translate("MainWindow", "\320\236\321\202\320\274\320\265\320\275\320\270\321\202\321\214", 0, QApplication::UnicodeUTF8));
        mnuUndo->setShortcut(QApplication::translate("MainWindow", "Ctrl+Z", 0, QApplication::UnicodeUTF8));
        mnuRedo->setText(QApplication::translate("MainWindow", "\320\237\320\276\320\262\321\202\320\276\321\200\320\270\321\202\321\214", 0, QApplication::UnicodeUTF8));
        mnuRedo->setShortcut(QApplication::translate("MainWindow", "Ctrl+Y", 0, QApplication::UnicodeUTF8));
        mnuCut->setText(QApplication::translate("MainWindow", "\320\222\321\213\321\200\320\265\320\267\320\260\321\202\321\214", 0, QApplication::UnicodeUTF8));
        mnuCut->setShortcut(QApplication::translate("MainWindow", "Ctrl+X", 0, QApplication::UnicodeUTF8));
        mnuCopy->setText(QApplication::translate("MainWindow", "\320\232\320\276\320\277\320\270\321\200\320\276\320\262\320\260\321\202\321\214", 0, QApplication::UnicodeUTF8));
        mnuCopy->setShortcut(QApplication::translate("MainWindow", "Ctrl+C", 0, QApplication::UnicodeUTF8));
        mnuPaste->setText(QApplication::translate("MainWindow", "\320\222\321\201\321\202\320\260\320\262\320\270\321\202\321\214", 0, QApplication::UnicodeUTF8));
        mnuPaste->setShortcut(QApplication::translate("MainWindow", "Ctrl+V", 0, QApplication::UnicodeUTF8));
        mnuDelete->setText(QApplication::translate("MainWindow", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214", 0, QApplication::UnicodeUTF8));
        mnuDelete->setShortcut(QApplication::translate("MainWindow", "Del", 0, QApplication::UnicodeUTF8));
        mnuFind->setText(QApplication::translate("MainWindow", "\320\235\320\260\320\271\321\202\320\270...", 0, QApplication::UnicodeUTF8));
        mnuFind->setShortcut(QApplication::translate("MainWindow", "Ctrl+F", 0, QApplication::UnicodeUTF8));
        mnuFindNext->setText(QApplication::translate("MainWindow", "\320\235\320\260\320\271\321\202\320\270 \320\264\320\260\320\273\320\265\320\265", 0, QApplication::UnicodeUTF8));
        mnuFindNext->setShortcut(QApplication::translate("MainWindow", "F3", 0, QApplication::UnicodeUTF8));
        mnuReplace->setText(QApplication::translate("MainWindow", "\320\227\320\260\320\274\320\265\320\275\320\270\321\202\321\214...", 0, QApplication::UnicodeUTF8));
        mnuReplace->setShortcut(QApplication::translate("MainWindow", "Ctrl+R", 0, QApplication::UnicodeUTF8));
        mnuGoto->setText(QApplication::translate("MainWindow", "\320\237\320\265\321\200\320\265\320\271\321\202\320\270...", 0, QApplication::UnicodeUTF8));
        mnuGoto->setShortcut(QApplication::translate("MainWindow", "Ctrl+G", 0, QApplication::UnicodeUTF8));
        mnuSelectAll->setText(QApplication::translate("MainWindow", "\320\222\321\213\320\264\320\265\320\273\320\270\321\202\321\214 \320\262\321\201\320\265", 0, QApplication::UnicodeUTF8));
        mnuSelectAll->setShortcut(QApplication::translate("MainWindow", "Ctrl+A", 0, QApplication::UnicodeUTF8));
        mnuHelp->setText(QApplication::translate("MainWindow", "\320\237\321\200\320\276\321\201\320\274\320\276\321\202\321\200\320\265\321\202\321\214 \321\201\320\277\321\200\320\260\320\262\320\272\321\203", 0, QApplication::UnicodeUTF8));
        mnuHelp->setShortcut(QApplication::translate("MainWindow", "F1", 0, QApplication::UnicodeUTF8));
        mnuAbout->setText(QApplication::translate("MainWindow", "\320\236 \320\277\321\200\320\276\320\263\321\200\320\260\320\274\320\274\320\265", 0, QApplication::UnicodeUTF8));
        mnuWordWrap->setText(QApplication::translate("MainWindow", "\320\237\320\265\321\200\320\265\320\275\320\276\321\201 \320\277\320\276 \321\201\320\273\320\276\320\262\320\260\320\274", 0, QApplication::UnicodeUTF8));
        mnuOptions->setText(QApplication::translate("MainWindow", "\320\235\320\260\321\201\321\202\321\200\320\276\320\271\320\272\320\270...", 0, QApplication::UnicodeUTF8));
        mnuRecursionCheck->setText(QApplication::translate("MainWindow", "\320\237\321\200\320\276\320\262\320\265\321\200\320\272\320\260 \321\200\320\265\320\272\321\203\321\200\321\201\320\270\320\262\320\275\320\276\321\201\321\202\320\270 \320\277\321\200\320\260\320\262\320\270\320\273", 0, QApplication::UnicodeUTF8));
        mnuBuildMatrixSimple->setText(QApplication::translate("MainWindow", "\320\237\320\276\321\201\321\202\321\200\320\276\320\270\321\202\321\214 \320\274\320\260\321\202\321\200\320\270\321\206\321\203 \320\277\321\200\320\276\321\201\321\202\320\276\320\263\320\276 \320\277\321\200\320\265\320\264\321\210\320\265\321\201\321\202\320\262\320\276\320\262\320\260\320\275\320\270\321\217", 0, QApplication::UnicodeUTF8));
        btnErrors->setText(QApplication::translate("MainWindow", "\320\236\321\210\320\270\320\261\320\272\320\270", 0, QApplication::UnicodeUTF8));
        btnWarnings->setText(QApplication::translate("MainWindow", "\320\237\321\200\320\265\320\264\321\203\320\277\321\200\320\265\320\266\320\264\320\265\320\275\320\270\321\217", 0, QApplication::UnicodeUTF8));
        menuFile->setTitle(QApplication::translate("MainWindow", "\320\244\320\260\320\271\320\273", 0, QApplication::UnicodeUTF8));
        menu->setTitle(QApplication::translate("MainWindow", "\320\237\321\200\320\260\320\262\320\272\320\260", 0, QApplication::UnicodeUTF8));
        menuAjhvfn->setTitle(QApplication::translate("MainWindow", "\320\244\320\276\321\200\320\274\320\260\321\202", 0, QApplication::UnicodeUTF8));
        menu_2->setTitle(QApplication::translate("MainWindow", "\320\241\320\277\321\200\320\260\320\262\320\272\320\260", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
