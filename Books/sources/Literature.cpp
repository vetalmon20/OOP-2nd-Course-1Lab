/**
 * 2nd Course K-29
 * Lab 1. Variant 2-10
 * Task: make a class that realise such tasks:
 *      1)gives the information about the book, author, date of wrote etc.
 *      2)gives the information about the main characters of the book, their importance etc.
 *      3)dividing the books on series
 *
 * Purpose:this file contains all the methods that are written in the Literature.h
 *
 *@author Vitaliy Datsiuk
 *@version 2 08/10/19
 *
 */
#include "..//Books/headers/Literature.h"
#include <iostream>

using namespace std;

/*all functions are almost duplicated with tiny differences. Documentation is written only for the
 * Array_literature functions just for the instance. The logic of appropriate functions in
 * Linked_List is the same*/

/**
 * Adds the book to the Literature
 *
 * @param in Book that would be added to the Literature
 */
inline void Array_literature :: add_book(Book in) {

    Books.add_node(in);
    bool upd = 0;                                //used to check if the character is already present

    int index = 0;
    //cycle for all the characters in the book
    for (int i = 0; i < in.characters_get().size(); i++){

        //while not the end of already present characters
        while(index < Characters.get_curr_size()){
            //if it is the same character adds the mention and importance
            if(Characters.arr[index].nickname_get() == in.characters_get()[i].nickname_get()) {
                Characters.arr[index].add_mention(in.name_get());
                Characters.arr[index].add_importance(in.characters_get()[i].importance_get());
                upd = 1;      //means that character was updated and we dont need to create new one
            }
            index++;
        }
        //if it is a new character create a new one
        if (upd == 0) {
            Global_Character new_Character;
            Character tempo = in.characters_get()[i];
            new_Character.nickname_set(tempo.nickname_get());
            new_Character.add_importance(tempo.importance_get());
            new_Character.add_mention(tempo.mention_get());
            Characters.add_node(new_Character);
        }
        upd = 0;
        index = 0;
    }
}

/**
* Function that generates a random List of the Books
*/
inline void Array_literature :: generate_Books(){

    //bases of needed data for generating the "random" data

    char alphanum[] =
            "0123456789"
            "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
            "abcdefghijklmnopqrstuvwxyz";

    string character_names[] = {"Batman", "Superman", "Hloria", "Megamen", "Spiderman", "Venom", "Atlant",
                                "Ronn", "Harry", "Germiona", "Ronaldo", "Gray", "Watson"};

    string authors_names[] = {"Wilson D.", "Malkoy A.", "Manny M.", "Melnychuk. J", "Walter D.", "Qiuao S",
                              "Greenwood K.", "Shevchenko T."};

    vector <string> authors;             //authors of the book
    int authors_length;                  //the number of authors

    int length = rand() % 7 + 5;         //Random num of the list

    int Book_name_length;                //the length of the name of the Book
    string Book_name;                    //temporary string that will be in the list

    vector<Character> characters;        //characters for the book
    int characters_length;               //the number of characters

    Date date;

    Book Book_temp;                      //Temporary book that will be added

    for (int i = 0 ;i < length; i++){           //BOOK[i]

        Book_name_length = rand() % 7 + 3;
        for (int j = 0; j < Book_name_length; j++){
            Book_name.push_back(alphanum[rand() % sizeof(alphanum)]);   //gen Book NAME
        }

        characters_length = rand() % 4 + 1;
        for(int k = 0; k < characters_length; k++){             //gen characters for the book
            Character char_temp;
            char_temp.new_character(character_names[rand() % 13], Book_name, rand() % 3 + 1);
            characters.push_back(char_temp);
        }

        authors_length = rand() % 2 + 1;
        for (int l = 0; l < authors_length; l++){                //gen the authors
            authors.push_back(authors_names[rand() % 8]);
        }

        date.year = rand() % 1019 + 1000;
        date.day = rand() % 28 + 1;
        date.month = rand() % 12 + 1;

        //setting the book
        Book_temp.new_book(Book_name, authors, date, rand() % 600 + 50, "Annotation", characters);

        add_book(Book_temp);        //adding the book

        authors.clear();
        characters.clear();         //deleting the values in our arrays
        Book_name.erase();
    }



}

/**
* Function that finds the series for the input character
*
* @param character For this character the series would be found
*/
inline void Array_literature  :: find_series(string character) {

    if (character == "") {
        cout << "empty character" << endl;
        return;
    }

    Arr_List<Book> series;                      //the output series
    int index_Char = 0;
    int index_Book = 0;

    //while array of characters is not empty
    while (index_Char < Characters.get_curr_size()) {
        Global_Character start = Characters.arr[index_Char];

        /*if we found our input character start seeking for its mentions and add to the series
         * that one where it has importance that equals 1 or 2*/
        if (start.nickname_get() == character) {
            for(int i = 0; i < start.mentions_get().size(); i++) {
                if (start.importances_get()[i] < 3) { //if it is main or secondary
                    while (index_Book < Books.get_curr_size()) {
                        if (Books.arr[index_Book].name_get() == start.mentions_get()[i]) {
                            series.add_node(Books.arr[index_Book]);
                        }
                        index_Book++;
                    }
                    index_Book = 0;
                }
            }
        }
        index_Char++;
    }
    if (series.get_curr_size() == 0){
        cout << "No series for this character" << endl;
        return;
    }
    series.mergesort();
    cout << endl << "series for the: " << character << ":" << endl;

    series.display();
}

/**
* Function that displays all of the characters on the screen
*/
inline void Array_literature :: display_characters() {
    Characters.display();
}

/**
* Function that displays all of the books on the screen
*/
inline void Array_literature :: display_books() {
    Books.display();
}

/**
 * Pops the last book
 */
inline void Array_literature::pop_book() {
    Books.pop_node();
}

/**
 * Sorts the books by data
 */
inline void Array_literature::sort_books() {
    Books.quicksort();
}


/**
* Adds the book to the Literature
*
* @param in Book that would be added to the Literature
*/
inline void Linked_literature :: add_book(Book in) {

    Books.add_node(in);
    bool upd = 0;


    for (int i = 0; i < in.characters_get().size(); i++){
        Node<Global_Character> *temp = Characters.get_head();

        while(temp != NULL){
            if(temp->data.nickname_get() == in.characters_get()[i].nickname_get()) {
                temp->data.add_mention(in.name_get());
                temp->data.add_importance(in.characters_get()[i].importance_get());
                upd = 1;
            }
            temp = temp->next;
        }
        if (upd == 0) {
            Global_Character new_Character;
            Character tempo = in.characters_get()[i];
            new_Character.nickname_set(tempo.nickname_get());
            new_Character.add_importance(tempo.importance_get());
            new_Character.add_mention(tempo.mention_get());
            Characters.add_node(new_Character);


        }
        upd = 0;
    }
}

/**
* Function that generates a random List of the Books
*/
inline void Linked_literature :: generate_Books(){

    char alphanum[] =
            "0123456789"
            "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
            "abcdefghijklmnopqrstuvwxyz";

    string character_names[] = {"Batman", "Superman", "Hloria", "Megamen", "Spiderman", "Venom", "Atlant",
                                "Ronn", "Harry", "Germiona", "Ronaldo", "Gray", "Watson"};

    string authors_names[] = {"Wilson D.", "Malkoy A.", "Manny M.", "Melnychuk. J", "Walter D.", "Qiuao S",
                              "Greenwood K.", "Shevchenko T."};

    vector <string> authors;             //authors of the book
    int authors_length;                  //the number of authors

    int length = rand() % 7 + 5;         //Random num of the list

    int Book_name_length;                //the length of the name of the Book
    string Book_name;                    //temporary string that will be in the list

    vector<Character> characters;        //characters for the book
    int characters_length;               //the number of characters

    Date date;

    Book Book_temp;                      //Temporary book that will be added

    for (int i = 0 ;i < length; i++){           //BOOK[i]

        Book_name_length = rand() % 7 + 3;
        for (int j = 0; j < Book_name_length; j++){
            Book_name.push_back(alphanum[rand() % sizeof(alphanum)]);   //gen Book NAME
        }

        characters_length = rand() % 4 + 1;
        for(int k = 0; k < characters_length; k++){             //gen characters for the book
            Character char_temp;
            char_temp.new_character(character_names[rand() % 13], Book_name, rand() % 3 + 1);
            characters.push_back(char_temp);
        }

        authors_length = rand() % 2 + 1;
        for (int l = 0; l < authors_length; l++){                //gen the authors
            authors.push_back(authors_names[rand() % 8]);
        }

        date.year = rand() % 1019 + 1000;
        date.day = rand() % 28 + 1;
        date.month = rand() % 12 + 1;

        Book_temp.new_book(Book_name, authors, date, rand() % 600 + 50, "Annotation", characters);

        add_book(Book_temp);

        authors.clear();
        characters.clear();         //deleting the values in our arrays
        Book_name.erase();
    }



}

/**
* Function that finds the series for the input character
*
* @param character For this character the series would be found
*/
inline void Linked_literature  :: find_series(string character) {

    if (character == "") {
        cout << "empty character" << endl;
        return;
    }

    Linked_List<Book> series;
    Node<Global_Character> *start = Characters.get_head();
    while (start != NULL) {
        if (start->data.nickname_get() == character) {
            for(int i = 0; i < start->data.mentions_get().size(); i++) {
                if (start->data.importances_get()[i] < 3) { //if it is main or secondary
                    Node<Book> *temp = Books.get_head();
                    while (temp != NULL) {
                        if (temp->data.name_get() == start->data.mentions_get()[i]) {
                            series.add_node(temp->data);
                        }
                        temp = temp->next;
                    }
                }
            }
        }

        start = start->next;
    }
    if (series.get_head() == NULL){
        cout << "No series for this character" << endl;
        return;
    }
    series.mergesort();
    cout << endl << "series for the: " << character << ":" << endl;

    Node<Book> *temp = series.get_head();
    while(temp != NULL){
        cout<<temp->data;
        temp = temp->next;
    }
}

/**
* Function that displays all of the books on the screen
*/
inline void Linked_literature :: display_characters() {
    Characters.display();
}

/**
* Function that displays all of the books on the screen
*/
inline void Linked_literature ::display_books() {
    Books.display();
}

/**
 * Pops the last book
 */
inline void Linked_literature::pop_book() {
    Books.pop_node();
}

/**
 * Sorts the books by data
 */
inline void Linked_literature::sort_books() {
    Books.quicksort();
}

/**
* Adds the book to the Literature
*
* @param in Book that would be added to the Literature
*/
inline void Vector_literature::add_book(Book in) {

    Books.add_node(in);
    bool upd = 0;                                //used to check if the character is already present

    int index = 0;
    //cycle for all the characters in the book
    for (int i = 0; i < in.characters_get().size(); i++){

        //while not the end of already present characters
        while(index < Characters.get_curr_size()){
            //if it is the same character adds the mention and importance
            if(Characters.arr[index].nickname_get() == in.characters_get()[i].nickname_get()) {
                Characters.arr[index].add_mention(in.name_get());
                Characters.arr[index].add_importance(in.characters_get()[i].importance_get());
                upd = 1;      //means that character was updated and we dont need to create new one
            }
            index++;
        }
        //if it is a new character create a new one
        if (upd == 0) {
            Global_Character new_Character;
            Character tempo = in.characters_get()[i];
            new_Character.nickname_set(tempo.nickname_get());
            new_Character.add_importance(tempo.importance_get());
            new_Character.add_mention(tempo.mention_get());
            Characters.add_node(new_Character);
        }
        upd = 0;
        index = 0;
    }
}

/**
* Function that generates a random List of the Books
*/
inline void Vector_literature::generate_Books() {

    //bases of needed data for generating the "random" data

    char alphanum[] =
            "0123456789"
            "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
            "abcdefghijklmnopqrstuvwxyz";

    string character_names[] = {"Batman", "Superman", "Hloria", "Megamen", "Spiderman", "Venom", "Atlant",
                                "Ronn", "Harry", "Germiona", "Ronaldo", "Gray", "Watson"};

    string authors_names[] = {"Wilson D.", "Malkoy A.", "Manny M.", "Melnychuk. J", "Walter D.", "Qiuao S",
                              "Greenwood K.", "Shevchenko T."};

    vector <string> authors;             //authors of the book
    int authors_length;                  //the number of authors

    int length = rand() % 7 + 5;         //Random num of the list

    int Book_name_length;                //the length of the name of the Book
    string Book_name;                    //temporary string that will be in the list

    vector<Character> characters;        //characters for the book
    int characters_length;               //the number of characters

    Date date;

    Book Book_temp;                      //Temporary book that will be added

    for (int i = 0 ;i < length; i++){           //BOOK[i]

        Book_name_length = rand() % 7 + 3;
        for (int j = 0; j < Book_name_length; j++){
            Book_name.push_back(alphanum[rand() % sizeof(alphanum)]);   //gen Book NAME
        }

        characters_length = rand() % 4 + 1;
        for(int k = 0; k < characters_length; k++){             //gen characters for the book
            Character char_temp;
            char_temp.new_character(character_names[rand() % 13], Book_name, rand() % 3 + 1);
            characters.push_back(char_temp);
        }

        authors_length = rand() % 2 + 1;
        for (int l = 0; l < authors_length; l++){                //gen the authors
            authors.push_back(authors_names[rand() % 8]);
        }

        date.year = rand() % 1019 + 1000;
        date.day = rand() % 28 + 1;
        date.month = rand() % 12 + 1;

        //setting the book
        Book_temp.new_book(Book_name, authors, date, rand() % 600 + 50, "Annotation", characters);

        add_book(Book_temp);        //adding the book

        authors.clear();
        characters.clear();         //deleting the values in our arrays
        Book_name.erase();
    }
}

/**
* Function that finds the series for the input character
*
* @param character For this character the series would be found
*/
inline void Vector_literature::find_series(string character) {


    if (character == "") {
        cout << "empty character" << endl;
        return;
    }

    Arr_List<Book> series;                      //the output series
    int index_Char = 0;
    int index_Book = 0;

    //while array of characters is not empty
    while (index_Char < Characters.get_curr_size()) {
        Global_Character start = Characters.arr[index_Char];

        /*if we found our input character start seeking for its mentions and add to the series
         * that one where it has importance that equals 1 or 2*/
        if (start.nickname_get() == character) {
            for(int i = 0; i < start.mentions_get().size(); i++) {
                if (start.importances_get()[i] < 3) { //if it is main or secondary
                    while (index_Book < Books.get_curr_size()) {
                        if (Books.arr[index_Book].name_get() == start.mentions_get()[i]) {
                            series.add_node(Books.arr[index_Book]);
                        }
                        index_Book++;
                    }
                    index_Book = 0;
                }
            }
        }
        index_Char++;
    }
    if (series.get_curr_size() == 0){
        cout << "No series for this character" << endl;
        return;
    }
    series.mergesort();
    cout << endl << "series for the: " << character << ":" << endl;

    series.display();
}

/**
* Function that displays all of the books on the screen
*/
inline void Vector_literature::display_books() {
Books.display();
}

/**
* Function that displays all of the characters on the screen
*/
inline void Vector_literature::display_characters() {
    Characters.display();
}

/**
 * Pops the last book
 */
inline void Vector_literature::pop_book() {
    Books.pop_node();
}

/**
 * Sorts the books by data
 */
inline void Vector_literature::sort_books() {
    Books.quicksort();
}
