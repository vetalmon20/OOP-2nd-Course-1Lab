#ifndef ADDBOOK_H
#define ADDBOOK_H

#include <QDialog>
#include <QDateTimeEdit>

namespace Ui {
class addbook;
}

/**
 * @brief The addbook class is used to create a window with input data to create the book
 */
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
    /**
     * @brief entered_value send the signal with the input value and the boolean type that shows the correction of the input
     * @param input input string
     * @param checked if the data is correct
     * @param date input date
     */
    void entered_value(std::string input, bool checked, QDate date);

private:
    Ui::addbook *ui;

    /**
     * @brief check_input checks the input
     * @return 1 if the data is correct, vice versa returns 0
     */
    bool check_input();
};

#endif // ADDBOOK_H
