#ifndef ADDVALUE_H
#define ADDVALUE_H

#include <QDialog>
#include <iostream>
#include <sstream>

using namespace std;

namespace Ui {
class addvalue;
}

class addvalue : public QDialog
{
    Q_OBJECT

public:
    explicit addvalue(QWidget *parent = nullptr);
    ~addvalue();
signals:
    /**
     * @brief entered_value send the signal with the input value and the boolean type that shows the correction of the input
     * @param input input string
     * @param checked if the data is correct
     */
    void entered_value(string input, bool checked);

public slots:
    /**
     * @brief set_type sets the type of the list to this class
     * @param type the type of the array
     */
    void set_type(int type);

private slots:
    void on_ok_clicked();

    void on_cancel_clicked();
private:
    Ui::addvalue *ui;
    int type;

    /**
     * @brief check_input checks the input
     * @return 1 if the data is correct, vice versa returns 0
     */
    bool check_input();
};

/**
 * @brief isInteger isFloat isChar are func that checks the correction of the input for respective types of data
 * @param in the input string
 * @return 1 if the data is correct. vice versa returns 0
 */
bool isInteger(const std::string & in);
bool isFloat(const std::string & in);
bool isChar(const std::string & in);

#endif // ADDVALUE_H
