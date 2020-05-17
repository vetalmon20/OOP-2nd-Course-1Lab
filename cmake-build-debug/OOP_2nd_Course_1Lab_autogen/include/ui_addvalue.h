/********************************************************************************
** Form generated from reading UI file 'addvalue.ui'
**
** Created by: Qt User Interface Compiler version 5.12.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDVALUE_H
#define UI_ADDVALUE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_addvalue
{
public:
    QTextEdit *user_input;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *ok;
    QPushButton *cancel;

    void setupUi(QDialog *addvalue)
    {
        if (addvalue->objectName().isEmpty())
            addvalue->setObjectName(QString::fromUtf8("addvalue"));
        addvalue->resize(647, 142);
        addvalue->setMinimumSize(QSize(647, 142));
        addvalue->setMaximumSize(QSize(647, 16777215));
        user_input = new QTextEdit(addvalue);
        user_input->setObjectName(QString::fromUtf8("user_input"));
        user_input->setGeometry(QRect(20, 40, 601, 41));
        horizontalLayoutWidget = new QWidget(addvalue);
        horizontalLayoutWidget->setObjectName(QString::fromUtf8("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(140, 90, 371, 41));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        ok = new QPushButton(horizontalLayoutWidget);
        ok->setObjectName(QString::fromUtf8("ok"));
        QFont font;
        font.setPointSize(13);
        font.setBold(true);
        font.setWeight(75);
        ok->setFont(font);

        horizontalLayout->addWidget(ok);

        cancel = new QPushButton(horizontalLayoutWidget);
        cancel->setObjectName(QString::fromUtf8("cancel"));
        cancel->setFont(font);

        horizontalLayout->addWidget(cancel);


        retranslateUi(addvalue);

        QMetaObject::connectSlotsByName(addvalue);
    } // setupUi

    void retranslateUi(QDialog *addvalue)
    {
        addvalue->setWindowTitle(QApplication::translate("addvalue", "Dialog", nullptr));
        user_input->setHtml(QApplication::translate("addvalue", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'MS Shell Dlg 2';\"><br /></p></body></html>", nullptr));
        ok->setText(QApplication::translate("addvalue", "OK", nullptr));
        cancel->setText(QApplication::translate("addvalue", "Cancel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class addvalue: public Ui_addvalue {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDVALUE_H
