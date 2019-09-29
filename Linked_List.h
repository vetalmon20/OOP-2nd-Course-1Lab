/**
 * 2nd Course K-29
 * Lab 1. Variant 2-10
 * Task: make a structure of linked list and realise different sort algorithms
 *
 *@author Vitaliy Datsiuk
 *@version 1.5 30/09/19
 * "Header"
 */

#ifndef OOP_2ND_COURSE_1LAB_LINKED_LIST_H
#define OOP_2ND_COURSE_1LAB_LINKED_LIST_H


#include <string>
#include "Book.h"

using namespace std;

//+* TASK


//Structure of the Node used in structure of the Linked List
template <class T>
struct Node{
    T data;             //Data that can contain and type of data
    Node* next;         //Pointer on the next element
    Node* prev;         //Pointer on the previous element
};

//Structure of the Linked list
template <class T>
class List {
private:

    Node <T> *head, *tail;                     //two pointers on the first and the last node
    int node_sum;                              //number of the nodes in list

    //swaps the data between nodes
    void swap(Node <T> *a, Node <T> *b);

    //next 3 functions generates the list of the following type
    void generate_int();
    void generate_double();
    void generate_char();

    //utility function for quicksort that sorts the array relatively to the pivot(< or > than pivot)
    Node <T>* partition_quicksort(Node <T>* start, Node <T>* finish);

    //actually quicksort
    void _quicksort(Node <T>* start, Node <T>* finish);

    //splits the list on two halves. Used in mergesort.
    void listsplit_mergesort(Node <T> *start, Node <T> **first, Node <T> **second);

    //merges two lists and returns the pointer on the head of the merged (final) list
    Node <T> *merge(Node <T> *first, Node <T> *second);

    //actually mergesort
    void _mergesort(Node <T> **source);

    //utility function for countingsort that fill the input array with 0
    void fill_array_0(int in[], int length);

public:
    List();

    Node <T>* get_tail();
    Node <T>* get_head();
    int get_node_sum();    //returns number of nodes
    int get_max_int();

    void add_node(T val);

    void generate_basic();    //function that randomly generates the list of basic type of data
    void generate_string();   //function that randomly generates the list of random strings

    virtual void display(Node <T> *start);    //printing all the data from the list on the screen


    void insertion_sort();//just calls the recursive _quicksort function in private
    void quicksort(); //just calls the recursive _quicksort function in private
    void mergesort();

    //+* task
    void selection_sort();

    //+* task
    //this sorting algorithm is valid only for the integers in [0,50)
    void countingsort(int exp = 1, int max_int = 50);

    //+* task
    //this sorting algorithm is valid only for the integers in [0,100)
    void bucketsort();

    //+* task
    //this sorting algorithm is valid only for the integers in [0,100)
    //uses modificated countingsort!
    void radixsort();

};

#endif //OOP_2ND_COURSE_1LAB_LINKED_LIST_H
