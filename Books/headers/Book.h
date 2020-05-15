/**
 * 2nd Course K-29
 * Lab 1. Variant 2-10
 * Task: make a class that realise such tasks:
 *      1)gives the information about the book, author, date of wrote etc.
 *      2)gives the information about the main characters of the book, their importance etc.
 *      3)dividing the books on series
 *
 * Purpose: contains declarations of methods of the class Book.
 *
 *@author Vitaliy Datsiuk
 *@version 2 08/10/19
 */

#ifndef OOP_2ND_COURSE_1LAB_BOOK_H
#define OOP_2ND_COURSE_1LAB_BOOK_H

#include <string>
#include <vector>
#include "Date.h"
#include "Character.h"

using namespace std;

/**
 * Structure that contains the specific Book
 */
class Book {
private:
    string name;
    vector <string> author;
    Date release;
    int page_num;
    string annotation;
    vector <Character> characters;
public:
    /**
     * Default constructor
     */
    Book();

    /**
     * Sets the author
     *
     * @param in input string that would be the future author
     */
    void author_set(vector <string> in);

    /**
    * Sets the release date
    *
    * @param in input string that would be the future release
    */
    void release_set(Date in);

    /**
    * Sets the page_num
    *
    * @param in input string that would be the future page_num
    */
    void page_num_set(int in);

    /**
    * Sets the annotation
    *
    * @param in input string that would be the future annotation
    */
    void annotation_set(string in);

    /**
    * Sets the characters
    *
    * @param in input string that would be the future characters vector
    */
    void characters_set(vector <Character> in);

    /**
     * Returns the name
     *
     * @return name
     */
    string name_get();

    /**
    * Returns the author
    *
    * @return author
    */
    vector <string> author_get();

    /**
    * Returns the release
    *
    * @return release
    */
    Date release_get();

    /**
    * Returns the page_num
    *
    * @return page_num
    */
    int page_num_get();

    /**
    * Returns the annotation
    *
    * @return annotation
    */
    string annotation_get();

    /**
    * Returns the characters
    *
    * @return characters vectors
    */
    vector <Character> characters_get();

    /**
     * Sets the name
     *
     * @param in input string that would be the future name
     */
    void name_set(string in);

    /**
     * Allows to output the structure to the stream
     *
     * @param out Automatically defined stream
     * @param in The parameter that would be passed on the right of "<<"
     * @return Reference to the ostream, to allow continuous streaming
     */
    friend std::ostream& operator << (std::ostream &out, const Book &in);

    /**
     * Allows to get the answer of the operator "<="
    *
    * @param left  The parameter that would be passed on the left of the "<="
    * @param right The parameter that would be passed on the right of the "<="
    * @return The bool value that define the answer of the operator "<="
    */
    friend bool operator <= (Book &left, Book &right);

    /**
    * Allows to get the answer of the operator ">="
    *
    * @param left The parameter that would be passed on the left of the ">="
    * @param right The parameter that would be passed on the right of the ">="
    * @return The bool value that define the answer of the operator ">="
     */
    friend bool operator >= (Book &left, Book &right);

    /**
     * Created a book with input parameters of the user
     */
    void create_book();

    /**
     * Displays the authors on the screen
     */
    void display_authors();

    /**
     * Displays the characters on the screen
     */
    void display_characters();

    /**
     * Displays the full information of the book on the screen
     */
    void display_book_full();
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
    void new_book(string name, vector <string> author, Date release, int page_num, string annotation, vector <Character> characters);

};


#endif //OOP_2ND_COURSE_1LAB_BOOK_H
