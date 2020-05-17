#include "addvalue.h"
#include "ui_addvalue.h"

bool isInteger(const std::string & in)
{
   if(in.empty() || ((!isdigit(in[0])) && (in[0] != '-') && (in[0] != '+'))) return false;

   char * p;
   strtol(in.c_str(), &p, 10);

   return (*p == 0 || *p == ' ');
}

bool isFloat(const std::string & in)
{
    std::istringstream iss(in);
    float f;
    iss >> noskipws >> f;
    return iss.eof() && !iss.fail();
}

bool isChar(const string & in)
{
    return(in.size() == 1);
}

addvalue::addvalue(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::addvalue)
{
    ui->setupUi(this);

}

addvalue::~addvalue()
{
    delete ui;
}

void addvalue::set_type(int type)
{
    this->type = type;
}

void addvalue::on_ok_clicked()
{
    QString in = ui->user_input->toPlainText();
    std::string output_string = in.toStdString();

    emit entered_value(output_string, check_input());
    this->close();
}

void addvalue::on_cancel_clicked()
{
    this->close();
}

bool addvalue::check_input()
{
    QString in = ui->user_input->toPlainText();
    std::string in_str = in.toStdString();

    switch (this->type) {
        case 0:{
            return isInteger(in_str);
            }
        case 1:{
            return isFloat(in_str);
            }
        case 2:{
            return isChar(in_str);
            }
        case 3:{
            return true;
        }
        default:{
            cout << "CRITICAL ERROR. WRONG TYPE OF DATA" << endl;
            return false;
            }
    }
}


