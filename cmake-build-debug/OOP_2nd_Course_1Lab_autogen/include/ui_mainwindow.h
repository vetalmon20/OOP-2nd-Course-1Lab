/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_mainwindow
{
public:
    QWidget *verticalLayoutWidget_3;
    QVBoxLayout *verticalLayout_4;
    QLabel *label;
    QSpacerItem *verticalSpacer;
    QPushButton *generateList;
    QSpacerItem *verticalSpacer_4;
    QHBoxLayout *horizontalLayout_6;
    QGroupBox *verticalGroupBox_5;
    QVBoxLayout *verticalLayout_8;
    QRadioButton *linkedCase;
    QRadioButton *arrayCase;
    QRadioButton *vectorCase;
    QGroupBox *verticalGroupBox_4;
    QVBoxLayout *verticalLayout_7;
    QRadioButton *intCase;
    QRadioButton *floatCase;
    QRadioButton *charCase;
    QRadioButton *stringCase;
    QPushButton *addList;
    QPushButton *deleteList;
    QPushButton *sortList;
    QSpacerItem *verticalSpacer_2;
    QPushButton *deleteEntireList;
    QSpacerItem *verticalSpacer_3;
    QLabel *label2;
    QPushButton *generateLiterature;
    QGroupBox *verticalGroupBox_41;
    QVBoxLayout *verticalLayout;
    QRadioButton *linkedLiteratureCase;
    QRadioButton *arrayLiteratureCase;
    QRadioButton *vectorLiteratureCase;
    QSpacerItem *verticalSpacer_5;
    QPushButton *addBook;
    QPushButton *deleteBook;
    QPushButton *sortBook;
    QPushButton *findSeries;
    QSpacerItem *verticalSpacer_6;
    QPushButton *deleteEntireLiterature;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout_5;
    QLabel *labelLiteratureData;
    QListWidget *literatureList;
    QHBoxLayout *horizontalLayout_3;
    QWidget *verticalLayoutWidget_2;
    QVBoxLayout *verticalLayout_6;
    QLabel *labelListData;
    QListWidget *listList;
    QHBoxLayout *horizontalLayout_4;

    void setupUi(QDialog *mainwindow)
    {
        if (mainwindow->objectName().isEmpty())
            mainwindow->setObjectName(QString::fromUtf8("mainwindow"));
        mainwindow->resize(1115, 817);
        mainwindow->setMinimumSize(QSize(1115, 817));
        mainwindow->setMaximumSize(QSize(1115, 817));
        verticalLayoutWidget_3 = new QWidget(mainwindow);
        verticalLayoutWidget_3->setObjectName(QString::fromUtf8("verticalLayoutWidget_3"));
        verticalLayoutWidget_3->setGeometry(QRect(411, 10, 291, 803));
        verticalLayout_4 = new QVBoxLayout(verticalLayoutWidget_3);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(verticalLayoutWidget_3);
        label->setObjectName(QString::fromUtf8("label"));
        label->setEnabled(true);
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Maximum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);
        QFont font;
        font.setPointSize(10);
        font.setBold(true);
        font.setWeight(75);
        label->setFont(font);
        label->setTextFormat(Qt::PlainText);
        label->setAlignment(Qt::AlignCenter);

        verticalLayout_4->addWidget(label);

        verticalSpacer = new QSpacerItem(20, 15, QSizePolicy::Minimum, QSizePolicy::Maximum);

        verticalLayout_4->addItem(verticalSpacer);

        generateList = new QPushButton(verticalLayoutWidget_3);
        generateList->setObjectName(QString::fromUtf8("generateList"));
        QFont font1;
        font1.setPointSize(17);
        generateList->setFont(font1);

        verticalLayout_4->addWidget(generateList);

        verticalSpacer_4 = new QSpacerItem(20, 5, QSizePolicy::Minimum, QSizePolicy::Maximum);

        verticalLayout_4->addItem(verticalSpacer_4);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        verticalGroupBox_5 = new QGroupBox(verticalLayoutWidget_3);
        verticalGroupBox_5->setObjectName(QString::fromUtf8("verticalGroupBox_5"));
        verticalLayout_8 = new QVBoxLayout(verticalGroupBox_5);
        verticalLayout_8->setObjectName(QString::fromUtf8("verticalLayout_8"));
        linkedCase = new QRadioButton(verticalGroupBox_5);
        linkedCase->setObjectName(QString::fromUtf8("linkedCase"));
        QFont font2;
        font2.setPointSize(12);
        linkedCase->setFont(font2);
        linkedCase->setChecked(true);

        verticalLayout_8->addWidget(linkedCase);

        arrayCase = new QRadioButton(verticalGroupBox_5);
        arrayCase->setObjectName(QString::fromUtf8("arrayCase"));
        arrayCase->setFont(font2);

        verticalLayout_8->addWidget(arrayCase);

        vectorCase = new QRadioButton(verticalGroupBox_5);
        vectorCase->setObjectName(QString::fromUtf8("vectorCase"));
        vectorCase->setFont(font2);

        verticalLayout_8->addWidget(vectorCase);


        horizontalLayout_6->addWidget(verticalGroupBox_5);

        verticalGroupBox_4 = new QGroupBox(verticalLayoutWidget_3);
        verticalGroupBox_4->setObjectName(QString::fromUtf8("verticalGroupBox_4"));
        verticalLayout_7 = new QVBoxLayout(verticalGroupBox_4);
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        intCase = new QRadioButton(verticalGroupBox_4);
        intCase->setObjectName(QString::fromUtf8("intCase"));
        QFont font3;
        font3.setPointSize(11);
        intCase->setFont(font3);
        intCase->setChecked(true);
        intCase->setAutoExclusive(true);

        verticalLayout_7->addWidget(intCase);

        floatCase = new QRadioButton(verticalGroupBox_4);
        floatCase->setObjectName(QString::fromUtf8("floatCase"));
        floatCase->setFont(font3);
        floatCase->setAutoExclusive(true);

        verticalLayout_7->addWidget(floatCase);

        charCase = new QRadioButton(verticalGroupBox_4);
        charCase->setObjectName(QString::fromUtf8("charCase"));
        charCase->setFont(font3);
        charCase->setAutoExclusive(true);

        verticalLayout_7->addWidget(charCase);

        stringCase = new QRadioButton(verticalGroupBox_4);
        stringCase->setObjectName(QString::fromUtf8("stringCase"));
        stringCase->setFont(font3);
        stringCase->setAutoExclusive(true);

        verticalLayout_7->addWidget(stringCase);


        horizontalLayout_6->addWidget(verticalGroupBox_4);


        verticalLayout_4->addLayout(horizontalLayout_6);

        addList = new QPushButton(verticalLayoutWidget_3);
        addList->setObjectName(QString::fromUtf8("addList"));
        addList->setFont(font1);

        verticalLayout_4->addWidget(addList);

        deleteList = new QPushButton(verticalLayoutWidget_3);
        deleteList->setObjectName(QString::fromUtf8("deleteList"));
        deleteList->setFont(font1);

        verticalLayout_4->addWidget(deleteList);

        sortList = new QPushButton(verticalLayoutWidget_3);
        sortList->setObjectName(QString::fromUtf8("sortList"));
        sortList->setFont(font1);

        verticalLayout_4->addWidget(sortList);

        verticalSpacer_2 = new QSpacerItem(20, 8, QSizePolicy::Minimum, QSizePolicy::Maximum);

        verticalLayout_4->addItem(verticalSpacer_2);

        deleteEntireList = new QPushButton(verticalLayoutWidget_3);
        deleteEntireList->setObjectName(QString::fromUtf8("deleteEntireList"));
        deleteEntireList->setFont(font1);

        verticalLayout_4->addWidget(deleteEntireList);

        verticalSpacer_3 = new QSpacerItem(20, 51, QSizePolicy::Minimum, QSizePolicy::Maximum);

        verticalLayout_4->addItem(verticalSpacer_3);

        label2 = new QLabel(verticalLayoutWidget_3);
        label2->setObjectName(QString::fromUtf8("label2"));
        QSizePolicy sizePolicy1(QSizePolicy::Maximum, QSizePolicy::Minimum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label2->sizePolicy().hasHeightForWidth());
        label2->setSizePolicy(sizePolicy1);
        label2->setFont(font);
        label2->setFrameShape(QFrame::NoFrame);
        label2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        verticalLayout_4->addWidget(label2);

        generateLiterature = new QPushButton(verticalLayoutWidget_3);
        generateLiterature->setObjectName(QString::fromUtf8("generateLiterature"));
        QFont font4;
        font4.setPointSize(16);
        generateLiterature->setFont(font4);

        verticalLayout_4->addWidget(generateLiterature);

        verticalGroupBox_41 = new QGroupBox(verticalLayoutWidget_3);
        verticalGroupBox_41->setObjectName(QString::fromUtf8("verticalGroupBox_41"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(verticalGroupBox_41->sizePolicy().hasHeightForWidth());
        verticalGroupBox_41->setSizePolicy(sizePolicy2);
        verticalLayout = new QVBoxLayout(verticalGroupBox_41);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        linkedLiteratureCase = new QRadioButton(verticalGroupBox_41);
        linkedLiteratureCase->setObjectName(QString::fromUtf8("linkedLiteratureCase"));
        QFont font5;
        font5.setPointSize(10);
        linkedLiteratureCase->setFont(font5);
        linkedLiteratureCase->setChecked(true);

        verticalLayout->addWidget(linkedLiteratureCase);

        arrayLiteratureCase = new QRadioButton(verticalGroupBox_41);
        arrayLiteratureCase->setObjectName(QString::fromUtf8("arrayLiteratureCase"));
        arrayLiteratureCase->setFont(font5);

        verticalLayout->addWidget(arrayLiteratureCase);

        vectorLiteratureCase = new QRadioButton(verticalGroupBox_41);
        vectorLiteratureCase->setObjectName(QString::fromUtf8("vectorLiteratureCase"));
        vectorLiteratureCase->setFont(font5);

        verticalLayout->addWidget(vectorLiteratureCase);


        verticalLayout_4->addWidget(verticalGroupBox_41);

        verticalSpacer_5 = new QSpacerItem(20, 5, QSizePolicy::Minimum, QSizePolicy::Maximum);

        verticalLayout_4->addItem(verticalSpacer_5);

        addBook = new QPushButton(verticalLayoutWidget_3);
        addBook->setObjectName(QString::fromUtf8("addBook"));
        QFont font6;
        font6.setPointSize(15);
        addBook->setFont(font6);

        verticalLayout_4->addWidget(addBook);

        deleteBook = new QPushButton(verticalLayoutWidget_3);
        deleteBook->setObjectName(QString::fromUtf8("deleteBook"));
        deleteBook->setFont(font6);

        verticalLayout_4->addWidget(deleteBook);

        sortBook = new QPushButton(verticalLayoutWidget_3);
        sortBook->setObjectName(QString::fromUtf8("sortBook"));
        sortBook->setFont(font6);

        verticalLayout_4->addWidget(sortBook);

        findSeries = new QPushButton(verticalLayoutWidget_3);
        findSeries->setObjectName(QString::fromUtf8("findSeries"));
        findSeries->setFont(font6);

        verticalLayout_4->addWidget(findSeries);

        verticalSpacer_6 = new QSpacerItem(20, 12, QSizePolicy::Minimum, QSizePolicy::Maximum);

        verticalLayout_4->addItem(verticalSpacer_6);

        deleteEntireLiterature = new QPushButton(verticalLayoutWidget_3);
        deleteEntireLiterature->setObjectName(QString::fromUtf8("deleteEntireLiterature"));
        deleteEntireLiterature->setFont(font6);

        verticalLayout_4->addWidget(deleteEntireLiterature);

        verticalLayoutWidget = new QWidget(mainwindow);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(700, 10, 401, 801));
        verticalLayout_5 = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        verticalLayout_5->setContentsMargins(0, 0, 0, 0);
        labelLiteratureData = new QLabel(verticalLayoutWidget);
        labelLiteratureData->setObjectName(QString::fromUtf8("labelLiteratureData"));
        QFont font7;
        font7.setPointSize(20);
        labelLiteratureData->setFont(font7);
        labelLiteratureData->setAlignment(Qt::AlignCenter);

        verticalLayout_5->addWidget(labelLiteratureData);

        literatureList = new QListWidget(verticalLayoutWidget);
        literatureList->setObjectName(QString::fromUtf8("literatureList"));
        literatureList->setFont(font7);

        verticalLayout_5->addWidget(literatureList);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));

        verticalLayout_5->addLayout(horizontalLayout_3);

        verticalLayoutWidget_2 = new QWidget(mainwindow);
        verticalLayoutWidget_2->setObjectName(QString::fromUtf8("verticalLayoutWidget_2"));
        verticalLayoutWidget_2->setGeometry(QRect(10, 10, 401, 801));
        verticalLayout_6 = new QVBoxLayout(verticalLayoutWidget_2);
        verticalLayout_6->setSpacing(6);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        verticalLayout_6->setContentsMargins(0, 0, 0, 0);
        labelListData = new QLabel(verticalLayoutWidget_2);
        labelListData->setObjectName(QString::fromUtf8("labelListData"));
        labelListData->setFont(font7);
        labelListData->setAutoFillBackground(false);
        labelListData->setFrameShape(QFrame::NoFrame);
        labelListData->setFrameShadow(QFrame::Plain);
        labelListData->setTextFormat(Qt::AutoText);
        labelListData->setScaledContents(false);
        labelListData->setAlignment(Qt::AlignCenter);

        verticalLayout_6->addWidget(labelListData);

        listList = new QListWidget(verticalLayoutWidget_2);
        listList->setObjectName(QString::fromUtf8("listList"));
        listList->setFont(font7);

        verticalLayout_6->addWidget(listList);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));

        verticalLayout_6->addLayout(horizontalLayout_4);


        retranslateUi(mainwindow);

        QMetaObject::connectSlotsByName(mainwindow);
    } // setupUi

    void retranslateUi(QDialog *mainwindow)
    {
        mainwindow->setWindowTitle(QApplication::translate("mainwindow", "Dialog", nullptr));
        label->setText(QApplication::translate("mainwindow", "Work with the List structure", nullptr));
        generateList->setText(QApplication::translate("mainwindow", "Generate the List", nullptr));
        linkedCase->setText(QApplication::translate("mainwindow", "Linked List", nullptr));
        arrayCase->setText(QApplication::translate("mainwindow", "Array List", nullptr));
        vectorCase->setText(QApplication::translate("mainwindow", "Vector List", nullptr));
        intCase->setText(QApplication::translate("mainwindow", "int", nullptr));
        floatCase->setText(QApplication::translate("mainwindow", "float", nullptr));
        charCase->setText(QApplication::translate("mainwindow", "char", nullptr));
        stringCase->setText(QApplication::translate("mainwindow", "string", nullptr));
        addList->setText(QApplication::translate("mainwindow", "Add node", nullptr));
        deleteList->setText(QApplication::translate("mainwindow", "Delete the last node", nullptr));
        sortList->setText(QApplication::translate("mainwindow", "Sort data", nullptr));
        deleteEntireList->setText(QApplication::translate("mainwindow", "Delete the list", nullptr));
        label2->setText(QApplication::translate("mainwindow", "       Work with the Literature structure", nullptr));
        generateLiterature->setText(QApplication::translate("mainwindow", "Generate the Literature", nullptr));
        linkedLiteratureCase->setText(QApplication::translate("mainwindow", "Linked List based Literature", nullptr));
        arrayLiteratureCase->setText(QApplication::translate("mainwindow", "Array based Literature", nullptr));
        vectorLiteratureCase->setText(QApplication::translate("mainwindow", "Vector based Literature", nullptr));
        addBook->setText(QApplication::translate("mainwindow", "Add Book", nullptr));
        deleteBook->setText(QApplication::translate("mainwindow", "Delete the last Book", nullptr));
        sortBook->setText(QApplication::translate("mainwindow", "Sort Books", nullptr));
        findSeries->setText(QApplication::translate("mainwindow", "Find series", nullptr));
        deleteEntireLiterature->setText(QApplication::translate("mainwindow", "Delete the Literature", nullptr));
        labelLiteratureData->setText(QApplication::translate("mainwindow", "Literature data", nullptr));
        labelListData->setText(QApplication::translate("mainwindow", "List data", nullptr));
    } // retranslateUi

};

namespace Ui {
    class mainwindow: public Ui_mainwindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
