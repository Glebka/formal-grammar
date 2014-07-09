/********************************************************************************
** Form generated from reading UI file 'matrixviewform.ui'
**
** Created: Mon 9. Sep 19:18:10 2013
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MATRIXVIEWFORM_H
#define UI_MATRIXVIEWFORM_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QFormLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QSpacerItem>
#include <QtGui/QSplitter>
#include <QtGui/QTableView>
#include <QtGui/QToolBar>
#include <QtGui/QTreeWidget>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MatrixViewForm
{
public:
    QAction *actionSaveAs;
    QAction *actionPrint;
    QAction *actionHelp;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QToolBar *mainToolBar;
    QHBoxLayout *horizontalLayout;
    QFormLayout *formLayout;
    QLabel *label;
    QComboBox *comboA;
    QLabel *relation;
    QFormLayout *formLayout_2;
    QLabel *label_2;
    QComboBox *comboB;
    QSpacerItem *horizontalSpacer;
    QSplitter *splitter;
    QTableView *matrixView;
    QWidget *layoutWidget1;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_3;
    QTreeWidget *listMessages;

    void setupUi(QWidget *MatrixViewForm)
    {
        if (MatrixViewForm->objectName().isEmpty())
            MatrixViewForm->setObjectName(QString::fromUtf8("MatrixViewForm"));
        MatrixViewForm->setWindowModality(Qt::WindowModal);
        MatrixViewForm->resize(672, 421);
        actionSaveAs = new QAction(MatrixViewForm);
        actionSaveAs->setObjectName(QString::fromUtf8("actionSaveAs"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icons/icons/save.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionSaveAs->setIcon(icon);
        actionPrint = new QAction(MatrixViewForm);
        actionPrint->setObjectName(QString::fromUtf8("actionPrint"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/icons/icons/print.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionPrint->setIcon(icon1);
        actionHelp = new QAction(MatrixViewForm);
        actionHelp->setObjectName(QString::fromUtf8("actionHelp"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/icons/icons/help.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionHelp->setIcon(icon2);
        layoutWidget = new QWidget(MatrixViewForm);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(50, 10, 375, 244));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        mainToolBar = new QToolBar(layoutWidget);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        mainToolBar->setAutoFillBackground(true);

        verticalLayout->addWidget(mainToolBar);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(2, -1, -1, -1);
        formLayout = new QFormLayout();
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        label = new QLabel(layoutWidget);
        label->setObjectName(QString::fromUtf8("label"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        comboA = new QComboBox(layoutWidget);
        comboA->setObjectName(QString::fromUtf8("comboA"));

        formLayout->setWidget(0, QFormLayout::FieldRole, comboA);


        horizontalLayout->addLayout(formLayout);

        relation = new QLabel(layoutWidget);
        relation->setObjectName(QString::fromUtf8("relation"));
        relation->setStyleSheet(QString::fromUtf8("border-style:solid;\n"
"border-color:black;\n"
"border-width:1px;"));

        horizontalLayout->addWidget(relation);

        formLayout_2 = new QFormLayout();
        formLayout_2->setObjectName(QString::fromUtf8("formLayout_2"));
        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        formLayout_2->setWidget(0, QFormLayout::LabelRole, label_2);

        comboB = new QComboBox(layoutWidget);
        comboB->setObjectName(QString::fromUtf8("comboB"));

        formLayout_2->setWidget(0, QFormLayout::FieldRole, comboB);


        horizontalLayout->addLayout(formLayout_2);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        verticalLayout->addLayout(horizontalLayout);

        splitter = new QSplitter(layoutWidget);
        splitter->setObjectName(QString::fromUtf8("splitter"));
        splitter->setOrientation(Qt::Vertical);
        matrixView = new QTableView(splitter);
        matrixView->setObjectName(QString::fromUtf8("matrixView"));
        splitter->addWidget(matrixView);
        layoutWidget1 = new QWidget(splitter);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        verticalLayout_2 = new QVBoxLayout(layoutWidget1);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        label_3 = new QLabel(layoutWidget1);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setMargin(2);

        verticalLayout_2->addWidget(label_3);

        listMessages = new QTreeWidget(layoutWidget1);
        QTreeWidgetItem *__qtreewidgetitem = new QTreeWidgetItem();
        __qtreewidgetitem->setText(0, QString::fromUtf8("1"));
        listMessages->setHeaderItem(__qtreewidgetitem);
        listMessages->setObjectName(QString::fromUtf8("listMessages"));

        verticalLayout_2->addWidget(listMessages);

        splitter->addWidget(layoutWidget1);

        verticalLayout->addWidget(splitter);


        mainToolBar->addAction(actionSaveAs);
        mainToolBar->addAction(actionPrint);
        mainToolBar->addSeparator();
        mainToolBar->addAction(actionHelp);

        retranslateUi(MatrixViewForm);

        QMetaObject::connectSlotsByName(MatrixViewForm);
    } // setupUi

    void retranslateUi(QWidget *MatrixViewForm)
    {
        MatrixViewForm->setWindowTitle(QApplication::translate("MatrixViewForm", "Form", 0, QApplication::UnicodeUTF8));
        actionSaveAs->setText(QApplication::translate("MatrixViewForm", "\320\241\320\276\321\205\321\200\320\260\320\275\320\270\321\202\321\214 \320\272\320\260\320\272...", 0, QApplication::UnicodeUTF8));
        actionSaveAs->setShortcut(QApplication::translate("MatrixViewForm", "Ctrl+S", 0, QApplication::UnicodeUTF8));
        actionPrint->setText(QApplication::translate("MatrixViewForm", "\320\237\320\265\321\207\320\260\321\202\321\214...", 0, QApplication::UnicodeUTF8));
        actionHelp->setText(QApplication::translate("MatrixViewForm", "\320\241\320\277\321\200\320\260\320\262\320\272\320\260", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("MatrixViewForm", "\320\241\320\270\320\274\320\262\320\276\320\273 \320\220:", 0, QApplication::UnicodeUTF8));
        relation->setText(QApplication::translate("MatrixViewForm", "\320\236\321\202\320\275\320\276\321\210\320\265\320\275\320\270\320\265", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("MatrixViewForm", "\320\241\320\270\320\274\320\262\320\276\320\273 \320\221:", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("MatrixViewForm", "\320\232\320\276\320\275\321\204\320\273\320\270\320\272\321\202\321\213", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MatrixViewForm: public Ui_MatrixViewForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MATRIXVIEWFORM_H
