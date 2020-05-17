#ifndef ADDBOOK_H
#define ADDBOOK_H

#include <QDialog>
#include <QDateTimeEdit>

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
    void entered_value(std::string input, bool checked, QDate date);

private:
    Ui::addbook *ui;

    bool check_input();
};

#endif // ADDBOOK_H
