#ifndef ADDBOOK_H
#define ADDBOOK_H

#include <QDialog>
#include <QDateTimeEdit>
#include <QMessageBox>

namespace Ui {
class addbook;
}

class addbook : public QDialog
{
    Q_OBJECT

public:
    explicit addbook(QWidget *parent = nullptr);
    ~addbook();

private slots:
    void on_cancel_clicked();

    void on_ok_clicked();

signals:
    void entered_value(QString name, QDate date, QString author, int page_number, QString characters, QString annotation);

private:
    Ui::addbook *ui;

    bool check_input();

    bool check_empty(QString in);

};

void remove_spaces(std::string &in);

#endif // ADDBOOK_H
