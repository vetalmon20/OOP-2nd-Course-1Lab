/**
 * 2nd Course K-29
 * Lab 1. Variant 2-10
 * Task: make a class that realise such tasks:
 *      1)gives the information about the book, author, date of wrote etc.
 *      2)gives the information about the main characters of the book, their importance etc.
 *      3)dividing the books on series
 *
 *@author Vitaliy Datsiuk
 *@version 1.4 25/09/19
 */

#ifndef OOP_2ND_COURSE_1LAB_BOOK_H
#define OOP_2ND_COURSE_1LAB_BOOK_H
#pragma once

#include <string>
#include <vector>


using namespace std;

class Date {
public:
    Date();

    int year;
    int month;
    int day;
};


class Character{
private:
    string nickname;
    vector <string> mentions;
    vector <int> importance;                //1- main; 2- secondary; 3 - episodable

    void nickname_set(string in);
    void mentions_set(vector <string> in);
    void importance_set(vector <int> in);

public:
    Character();

    string nickname_get();
    vector <string> mentions_get();
    vector <int> importance_get();

    void new_character(string nickname, vector <string> mentions,vector <int> importance);

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

    void display_authors();
    void display_characters();

public:

    Book();
    string name_get();
    vector <string> author_get();
    Date release_get();
    int page_num_get();
    string annotation_get();
    vector <Character> characters_get();

    void name_set(string in);                   //

    //overloading the <<; <= and >= operator for the Book structure
    friend std::ostream& operator<< (std::ostream &out, const Book &in);
    friend bool operator <= (Book &left, Book &right);
    friend bool operator >= (Book &left, Book &right);

    void new_book(string name, vector <string> author, Date release, int page_num, string annotation, vector<Character> characters);
    void display_book_full();
    bool find_character (string in);
};


#endif //OOP_2ND_COURSE_1LAB_BOOK_H
