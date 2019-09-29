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

#ifndef OOP_2ND_COURSE_1LAB_LITERATURE_H
#define OOP_2ND_COURSE_1LAB_LITERATURE_H

#include "Book.h"
#include "Linked_List.h"

template <class T>
class Literature {
public:
    List <Global_Character> Characters;
    List <Book> Books;

    void add_book(Book in);

    void generate_Books();

    void find_series(string character);
};


#endif //OOP_2ND_COURSE_1LAB_LITERATURE_H
