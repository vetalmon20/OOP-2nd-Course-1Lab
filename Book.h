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

#ifndef OOP_2ND_COURSE_1LAB_BOOK_H
#define OOP_2ND_COURSE_1LAB_BOOK_H

#include <string>
#include <vector>


using namespace std;

//struct that used in Book that shows date
class Date {
public:
    Date();

    int year;
    int month;
    int day;
};                          //variables are public for the comfort access


class Character{
private:
    string nickname;
    string mention;
    int importance;                //1- main; 2- secondary; 3 - episodable

    void nickname_set(string in);
    void mention_set(string in);
    void importance_set(int in);

public:
    Character();

    //overloading operators for Character in order to compare them and print on the screen
    friend std::ostream& operator << (std::ostream &out, const Character &in);
    friend bool operator <= (Character &left, Character &right);
    friend bool operator >= (Character &left, Character &right);

    string nickname_get();
    string mention_get();
    int importance_get();

    //creates a new character with input parametres
    void new_character(string _nickname, string _mentions,int _importance);

};

class Global_Character{
private:
    string nickname;
    vector<string> mentions;
    vector<int> importances;                //1- main; 2- secondary; 3 - episodable

public:
    Global_Character();

    //overloading operators for Global_Character in order to compare them and print on the screen
    friend std::ostream& operator << (std::ostream &out, const Global_Character &in);
    friend bool operator <= (Global_Character &left, Global_Character &right);
    friend bool operator >= (Global_Character &left, Global_Character &right);

    string nickname_get();
    void nickname_set(string in);
    vector<string> mentions_get();
    vector<int> importances_get();

    //Adds the importance/mention value in the end of the vector
    void add_importance(int in);
    void add_mention(string in);

};

class Book {
private:
    string name;
    vector <string> author;
    Date release;
    int page_num;
    string annotation;
    vector <Character> characters;


    void author_set(vector <string> in);
    void release_set(Date in);
    void page_num_set(int in);
    void annotation_set(string in);
    void characters_set(vector <Character> in);

public:

    Book();

    string name_get();
    vector <string> author_get();
    Date release_get();
    int page_num_get();
    string annotation_get();
    vector <Character> characters_get();

    void name_set(string in);

    //overloading operators for Book in order to compare them and print on the screen
    friend std::ostream& operator << (std::ostream &out, const Book &in);
    friend bool operator <= (Book &left, Book &right);
    friend bool operator >= (Book &left, Book &right);

    //creates a new Book with input parametres
    void new_book(string name, vector <string> author, Date release, int page_num, string annotation, vector <Character> characters);

    //functions that prints the following content on the screen
    void display_authors();
    void display_characters();

    //displays all the information about following book
    void display_book_full();
};


#endif //OOP_2ND_COURSE_1LAB_BOOK_H
