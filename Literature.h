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
 * "Header"
 */

#ifndef OOP_2ND_COURSE_1LAB_LITERATURE_H
#define OOP_2ND_COURSE_1LAB_LITERATURE_H

#include "Book.h"
#include "Lists.h"

/*This structure is dedicated to save Books and Characters in comfortable way. It synchronise the
 * added characters and their mentions in other books. So using this structure You can find the
 * series for the appropriate character*/

struct Literature{
public:

    virtual void add_book(Book in) = 0;             //adds the book and the mentions for characters
    virtual void generate_Books() = 0;              //random generating of a Book
    virtual void find_series(string character) = 0; //finds the series for the character

    virtual void display_books() = 0;               //displays the books in literature
    virtual void display_characters() = 0;          //displays the characters in literature
};                       //Interface

struct Array_literature : Literature{
public:
    Arr_List <Global_Character> Characters;
    Arr_List <Book> Books;

    void add_book(Book in) override ;

    void generate_Books() override ;

    void find_series(string character) override ;

    virtual void display_books() override ;
    virtual void display_characters() override;
};    //Litearature based on Array_List

struct Linked_literature : Literature{
public:
    Linked_List <Global_Character> Characters;
    Linked_List <Book> Books;

    void add_book(Book in) override ;

    void generate_Books() override ;

    void find_series(string character) override ;

    virtual void display_books() override ;
    virtual void display_characters() override ;
};   //Literature based on Linked_list


#endif //OOP_2ND_COURSE_1LAB_LITERATURE_H
