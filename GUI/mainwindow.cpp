#include "mainwindow.h"
#include "ui_mainwindow.h"


mainwindow::mainwindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::mainwindow)
{
    ui->setupUi(this);

    connect_db();

    curr_literature = new Vector_literature();

    fill_table();
    QTableView *books_table = this->ui->tableLiterature;
    books_table->horizontalHeader()->setStretchLastSection(true);
    books_table->setColumnWidth(3, this->width() / 18);
    books_table->setColumnWidth(4, this->width() / 6);
    books_table->setColumnWidth(5, this->width() / 5);
    books_table->horizontalHeader()->setSectionResizeMode(QHeaderView::Fixed);
    books_table->setSelectionBehavior(QAbstractItemView::SelectRows);

    QHeaderView *header = qobject_cast<QTableView *>(books_table)->horizontalHeader();
    connect(header, &QHeaderView::sectionClicked, this, &mainwindow::sort_by_section);

    fill_literature();
}

mainwindow::~mainwindow()
{
    disconnect_db();
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

void mainwindow::display_literature(Literature* input_literature){
    int curr_size = input_literature->get_curr_size();
    for(int i = 0; i < curr_size; i++){
        Book temp = (*input_literature)[i];
        //ui->literatureList->addItem(QString::fromStdString(to_str(temp)));
    }
}

void mainwindow::fill_literature()
{
    Book temp;

    std::string name;
    vector <std::string> authors;             //authors of the book
    Date date;
    int pages;
    std::string annotation;
    vector<Character> characters;        //characters for the book

    for(int i = 0; i < books_size; i++){
        name = ui->tableLiterature->model()->data(ui->tableLiterature->model()->index(i,0)).toString().toStdString();

        QDate qdate =  QDate::fromString(ui->tableLiterature->model()->data(ui->tableLiterature->model()->index(i,1)).toString(),"dd.MM.yyyy");
        date.day = qdate.day();
        date.month = qdate.month();
        date.year = qdate.year();

        authors = get_authors_from_qstr(ui->tableLiterature->model()->data(ui->tableLiterature->model()->index(i,2)).toString());

        pages = std::stoi(ui->tableLiterature->model()->data(ui->tableLiterature->model()->index(i,3)).toString().toStdString());

        characters = get_characters_from_qstr(ui->tableLiterature->model()->data(ui->tableLiterature->model()->index(i,4)).toString(), name);

        annotation =  ui->tableLiterature->model()->data(ui->tableLiterature->model()->index(i,5)).toString().toStdString();


        temp.new_book(name, authors, date, pages, annotation, characters);

        curr_literature->add_book(temp);
    }

    curr_literature->display_books();
}

QSqlQuery* mainwindow::update_table_view()
{
    QSqlQuery *qry = new QSqlQuery(books_db);
    QSqlQueryModel *model = new QSqlQueryModel();

    qry->prepare("SELECT * FROM BOOKS");

    qry->exec();
    model->setQuery(*qry);
    ui->tableLiterature->setModel(model);
    return qry;
}

bool mainwindow::connect_db()
{
    books_db = QSqlDatabase::addDatabase("QSQLITE");
    books_db.setDatabaseName("D:/MyRepositories/OOP/OOP-2nd-Course-1Lab/Data_Bases/Books.db");

    if(!books_db.open())
        return 0;
    return 1;
}

void mainwindow::disconnect_db()
{
    books_db.close();
    books_db.removeDatabase(QSqlDatabase::defaultConnection);
}

void mainwindow::fill_table()
{
    QSqlQuery *qry = update_table_view();

    if (books_db.driver()->hasFeature(QSqlDriver::QuerySize)) {
            this->books_size = qry->size();
        } else {
            qry->last();
            this->books_size = qry->at() + 1;
        }
}

void mainwindow::on_addBook_clicked()
{
    AB_Win = new addbook(this);
    AB_Win->setModal(true);
    AB_Win->show();
    connect(AB_Win ,&addbook::entered_value, this, &mainwindow::add_book);
}

void mainwindow::add_book(QString name, QDate date, QString author, int page_number, QString characters, QString annotation)
{
    Book *temp = new Book();
    temp->new_book(name.toStdString(), get_authors_from_qstr(author), get_date_from_qdate(date), page_number, annotation.toStdString(), get_characters_from_qstr(characters, name.toStdString()));
    curr_literature->add_book(*temp);

    QString date_qstr = date.toString("yyyy-MM-dd");

    QSqlQuery query;
    std::string query_text= "INSERT INTO BOOKS (NAME, DATE, AUTHOR, \"PAGE NUMBER\", CHARACTERS, ANNOTATION) "
                                       "VALUES ('";

    query_text += name.toStdString();
    query_text += "', '";
    query_text += date_qstr.toStdString();
    query_text += "', '";
    query_text += author.toStdString();
    query_text += "', ";
    query_text += std::to_string(page_number);
    query_text += ", '";
    query_text += characters.toStdString();
    query_text += "', '";
    query_text += annotation.toStdString();
    query_text += "')";

    if(query.prepare(QString::fromStdString(query_text))){
       query.exec(QString::fromStdString(query_text));
    } else {
        cout << "wrong sql query!" << endl;
        cout <<query_text << endl;
    }

    update_table_view();

    books_size++;
}

void mainwindow::on_deleteBook_clicked()
{
    QSqlQuery *qry = new QSqlQuery(books_db);
    QModelIndexList temporary;
    QTableView *books_table = this->ui->tableLiterature;
    QItemSelectionModel *select =  books_table->selectionModel();
    QString query_text = "DELETE FROM BOOKS WHERE NAME = '";
    QString query_text_default = query_text;

    temporary = select->selectedRows();
    for(int i = 0; i < temporary.size(); i++){
        QString book_name = ui->tableLiterature->model()->data(ui->tableLiterature->model()->index(temporary[i].row(),0)).toString();
        book_name.push_back("'");
        query_text.push_back(book_name);
        if(qry->prepare(query_text)){
            qry->exec(query_text);
            cout << query_text.toStdString() << endl;
            query_text = query_text_default;
        } else {
            cout << "wrong sql query!";
            query_text = query_text_default;
        }
    }

    update_table_view();
}

void mainwindow::on_findSeries_clicked()
{
        QMessageBox msgBox;
        //msgBox.setText(curr_literature)

        AV_Win = new addvalue(this);
        AV_Win->show();
        connect(AV_Win ,&addvalue::entered_value, this, &mainwindow::show_series);
}


void mainwindow::show_series(QString input_character)
{
    QMessageBox msgBox;
    msgBox.setText(QString::fromStdString(curr_literature->find_series(input_character.toStdString())));
    msgBox.exec();
}

void mainwindow::sort_by_section(int section_index)
{
    switch (section_index) {
        case 0:{
            QSqlQuery *qry = new QSqlQuery(books_db);
            QSqlQueryModel *model = new QSqlQueryModel();

            if(qry->prepare("SELECT * FROM BOOKS ORDER BY NAME ASC")){
                qry->exec("SELECT * FROM BOOKS ORDER BY NAME ASC");
                cout << "yes";
                model->setQuery(*qry);
                ui->tableLiterature->setModel(model);
            } else {
                cout << "wrong sql query!";
            }
            return;
        }
        case 1:{
            QSqlQuery *qry = new QSqlQuery(books_db);
            QSqlQueryModel *model = new QSqlQueryModel();

            if(qry->prepare("SELECT * FROM BOOKS ORDER BY date(DATE) ASC")){
                qry->exec("SELECT * FROM BOOKS ORDER BY date(DATE) ASC");
                cout << "yes";
                model->setQuery(*qry);
                ui->tableLiterature->setModel(model);
            } else {
                cout << "wrong sql query!";
            }
            return;
        }
        case 2:{
            QSqlQuery *qry = new QSqlQuery(books_db);
            QSqlQueryModel *model = new QSqlQueryModel();

            if(qry->prepare("SELECT * FROM BOOKS ORDER BY AUTHOR ASC")){
                qry->exec("SELECT * FROM BOOKS ORDER BY AUTHOR ASC");
                cout << "yes";
                model->setQuery(*qry);
                ui->tableLiterature->setModel(model);
            } else {
                cout << "wrong sql query!";
            }
            return;
        }
        case 3:{
            QSqlQuery *qry = new QSqlQuery(books_db);
            QSqlQueryModel *model = new QSqlQueryModel();

            if(qry->prepare("SELECT * FROM BOOKS ORDER BY \"PAGE NUMBER\" ASC")){
                qry->exec("SELECT * FROM BOOKS ORDER BY \"PAGE NUMBER\" ASC");
                cout << "yes";
                model->setQuery(*qry);
                ui->tableLiterature->setModel(model);
            } else {
                cout << "wrong sql query!";
            }
            return;
        }
        case 4:{
            QSqlQuery *qry = new QSqlQuery(books_db);
            QSqlQueryModel *model = new QSqlQueryModel();

            if(qry->prepare("SELECT * FROM BOOKS ORDER BY CHARACTERS ASC")){
                qry->exec("SELECT * FROM BOOKS ORDER BY CHARACTERS ASC");
                cout << "yes";
                model->setQuery(*qry);
                ui->tableLiterature->setModel(model);
            } else {
                cout << "wrong sql query!";
            }
            return;
        }
        case 5:{
            QSqlQuery *qry = new QSqlQuery(books_db);
            QSqlQueryModel *model = new QSqlQueryModel();

            if(qry->prepare("SELECT * FROM BOOKS ORDER BY ANNOTATION ASC")){
                qry->exec("SELECT * FROM BOOKS ORDER BY ANNOTATION ASC");
                cout << "yes";
                model->setQuery(*qry);
                ui->tableLiterature->setModel(model);
            } else {
                cout << "wrong sql query!";
            }
            return;
        }
    }
}

vector<string> get_authors_from_qstr(QString in)
{
    string in_str = in.toStdString();
    string author = "def_author";
    vector<string> authors;
    unsigned long long int start, end;
    start = end = 0;
    for(unsigned long long int i = 0; i < in_str.size(); i++){
        if(in_str[i] == ','){
            end = i;
            author = in_str.substr(start, end - start);
            authors.push_back(author);
            start = i + 1;
        }
    }

    end = in_str.size();
    author = in_str.substr(start, end - start);
    authors.push_back(author);

    return authors;
}

vector<Character> get_characters_from_qstr(QString in, string book_name)
{
    string in_str = in.toStdString();
    Character character;
    vector<Character> characters;
    unsigned long long int start, end;
    start = end = 0;
    for(unsigned long long int i = 0; i < in_str.size(); i++){
        if(in_str[i] == ','){
            end = i;
            character.nickname_set(in_str.substr(start, end - start));
            character.mention_set(book_name);
            character.importance_set(1);
            characters.push_back(character);
            start = i + 1;
        }
    }

    end = in_str.size();
    character.nickname_set(in_str.substr(start, end - start));
    character.mention_set(book_name);
    character.importance_set(1);
    characters.push_back(character);

    return characters;
}

Date get_date_from_qdate(QDate in)
{
    Date temp;
    temp.day = in.day();
    temp.month = in.month();
    temp.year = in.year();
    return temp;
}
