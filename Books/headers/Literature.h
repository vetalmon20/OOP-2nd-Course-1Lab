/**
 * 2nd Course K-29
 * Lab 1. Variant 2-10
 * Task: make a class that realise such tasks:
 *      1)gives the information about the book, author, date of wrote etc.
 *      2)gives the information about the main characters of the book, their importance etc.
 *      3)dividing the books on series
 *
 * Purpose:This structure is dedicated to save Books and Characters in comfortable way. It synchronise the
 *         added characters and their mentions in other books. So using this structure You can find the
 *         series for the appropriate character
 *
 *@author Vitaliy Datsiuk
 *@version 2 08/10/19
 *
 */

#ifndef OOP_2ND_COURSE_1LAB_LITERATURE_H
#define OOP_2ND_COURSE_1LAB_LITERATURE_H

#include "Book.h"
#include "Lists.h"
#include "Global_Character.h"

/**
 * Interface structure for the Literature structure
 */
struct Literature{
public:

    /**
     * Virtual function that adds the book to the Literature
     *
     * @param in Book that would be added to the Literature
     */
    virtual void add_book(Book in) = 0;             //adds the book and the mentions for characters

    /**
     * Virtual function that generates a random List of the Books
     */
    virtual void generate_Books() = 0;              //random generating of a Book

    /**
     * Virtual function that finds the series for the input character
     *
     * @param character For this character the series would be found
     */
    virtual void find_series(string character) = 0; //finds the series for the character

    /**
     * Virtual function that displays all of the books on the screen
     */
    virtual void display_books() = 0;               //displays the books in literature

    /**
     * Virtual function that displays all of the characters on the screen
     */
    virtual void display_characters() = 0;          //displays the characters in literature

    /**
     * Virtual function that pops the last book
     */
    virtual void pop_book() = 0;

    /**
     * Sorts the books by data
     */
    virtual void sort_books() = 0;
};                       //Interface

/**
 * Literature structure that is based on the Linked List
 */
struct Array_literature : Literature{
public:
    Arr_List <Global_Character> Characters;
    Arr_List <Book> Books;

    /**
     * Adds the book to the Literature
     *
     * @param in Book that would be added to the Literature
     */
    void add_book(Book in) override ;

    /**
    * Function that generates a random List of the Books
    */
    void generate_Books() override ;

    /**
    * Function that finds the series for the input character
    *
    * @param character For this character the series would be found
    */
    void find_series(string character) override ;

    /**
    * Function that displays all of the books on the screen
    */
    void display_books() override;

    /**
    * Function that displays all of the characters on the screen
    */
    void display_characters() override;

    /**
     * Pops the last book
     */
    void pop_book() override ;

    /**
     * Sorts the books by data
     */
    void sort_books() override ;
};    //Litearature based on Array_List

struct Linked_literature : Literature{
public:
    Linked_List <Global_Character> Characters;
    Linked_List <Book> Books;

    /**
    * Adds the book to the Literature
    *
    * @param in Book that would be added to the Literature
    */
    void add_book(Book in) override ;

    /**
    * Function that generates a random List of the Books
    */
    void generate_Books() override ;

    /**
    * Function that finds the series for the input character
    *
    * @param character For this character the series would be found
    */
    void find_series(string character) override ;

    /**
    * Function that displays all of the books on the screen
    */
    void display_books() override ;

    /**
    * Function that displays all of the characters on the screen
    */
    void display_characters() override ;

    /**
     * Pops the last book
     */
    void pop_book() override ;

    /**
     * Sorts the books by data
     */
    void sort_books() override ;
};

/**
 * Literature structure that is based on the Vector List
 */
struct Vector_literature : Literature {
public:
    Vector_List <Global_Character> Characters;
    Vector_List <Book> Books;

    /**
    * Adds the book to the Literature
    *
    * @param in Book that would be added to the Literature
    */
    void add_book(Book in) override ;

    /**
    * Function that generates a random List of the Books
    */
    void generate_Books() override ;

    /**
    * Function that finds the series for the input character
    *
    * @param character For this character the series would be found
    */
    void find_series(string character) override ;

    /**
    * Function that displays all of the books on the screen
    */
    void display_books() override ;

    /**
    * Function that displays all of the characters on the screen
    */
    void display_characters() override ;

    /**
     * Pops the last book
     */
    void pop_book() override ;

    /**
     * Sorts the books by data
     */
    void sort_books() override ;
};

#endif //OOP_2ND_COURSE_1LAB_LITERATURE_H
