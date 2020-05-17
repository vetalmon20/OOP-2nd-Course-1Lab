#include "addbook.h"
#include "ui_addbook.h"

addbook::addbook(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::addbook)
{
    ui->setupUi(this);
}

addbook::~addbook()
{
    delete ui;
}

void addbook::on_cancel_clicked()
{
    this->close();
}

void addbook::on_ok_clicked()
{
    QString in = ui->user_input->toPlainText();
    std::string output_string = in.toStdString();

    emit entered_value(output_string, check_input(), ui->dateRelease->date());
    this->close();
}

bool addbook::check_input()
{
    QString in = ui->user_input->toPlainText();
    std::string in_str = in.toStdString();

    if(in == ' ' || in == nullptr)
        return 0;
    return 1;
}
