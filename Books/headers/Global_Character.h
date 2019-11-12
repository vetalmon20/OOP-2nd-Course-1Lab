/**
 * 2nd Course K-29
 * Lab 1. Variant 2-10
 * Task: make a class that realise such tasks:
 *      1)gives the information about the book, author, date of wrote etc.
 *      2)gives the information about the main characters of the book, their importance etc.
 *      3)dividing the books on series
 *
 * Purpose: contains declarations of methods of the class Global_Character.
 *
 *@author Vitaliy Datsiuk
 *@version 2 08/10/19
 */

#ifndef OOP_2ND_COURSE_1LAB_GLOBAL_CHARACTER_H
#define OOP_2ND_COURSE_1LAB_GLOBAL_CHARACTER_H

#include <string>
#include <vector>

using namespace std;

/**
 * Structure that contains the specific character and all it's mentions in the books
 */
class Global_Character{
private:
    string nickname;
    vector<string> mentions;
    vector<int> importances;                //1- main; 2- secondary; 3 - episodable

public:
    /**
     * Default constructor
     */
    Global_Character();

    /**
    * Allows to output the structure to the stream
    *
    * @param out Automatically defined stream
    * @param in The parameter that would be passed on the right of "<<"
    * @return Reference to the ostream, to allow continuous streaming
    */
    friend std::ostream& operator << (std::ostream &out, const Global_Character &in);

    /**
     * Allows to get the answer of the operator "<="
    *
    * @param left  The parameter that would be passed on the left of the "<="
    * @param right The parameter that would be passed on the right of the "<="
    * @return The bool value that define the answer of the operator "<="
    */
    friend bool operator <= (Global_Character &left, Global_Character &right);

    /**
    * Allows to get the answer of the operator ">="
    *
    * @param left The parameter that would be passed on the left of the ">="
    * @param right The parameter that would be passed on the right of the ">="
    * @return The bool value that define the answer of the operator ">="
    */
    friend bool operator >= (Global_Character &left, Global_Character &right);

    /**
     * Returns the nickname
     *
     * @return nickname
     */
    string nickname_get();

    /**
    * Sets the nickname
    *
    * @param in input string that would be the future nickname
    */
    void nickname_set(string in);

    /**
    * Returns the vector of the mentions
    *
    * @return mentions
    */
    vector<string> mentions_get();

    /**
    * Returns the vector of the importances
    *
    * @return importances
    */
    vector<int> importances_get();

    /**
     * Adds the value in the end of the vector if importances
     *
     * @param in The value that would be added in the end of the vector if importances
     */
    void add_importance(int in);

    /**
     * Adds the value in the end of the vector if mentions
     *
     * @param in The value that would be added in the end of the vector if mentions
     */
    void add_mention(string in);

};


#endif //OOP_2ND_COURSE_1LAB_GLOBAL_CHARACTER_H
