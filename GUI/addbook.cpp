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
    if(check_input() == 1){
        QString name = this->ui->bookName->text();
        QDate date = this->ui->bookDate->date();
        QString author = this->ui->bookAuthor->text();
        int page_number = this->ui->bookPageNumber->value();
        QString characters = this->ui->bookCharacters->text();
        QString annotation = this->ui->bookAnnotation->text();

        emit entered_value(name, date, author, page_number, characters, annotation);
        this->close();
    }
}

bool addbook::check_input()
{
    QString in = ui->bookName->text();
    if(check_empty(in) == 0){
        QMessageBox msgBox;
        msgBox.setText("You need to fill the name of the book");
        msgBox.exec();
        return 0;
    }
    in = ui->bookAuthor->text();
    if(check_empty(in) == 0){
        QMessageBox msgBox;
        msgBox.setText("You need to fill the Author of the book");
        msgBox.exec();
        return 0;
    }
    in = ui->bookCharacters->text();
    if(check_empty(in) == 0){
        QMessageBox msgBox;
        msgBox.setText("You need to fill the Characters of the book");
        msgBox.exec();
        return 0;
    }
    return 1;
}

bool addbook::check_empty(QString in)
{
    if(in == ' ' || in == nullptr)
        return 0;
    int count = 0;
    for(int i = 0; i < in.size(); i++){
        if(in[i] == ' ')
            count++;
    }
    if (count == in.size())
        return 0;
    return 1;
}

void remove_spaces(std::string &str)
{
    unsigned long long int n = str.length();

    int i = 0, j = -1;

    bool spaceFound = false;

    while (++j < static_cast<int>(n) && str[static_cast<unsigned long long int>(j)] == ' ');

    // read all characters of original string
    while (j < static_cast<int>(n))
    {
        // if current characters is non-space
        if (str[static_cast<unsigned long long int>(j)] != ' ')
        {
            // remove preceding spaces before dot,
            // comma & question mark
            if ((str[static_cast<unsigned long long int>(j)] == '.' || str[static_cast<unsigned long long int>(j)] == ',' ||
                 str[static_cast<unsigned long long int>(j)] == '?') && i - 1 >= 0 &&
                 str[static_cast<unsigned long long int>(i) - 1] == ' ')
                 str[static_cast<unsigned long long int>(i) - 1] = str[static_cast<unsigned long long int>(j++)];

            else
                // copy current character at index i
                // and increment both i and j
                str[static_cast<unsigned long long int>(i++)] = str[static_cast<unsigned long long int>(j++)];

            // set space flag to false when any
            // non-space character is found
            spaceFound = false;
        }
        // if current character is a space
        else if (str[static_cast<unsigned long long int>(j++)] == ' ')
        {
            // If space is encountered for the first
            // time after a word, put one space in the
            // output and set space flag to true
            if (!spaceFound)
            {
                str[static_cast<unsigned long long int>(i++)] = ' ';
                spaceFound = true;
            }
        }
    }

    // Remove trailing spaces
    if (i <= 1)
        str.erase(str.begin() + i, str.end());
    else
        str.erase(str.begin() + i - 1, str.end());
}
