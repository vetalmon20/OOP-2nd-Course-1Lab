#include "mainwindow.h"
#include "ui_mainwindow.h"


mainwindow::mainwindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::mainwindow)
{
    ui->setupUi(this);
}

mainwindow::~mainwindow()
{
    delete ui;
}


/**
 * Converts the input value to the string
 */
template<class T>
std::string to_str(T input){
    return std::to_string(input);
}

template<>
inline std::string to_str(char input){
    string temp;
    temp.push_back(input);
    return temp;
}

template<>
inline std::string to_str(string input){
    return input;
}

template<>
inline std::string to_str(Book input){
    std::string output;
    output = input.name_get() + ";   ";
    output += input.release_get().to_str();
    return output;
}

template <class T>
void mainwindow::display_list(IList<T>* input_list)
{
    int curr_size = input_list->get_curr_size();
    for(int i = 0; i < curr_size; i++){
        T temp = (*input_list)[i];
        ui->listList->addItem(QString::fromStdString(to_str(temp)));
    }
}


void mainwindow::display_literature(Literature* input_literature){
    int curr_size = input_literature->get_curr_size();
    for(int i = 0; i < curr_size; i++){
        Book temp = (*input_literature)[i];
        ui->literatureList->addItem(QString::fromStdString(to_str(temp)));
    }
}

//*********************
void mainwindow::on_generateList_clicked()
{
    ui->listList->clear();
    curr_list<int> = nullptr;
    curr_list<float> = nullptr;
    curr_list<char> = nullptr;
    curr_list<std::string> = nullptr;

    int data_type = 0;

    if(ui->floatCase->isChecked())
        data_type = 1;
    else {
        if(ui->charCase->isChecked())
            data_type = 2;
        else {
            if(ui->stringCase->isChecked())
                data_type = 3;
        }
    }
    curr_data_type = data_type;

    int list_type = 0;

    if(ui->arrayCase->isChecked())
        list_type = 1;
    else {
        if(ui->vectorCase->isChecked())
            list_type = 2;
    }
    curr_list_type = list_type;

    switch(data_type){
        case 0:{
            IList<int> *int_ptr;
            switch(list_type){
                case 0:{
                    Linked_List<int> *temp = new Linked_List<int>;
                    int_ptr = temp;
                    int_ptr->generate();
                    display_list(int_ptr);
                    curr_list<int> = int_ptr;
                    break;
                }
                case 1:{
                    Arr_List<int> *temp = new Arr_List<int>;
                    int_ptr = temp;
                    int_ptr->generate();
                    curr_list<int> = int_ptr;
                    display_list(int_ptr);
                    break;
                }
                case 2:{
                    Vector_List<int> *temp = new Vector_List<int>;
                    int_ptr = temp;
                    int_ptr->generate();
                    curr_list<int> = int_ptr;
                    display_list(int_ptr);
                    break;
                }
                default:{
                    std::cout << "CRITICAL ERROR. WRONG LIST TYPE" << endl;
                }
            }
            break;
        }
        case 1:{
            IList<float> *float_ptr;
            switch(list_type){
                case 0:{
                    Linked_List<float> *temp = new Linked_List<float>;
                    float_ptr = temp;
                    float_ptr->generate();
                    curr_list<float> = float_ptr;
                    display_list(float_ptr);
                    break;
                }
                case 1:{
                    Arr_List<float> *temp = new Arr_List<float>;
                    float_ptr = temp;
                    float_ptr->generate();
                    curr_list<float> = float_ptr;
                    display_list(float_ptr);
                    break;
                }
                case 2:{
                    Vector_List<float> *temp = new Vector_List<float>;
                    float_ptr = temp;
                    float_ptr->generate();
                    curr_list<float> = float_ptr;
                    display_list(float_ptr);
                    break;
                }
                default:{
                    std::cout << "CRITICAL ERROR. WRONG LIST TYPE" << endl;
                }
            }
            break;
        }
        case 2:{
            IList<char> *char_ptr;
            switch(list_type){
                case 0:{
                    Linked_List<char> *temp = new Linked_List<char>;
                    char_ptr = temp;
                    char_ptr->generate();
                    curr_list<char> = char_ptr;
                    display_list(char_ptr);
                    break;
                }
                case 1:{
                    Arr_List<char> *temp = new Arr_List<char>;
                    char_ptr = temp;
                    char_ptr->generate();
                    curr_list<char> = char_ptr;
                    display_list(char_ptr);
                    break;
                }
                case 2:{
                   Vector_List<char> *temp = new Vector_List<char>;
                    char_ptr = temp;
                    char_ptr->generate();
                    curr_list<char> = char_ptr;
                    display_list(char_ptr);
                    break;
                }
                default:{
                    std::cout << "CRITICAL ERROR. WRONG LIST TYPE" << endl;
                }
            }
            break;
        }
        case 3:{
            IList<std::string> *string_ptr;
            switch(list_type){
                case 0:{
                    Linked_List<std::string> *temp = new Linked_List<std::string>;
                    string_ptr = temp;
                    string_ptr->generate();
                    curr_list<std::string> = string_ptr;
                    display_list(string_ptr);
                    break;
                }
                case 1:{
                    Arr_List<std::string> *temp = new Arr_List<std::string>;
                    string_ptr = temp;
                    string_ptr->generate();
                    curr_list<std::string> = string_ptr;
                    display_list(string_ptr);
                    break;
                }
                case 2:{
                    Vector_List<std::string> *temp = new Vector_List<std::string>;
                    string_ptr = temp;
                    string_ptr->generate();
                    curr_list<std::string> = string_ptr;
                    display_list(string_ptr);
                    break;
                }
                default:{
                    std::cout << "CRITICAL ERROR. WRONG LIST TYPE" << endl;
                }
            }
            break;
        }
        default:{
            cout << "CRITICAL ERROR. WRONG DATA TYPE" << endl;
        }
    }
    //return nullptr;
    list_present = 1;
}


void mainwindow::add_node(string input, bool checked)
{

    if(checked == 0){
        QMessageBox msgBox;
        msgBox.setText("You entered the wrong data");
        msgBox.exec();
        return;
    }
    ui->listList->addItem(QString::fromStdString(input));
    switch(curr_data_type){
        case 0:{
            curr_list<int>->add_node(std::stoi(input));
            break;
        }
        case 1:{
            curr_list<float>->add_node(std::stoi(input));
            break;
        }
        case 2:{
             curr_list<char>->add_node(input[0]);
             break;
        }
        case 3:{
             curr_list<std::string>->add_node(input);
             break;
        }
        default:{
            std::cout << "CRITICAL ERROR. WRONG LIST TYPE" << endl;
        }
    }
}


void mainwindow::on_addList_clicked()
{
    if(list_present == 0){
        QMessageBox msgBox;
        msgBox.setText("You need to generate the list");
        msgBox.exec();
        return;
    }
    AV_Win = new addvalue(this);
    AV_Win->setModal(true);
    AV_Win->show();
    connect(AV_Win ,&addvalue::entered_value, this, &mainwindow::add_node);
    connect(this, &mainwindow::data_type_info, AV_Win, &addvalue::set_type);

    emit data_type_info(this->curr_data_type);
}


void mainwindow::on_deleteList_clicked()
{
    if(list_present == 0){
        QMessageBox msgBox;
        msgBox.setText("You need to generate the list");
        msgBox.exec();
        return;
    }
   switch(curr_data_type){
       case 0:{
           if(curr_list<int>->get_curr_size() == 1)
               list_present = 0;
           curr_list<int>->pop_node();
           break;
       }
       case 1:{
           if(curr_list<float>->get_curr_size() == 1)
               list_present = 0;
           curr_list<float>->pop_node();
           break;
       }
       case 2:{
           if(curr_list<char>->get_curr_size() == 1)
               list_present = 0;
           curr_list<char>->pop_node();
           break;
       }
       case 3:{
           if(curr_list<std::string>->get_curr_size() == 1)
               list_present = 0;
           curr_list<std::string>->pop_node();
           break;
       }
   }


   ui->listList->takeItem(ui->listList->count() - 1);
}


void mainwindow::on_sortList_clicked()
{
    if(list_present == 0){
        QMessageBox msgBox;
        msgBox.setText("You need to generate the list");
        msgBox.exec();
        return;
    }
    ui->listList->clear();
    switch(curr_data_type){
        case 0:{
            curr_list<int>->quicksort();
            display_list(curr_list<int>);
            break;
        }
        case 1:{
            curr_list<float>->quicksort();
            display_list(curr_list<float>);
            break;
        }
        case 2:{
            curr_list<char>->quicksort();
            display_list(curr_list<char>);
            break;
        }
        case 3:{
            curr_list<std::string>->quicksort();
            display_list(curr_list<std::string>);
            break;
        }
    }
}


void mainwindow::on_deleteEntireList_clicked()
{
    switch(curr_data_type){
        case 0:{
            curr_list<int> = nullptr;
            break;
        }
        case 1:{
            curr_list<float> = nullptr;
            break;
        }
        case 2:{
            curr_list<char> = nullptr;
            break;
        }
        case 3:{
            curr_list<std::string> = nullptr;
            break;
        }
    }
    list_present = 0;
    ui->listList->clear();
}


void mainwindow::on_generateLiterature_clicked()
{
    ui->literatureList->clear();
    curr_literature = nullptr;

    int literature_type = 0;
    if(ui->arrayLiteratureCase->isChecked())
        literature_type = 1;
    else {
        if(ui->charCase->isChecked())
            literature_type = 2;
    }
    curr_literature_type = literature_type;

    switch(curr_literature_type){
        case 0:{
            Linked_literature *temp = new Linked_literature;
            curr_literature = temp;
            break;
        }
        case 1:{
            Array_literature *temp = new Array_literature;
            curr_literature = temp;
            break;
        }
        case 2:{
            Vector_literature *temp = new Vector_literature;
            curr_literature = temp;
            break;
        }
        default:{
            cout << "CRITICAL ERROR. WRONG LITERATURE TYPE." << endl;
            return;
        }
    }
    curr_literature->generate_Books();
    display_literature(curr_literature);

    literature_present = 1;
}


void mainwindow::on_addBook_clicked()
{
    if(literature_present == 0){
        QMessageBox msgBox;
        msgBox.setText("You need to generate the literature");
        msgBox.exec();
        return;
    }
    AB_Win = new addbook(this);
    AB_Win->setModal(true);
    AB_Win->show();
    connect(AB_Win ,&addbook::entered_value, this, &mainwindow::add_book);
}


void mainwindow::add_book(string input, bool checked, QDate date)
{
    if(checked == 0){
        QMessageBox msgBox;
        msgBox.setText("The name of the book can not be empty");
        msgBox.exec();
        return;
    }

    Book *temp = new Book();
    Date release_date;

    release_date.day = date.day();
    release_date.month = date.month();
    release_date.year = date.year();

    if(input[input.size() - 1] == '\n')
        input.erase(input.size() - 1, 1);
    temp->name_set(input);
    temp->release_set(release_date);
    temp->page_num_set(rand() % 500 + 100);


    ui->literatureList->addItem(QString::fromStdString(to_str(*temp)));
    curr_literature->add_book(*temp);

}


void mainwindow::on_deleteBook_clicked()
{
    if(literature_present == 0){
        QMessageBox msgBox;
        msgBox.setText("You need to generate the literature");
        msgBox.exec();
        return;
    }

    if(curr_literature->get_curr_size() == 1)
        literature_present = 0;
    curr_literature->pop_book();
    ui->literatureList->takeItem(ui->literatureList->count() - 1);
}


void mainwindow::on_sortBook_clicked()
{
    if(literature_present == 0){
        QMessageBox msgBox;
        msgBox.setText("You need to generate the literature");
        msgBox.exec();
        return;
    }
    ui->literatureList->clear();
    curr_literature->sort_books();
    display_literature(curr_literature);
}


void mainwindow::on_findSeries_clicked()
{
    if(literature_present == 0){
        QMessageBox msgBox;
        msgBox.setText("You need to generate the literature");
        msgBox.exec();
        return;
    }
        QMessageBox msgBox;
        //msgBox.setText(curr_literature)

        AV_Win = new addvalue(this);
        AV_Win->show();
        connect(AV_Win ,&addvalue::entered_value, this, &mainwindow::show_series);
        connect(this, &mainwindow::data_type_info, AV_Win, &addvalue::set_type);

        emit data_type_info(3);

}


void mainwindow::show_series(string input_character)
{
    QMessageBox msgBox;
    msgBox.setText(QString::fromStdString(curr_literature->find_series(input_character)));
    msgBox.exec();
}


void mainwindow::on_deleteEntireLiterature_clicked()
{
    curr_literature = nullptr;
    literature_present = 0;
    ui->literatureList->clear();

}
