/**
 * 2nd Course K-29
 * Lab 1. Variant 2-10
 * Task: make a structure of linked list and realise different sort algorithms
 *
 * Purpose: the main demo function that are shown to the user
 *
 *@author Vitaliy Datsiuk
 *@version 2 05/11/19
 */


#include <iostream>
#include "Literature.h"

using namespace std;

inline void demo(){

    IList<int> *int_ptr;
    Arr_List<int> int_l1;
    Linked_List<int> int_l2;
    Vector_List<int> int_l3;
    IList<float> *float_ptr;
    Arr_List<float> float_l1;
    Linked_List<float> float_l2;
    Vector_List<float> float_l3;
    IList<char> *char_ptr;
    Arr_List<char> char_l1;
    Linked_List<char> char_l2;
    Vector_List<char> char_l3;
    IList<string> *string_ptr;
    Arr_List<string> string_l1;
    Linked_List<string> string_l2;
    Vector_List<string> string_l3;
    IList<Book> *book_ptr;
    Arr_List<Book> book_l1;
    Linked_List<Book> book_l2;
    Vector_List<Book> book_l3;


    bool created = 0;
    cout << "Welcome to the program" << endl;
    cout << "What do You want to do?" << endl;
    cout << "1 - Generate a List" << endl;
    cout << "2 - Add node to the list" << endl;
    cout << "3 - Delete the last element from the list" << endl;
    cout << "4 - Print the list" << endl;
    cout << "5 - Sort the list" << endl;
    cout << "0 - exit" << endl;
    int variant = -1;
    int type = -1;
    int temp = -1;
    while (1){

        cin >> temp;

        while (1) {
            if (temp < 1 || temp > 6)
                cout << "Wrong input. Try again" << endl;
            else
                break;
        }
        switch(temp){
            case 1:{
                if (created == 0) {

                    created = 1;
                    cout << "Choose a type of data to create a list of:" << endl;
                    cout << "1 - int" << endl;
                    cout << "2 - float" << endl;
                    cout << "3 - char" << endl;
                    cout << "4 - string" << endl;
                    cout << "5 - Books" << endl;

                    cin >> variant;
                    while (1) {
                        if (variant < 1 || variant > 4)
                            cout << "Wrong input. Try again" << endl;
                        else
                            break;
                    }

                    cout << "Choose a type of list:" << endl;
                    cout << "1 - Array list" << endl;
                    cout << "2 - Linked list" << endl;
                    cout << "3 - Vector list" << endl;

                    cin >> type;
                    while (1) {
                        if (type < 1 || type > 3)
                            cout << "Wrong input. Try again" << endl;
                        else
                            break;
                    }

                    switch(variant){
                        case 1:{    //int
                            int_l1.generate();
                            int_l2.generate();
                            int_l3.generate();
                            if(type == 1)
                                int_ptr = &int_l1;
                            else
                                if(type == 2)
                                    int_ptr = &int_l2;
                                else
                                    int_ptr = &int_l3;
                            break;
                        }
                        case 2:{    //float
                            if(type == 1)
                                float_ptr = &float_l1;
                            else
                            if(type == 2)
                                float_ptr = &float_l2;
                            else
                                float_ptr = &float_l3;
                            float_ptr->generate();
                            break;
                        }
                        case 3:{    //char
                            if(type == 1)
                                char_ptr = &char_l1;
                            else
                            if(type == 2)
                                char_ptr = &char_l2;
                            else
                                char_ptr = &char_l3;
                            char_ptr->generate();
                            break;
                        }
                        case 4:{    //string
                            if(type == 1)
                                string_ptr = &string_l1;
                            else
                            if(type == 2)
                                string_ptr = &string_l2;
                            else
                                string_ptr = &string_l3;
                            string_ptr->generate();
                            break;
                        }
                        case 5:{    //Book
                            if(type == 1)
                                book_ptr = &book_l1;
                            else
                            if(type == 2)
                                book_ptr = &book_l2;
                            else
                                book_ptr = &book_l3;
                            book_ptr->generate();
                            break;
                        }
                    }
                } else {
                    cout << "The list is already created" << endl;
                }
                break;
            }
            case 2:{
                if(created == 0){
                    cout << "There is no list" << endl;
                    break;
                }
                switch (variant){
                    case 1:{
                        int temp;
                        cout << "Enter the value" << endl;
                        cin >> temp;
                        int_ptr->add_node(temp);
                        break;
                    }
                    case 2:{
                        float temp;
                        cout << "Enter the value" << endl;
                        cin >> temp;
                        float_ptr->add_node(temp);
                        break;
                    }
                    case 3:{
                        char temp;
                        cout << "Enter the value" << endl;
                        cin >> temp;
                        char_ptr->add_node(temp);
                        break;
                    }
                    case 4:{
                        string temp;
                        cout << "Enter the value" << endl;
                        cin >> temp;
                        string_ptr->add_node(temp);
                        break;
                    }
                    case 5:{
                        Book temp;
                        cout << "Enter the value" << endl;
                        temp.create_book();
                        book_ptr->add_node(temp);
                        break;
                    }
                }
                break;
            }
            case 3:{
                if(created == 0){
                    cout << "There is no list" << endl;
                    break;
                }
                switch (variant){
                    case 1:{
                        int_ptr->pop_node();
                        break;
                    }
                    case 2:{
                        float_ptr->pop_node();
                        break;
                    }
                    case 3:{
                        char_ptr->pop_node();
                        break;
                    }
                    case 4:{
                        string_ptr->pop_node();
                        break;
                    }
                    case 5:{
                        book_ptr->pop_node();
                        break;
                    }
                }
                break;
            }
            case 4:{
                if(created == 0){
                    cout << "There is no list" << endl;
                    break;
                }
                switch (variant){
                    case 1:{
                        int_ptr->display();
                        break;
                    }
                    case 2:{
                        float_ptr->display();
                        break;
                    }
                    case 3:{
                        char_ptr->display();
                        break;
                    }
                    case 4:{
                        string_ptr->display();
                        break;
                    }
                    case 5:{
                        book_ptr->display();
                        break;
                    }
                }
                break;
            }
            case 5:{
                if(created == 0){
                    cout << "There is no list" << endl;
                    break;
                }
                switch (variant){
                    case 1:{
                        int_ptr->quicksort();
                        break;
                    }
                    case 2:{
                        float_ptr->quicksort();
                        break;
                    }
                    case 3:{
                        char_ptr->quicksort();
                        break;
                    }
                    case 4:{
                        string_ptr->quicksort();
                        break;
                    }
                    case 5:{
                        book_ptr->quicksort();
                        break;
                    }
                }
            }
            case 0:{
                return;
            }
        }
        cout << "What do You want to do?" << endl;
    }



/*    cout << "1 - Linked List" << endl;
    cout << "2 - Array List" << endl;
    cout << "3 - Vector List" << endl;*/

}