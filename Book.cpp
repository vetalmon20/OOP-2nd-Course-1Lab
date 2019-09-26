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

#include <iostream>
#include "Book.h"

using namespace std;

Date :: Date() {
    year = 0;
    month = 0;
    day = 0;
}

Character :: Character() {
    nickname = "";
}

string Character :: nickname_get() {
    return nickname;
}

void Character :: nickname_set(string in) {
    nickname = in;
}

vector <int> Character :: importance_get() {
    return importance;
}

void Character :: importance_set(vector <int> in) {
    importance = in;
}

vector <string> Character :: mentions_get() {
    return mentions;
}

void Character :: mentions_set(vector <string> in) {
    mentions = in;
}

void Character :: new_character(string nickname, vector<string> mentions, vector<int> importance) {
    nickname_set(nickname);
    mentions_set(mentions);
    importance_set(importance);
}

Book :: Book() {
    name = "";
    page_num = 0;
    annotation = "";

}

string Book :: name_get() {

    return name;
}

void Book :: name_set(string in) {
    name = in;
}

vector <string> Book :: author_get() {
    return author;
}

void Book :: author_set(vector <string> in) {
    author = in;
}

string Book :: annotation_get() {
    return annotation;
}

void Book :: annotation_set(string in) {
    annotation = in;
}

int Book :: page_num_get() {
    return page_num;
}

void Book :: page_num_set(int in) {
    page_num = in;
}

vector <Character> Book :: characters_get() {
    return characters;
}

void Book :: characters_set(vector <Character> in) {
    characters = in;
}

Date Book :: release_get() {
    return release;
}

void Book :: release_set(Date in) {
    release.year = in.year;
    release.day = in.day;
    release.month = in.month;
}

void Book :: new_book(string name, vector <string> author, Date release, int page_num, string annotation, vector <Character> characters) {
    name_set(name);
    author_set(author);
    release_set(release);
    page_num_set(page_num);
    annotation_set(annotation);
    characters_set(characters);
}

bool Book::find_character(string in) {

    int length = characters.size();

    for (int i = 0; i < length; i++){
        if (characters[i].nickname_get() == in){
            //if character is main or secondary
            if(characters[i].importance_get()[i] == 1 || characters[i].importance_get()[i] == 2)
                return 1;       //character is belongs to the series
                //if it is episodable
            if(characters[i].importance_get()[i] == 3)
                return 0;       //character do not belongs to the series
        }
    }
    return 0;               //there no such a character in the book
}


void Book :: display_authors() {

    for (int i = 0; i < author.size(); i++)
        cout << author[i] << " ";
}

void Book :: display_characters() {

    for (int i = 0; i < characters.size(); i++)
        cout << characters[i].nickname_get() << " ";
}

void Book :: display_book_full() {
    cout << "Name: "<< name_get()<<"; Date: " << release_get().year << "/" << release_get().month;
    cout << "/" << release_get().day << "; Pages: " << page_num_get() << "; Characters: ";
    display_characters();
    cout << "; Author(s): ";
    display_authors();
    cout << "; Annotation: " << annotation_get() << endl;
}

std::ostream& operator << (std::ostream &out, const Book &in)
{
    Book a = in;

    out <<"Name:"<<a.name_get()<<" Year:"<<a.release_get().year<<" "<<endl;

    return out;
}

bool operator <= (Book &left, Book &right){
        return left.release_get().year <= right.release_get().year;
}

bool operator >= (Book &left, Book &right){
    return left.release_get().year >= right.release_get().year;
}

