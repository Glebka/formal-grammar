/********************************************************************************
** Form generated from reading UI file 'gotodialog.ui'
**
** Created: Mon 9. Sep 19:18:10 2013
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GOTODIALOG_H
#define UI_GOTODIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QSpacerItem>
#include <QtGui/QSpinBox>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GotoDialog
{
public:
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QSpinBox *line;
    QSpacerItem *verticalSpacer;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *GotoDialog)
    {
        if (GotoDialog->objectName().isEmpty())
            GotoDialog->setObjectName(QString::fromUtf8("GotoDialog"));
        GotoDialog->resize(239, 188);
        layoutWidget = new QWidget(GotoDialog);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(20, 20, 182, 54));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label = new QLabel(layoutWidget);
        label->setObjectName(QString::fromUtf8("label"));

        verticalLayout->addWidget(label);

        line = new QSpinBox(layoutWidget);
        line->setObjectName(QString::fromUtf8("line"));
        line->setMinimum(1);

        verticalLayout->addWidget(line);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);


        horizontalLayout->addLayout(verticalLayout);

        buttonBox = new QDialogButtonBox(layoutWidget);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Vertical);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        horizontalLayout->addWidget(buttonBox);

        QWidget::setTabOrder(line, buttonBox);

        retranslateUi(GotoDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), GotoDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), GotoDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(GotoDialog);
    } // setupUi

    void retranslateUi(QDialog *GotoDialog)
    {
        GotoDialog->setWindowTitle(QApplication::translate("GotoDialog", "Dialog", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("GotoDialog", "\320\241\321\202\321\200\320\276\320\272\320\260:", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class GotoDialog: public Ui_GotoDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GOTODIALOG_H
