/**
 * 2nd Course K-29
 * Lab 1. Variant 2-10
 * Task: make a class that realise such tasks:
 *      1)gives the information about the book, author, date of wrote etc.
 *      2)gives the information about the main characters of the book, their importance etc.
 *      3)dividing the books on series
 *
 *@author Vitaliy Datsiuk
 *@version 2 08/10/19
 *
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
    importance = 3;
    mention = "";
}

string Character :: nickname_get() {
    return nickname;
}

void Character :: nickname_set(string in) {
    nickname = in;
}

int Character :: importance_get() {
    return importance;
}

void Character :: importance_set(int in) {
    if (in > 3 || in <1){
        cout << "Wrong value of importance. Now the Character is episodable(3)";
        in = 3;
    }
    importance = in;
}

string Character :: mention_get() {
    return mention;
}

void Character :: mention_set(string in) {
    mention = in;
}

void Character :: new_character(string _nickname, string _mention, int _importance) {
    nickname_set(_nickname);
    mention_set(_mention);
    importance_set(_importance);
}



Global_Character :: Global_Character(){
    nickname = "";
}

string Global_Character :: nickname_get() {
    return nickname;
}

void Global_Character :: nickname_set(string in) {
    nickname = in;
}

vector<string> Global_Character :: mentions_get() {
    return mentions;
}

vector<int> Global_Character :: importances_get(){
    return importances;
}

void Global_Character :: add_importance(int in) {
    importances.push_back(in);
}

void Global_Character :: add_mention(string in) {
    mentions.push_back(in);
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

void Book :: display_authors() {

    for (int i = 0; i < author.size(); i++)
        cout << author[i] << " ";
}

void Book :: display_characters() {

    for (int i = 0; i < characters.size(); i++)
        cout << characters[i].nickname_get() << " ";
}

void Book :: display_book_full() {
    cout << "Name: "<< name_get() << "; Date: " << release_get().year << "/" << release_get().month;
    cout << "/" << release_get().day << "; Pages: " << page_num_get() << "; Characters: ";
    display_characters();
    cout << "; Author(s): ";
    display_authors();
    cout << "; Annotation: " << annotation_get() << endl;
}





/*Overloading the operators for all my classes:*/

std::ostream& operator << (std::ostream &out, const Book &in)
{
    Book a = in;

    out << "Name: " << a.name_get() << " Year:" << a.release_get().year << " " <<endl;

    return out;
}

bool operator <= (Book &left, Book &right){
    if(left.release_get().year != right.release_get().year)
        return left.release_get().year <= right.release_get().year;
    if(left.release_get().month != right.release_get().month)
        return left.release_get().month <= right.release_get().month;

    return left.release_get().day <= right.release_get().day;
}

bool operator >= (Book &left, Book &right){
    if (left.release_get().year != right.release_get().year)
    return left.release_get().year >= right.release_get().year;

    if(left.release_get().month != right.release_get().month)
        return left.release_get().month >= right.release_get().month;

    return left.release_get().day >= right.release_get().day;

}

std::ostream& operator << (std::ostream &out, const Character &in){

    Character a = in;

    out << " " << a.nickname_get() << " ";

    return out;

}

bool operator <= (Character &left, Character &right){
    return left.nickname_get() <= right.nickname_get();
}

bool operator >= (Character &left, Character &right){
    return left.nickname_get() >= right.nickname_get();
}

std::ostream& operator << (std::ostream &out, const Global_Character &in){

    Global_Character a = in;

    out << " " << a.nickname_get() << " ";

    return out;

}

bool operator <= (Global_Character &left, Global_Character &right){
    return left.nickname_get() <= right.nickname_get();
}

bool operator >= (Global_Character &left, Global_Character &right){
    return left.nickname_get() >= right.nickname_get();
}