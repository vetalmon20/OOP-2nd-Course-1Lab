/**
 * 2nd Course K-29
 * Lab 1. Variant 2-10
 * Task: make a class that realise such tasks:
 *      1)gives the information about the book, author, date of wrote etc.
 *      2)gives the information about the main characters of the book, their importance etc.
 *      3)dividing the books on series
 *
 * Purpose: contains methods of the class Book.
 *
 *@author Vitaliy Datsiuk
 *@version 2 08/10/19
 */

#include <iostream>
#include "..//Books/headers/Book.h"

using namespace std;

/**
 * Default constructor
 */
Book :: Book() {
    name = "";
    page_num = 0;
    annotation = "";

}

/**
 * Returns the name
 *
 * @return name
 */
string Book :: name_get() {

    return name;
}

/**
 * Sets the name
 *
 * @param in input string that would be the future name
 */
void Book :: name_set(string in) {
    name = in;
}

/**
* Returns the author
*
* @return author
*/
vector <string> Book :: author_get() {
    return author;
}

/**
 * Sets the author
 *
 * @param in input string that would be the future author
 */
void Book :: author_set(vector <string> in) {
    author = in;
}

/**
* Returns the annotation
*
* @return annotation
*/
string Book :: annotation_get() {
    return annotation;
}

/**
* Sets the annotation
*
* @param in input string that would be the future annotation
*/
void Book :: annotation_set(string in) {
    annotation = in;
}

/**
* Returns the page_num
*
* @return page_num
*/
int Book :: page_num_get() {
    return page_num;
}

/**
* Sets the page_num
*
* @param in input string that would be the future page_num
*/
void Book :: page_num_set(int in) {
    page_num = in;
}

/**
* Returns the characters
*
* @return characters vectors
*/
vector <Character> Book :: characters_get() {
    return characters;
}

/**
* Sets the characters
*
* @param in input string that would be the future characters vector
*/
void Book :: characters_set(vector <Character> in) {
    characters = in;
}

/**
* Returns the release
*
* @return release
*/
Date Book :: release_get() {
    return release;
}

/**
* Sets the release date
*
* @param in input string that would be the future release
*/
void Book :: release_set(Date in) {
    release.year = in.year;
    release.day = in.day;
    release.month = in.month;
}

/**
 * Creates an object of Book with the input parameters
 *
 * @param name input string that would be the future name
 * @param author input vector of string that would be the future author
 * @param release input Date that would be the future release
 * @param page_num input int that would be the future page_num
 * @param annotation input string that would be the future annotation
 * @param characters input vector of Characters that would be the future characters
 */
void Book :: new_book(string name, vector <string> author, Date release, int page_num, string annotation, vector <Character> characters) {
    name_set(name);
    author_set(author);
    release_set(release);
    page_num_set(page_num);
    annotation_set(annotation);
    characters_set(characters);
}

/**
 * Displays the authors on the screen
 */
void Book :: display_authors() {

    for (int i = 0; i < author.size(); i++)
        cout << author[i] << " ";
}

/**
 * Displays the characters on the screen
 */
void Book :: display_characters() {

    for (int i = 0; i < characters.size(); i++)
        cout << characters[i].nickname_get() << " ";
}

/**
 * Displays the full information of the book on the screen
 */
void Book :: display_book_full() {
    cout << "Name: "<< name_get() << "; Date: " << release_get().year << "/" << release_get().month;
    cout << "/" << release_get().day << "; Pages: " << page_num_get() << "; Characters: ";
    display_characters();
    cout << "; Author(s): ";
    display_authors();
    cout << "; Annotation: " << annotation_get() << endl;
}

/**
 * Allows to output the structure to the stream
 *
 * @param out Automatically defined stream
 * @param in The parameter that would be passed on the right of "<<"
 * @return Reference to the ostream, to allow continuous streaming
 */
std::ostream& operator << (std::ostream &out, const Book &in)
{
    Book a = in;

    out << "Name: " << a.name_get() << " Year:" << a.release_get().year << " " <<endl;

    return out;
}

/**
 * Allows to get the answer of the operator "<="
*
* @param left  The parameter that would be passed on the left of the "<="
* @param right The parameter that would be passed on the right of the "<="
* @return The bool value that define the answer of the operator "<="
*/
bool operator <= (Book &left, Book &right){
    if(left.release_get().year != right.release_get().year)
        return left.release_get().year <= right.release_get().year;
    if(left.release_get().month != right.release_get().month)
        return left.release_get().month <= right.release_get().month;

    return left.release_get().day <= right.release_get().day;
}

/**
* Allows to get the answer of the operator ">="
*
* @param left The parameter that would be passed on the left of the ">="
* @param right The parameter that would be passed on the right of the ">="
* @return The bool value that define the answer of the operator ">="
 */
bool operator >= (Book &left, Book &right){
    if (left.release_get().year != right.release_get().year)
    return left.release_get().year >= right.release_get().year;

    if(left.release_get().month != right.release_get().month)
        return left.release_get().month >= right.release_get().month;

    return left.release_get().day >= right.release_get().day;

}