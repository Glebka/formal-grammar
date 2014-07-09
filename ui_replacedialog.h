/********************************************************************************
** Form generated from reading UI file 'replacedialog.ui'
**
** Created: Mon 9. Sep 19:18:10 2013
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REPLACEDIALOG_H
#define UI_REPLACEDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QDialog>
#include <QtGui/QFormLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ReplaceDialog
{
public:
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QFormLayout *formLayout;
    QLabel *label;
    QLineEdit *txtWhat;
    QLabel *label_2;
    QLineEdit *txtReplace;
    QCheckBox *checkBox;
    QSpacerItem *verticalSpacer;
    QVBoxLayout *verticalLayout_3;
    QVBoxLayout *verticalLayout_2;
    QPushButton *btnFindNext;
    QPushButton *btnReplace;
    QPushButton *btnReplaceAll;
    QPushButton *btnCancel;
    QSpacerItem *verticalSpacer_2;

    void setupUi(QDialog *ReplaceDialog)
    {
        if (ReplaceDialog->objectName().isEmpty())
            ReplaceDialog->setObjectName(QString::fromUtf8("ReplaceDialog"));
        ReplaceDialog->resize(400, 191);
        layoutWidget = new QWidget(ReplaceDialog);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(20, 10, 254, 167));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        formLayout = new QFormLayout();
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        label = new QLabel(layoutWidget);
        label->setObjectName(QString::fromUtf8("label"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        txtWhat = new QLineEdit(layoutWidget);
        txtWhat->setObjectName(QString::fromUtf8("txtWhat"));

        formLayout->setWidget(0, QFormLayout::FieldRole, txtWhat);

        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_2);

        txtReplace = new QLineEdit(layoutWidget);
        txtReplace->setObjectName(QString::fromUtf8("txtReplace"));

        formLayout->setWidget(1, QFormLayout::FieldRole, txtReplace);


        verticalLayout->addLayout(formLayout);

        checkBox = new QCheckBox(layoutWidget);
        checkBox->setObjectName(QString::fromUtf8("checkBox"));

        verticalLayout->addWidget(checkBox);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);


        horizontalLayout->addLayout(verticalLayout);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        btnFindNext = new QPushButton(layoutWidget);
        btnFindNext->setObjectName(QString::fromUtf8("btnFindNext"));
        btnFindNext->setDefault(true);

        verticalLayout_2->addWidget(btnFindNext);

        btnReplace = new QPushButton(layoutWidget);
        btnReplace->setObjectName(QString::fromUtf8("btnReplace"));

        verticalLayout_2->addWidget(btnReplace);

        btnReplaceAll = new QPushButton(layoutWidget);
        btnReplaceAll->setObjectName(QString::fromUtf8("btnReplaceAll"));

        verticalLayout_2->addWidget(btnReplaceAll);

        btnCancel = new QPushButton(layoutWidget);
        btnCancel->setObjectName(QString::fromUtf8("btnCancel"));

        verticalLayout_2->addWidget(btnCancel);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_2);


        verticalLayout_3->addLayout(verticalLayout_2);


        horizontalLayout->addLayout(verticalLayout_3);

#ifndef QT_NO_SHORTCUT
        label->setBuddy(txtWhat);
        label_2->setBuddy(txtReplace);
#endif // QT_NO_SHORTCUT
        QWidget::setTabOrder(txtWhat, txtReplace);
        QWidget::setTabOrder(txtReplace, checkBox);
        QWidget::setTabOrder(checkBox, btnFindNext);
        QWidget::setTabOrder(btnFindNext, btnReplace);
        QWidget::setTabOrder(btnReplace, btnReplaceAll);
        QWidget::setTabOrder(btnReplaceAll, btnCancel);

        retranslateUi(ReplaceDialog);
        QObject::connect(btnCancel, SIGNAL(clicked()), ReplaceDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(ReplaceDialog);
    } // setupUi

    void retranslateUi(QDialog *ReplaceDialog)
    {
        ReplaceDialog->setWindowTitle(QApplication::translate("ReplaceDialog", "Dialog", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("ReplaceDialog", "\320\247\321\202&\320\276:", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("ReplaceDialog", "\320\247&\320\265\320\274:", 0, QApplication::UnicodeUTF8));
        checkBox->setText(QApplication::translate("ReplaceDialog", "\320\241 \321\203\321\207\320\265\321\202\320\276\320\274 \321\200\320\265&\320\263\320\270\321\201\321\202\321\200\320\260", 0, QApplication::UnicodeUTF8));
        btnFindNext->setText(QApplication::translate("ReplaceDialog", "&\320\235\320\260\320\271\321\202\320\270 \320\264\320\260\320\273\320\265\320\265", 0, QApplication::UnicodeUTF8));
        btnReplace->setText(QApplication::translate("ReplaceDialog", "&\320\227\320\260\320\274\320\265\320\275\320\270\321\202\321\214", 0, QApplication::UnicodeUTF8));
        btnReplaceAll->setText(QApplication::translate("ReplaceDialog", "\320\227\320\260\320\274\320\265\320\275\320\270\321\202\321\214 &\320\262\321\201\320\265", 0, QApplication::UnicodeUTF8));
        btnCancel->setText(QApplication::translate("ReplaceDialog", "\320\236\321\202\320\274\320\265\320\275\320\260", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class ReplaceDialog: public Ui_ReplaceDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REPLACEDIALOG_H
