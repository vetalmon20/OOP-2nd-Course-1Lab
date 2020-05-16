/**
 * 2nd Course K-29
 * Lab 1. Variant 2-10
 * Task: make a class that realise such tasks:
 *      1)gives the information about the book, author, date of wrote etc.
 *      2)gives the information about the main characters of the book, their importance etc.
 *      3)dividing the books on series
 *
 * Purpose: contains methods of the class Date.
 *
 *@author Vitaliy Datsiuk
 *@version 2 08/10/19
 */

#include "..//Books/headers/Date.h"

/**
 * Default constructor
 */
Date :: Date() {
    year = 0;
    month = 0;
    day = 0;
}

std::string Date::to_str()
{
    std::string output;
    output = std::to_string(day);
    output += '.';
    output += std::to_string(month);
    output += '.';
    output += std::to_string(year);
    return output;
}
