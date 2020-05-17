/********************************************************************************
** Form generated from reading UI file 'addbook.ui'
**
** Created by: Qt User Interface Compiler version 5.12.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDBOOK_H
#define UI_ADDBOOK_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_addbook
{
public:
    QWidget *verticalLayoutWidget_3;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QTextEdit *user_input;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_2;
    QSpacerItem *verticalSpacer_2;
    QDateEdit *dateRelease;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout;
    QPushButton *ok;
    QPushButton *cancel;

    void setupUi(QDialog *addbook)
    {
        if (addbook->objectName().isEmpty())
            addbook->setObjectName(QString::fromUtf8("addbook"));
        addbook->resize(605, 167);
        addbook->setMinimumSize(QSize(605, 167));
        addbook->setMaximumSize(QSize(605, 167));
        verticalLayoutWidget_3 = new QWidget(addbook);
        verticalLayoutWidget_3->setObjectName(QString::fromUtf8("verticalLayoutWidget_3"));
        verticalLayoutWidget_3->setGeometry(QRect(10, 10, 591, 151));
        verticalLayout_3 = new QVBoxLayout(verticalLayoutWidget_3);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label = new QLabel(verticalLayoutWidget_3);
        label->setObjectName(QString::fromUtf8("label"));
        QFont font;
        font.setPointSize(18);
        font.setBold(true);
        font.setWeight(75);
        label->setFont(font);
        label->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label);

        user_input = new QTextEdit(verticalLayoutWidget_3);
        user_input->setObjectName(QString::fromUtf8("user_input"));
        QFont font1;
        font1.setPointSize(20);
        user_input->setFont(font1);

        verticalLayout->addWidget(user_input);


        horizontalLayout_2->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        label_2 = new QLabel(verticalLayoutWidget_3);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Maximum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy);
        QFont font2;
        font2.setPointSize(18);
        label_2->setFont(font2);
        label_2->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);

        verticalLayout_2->addWidget(label_2);

        verticalSpacer_2 = new QSpacerItem(20, 7, QSizePolicy::Minimum, QSizePolicy::Maximum);

        verticalLayout_2->addItem(verticalSpacer_2);

        dateRelease = new QDateEdit(verticalLayoutWidget_3);
        dateRelease->setObjectName(QString::fromUtf8("dateRelease"));
        dateRelease->setMinimumSize(QSize(0, 50));
        QFont font3;
        font3.setPointSize(15);
        dateRelease->setFont(font3);

        verticalLayout_2->addWidget(dateRelease);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer);


        horizontalLayout_2->addLayout(verticalLayout_2);


        verticalLayout_3->addLayout(horizontalLayout_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        ok = new QPushButton(verticalLayoutWidget_3);
        ok->setObjectName(QString::fromUtf8("ok"));
        QFont font4;
        font4.setPointSize(14);
        font4.setBold(true);
        font4.setItalic(false);
        font4.setWeight(75);
        ok->setFont(font4);

        horizontalLayout->addWidget(ok);

        cancel = new QPushButton(verticalLayoutWidget_3);
        cancel->setObjectName(QString::fromUtf8("cancel"));
        QFont font5;
        font5.setPointSize(14);
        font5.setBold(true);
        font5.setWeight(75);
        cancel->setFont(font5);

        horizontalLayout->addWidget(cancel);


        verticalLayout_3->addLayout(horizontalLayout);


        retranslateUi(addbook);

        QMetaObject::connectSlotsByName(addbook);
    } // setupUi

    void retranslateUi(QDialog *addbook)
    {
        addbook->setWindowTitle(QApplication::translate("addbook", "Dialog", nullptr));
        label->setText(QApplication::translate("addbook", "Book name", nullptr));
        user_input->setDocumentTitle(QString());
        user_input->setHtml(QApplication::translate("addbook", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:20pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'MS Shell Dlg 2';\">Default name</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'MS Shell Dlg 2';\"><br /></p></body></html>", nullptr));
        user_input->setPlaceholderText(QString());
        label_2->setText(QApplication::translate("addbook", "Date of the release", nullptr));
        ok->setText(QApplication::translate("addbook", "OK", nullptr));
        cancel->setText(QApplication::translate("addbook", "Cancel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class addbook: public Ui_addbook {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDBOOK_H
