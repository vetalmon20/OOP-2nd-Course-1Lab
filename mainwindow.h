#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QDialog>
#include <QButtonGroup>
#include "Lists.h"
#include "Literature.h"
#include "addvalue.h"
#include <iostream>
#include <QMessageBox>
#include "Literature.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class mainwindow;
}
QT_END_NAMESPACE

class mainwindow : public QDialog
{
    Q_OBJECT

public:
    explicit mainwindow(QWidget *parent = nullptr);
    ~mainwindow();


private slots:
    void on_generateList_clicked();

    void on_addList_clicked();

    void add_node(string input, bool checked);

    void on_deleteList_clicked();

    void on_sortList_clicked();

    void on_deleteEntireList_clicked();

    void on_generateLiterature_clicked();

signals:
     void data_type_info(int type);

private:
    Ui::mainwindow *ui;
    addvalue *AV_Win;
    int curr_data_type = 0;
    int curr_list_type = 0;
    int curr_literature_type = 0;
    bool list_present = 0;
    bool literature_present = 0;

    template <class T>
    void display_list(IList<T>* input_list);
    void display_literature(Literature* input_literature);

};

/**
 * Converts the input value to the string
 */
template<class T>
std::string to_str(T input);

template<class T>
IList<T>* curr_list;

inline Literature* curr_literature;

#endif // MAINWINDOW_H
