/**
 * 2nd Course K-29
 * Lab 1. Variant 2-10
 * Task: make a structure of linked list and realise different sort algorithms
 *
 *@author Vitaliy Datsiuk
 *@version 2 08/10/19
 * "Header"
 */

#ifndef OOP_2ND_COURSE_1LAB_LISTS_H
#define OOP_2ND_COURSE_1LAB_LISTS_H


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


template <class T>
struct IList{
public:

    virtual void add_node(T val) = 0;

    virtual void generate() = 0;    //function that randomly generates the list of spec. data

    virtual void display() = 0;    //printing all the data from the list on the screen


    virtual void insertion_sort() = 0;
    virtual void quicksort() = 0; //just calls the recursive _quicksort function in private
    virtual void mergesort() = 0;

    //+* task
    virtual void selection_sort() = 0;

    //+* task
    //this sorting algorithm is valid only for the integers in [0,50)
    virtual void countingsort(int exp = 1 , int max_int = 50) = 0;

    //+* task
    //this sorting algorithm is valid only for the integers in [0,100)
    virtual void bucketsort() = 0;

    //+* task
    //this sorting algorithm is valid only for the integers in [0,100)
    //uses modificated countingsort!
    virtual void radixsort() = 0;
};                                   //Interface

template <class T>
struct Arr_List : IList <T> {
private:
    int curr_size;                //current size of the array
    int max_size;                 //allocated memory for the array
    void incr_size(int new_size); //allocates additional memory of *new_size* to an array

    void swap(int a, int b);      //swaps the data between indexes

    int get_max_int();
    void fill_array_0(int in[], int length);

    //utility function for quicksort that sorts the array relatively to the pivot(< or > than pivot)
    int partition_quicksort(int start, int finish);

    //actually quicksort
    void _quicksort(int start, int finish);

    //merges two arrays in one
    void  merge(int left, int middle, int right);
    //actually mergesort
    void _mergesort(int left, int right);

public:
    T *arr;
    Arr_List();

    //returns indexes
    int get_head();
    int get_tail();
    int get_curr_size();

    void add_node(T val) override ;

    void generate() override ;      //function that randomly generates the list of spec. data

    void display() override ;       //printing all the data from the list on the screen

    void insertion_sort() override ;
    void quicksort() override ;     //just calls the recursive _quicksort function in private
    void mergesort() override ;

    //+* task
    void selection_sort() override ;

    //+* task
    //this sorting algorithm is valid only for the integers in [0,50)
    void countingsort(int exp = 1, int max_int = 50) override ;

    //+* task
    //this sorting algorithm is valid only for the integers in [0,100)
    void bucketsort() override ;

    //+* task
    //this sorting algorithm is valid only for the integers in [0,100)
    //uses modificated countingsort!
    void radixsort() override ;
};                   //List based on the array

template <class T>
struct Linked_List : IList <T> {
private:

    Node <T> *head, *tail;                     //two pointers on the first and the last node
    int node_sum;                              //number of the nodes in list

    int get_max_int();

    //swaps the data between nodes
    void swap(Node <T> *a, Node <T> *b);

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
    Linked_List();

    Node <T>* get_tail();
    Node <T>* get_head();
    int get_node_sum();    //returns number of nodes

    void add_node(T val) override ;

    void generate() override;           //function that randomly generates the list of spec. data

    virtual void display() override;    //printing all the data from the list on the screen


    void insertion_sort() override;
    void quicksort() override; //just calls the recursive _quicksort function in private
    void mergesort() override;

    //+* task
    void selection_sort() override;

    //+* task
    //this sorting algorithm is valid only for the integers in [0,50)
    void countingsort(int exp = 1, int max_int = 50) override;

    //+* task
    //this sorting algorithm is valid only for the integers in [0,100)
    void bucketsort() override;

    //+* task
    //this sorting algorithm is valid only for the integers in [0,100)
    //uses modificated countingsort!
    void radixsort() override;

};                //List based on the Linked list

#endif //OOP_2ND_COURSE_1LAB_LISTS_H
