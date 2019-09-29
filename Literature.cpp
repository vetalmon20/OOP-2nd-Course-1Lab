/**
 * 2nd Course K-29
 * Lab 1. Variant 2-10
 * Task: make a class that realise such tasks:
 *      1)gives the information about the book, author, date of wrote etc.
 *      2)gives the information about the main characters of the book, their importance etc.
 *      3)dividing the books on series
 *
 *@author Vitaliy Datsiuk
 *@version 1.5 30/09/19
 * "Header"
 */
#include "Literature.h"
#include <iostream>

using namespace std;

template <class T>
void Literature <T> :: add_book(Book in) {

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
template <class T>
void Literature <T> :: generate_Books(){

    char alphanum[] =
            "0123456789"
            "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
            "abcdefghijklmnopqrstuvwxyz";

    string character_names[] = {"Batman", "Superman", "Hloria", "Megamen", "Spiderman", "Venom", "Atlant",
                                "Ronn", "Harry", "Germiona", "Ronaldo", "Gray", "Watson"};

    string authors_names[] = {"Wilson D.", "Malkoy A.", "Manny M.", "Melnychuk. J", "Walter D.", "Qiuao S",
                              "Greenwood K.", "Shevchenko T."};

    vector <string> authors;              //authors of the book
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
template <class T>
void Literature <T> :: find_series(string character) {

    if (character == "") {
        cout << "empty character" << endl;
        return;
    }

    Global_Character ex;

    List<Book> series;
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