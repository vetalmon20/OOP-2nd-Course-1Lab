#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QDialog>
#include <QButtonGroup>
#include "Lists.h"
#include "Literature.h"
#include "addbook.h"
#include "addvalue.h"
#include <iostream>
#include <QMessageBox>
#include <QDateTimeEdit>
#include <QSqlDatabase>
#include <QSqlQueryModel>
#include <QSqlQuery>
#include <QSqlDriver>

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
    void on_addBook_clicked();

    void add_book(QString name, QDate date, QString author, int page_number, QString characters, QString annotation);

    void on_deleteBook_clicked();

    void on_findSeries_clicked();

    void show_series(QString input_character);

    void sort_by_section(int section_index);

private:
    Ui::mainwindow *ui;
    addbook *AB_Win;
    addvalue *AV_Win;
    QSqlDatabase books_db;
    Vector_literature* curr_literature;
    int books_size = 0;

    void display_literature(Literature* input_literature);

    void fill_literature();

    QSqlQuery* update_table_view();

    bool connect_db();
    void disconnect_db();

    void fill_table();
};

/**
 * Converts the input value to the string
 */
template<class T>
std::string to_str(T input);

vector<std::string> get_authors_from_qstr(QString in);

vector<Character> get_characters_from_qstr(QString in, string book_name);

Date get_date_from_qdate(QDate in);

#endif // MAINWINDOW_H
