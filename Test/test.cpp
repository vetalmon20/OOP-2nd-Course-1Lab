/**
 * 2nd Course K-29
 * Lab 1. Variant 2-10
 *
 * Purpose : Test file that contains all of the test modules for different type of data and lists.
 *
 *@author Vitaliy Datsiuk
 *@version 2 08/10/19
 */

#include <iostream>
#include "Lists.cpp"
#include "..//Books/sources/Literature.cpp"
#include <vector>

using namespace std;

/**
 * Tests the list for int
 */
inline void list_test_int() {

    int temp;
    IList<int> *ptr;
    Linked_List<int> test1;
    Arr_List<int> test2;
    Vector_List<int> test3;

    cout << "Choose the type of List: 1 - Linked List; 2 - Array List; 3 - Vector List" << endl;
    cin >> temp;
    if (temp != 1 && temp != 2 && temp != 3) {
        cout << "Wrong value" << endl;
        return;
    }

    if (temp == 1)
        ptr = &test1;
    else
        if(temp == 2)
            ptr = &test2;
        else
            ptr = &test3;

    if(temp == 1)
        cout << "Test for the Linked_List<int>" << endl;
    else
        if(temp == 2)
            cout << "Test for the Array_List<int>" << endl;
        else
            cout << "Test for the Vector_List<int>" << endl;

    ptr->generate();
    cout << "Random array:";
    ptr->display();
    cout << "Using quicksort:";
    ptr->quicksort();
    ptr->display();
    cout << "Random array:";
    ptr->generate();
    ptr->display();
    cout << "Using mergesort:";
    ptr->mergesort();
    ptr->display();
    cout << "Random array:";
    ptr->generate();
    ptr->display();
    cout << "Using insertion sort:";
    ptr->insertion_sort();
    ptr->display();
    cout << "Random array:";
    ptr->generate();
    ptr->display();
    cout << "Using selection sort:";
    ptr->selection_sort();
    ptr->display();
    cout << "Random array:";
    ptr->generate();
    ptr->display();
    cout << "Using counting sort:";
    ptr->countingsort();
    ptr->display();
    cout << "Random array:";
    ptr->generate();
    ptr->display();
    cout << "Using bucketsort:";
    ptr->bucketsort();
    ptr->display();
    cout << "Random array:";
    ptr->generate();
    ptr->display();
    cout << "Using radix sort:";
    ptr->radixsort();
    ptr->display();

    cout << "--------------------" << endl;
}

/**
 * Tests the list for float
 */
inline void list_test_float(){

    int temp;
    IList<float> *ptr;
    Linked_List<float> test1;
    Arr_List<float> test2;
    Vector_List<float> test3;

    cout << "Choose the type of List: 1 - Linked List; 2 - Array List; 3 - Vector List" << endl;
    cin >> temp;
    if (temp != 1 && temp != 2 && temp != 3) {
        cout << "Wrong value" << endl;
        return;
    }

    if (temp == 1)
        ptr = &test1;
    else
        if(temp == 2)
             ptr = &test2;
        else
             ptr = &test3;


    if(temp == 1)
        cout << "Test for the Linked_List<float>" << endl;
    else
        if(temp == 2)
            cout << "Test for the Array_List<float>" << endl;
        else
            cout << "Test for the Vector_List<float>" << endl;

    ptr->generate();
    cout << "Random array:";
    ptr->display();
    cout << "Using quicksort:";
    ptr->quicksort();
    ptr->display();
    cout << "Random array:";
    ptr->generate();
    ptr->display();
    cout << "Using mergesort:";
    ptr->mergesort();
    ptr->display();
    cout << "Random array:";
    ptr->generate();
    ptr->display();
    cout << "Using insertion sort:";
    ptr->insertion_sort();
    ptr->display();
    cout << "Random array:";
    ptr->generate();
    ptr->display();
    cout << "Using selection sort:";
    ptr->selection_sort();
    ptr->display();
    cout << "--------------------" << endl;
}

/**
 * Tests the list for char
 */
inline void list_test_char(){


    int temp;
    IList<char> *ptr;
    Linked_List<char> test1;
    Arr_List<char> test2;
    Vector_List<char> test3;

    cout << "Choose the type of List: 1 - Linked List; 2 - Array List; 3 - Vector List" << endl;
    cin >> temp;
    if (temp != 1 && temp != 2 && temp != 3) {
        cout << "Wrong value" << endl;
        return;
    }

    if (temp == 1)
        ptr = &test1;
    else
        if(temp == 2)
            ptr = &test2;
        else
            ptr = &test3;

    if(temp == 1)
        cout << "Test for the Linked_List<char>" << endl;
    else
        if(temp == 2)
            cout << "Test for the Array_List<char>" << endl;
        else
            cout << "Test for the Vector_List<char>" << endl;

    ptr->generate();
    cout << "Random array:";
    ptr->display();
    cout << "Using quicksort:";
    ptr->quicksort();
    ptr->display();
    cout << "Random array:";
    ptr->generate();
    ptr->display();
    cout << "Using mergesort:";
    ptr->mergesort();
    ptr->display();
    cout << "Random array:";
    ptr->generate();
    ptr->display();
    cout << "Using insertion sort:";
    ptr->insertion_sort();
    ptr->display();
    cout << "Random array:";
    ptr->generate();
    ptr->display();
    cout << "Using selection sort:";
    ptr->selection_sort();
    ptr->display();
    cout << "--------------------" << endl;
}

/**
 * Tests the list for string
 */
inline void list_test_string(){

    int temp;
    IList<string> *ptr;
    Linked_List<string> test1;
    Arr_List<string> test2;
    Vector_List<string> test3;

    cout << "Choose the type of List: 1 - Linked List; 2 - Array List; 3 - Vector List" << endl;
    cin >> temp;
    if (temp != 1 && temp != 2 && temp != 3) {
        cout << "Wrong value" << endl;
        return;
    }

    if (temp == 1)
        ptr = &test1;
    else
        if(temp == 2)
             ptr = &test2;
        else
             ptr = &test3;

    if(temp == 1)
        cout << "Test for the Linked_List<string>" << endl;
    else
    if(temp == 2)
        cout << "Test for the Array_List<string>" << endl;
    else
        cout << "Test for the Vector_List<string>" << endl;

    ptr->generate();
    cout << "Random array:";
    ptr->display();
    cout << "Using quicksort:";
    ptr->quicksort();
    ptr->display();
    cout << "Random array:";
    ptr->generate();
    ptr->display();
    cout << "Using mergesort:";
    ptr->mergesort();
    ptr->display();
    cout << "Random array:";
    ptr->generate();
    ptr->display();
    cout << "Using insertion sort:";
    ptr->insertion_sort();
    ptr->display();
    cout << "Random array:";
    ptr->generate();
    ptr->display();
    cout << "Using selection sort:";
    ptr->selection_sort();
    ptr->display();
    cout << "--------------------" << endl;
}

/**
 * Tests the list for book structure
 */
inline void list_test_book(){

    int temp;

    cout << "Choose the type of List: 1 - Linked List; 2 - Array List; 3 - Vector List" << endl;
    cin >> temp;
    if (temp != 1 && temp != 2 && temp != 3) {
        cout << "Wrong value" << endl;
        return;
    }

    Book B1,B2,B3,B4;
    vector <string> auth1;
    auth1.push_back("Igor");auth1.push_back("OLya");
    Date D1; D1.month = 1; D1.day = 10; D1.year = 2000;
    Character Batman1,Batman2,Batman3, Superman,Superman2, Harry, Kenny,Mohr;
    Batman3.new_character("Batman","Mention2",3);
    Batman2.new_character("Batman","Mention3",2);
    Batman1.new_character("Batman","Book_1",1);
    Superman.new_character("Superman","Mention",1);
    Superman2.new_character("Superman","Mention",2);
    Harry.new_character("Harry","Mention",3);
    Kenny.new_character("Kenny","Mention",1);
    Mohr.new_character("Mohr","Mention",1);
    vector<Character> CH1; CH1.push_back(Batman1);CH1.push_back(Superman);
    vector<Character> CH2; CH2.push_back(Batman2);CH2.push_back(Superman2);
    vector<Character> CH3; CH3.push_back(Batman3);CH3.push_back(Kenny);
    vector<Character> CH4; CH4.push_back(Batman1);CH4.push_back(Mohr);
    B1.new_book("Simple_city",auth1,D1,111,"Annotation1",CH1);
    D1.month = 9;
    B2.new_book("The Great Gatsby",auth1,D1,111,"Annotation2",CH2);
    D1.day = 11;
    B3.new_book("Don Quixote",auth1,D1,111,"Annotation3",CH3);
    D1.year=1111;
    B4.new_book("Moby Dick",auth1,D1,111,"Annotation4",CH4);

    IList<Book> *ptr;
    Linked_List<Book> test1;
    Arr_List<Book> test2;
    Vector_List<Book> test3;

    if (temp == 1)
        ptr = &test1;
    else
         if(temp == 2)
            ptr = &test2;
         else
             ptr = &test3;

    if(temp == 1)
        cout << "Test for the Linked_List<Book>" << endl;
    else
        if(temp == 2)
             cout << "Test for the Array_List<Book>" << endl;
        else
             cout << "Test for the Vector_List<Book>" << endl;

    ptr->add_node(B1);
    ptr->add_node(B2);
    ptr->add_node(B3);
    ptr->add_node(B4);
    ptr->display();
    cout << "Using quicksort:" << endl;
    ptr->quicksort();
    ptr->display();
    cout << endl;
}

/**
 * Tests the list for literature structure
 */
inline void literature_test(){

    int temp;

    cout << "Choose the type of List: 1 - Linked List; 2 - Array List; 3 - Vector List" << endl;
    cin >> temp;
    if (temp != 1 && temp != 2) {
        cout << "Wrong value" << endl;
        return;
    }

    Literature *ptr;
    Linked_literature test1;
    Array_literature test2;
    //Vector_Literature test3;

    if (temp == 1)
        ptr = &test1;
    else
        if(temp == 2)
             ptr = &test2;
/*        else
             ptr = &test3;*/

    if(temp == 1)
        cout << "Test for the Literature based on Linked_List" << endl;
    else
        cout << "Test for the Literature based on Array_List" << endl;

    ptr->generate_Books();

    cout << "There are such characters in the literature:" << endl;
    ptr->display_characters();
    cout << "There are such books in the literature:" << endl;
    ptr->display_books();
    ptr->find_series("Batman");
    cout << endl;
}
