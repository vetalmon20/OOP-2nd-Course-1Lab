/**
 * 2nd Course K-29
 * Lab 1. Variant 2-10
 * Task: make a class that realise such tasks:
 *      1)gives the information about the book, author, date of wrote etc.
 *      2)gives the information about the main characters of the book, their importance etc.
 *      3)dividing the books on series
 *
 * Purpose: contains methods of the class Character.
 *
 *@author Vitaliy Datsiuk
 *@version 2 08/10/19
 */

#include "..//Books/headers/Character.h"
#include <iostream>

using namespace std;

/**
 * Default constructor
 */
Character :: Character() {
    nickname = "";
    importance = 3;
    mention = "";
}

/**
 * Returns the nickname
 *
 * @return nickname
 */
string Character :: nickname_get() {
    return nickname;
}

/**
 * Sets the nickname
 *
 * @param in input string that would be the future nickname
 */
void Character :: nickname_set(string in) {
    nickname = in;
}

/**
 * Returns the importance
 *
 * @return importance
 */
int Character :: importance_get() {
    return importance;
}

/**
* Sets the importance
*
* @param in input int would be the future importance
*/
void Character :: importance_set(int in) {
    if (in > 3 || in <1){
        cout << "Wrong value of importance. Now the Character is episodable(3)";
        in = 3;
    }
    importance = in;
}

/**
 * Returns the mention
 *
 * @return mention
 */
string Character :: mention_get() {
    return mention;
}

/**
 * Sets the mentins
 *
 * @param in input string that would be the future mention
 */
void Character :: mention_set(string in) {
    mention = in;
}

/**
 * Creates an object of Character with the input parameters
 *
 * @param _nickname input string that would be the future nickname
 * @param _mentions input string that would be the future mentions
 * @param _importance input int that would be the future importance
 */
void Character :: new_character(string _nickname, string _mention, int _importance) {
    nickname_set(_nickname);
    mention_set(_mention);
    importance_set(_importance);
}

/**
 * Allows to output the structure to the stream
 *
 * @param out Automatically defined stream
 * @param in The parameter that would be passed on the right of "<<"
 * @return Reference to the ostream, to allow continuous streaming
 */
std::ostream& operator << (std::ostream &out, const Character &in){

    Character a = in;

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
bool operator <= (Character &left, Character &right){
    return left.nickname_get() <= right.nickname_get();
}

/**
 * Allows to get the answer of the operator ">="
 *
 * @param left The parameter that would be passed on the left of the ">="
 * @param right The parameter that would be passed on the right of the ">="
 * @return The bool value that define the answer of the operator ">="
 */
bool operator >= (Character &left, Character &right){
    return left.nickname_get() >= right.nickname_get();
}