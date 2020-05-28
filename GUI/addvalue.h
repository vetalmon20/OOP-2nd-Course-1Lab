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
    void entered_value(QString character_name);

public slots:

private slots:
    void on_ok_clicked();

    void on_cancel_clicked();
private:
    Ui::addvalue *ui;
};

bool isInteger(const std::string & in);
bool isFloat(const std::string & in);
bool isChar(const std::string & in);

#endif // ADDVALUE_H
