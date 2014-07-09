/********************************************************************************
** Form generated from reading UI file 'searchdialog.ui'
**
** Created: Mon 9. Sep 19:18:10 2013
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SEARCHDIALOG_H
#define UI_SEARCHDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QDialog>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SearchDialog
{
public:
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayoutMain;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *txtSearch;
    QCheckBox *checkBox;
    QVBoxLayout *verticalLayout_2;
    QPushButton *btnSearch;
    QPushButton *pushButton;
    QSpacerItem *verticalSpacer;

    void setupUi(QDialog *SearchDialog)
    {
        if (SearchDialog->objectName().isEmpty())
            SearchDialog->setObjectName(QString::fromUtf8("SearchDialog"));
        SearchDialog->resize(324, 125);
        layoutWidget = new QWidget(SearchDialog);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(20, 30, 251, 62));
        horizontalLayoutMain = new QHBoxLayout(layoutWidget);
        horizontalLayoutMain->setObjectName(QString::fromUtf8("horizontalLayoutMain"));
        horizontalLayoutMain->setContentsMargins(0, 0, 0, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(layoutWidget);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        txtSearch = new QLineEdit(layoutWidget);
        txtSearch->setObjectName(QString::fromUtf8("txtSearch"));

        horizontalLayout->addWidget(txtSearch);


        verticalLayout->addLayout(horizontalLayout);

        checkBox = new QCheckBox(layoutWidget);
        checkBox->setObjectName(QString::fromUtf8("checkBox"));

        verticalLayout->addWidget(checkBox);


        horizontalLayoutMain->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        btnSearch = new QPushButton(layoutWidget);
        btnSearch->setObjectName(QString::fromUtf8("btnSearch"));
        btnSearch->setDefault(true);

        verticalLayout_2->addWidget(btnSearch);

        pushButton = new QPushButton(layoutWidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        verticalLayout_2->addWidget(pushButton);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer);


        horizontalLayoutMain->addLayout(verticalLayout_2);

#ifndef QT_NO_SHORTCUT
        label->setBuddy(txtSearch);
#endif // QT_NO_SHORTCUT
        QWidget::setTabOrder(txtSearch, checkBox);
        QWidget::setTabOrder(checkBox, btnSearch);

        retranslateUi(SearchDialog);
        QObject::connect(pushButton, SIGNAL(clicked()), SearchDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(SearchDialog);
    } // setupUi

    void retranslateUi(QDialog *SearchDialog)
    {
        SearchDialog->setWindowTitle(QApplication::translate("SearchDialog", "Dialog", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("SearchDialog", "\320\247\321\202&\320\276:", 0, QApplication::UnicodeUTF8));
        checkBox->setText(QApplication::translate("SearchDialog", "\320\241 \321\203&\321\207\320\265\321\202\320\276\320\274 \321\200\320\265\320\263\320\270\321\201\321\202\321\200\320\260", 0, QApplication::UnicodeUTF8));
        btnSearch->setText(QApplication::translate("SearchDialog", "&\320\235\320\260\320\271\321\202\320\270 \320\264\320\260\320\273\320\265\320\265", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("SearchDialog", "\320\236\321\202\320\274\320\265\320\275\320\260", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class SearchDialog: public Ui_SearchDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SEARCHDIALOG_H
