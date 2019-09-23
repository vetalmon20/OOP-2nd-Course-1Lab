/**
 * 2nd Course K-29
 * Lab 1. Variant 2-10
 * Task: make a structure of linked list and realise different sort algorithms
 *
 *@author Vitaliy Datsiuk
 *@version 1.3 23/09/19
 */

#include <iostream>
#include "Linked_List.h"

using namespace std;

template <typename T>
    void List<T>::swap(Node <T> *a, Node <T> *b) {

        //cathing the possible error
        if(a == NULL || b == NULL){
            cout << "One of the nodes is empty. Nothing to swap." << endl;
            return;
        }

        T temp;
        temp = a->data;
        a->data = b->data;
        b->data = temp;
    }

template <typename T>
    Node <T>* List<T>:: partition_quicksort(Node <T>* start, Node <T>* finish){

        T piv_data = finish->data;      //data that pivot contain
        Node <T>* temp = start->prev;   //pointer on the place to swap the values
        Node <T>* j;                    //iterator

        //partition part
        for (j = start; j !=finish; j = j->next) {
            if (j->data <= piv_data) {
                if (temp == NULL)
                    temp = start;
                else
                    temp = temp->next;
                swap(temp, j);
            }
        }

        //swapping the pivot
        if (temp == NULL )
            temp = start;
        else
            temp = temp->next;
        swap (temp, j);

        return temp;
    }

template <typename T>
    void List<T>:: _quicksort(Node <T>* start, Node <T>* finish){

        if (finish != NULL && start != finish && start != finish->next){
            Node <T> *pivot = partition_quicksort(start, finish);
            _quicksort(start, pivot->prev);
            _quicksort(pivot->next, finish);
        }
    }

template <typename T>
    void List<T>:: listsplit_mergesort(Node <T> *start, Node <T> **first, Node <T> **second){

        //Catching the possible error
        if (start == NULL){
            cout<<"Unexpected error."<<endl;
            return;
        }

        Node <T> *fast, *slow; //used in fast/slow pointer method to divide list on 2 halves
        fast = start->next;
        slow = start;

        //the algorithm on dividing the list on 2
        while (fast != NULL){
            fast = fast->next;
            if (fast != NULL){
                slow = slow->next;
                fast = fast->next;
            }
        }

        *first = start;
        *second = slow->next;
        slow->next = NULL;
    }

template <typename T>
    Node <T>* List<T>:: merge(Node <T> *first, Node <T> *second){

        Node <T> *result;               //pointer on the result linked

        if (first == NULL)              //basic cases
            return second;
        if (second == NULL)
            return first;

        if (first->data <= second->data) {          //standard merge
            result = first;
            result->next = merge(first->next, second);
        }
        else {
            result = second;
            result->next = merge(first, second->next);
        }

        return (result);
    }

template <typename T>
    void List<T>::_mergesort(Node <T> **source)
    {
        Node <T> *start = *source;
        Node <T> *first;
        Node <T> *second;

        //Basic case
        if (start == NULL || start->next == NULL) {
            return;
        }

        //splits the source on 2 halves
        listsplit_mergesort(start, &first, &second);

        //recursive sort
        _mergesort(&first);
        _mergesort(&second);

        //merging the 2 halves
        *source = merge(first, second);
        head = *source;

        //updating the head and the tail
        Node <T> *temp;
        temp = head;
        if (temp == NULL)
            return;
        while (temp->next != NULL){
            temp = temp->next;
        }
        tail = temp;
    }

template <typename T>
    void List<T>:: fill_array_0(int in[], int length){
        for (int i = 0; i < length; i++){
            in[i] = 0;
        }
    }

template <typename T>
    List<T>::List(){

        head = NULL;
        tail = NULL;
        node_sum = 0;
    }

template <typename T>
    Node <T>* List<T>:: get_tail(){
        return tail;
    }

template <typename T>
    Node <T>* List<T>:: get_head(){
        return head;
    }

template <typename T>
    int List<T>:: get_node_sum(){
        return node_sum;
    }

template <typename T>
    int List<T>:: get_max_int(){
        if (typeid(T).name() != typeid(int).name()){
            cout << "Sorry, your values are not integers"<<endl;    //if elements are not int
            return 0;
        }
        int a = head->data;
        Node <T> *start = head;
        while (start != NULL){
            if (a < start->data)
                a = start->data;
            start = start->next;
        }
        return a;
    }

template <typename T>
    void List<T>:: add_node(T val){

        Node <T> *new_node = new Node <T>;
        new_node->data = val;
        new_node->next = NULL;
        new_node->prev = NULL;

        if (head == NULL){
            head = new_node;
            tail = new_node;
        } else {
            new_node->prev = tail;
            tail->next = new_node;
            tail = tail->next;
        }

        node_sum ++;                    //updated the number of the nodes
    }

template <typename T>
    void List<T>:: display(Node <T> *start){

        if(start != NULL)
        {
            cout << start->data << " ";
            display(start->next);
        }
    }

template <typename T>
    void List<T>:: insertion_sort(){

        Node <T> *current_p, *insertion_p;                //creating two auxillary pointers
        current_p = insertion_p=head;                     //marking them on the head of the list

        while (current_p != NULL || insertion_p != NULL){ //if both pointer in the end - finish
            current_p = insertion_p->next;
            while (current_p != NULL){
                if (current_p->data <= insertion_p->data)
                    swap(current_p, insertion_p);
                current_p = current_p->next;
            }
            insertion_p = insertion_p->next;
        }
    }

template <typename T>
    void List<T>:: quicksort(){
        _quicksort(head,tail);  //calls the function
    }

template <typename T>
    void List<T>:: mergesort(){
        _mergesort(&head);
    }

template <typename T>
    void List<T>:: countingsort(int exp, int max_int){

        //exp is used to radix algorithm. If u want to use this sort in default conditions
        //the value of exp and ten must be = 1 and 50 respectively (just don't touch it)

        //I use "49" as maximum possible value to the given integer

        if (typeid(T).name() != typeid(int).name()){
            cout << "Sorry, your values are not integers"<<endl;    //if elements are not int
            return;
        }

        Node <T>* start = head;
        int num = get_node_sum();
        if (num < 2){
            cout<<"nothing to sort"<<endl;                  //if number of elements are 0 or 1
            return;
        }

        if (get_max_int() > 49){
            cout<<"this algorithm is valid only for integers that <50"<<endl;
            return;
        }

        int index[max_int];
        fill_array_0(index,max_int);                    //creating index array

        int out[num];                                   //output array
        int temp;

        //creating the index array
        while (start != NULL){
            temp = (start->data / exp) % max_int;
            index[temp]++;                          //incrementing the index val of the current value
            start = start->next;
        }

        //modifying the index array
        for (int i = 1; i < max_int; i++){
            index[i] = index[i] + index[i - 1];
        }

        //creating the output array using index array
        if (max_int == 10){
            start = tail;
           // for (int s = num - 1; s >= 0; s--){
           while (start != NULL){
                temp = start->data;
                out[index[(temp / exp) % max_int] - 1] = temp;
                index[(temp / exp) % max_int]--;
                start = start->prev;
            }
        } else {
            start = head;
            while (start != NULL) {
                temp = start->data;
                out[index[(temp / exp) % max_int] - 1] = temp;
                index[(temp / exp) % max_int]--;
                start = start->next;
            }
        }

        //rewriting the values in the linked list from the output array
        start = head;
        for(int k = 0; k < num; k++) {
            start->data = out[k];
            start = start->next;
        }
    } // int exp = 1, int max_int = 50

template <typename T>
    void List<T>:: bucketsort(){

        if (typeid(T).name() != typeid(int).name()){
            cout << "Sorry, your values are not integers"<<endl;    //if elements are not int
            return;
        }
        if (get_node_sum() < 2){
            cout<<"nothing to sort"<<endl;                  //if number of elements are 0 or 1
            return;
        }

        List<int> arr[10];
        Node <T>* start = head;
        int base;                            //the basis dividing

        //determine the index of the integer to put in
        while (start != NULL){
            base = start->data / 10;
            arr[base].add_node(start->data);
            start = start->next;
        }

        //sorting the every list in array
        for (int i=0; i<10; i++) {
            arr[i].insertion_sort();
        }

        int n = -1;

        //used to determine the first not empty list
        for (int l = 0; l < 10; l++){
            if (arr[l].get_head() != NULL){
                n = l;
                head = arr[l].get_head();
                tail = arr[l].get_tail();
                break;
            }
        }

        //unexpected error
        if (n == -1){
            cout<<"the array is empty"<<endl;
            return;
        }

        //concatenating the lists in one
        for (int k = n + 1; k < 10; k++){
           if (arr[k].get_head() != NULL){
               tail->next = arr[k].get_head();
               tail = arr[k].get_tail();
           }
        }
    }

template <typename T>
    void List<T>:: radixsort(){

        int exp = 1;
        int max = get_max_int();

        while (max / exp > 0){
            countingsort(exp, 10);

            exp = exp * 10;
        }
    }