/**
 * 2nd Course K-29
 * Lab 1. Variant 2-10
 * Task: make a class that realise such tasks:
 *      1)gives the information about the book, author, date of wrote etc.
 *      2)gives the information about the main characters of the book, their importance etc.
 *      3)dividing the books on series
 *
 * Purpose: contains declarations of methods of the class date.
 *
 *@author Vitaliy Datsiuk
 *@version 2 08/10/19
 */

#ifndef OOP_2ND_COURSE_1LAB_DATE_H
#define OOP_2ND_COURSE_1LAB_DATE_H


/**
 * This structure used to show and save the Date. Used in Book structure. Variables are public for the comfort access.
 */
class Date {
public:
    /**
    * Default constructor
    */
    Date();

    int year;
    int month;
    int day;
};

#endif //OOP_2ND_COURSE_1LAB_DATE_H
