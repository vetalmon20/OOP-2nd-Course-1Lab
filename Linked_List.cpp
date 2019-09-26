/**
 * 2nd Course K-29
 * Lab 1. Variant 2-10
 * Task: make a structure of linked list and realise different sort algorithms
 *
 *@author Vitaliy Datsiuk
 *@version 1.4 25/09/19
 */

#include <iostream>
#include "Linked_List.h"
#include "Book.h"

using namespace std;

template <class T>
    void List<T>::swap(Node <T> *a, Node <T> *b) {

        //cathing the possible error
        if(a == NULL || b == NULL){
            cout << "One of the nodes is empty. Nothing to swap." << endl;
            return;
        }

/*
        Book temp_book;
        if (typeid(T).name() == typeid(temp_book).name()){
            temp_book =
        }
*/

        T temp;
        temp = a->data;
        a->data = b->data;
        b->data = temp;
    }

template <class T>
    Node <T>* List<T>:: partition_quicksort(Node <T>* start, Node <T>* finish){

        T piv_data = finish->data;      //data that pivot contain
        Node <T>* temp = start->prev;   //pointer on the place to swap the values
        Node <T>* j;                    //iterator

/*        Book ex;
        Book piv_data_book;
        if (typeid(T).name() == typeid(ex).name()){
            //partition part for the book
            piv_data_book = piv_data;
            for (j = start; j !=finish; j = j->next) {
                ex = j->data;
                if (ex.release_get().year <= piv_data_book.release_get().year) {
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
        }*/

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

template <class T>
    void List<T>:: _quicksort(Node <T>* start, Node <T>* finish){

        if (finish != NULL && start != finish && start != finish->next){
            Node <T> *pivot = partition_quicksort(start, finish);
            _quicksort(start, pivot->prev);
            _quicksort(pivot->next, finish);
        }
    }

template <class T>
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

template <class T>
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

template <class T>
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

template <class T>
    void List<T>:: fill_array_0(int in[], int length){
        for (int i = 0; i < length; i++){
            in[i] = 0;
        }
    }

template <class T>
    List<T>::List(){

        head = NULL;
        tail = NULL;
        node_sum = 0;
    }

template <class T>
    Node <T>* List<T>:: get_tail(){
        return tail;
    }

template <class T>
    Node <T>* List<T>:: get_head(){
        return head;
    }

template <class T>
    int List<T>:: get_node_sum(){
        return node_sum;
    }

template <class T>
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

template <class T>
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

template <class T>
    void List<T>:: generate_basic(){

        int a;
        double b;
        char c;

        if (typeid(curr_type).name() == typeid(a).name()) {
            generate_int();
            return;
        }

        if (typeid(curr_type).name() == typeid(b).name()) {
            generate_double();
            return;
        }

        if (typeid(curr_type).name() == typeid(c).name()) {
            generate_char();
            return;
        }

        cout << "there are no generating function for such type of data" << endl;
        return;
    };

template <class T>
    void List<T>:: generate_int() {

        int length = rand() % 7 + 5;    //the length of the list

        for (int i = 0; i < length; i++){
            add_node(rand() % 49 + 1);
        }
    }

template <class T>
    void List<T>:: generate_char() {

        int length = rand() % 7 + 5;    //the length of the list

        for (int i = 0; i < length; i++){
            add_node(rand() % 95 + 32);
        }
    }

template <class T>
    void List<T>:: generate_double() {

        int length = rand() % 7 + 5;    //the length of the list

        for (int i = 0; i < length; i++){
            add_node((float)rand() / RAND_MAX);
        }
}

template <class T>
    void List<T>:: generate_string() {

        string ex;
    if (typeid(curr_type).name() != typeid(ex).name()) {
        cout << "It is not a string" << endl;               //Error catching
        return;
    }

     char alphanum[] =
            "0123456789"
            "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
            "abcdefghijklmnopqrstuvwxyz";

        int length = rand() % 7 + 5;    //the length of the list
        int string_length;              //the length of the string
        string temp;                    //temporary string that will be in the list

        for (int i = 0; i < length; i++){
           string_length = rand() % 7 + 3;
           for(int k = 0; k < string_length; k++){
               temp.push_back(alphanum[rand() % sizeof(alphanum)]);
           }
           add_node(temp);
           temp.erase();
        }
}

template <class T>
    void List<T>:: display(Node <T> *start){

        if(start != NULL)
        {
            cout << start->data << " ";
            display(start->next);
        }
    }

template <class T>
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

template <class T>
    void List<T>:: quicksort(){
        _quicksort(head,tail);  //calls the function
    }

template <class T>
    void List<T>:: mergesort(){
        _mergesort(&head);
    }

template <class T>
    void List<T>:: selection_sort() {

        Node <T> *curr = head;

        if (curr == NULL || curr->next == NULL){
            cout << "Nothing to sort" << endl;
            return;
        }

        Node <T> *iterator, *min;

        while(curr != NULL){
            min = curr;
            iterator = curr->next;
            while(iterator != NULL){
                if(iterator->data <= min->data)
                    min = iterator;
                iterator = iterator->next;
            }
            swap(curr, min);
            curr = curr->next;
        }
    }

template <class T>
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

template <class T>
    void List<T> :: bucketsort(){

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

template <class T>
    void List<T> :: radixsort(){

        int exp = 1;
        int max = get_max_int();

        while (max / exp > 0){
            countingsort(exp, 10);

            exp = exp * 10;
        }
    }

template <class T>
    void List <T> :: find_series(string character) {

        if (character == "" ) {
            cout << "empty character" << endl;
            return;
        }

        Book a;
        List <Book> series;
        if (typeid(a).name() == typeid(T).name()) {                 //if a T is a Book type

            Node<T> *start = head;
            while (start != NULL) {
                a = start->data;
                if (a.find_character(character) == 1)
                    series.add_node(a);
                start = start->next;
            }
            cout<<" ";
            series.display(series.get_head());
            series.mergesort();
            series.display(series.get_head());
        } else {
            cout << " The type of data is not a Book" << endl;
            return;
        }

    }

