/**
 * 2nd Course K-29
 * Lab 1. Variant 2-10
 * Task: make a structure of linked list and realise different sort algorithms
 *
 * Purpose: contains declarations of the list interface and two lists that are based on the linked list and the array
 *          list.
 *
 *@author Vitaliy Datsiuk
 *@version 2 08/10/19
 */

#ifndef OOP_2ND_COURSE_1LAB_LISTS_H
#define OOP_2ND_COURSE_1LAB_LISTS_H


#include <string>
#include "..//Books/headers/Book.h"


using namespace std;

//+* TASK


/**
 * Template Node structure that is used in the List structure
 */
template <class T>
struct Node{
    T data;             //Data that can contain and type of data
    Node* next;         //Pointer on the next element
    Node* prev;         //Pointer on the previous element
};

/**
 * Template interface structure for the List interface structure
 */
template <class T>
struct IList{
public:

    /**
     * Pure virtual function that adds the Node to the List
     *
     * @param val The value that would be added to the List
     */
    virtual void add_node(T val) = 0;

    /**
     * Deletes the last element of the list
     */
    virtual void pop_node() = 0;

    /**
     * Pure virtual function that randomly generates the List of spec. data
     */
    virtual void generate() = 0;

    /**
     * Pure virtual function that prints all the data from the list on the screen
     */
    virtual void display() = 0;

    /**
     * Pure virtual function that performs the insertion sort algorithm
     */
    virtual void insertion_sort() = 0;

    /**
    * Pure virtual function that performs the quicksort algorithm
    */
    virtual void quicksort() = 0;

    /**
    * Pure virtual function that performs the mergesort algorithm
    */
    virtual void mergesort() = 0;

    //+* task
    /**
    * Pure virtual function that performs the selection sort algorithm
    */
    virtual void selection_sort() = 0;

    //+* task
    /**
     * Pure virtual function that performs the counting sort algorithm. Uses default arguments for simple countingsort.
     * The default values are changed in radixsort algorithm as countingsort is a part of radix sort.
     * This sorting algorithm is valid only for the integers in [0,50)
     *
     * @param exp The default argument that equals 1 for the default countingsort. Contains the value that equals
     *        10^(exp-1) in radixsort algorithm where i is number of recursive iteration
     * @param max_int The default argument that equals 50 for the default countingsort. Means the maximum possible
     *        value for a sorted integer
     */
    virtual void countingsort(int exp = 1 , int max_int = 50) = 0;

    //+* task
    /**
     * Pure virtual function that performs the bucketsort algorithm.
     * This sorting algorithm is valid only for the integers in [0,100)
     */
    virtual void bucketsort() = 0;

    //+* task
    /**
     * Pure virtual function that performs the radix sort algorithm.
     * This sorting algorithm is valid only for the integers in [0,100)
     * This algorithm uses modificated countingsort!
     */
    virtual void radixsort() = 0;
};                                   //Interface

/**
 * Template interface structure for the List structure that is based on the array
 */
template <class T>
struct Arr_List : IList <T> {
private:
    int curr_size;                //current size of the array
    int max_size;                 //allocated memory for the array

    /**
     * Function that allocates additional memory of *new_size* to an array
     *
     * @param new_size The new size for the array
     */
    void incr_size(int new_size);

    /**
     * Function that swaps the data between indexes
     *
     * @param a Index a to swap
     * @param b Index b to swap
     */
    void swap(int a, int b);

    /**
     * Returns the max int in the list
     *
     * @return the max int in the list
     */
    int get_max_int();

    /**
     * Utility function for countingsort that fills the input arrays with zeros
     *
     * @param in The input array to fill
     * @param length The length of this array
     */
    void fill_array_0(int in[], int length);

    /**
     * Utility function for quicksort that sorts the array relatively to the pivot(< or > than pivot)
     *
     * @param start The start of the array to sort
     * @param finish The finish of the array to sort
     * @return the Index of the end of the sorted part of the array
     */
    int partition_quicksort(int start, int finish);

    /**
     * Function that performs the quicksort algorithm
     *
     * @param start The start of the subarray to sort
     * @param finish The end of the subarray to sort
     */
    void _quicksort(int start, int finish);

    /**
     * The function that divides the array in two subarrays and then merges them into one in ascending order
     *
     * @param left The start of the first array
     * @param middle The end of the first array and the start of the second array
     * @param right The end of the second array
     */
    void  merge(int left, int middle, int right);

    /**
     * Function that performs the mergesort algorithm
     *
     * @param left The left border of the array
     * @param right The right border of the array
     */
    void _mergesort(int left, int right);

public:
    T *arr;

    /**
     * The default constructor
     */
    Arr_List();

    /**
     * Returns the index of the head of the list
     *
     * @return the index of the head of the list
     */
    int get_head();

    /**
     * Returns the index of the tail of the list
     *
     * @return the index of the tail of the list
     */
    int get_tail();

    /**
     * Returns the current size of the array
     *
     * @return the current size of the array
     */
    int get_curr_size();

    /**
     * Adds the input value to the list
     *
     * @param val The value that will be added to the list
     */
    void add_node(T val) override ;

    /**
     * Deletes the last element of the list
     */
    void pop_node() override;

    /**
     * Function that randomly generates the List of spec. data
     */
    void generate() override ;

    /**
    * Function that prints all the data from the list on the screen
    */
    void display() override ;

    /**
    * Function that performs the insertion sort algorithm
    */
    void insertion_sort() override ;

    /**
    * Function that basically calls the _quicksort function that is in private section
    */
    void quicksort() override ;

    /**
    * Function that basically calls the _mergesort function that is in private section
    */
    void mergesort() override ;

    //+* task
    /**
    * Function that performs the selection sort algorithm
    */
    void selection_sort() override ;

    //+* task
    /**
     * Function that performs the counting sort algorithm. Uses default arguments for simple countingsort.
     * The default values are changed in radixsort algorithm as countingsort is a part of radix sort.
     * This sorting algorithm is valid only for the integers in [0,50)
     *
     * @param exp The default argument that equals 1 for the default countingsort. Contains the value that equals
     *        10^(exp-1) in radixsort algorithm where i is number of recursive iteration
     * @param max_int The default argument that equals 50 for the default countingsort. Means the maximum possible
     *        value for a sorted integer
     */
    void countingsort(int exp = 1, int max_int = 50) override ;

    //+* task
    /**
     * Function that performs the bucketsort algorithm.
     * This sorting algorithm is valid only for the integers in [0,100)
     */
    void bucketsort() override ;

    //+* task
    /**
     * Function that performs the radix sort algorithm.
     * This sorting algorithm is valid only for the integers in [0,100)
     * This algorithm uses modificated countingsort!
     */
    void radixsort() override ;
};                   //List based on the array

/**
 * Template interface structure for the List structure that is based on the linked list
 */
template <class T>
struct Linked_List : IList <T> {
private:

    Node <T> *head, *tail;                     //two pointers on the first and the last node
    int node_sum;                              //number of the nodes in list

    /**
     * Returns the max int in the list
     *
     * @return the max int in the list
    */
    int get_max_int();

    /**
     * Function that swaps the data between indexes
     *
     * @param a Index a to swap
     * @param b Index b to swap
     */
    void swap(Node <T> *a, Node <T> *b);

    /**
     * Utility function for quicksort that sorts the linked list relatively to the pivot(< or > than pivot)
     *
     * @param start The start of the linked list to sort
     * @param finish The finish of the linked list to sort
     * @return the Index of the end of the sorted part of the linked list
     */
    Node <T>* partition_quicksort(Node <T>* start, Node <T>* finish);

    /**
     * Function that performs the quicksort algorithm
     *
     * @param start The start of the sublist to sort
     * @param finish The end of the sublist to sort
     */
    void _quicksort(Node <T>* start, Node <T>* finish);

    /**
     * The function that divides the linked list in two linked lists
     * The first linked list is saved in the **first, the second linked list is saved in the **second
     *
     * @param start The linked list to divide
     * @param first The first part of the input linked list
     * @param second The second part of the input linked list
     */
    void listsplit_mergesort(Node <T> *start, Node <T> **first, Node <T> **second);

    /**
     * The function that merges two linked lists in one
     *
     * @param first The first linked list
     * @param second The second linked list
     * @return The merged linked list
     */
    Node <T> *merge(Node <T> *first, Node <T> *second);


    /**
    * Function that performs the mergesort algorithm
    *
    * @param source The pointer on the linked list that would be sorted
    */
    void _mergesort(Node <T> **source);

    /**
    * Utility function for countingsort that fills the input arrays with zeros.
    *
    * @param in The input array to fill
    * @param length The length of this array
    */
    void fill_array_0(int in[], int length);

public:

    /**
     * Default constructor
     */
    Linked_List();

    /**
    * Returns the pointer on the tail of the list
    *
    * @return the pointer on the tail of the list
    */
    Node <T>* get_tail();

    /**
     * Returns the pointer on the head of the list
     *
     * @return the pointer on the head of the list
     */
    Node <T>* get_head();

    /**
     * Returns the number of the nodes in the list
     *
     * @return the number of the nodes in the list
     */
    int get_node_sum();

    /**
    * Function that adds the Node to the List
    *
    * @param val The value that would be added to the List
    */
    void add_node(T val) override ;

    /**
     * Deletes the last element of the list
     */
    void pop_node() override ;

    /**
    * Function that randomly generates the List of spec. data
    */
    void generate() override;

    /**
    * Function that prints all the data from the list on the screen
    */
    void display() override;

    /**
    * Function that performs the insertion sort algorithm
    */
    void insertion_sort() override;

    /**
    * Function that basically calls the _quicksort function that is in private section
    */
    void quicksort() override;

    /**
    * Function that basically calls the _mergesort function that is in private section
    */
    void mergesort() override;

    //+* task
    /**
    * Function that performs the selection sort algorithm
    */
    void selection_sort() override;

    //+* task
    /**
     * Function that performs the counting sort algorithm. Uses default arguments for simple countingsort.
     * The default values are changed in radixsort algorithm as countingsort is a part of radix sort.
     * This sorting algorithm is valid only for the integers in [0,50)
     *
     * @param exp The default argument that equals 1 for the default countingsort. Contains the value that equals
     *        10^(exp-1) in radixsort algorithm where i is number of recursive iteration
     * @param max_int The default argument that equals 50 for the default countingsort. Means the maximum possible
     *        value for a sorted integer
     */
    void countingsort(int exp = 1, int max_int = 50) override;

    //+* task

    /**
    * Function that performs the bucketsort algorithm.
    * This sorting algorithm is valid only for the integers in [0,100)
    */
    void bucketsort() override;

    //+* task
    /**
     * Function that performs the radix sort algorithm.
     * This sorting algorithm is valid only for the integers in [0,100)
     * This algorithm uses modificated countingsort!
     */
    void radixsort() override;

};                //List based on the Linked list

/**
 * Template interface structure for the List structure that is based on the vector
 */
template <class T>
struct Vector_List : IList <T> {
    /**
    * Function that swaps the data between indexes
    *
    * @param a Index a to swap
    * @param b Index b to swap
    */
    void swap(int a, int b);

    /**
    * Returns the max int in the list
    *
    * @return the max int in the list
    */
    int get_max_int();

    /**
     * Utility function for countingsort that fills the input arrays with zeros
     *
     * @param in The input array to fill
     * @param length The length of this array
     */
    void fill_array_0(int in[], int length);

    /**
     * Utility function for quicksort that sorts the array relatively to the pivot(< or > than pivot)
     *
     * @param start The start of the array to sort
     * @param finish The finish of the array to sort
     * @return the Index of the end of the sorted part of the array
     */
    int partition_quicksort(int start, int finish);

    /**
     * Function that performs the quicksort algorithm
     *
     * @param start The start of the subarray to sort
     * @param finish The end of the subarray to sort
     */
    void _quicksort(int start, int finish);

    /**
     * The function that divides the array in two subarrays and then merges them into one in ascending order
     *
     * @param left The start of the first array
     * @param middle The end of the first array and the start of the second array
     * @param right The end of the second array
     */
    void  merge(int left, int middle, int right);

    /**
     * Function that performs the mergesort algorithm
     *
     * @param left The left border of the array
     * @param right The right border of the array
     */
    void _mergesort(int left, int right);

public:
    vector<T> arr;

    /**
     * The default constructor
     */
    Vector_List();

    /**
     * Returns the index of the head of the list
     *
     * @return the index of the head of the list
     */
    int get_head();

    /**
     * Returns the index of the tail of the list
     *
     * @return the index of the tail of the list
     */
    int get_tail();

    /**
     * Returns the current size of the array
     *
     * @return the current size of the array
     */
    int get_curr_size();

    /**
     * Adds the input value to the list
     *
     * @param val The value that will be added to the list
     */
    void add_node(T val) override ;

    /**
     * Deletes the last element of the list
     */
    void pop_node() override ;

    /**
     * Function that randomly generates the List of spec. data
     */
    void generate() override ;

    /**
    * Function that prints all the data from the list on the screen
    */
    void display() override ;

    /**
    * Function that performs the insertion sort algorithm
    */
    void insertion_sort() override ;

    /**
    * Function that basically calls the _quicksort function that is in private section
    */
    void quicksort() override ;

    /**
    * Function that basically calls the _mergesort function that is in private section
    */
    void mergesort() override ;

    //+* task
    /**
    * Function that performs the selection sort algorithm
    */
    void selection_sort() override ;

    //+* task
    /**
     * Function that performs the counting sort algorithm. Uses default arguments for simple countingsort.
     * The default values are changed in radixsort algorithm as countingsort is a part of radix sort.
     * This sorting algorithm is valid only for the integers in [0,50)
     *
     * @param exp The default argument that equals 1 for the default countingsort. Contains the value that equals
     *        10^(exp-1) in radixsort algorithm where i is number of recursive iteration
     * @param max_int The default argument that equals 50 for the default countingsort. Means the maximum possible
     *        value for a sorted integer
     */
    void countingsort(int exp = 1, int max_int = 50) override ;

    //+* task
    /**
     * Function that performs the bucketsort algorithm.
     * This sorting algorithm is valid only for the integers in [0,100)
     */
    void bucketsort() override ;

    //+* task
    /**
     * Function that performs the radix sort algorithm.
     * This sorting algorithm is valid only for the integers in [0,100)
     * This algorithm uses modificated countingsort!
     */
    void radixsort() override ;
};



#endif //OOP_2ND_COURSE_1LAB_LISTS_H
