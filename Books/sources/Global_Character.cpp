/**
 * 2nd Course K-29
 * Lab 1. Variant 2-10
 * Task: make a class that realise such tasks:
 *      1)gives the information about the book, author, date of wrote etc.
 *      2)gives the information about the main characters of the book, their importance etc.
 *      3)dividing the books on series
 *
 * Purpose: contains methods of the class Global_Character.
 *
 *@author Vitaliy Datsiuk
 *@version 2 08/10/19
 */

#include "..//Books/headers/Global_Character.h"
#include <iostream>

/**
 * Default constructor
 */
Global_Character :: Global_Character(){
    nickname = "";
}

/**
 * Returns the nickname
 *
 * @return nickname
 */
string Global_Character :: nickname_get() {
    return nickname;
}

/**
* Sets the nickname
*
* @param in input string that would be the future nickname
*/
void Global_Character :: nickname_set(string in) {
    nickname = in;
}

/**
* Returns the vector of the mentions
*
* @return mentions
*/
vector<string> Global_Character :: mentions_get() {
    return mentions;
}

/**
* Returns the vector of the importances
*
* @return importances
*/
vector<int> Global_Character :: importances_get(){
    return importances;
}

/**
 * Adds the value in the end of the vector if importances
 *
 * @param in The value that would be added in the end of the vector if importances
 */
void Global_Character :: add_importance(int in) {
    importances.push_back(in);
}

/**
 * Adds the value in the end of the vector if mentions
 *
 * @param in The value that would be added in the end of the vector if mentions
 */
void Global_Character :: add_mention(string in) {
    mentions.push_back(in);
}

/**
* Allows to output the structure to the stream
*
* @param out Automatically defined stream
* @param in The parameter that would be passed on the right of "<<"
* @return Reference to the ostream, to allow continuous streaming
*/
std::ostream& operator << (std::ostream &out, const Global_Character &in){

    Global_Character a = in;

    out << " " << a.nickname_get() << " ";

    return out;
}

/**
 * Allows to get the answer of the operator "<="
*
* @param left  The parameter that would be passed on the left of the "<="
* @param right The parameter that would be passed on the right of the "<="
* @return The bool value that define the answer of the operator "<="
*/
bool operator <= (Global_Character &left, Global_Character &right){
    return left.nickname_get() <= right.nickname_get();
}

/**
* Allows to get the answer of the operator ">="
*
* @param left The parameter that would be passed on the left of the ">="
* @param right The parameter that would be passed on the right of the ">="
* @return The bool value that define the answer of the operator ">="
*/
bool operator >= (Global_Character &left, Global_Character &right){
    return left.nickname_get() >= right.nickname_get();
}