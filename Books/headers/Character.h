/**
 * 2nd Course K-29
 * Lab 1. Variant 2-10
 * Task: make a class that realise such tasks:
 *      1)gives the information about the book, author, date of wrote etc.
 *      2)gives the information about the main characters of the book, their importance etc.
 *      3)dividing the books on series
 *
 * Purpose: contains declarations of methods of the class Character.
 *
 *@author Vitaliy Datsiuk
 *@version 2 08/10/19
 */

#ifndef OOP_2ND_COURSE_1LAB_CHARACTER_H
#define OOP_2ND_COURSE_1LAB_CHARACTER_H

#include <string>

using namespace std;

/**
 * Structure that saves the specific character in specific book
 */
class Character{
private:
    string nickname;
    string mention;
    int importance;                //1- main; 2- secondary; 3 - episodable
public:
    /**
    * Default constructor
    */
    Character();

    /**
     * Allows to output the structure to the stream
     *
     * @param out Automatically defined stream
     * @param in The parameter that would be passed on the right of "<<"
     * @return Reference to the ostream, to allow continuous streaming
     */
    friend std::ostream& operator << (std::ostream &out, const Character &in);

    /**
     * Allows to get the answer of the operator "<="
     *
     * @param left  The parameter that would be passed on the left of the "<="
     * @param right The parameter that would be passed on the right of the "<="
     * @return The bool value that define the answer of the operator "<="
     */
    friend bool operator <= (Character &left, Character &right);

    /**
     * Allows to get the answer of the operator ">="
     *
     * @param left The parameter that would be passed on the left of the ">="
     * @param right The parameter that would be passed on the right of the ">="
     * @return The bool value that define the answer of the operator ">="
     */
    friend bool operator >= (Character &left, Character &right);

    /**
     * Sets the nickname
     *
     * @param in input string that would be the future nickname
     */
    void nickname_set(string in);

    /**
    * Sets the mentins
    *
    * @param in input string that would be the future mention
    */
    void mention_set(string in);

    /**
    * Sets the importance
    *
    * @param in input int that would be the future importance
    */
    void importance_set(int in);

    /**
     * Returns the nickname
     *
     * @return nickname
     */
    string nickname_get();

    /**
    * Returns the mention
    *
    * @return mention
    */
    string mention_get();

    /**
    * Returns the importance
    *
    * @return importance
    */
    int importance_get();
    /**
     * Creates an object of Character with the input parameters
     *
     * @param _nickname input string that would be the future nickname
     * @param _mentions input string that would be the future mentions
     * @param _importance input int that would be the future importance
     */
    void new_character(string _nickname, string _mentions,int _importance);
};


#endif //OOP_2ND_COURSE_1LAB_CHARACTER_H
