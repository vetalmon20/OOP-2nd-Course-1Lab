/**
 * 2nd Course K-29
 * Lab 1. Variant 2-10
 * Task: make a structure of linked list and realise different sort algorithms
 *
 *@author Vitaliy Datsiuk
 *@version 2 08/10/19
 */


#include <iostream>
#include "Lists.h"
#include "Book.h"

using namespace std;;

template <>
    inline int Arr_List <int> :: get_max_int(){

        int max = arr[0];
        for (int i = 1; i < curr_size; i++)
            if (arr[i] > max)
                max = arr[i];
        return max;
    }
template <>
    inline void Arr_List <int> :: generate(){

        arr = new int[1];
        curr_size = 0;
        max_size = 1;

        int length = rand() % 7 + 5;    //the length of the list

        for (int i = 0; i < length; i++){
            add_node(rand() % 49 + 1);
        }
    }
template <>
    inline void Arr_List <float> :: generate(){

        arr = new float[1];
        curr_size = 0;
        max_size = 1;

        int length = rand() % 7 + 5;    //the length of the list

        for (int i = 0; i < length; i++){
            add_node((float)rand() / RAND_MAX);
        }
    }
template <>
    inline void Arr_List <char> :: generate(){

        arr = new char[1];
        curr_size = 0;
        max_size = 1;

    int length = rand() % 7 + 5;    //the length of the list

        for (int i = 0; i < length; i++){
            add_node(rand() % 95 + 32);
        }
    }
template <>
    inline void Arr_List <string> :: generate(){

        arr = new string[1];
        curr_size = 0;
        max_size = 1;

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
                temp.push_back(alphanum[rand() % sizeof(alphanum)]); //adds a random symbol
            }
            add_node(temp);              //adding the random string to the list
            temp.erase();                //erasing the data from the string in order to keep it clean
        }
    }
template <>
    inline void Arr_List <Book> :: generate(){
        cout << "for generating Books pls use the Literature structure" << endl;
    }
template <>
    inline void Arr_List <Global_Character> :: generate(){
        cout << "for generating Books pls use the Literature structure" << endl;
    }
template <class T>
    void Arr_List <T> :: incr_size(int new_size) {

        max_size = new_size;
        T *temp = new T[new_size];

        for (int i = 0; i < curr_size; i++){
            temp[i] = arr[i];
        }
        delete[] arr;
        arr = temp;
    }
template <class T>
    void Arr_List <T> :: swap(int a, int b) {
        if (a < 0 || b < 0 || a >= curr_size || b >= curr_size){
            cout << "Unexpected error. Wrong indexes for an array in function swap(a,b)";
            return;
        }

        T temp;
        temp = arr[a];
        arr[a] = arr[b];
        arr[b] = temp;
}
template <class T>
    void Arr_List <T> :: fill_array_0(int in[], int length){
        for (int i = 0; i < length; i++){
            in[i] = 0;
        }
    }
template <class T>
    int Arr_List <T> :: partition_quicksort(int start, int finish) {
        T piv_data = arr[finish];      //data that pivot contain
        int temp = start - 1;                 //index of the place to swap the values
        int j;                         //iterator

        //partition part
        for (j = start; j !=finish; j++) {
            if (arr[j] <= piv_data) {
                temp++;
                swap(temp, j);
            }
        }

        //swapping the pivot
        temp++;
        swap (temp, j);
        return temp;
    }
template <class T>
    void Arr_List <T> :: _quicksort(int start, int finish){

        if (finish != 0 && start != finish && start != finish + 1){
            int pivot = partition_quicksort(start, finish);   //finding the place to pivot
            _quicksort(start, pivot-1);                   //doing the same to the left part
            _quicksort(pivot+1, finish);                  //doing the same to the right part
        }
    }
template <class T>
    void Arr_List <T> :: merge(int left, int middle, int right){

        int len1 = middle - left + 1;
        int len2 = right - middle;
        //creating 2 temp subarrays
        T A[len1];
        T B[len2];

        //copy data to temp subarrays
        for(int i = 0; i < len1; i++){
            A[i] = arr[left + i];
        }
        for(int j = 0; j< len2; j++){
            B[j] = arr[middle + 1 + j];
        }

        int i = 0;
        int j = 0;
        int k = left;

        while(i < len1 && j < len2){
            if(A[i] <= B[j]){
                arr[k] = A[i];
                i++;
            }else{
                arr[k] = B[j];
                j++;
            }
            k++;
        }

        //copy the rest of the subarray to our array
        while(i < len1){
            arr[k] = A[i];
            i++;
            k++;
        }
        while(j < len2){
            arr[k] = B[j];
            j++;
            k++;
        }
    }
template <class T>
    void Arr_List <T> :: _mergesort(int left, int right){
        if(left < right) {
            int middle = left + (right - left) / 2;         //avoids the excessing of maxint error
            _mergesort(left, middle);
            _mergesort(middle + 1, right);
            merge(left, middle, right);
        }
    }


template <class T>
    Arr_List <T> :: Arr_List() {
        arr = new T[1];
        curr_size = 0;
        max_size = 1;
    }
template <class T>
    int Arr_List <T> :: get_head() {
        return 0;
}
template <class T>
    int Arr_List <T> :: get_tail() {
        return curr_size - 1;
}
template<class T>
    int Arr_List <T> :: get_curr_size() {
        return curr_size;
    }
template <class T>
    void Arr_List <T> :: add_node(T val) {
        if (curr_size == max_size)
            incr_size(max_size + 20);
        arr[curr_size] = val;
        curr_size++;
    }
template <class T>
    void Arr_List <T> :: display() {
        for (int i = 0; i < curr_size; i++)
            cout << arr[i] << " ";
        cout << endl;
    }
template <class T>
    void Arr_List <T> :: insertion_sort() {

        int current_p, insertion_p;               //creating two auxillary pointers
        current_p = insertion_p = 0;              //marking them on the head of the list

        while (current_p < curr_size  || insertion_p < curr_size){ //if both pointer in the end - finish
            current_p = insertion_p + 1;
            while (current_p < curr_size){
                if (arr[current_p] <= arr[insertion_p])
                    swap(current_p, insertion_p);
                current_p = current_p + 1;
            }
            insertion_p = insertion_p + 1;
        }
    }
template <class T>
    void Arr_List <T> :: quicksort() {
        _quicksort(get_head(), get_tail());  //calls the function
    }
template <class T>
    void Arr_List <T> :: mergesort() {
        _mergesort(0, curr_size - 1);          //calls the function
    }
template <class T>
    void Arr_List <T> :: selection_sort() {

        if (get_tail() < 1){
            cout << "Nothing to sort" << endl;
            return;
        }

        int iterator, min;  //indexes
        int curr = 0;

        while(curr < curr_size){
            //save the smallest val in order to place it on the start of unsorted part of the array
            min = curr;
            iterator = curr + 1;
            while(iterator < curr_size){
                if(arr[iterator] <= arr[min])
                    min = iterator;
                iterator = iterator + 1;
            }
            swap(curr, min);
            curr = curr + 1;
        }
    }
template <class T>
    void Arr_List <T> :: countingsort(int exp, int max_int) {
        cout << "You cannot use this sort for this type of data" << endl;
    }
template <>
    inline void Arr_List<int> :: countingsort(int exp, int max_int) {
            //exp is used to radix algorithm. If u want to use this sort in default conditions
            //the value of exp and ten must be = 1 and 50 respectively (just don't touch it)

            //I use "49" as maximum possible value to the given integer

            int start = get_head();             //= 0
            int num = get_tail();
            if (num < 1){
                cout << "nothing to sort" << endl;                  //if number of elements are 0 or 1
                return;
            }

            if (get_max_int() > 49){
                cout << "this algorithm is valid only for integers that <50" << endl;
                return;
            }

            int index[max_int];
            fill_array_0(index, max_int);                    //creating index array

            int out[num + 1];                                   //output array
            int temp;

            //creating the index array
            while (start < curr_size){
                temp = (arr[start] / exp) % max_int;
                index[temp]++;                         //incrementing the index val of the current value
                start++;
            }

            //modifying the index array
            for (int i = 1; i < max_int; i++){
                index[i] = index[i] + index[i - 1];
            }

            //creating the output array using index array
            if (max_int == 10){
                start = get_tail();
                while (start >= 0){
                    temp = arr[start];
                    out[index[(temp / exp) % max_int] - 1] = temp;
                    index[(temp / exp) % max_int]--;
                    start--;
                }
            } else {
                start = get_head();
                while (start < curr_size) {
                    temp = arr[start];
                    out[index[(temp / exp) % max_int] - 1] = temp;
                    index[(temp / exp) % max_int]--;
                    start++;
                }
            }

            //rewriting the values in the linked list from the output array
            start = get_head();
            for(int k = 0; k <= num; k++) {
                arr[start] = out[k];
                start++;
            }
        }
template <class T>
    void Arr_List <T> :: bucketsort() {
        cout << "You cannot use this sort for this type of data" << endl;
    }
template <>
    inline void Arr_List <int> :: bucketsort() {

        if (get_tail() < 1){
            cout<<"nothing to sort"<<endl;                  //if number of elements are 0 or 1
            return;
        }

        Linked_List <int> temparr[10];
        int start = get_head();
        int base;                            //the basis dividing
        Node<int> *head, *tail;                 //used to mark head and tail of list in array of list

        //determine the index of the integer to put in
        while (start < curr_size){
            base = arr[start] / 10;
            temparr[base].add_node(arr[start]);
            start++;
        }

        //sorting the every list in array
        for (int i = 0; i < 10; i++) {
            temparr[i].insertion_sort();
        }

        int n = -1;

        //used to determine the first not empty list
        for (int l = 0; l < 10; l++){
            if (temparr[l].get_head() != NULL){
                n = l;
                head = temparr[l].get_head();
                tail = temparr[l].get_tail();
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
            if (temparr[k].get_head() != NULL){
                tail->next = temparr[k].get_head();
                tail = temparr[k].get_tail();
            }
        }

        //rewriting the sorted list in our array
        Node<int> *iter = head;
        int k = 0;
        while (iter != NULL){
            arr[k] = iter->data;
            iter = iter->next;
            k++;
        }
    }
template <class T>
    void Arr_List <T> :: radixsort() {
    cout << "You cannot use this sort for this type of data" << endl;
    }
template <>
    inline void Arr_List <int> :: radixsort() {

        int exp = 1;
        int max = get_max_int();

        while (max / exp > 0){
            countingsort(exp, 10);

            exp = exp * 10;
        }
    }




template <>
    inline void Linked_List <int> :: generate(){

    head = NULL;
    tail = NULL;
    node_sum = 0;

    int length = rand() % 7 + 5;    //the length of the list

    for (int i = 0; i < length; i++){
        add_node(rand() % 49 + 1);
    }
}
template <>
    inline void Linked_List <float> :: generate(){

    head = NULL;
    tail = NULL;
    node_sum = 0;

    int length = rand() % 7 + 5;    //the length of the list

    for (int i = 0; i < length; i++){
        add_node((float)rand() / RAND_MAX);
    }
}
template <>
    inline void Linked_List <char> :: generate(){

    head = NULL;
    tail = NULL;
    node_sum = 0;

    int length = rand() % 7 + 5;    //the length of the list

    for (int i = 0; i < length; i++){
        add_node(rand() % 95 + 32);
    }
}
template <>
    inline void Linked_List <string> :: generate(){

    head = NULL;
    tail = NULL;
    node_sum = 0;

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
            temp.push_back(alphanum[rand() % sizeof(alphanum)]); //adds a random symbol
        }
        add_node(temp);              //adding the random string to the list
        temp.erase();                //erasing the data from the string in order to keep it clean
    }
}
template <>
    inline void Linked_List <Book> :: generate(){
    cout << "for generating Books pls use the Literature structure" << endl;
    }
template <>
    inline void Linked_List <Global_Character> :: generate(){
        cout << "for generating Books pls use the Literature structure" << endl;
    }
template <class T>
    int Linked_List <T> :: get_max_int(){
    if (typeid(T).name() != typeid(int).name()){
        cout << "Sorry, your values are not integers"<<endl;    //if elements are not int
        return 0;
    }
    int a = head->data;                 //parcing all the list. The biggest int is saved in 'a'
    Node <T> *start = head;
    while (start != NULL){
        if (a < start->data)
            a = start->data;
        start = start->next;
    }
    return a;
}
template <class T>
    void Linked_List <T> :: swap(Node <T> *a, Node <T> *b) {

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
template <class T>
    Node <T>* Linked_List <T> :: partition_quicksort(Node <T> *start, Node <T> *finish){

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
template <class T>
    void Linked_List <T> :: _quicksort(Node <T> *start, Node <T> *finish){

        if (finish != NULL && start != finish && start != finish->next){
            Node <T> *pivot = partition_quicksort(start, finish);   //finding the place to pivot
            _quicksort(start, pivot->prev);            //doing the same to the left part
            _quicksort(pivot->next, finish);           //doing the same to the right part
        }
    }
template <class T>
    void Linked_List <T> :: listsplit_mergesort(Node <T> *start, Node <T> **first, Node <T> **second){

        //Catching the possible error
        if (start == NULL){
            cout<<"Unexpected error."<<endl;
            return;
        }

        Node <T> *fast, *slow; //used in fast/slow pointer method to divide list on 2 halves
        fast = start->next;
        slow = start;

        //the algorithm on dividing the list on two lists
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
    Node <T>* Linked_List<T> :: merge(Node <T> *first, Node <T> *second){

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
    void Linked_List <T> :: _mergesort(Node <T> **source)
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
    void Linked_List <T> :: fill_array_0(int in[], int length){
        for (int i = 0; i < length; i++){
            in[i] = 0;
        }
    }


template <class T>
    Linked_List <T> :: Linked_List(){

        head = NULL;
        tail = NULL;
        node_sum = 0;
    }
template <class T>
    Node <T>* Linked_List <T> :: get_tail(){
        return tail;
    }
template <class T>
    Node <T>* Linked_List <T> :: get_head(){
        return head;
    }
template <class T>
    int Linked_List <T> :: get_node_sum(){
        return node_sum;
    }
template <class T>
    void Linked_List <T> :: add_node(T val){

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
    void Linked_List <T> :: display(){

        Node<T> *temp = head;
        while(temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
template <class T>
    void Linked_List <T> :: insertion_sort(){

        Node <T> *current_p, *insertion_p;                //creating two auxillary pointers
        current_p = insertion_p = head;                     //marking them on the head of the list

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
    void Linked_List <T> :: quicksort(){
        _quicksort(get_head(),get_tail());  //calls the function
    }
template <class T>
    void Linked_List <T> :: mergesort(){
        _mergesort(&head);          //calls the function
    }
template <class T>
    void Linked_List <T> :: selection_sort() {

        Node <T> *curr = head;

        if (curr == NULL || curr->next == NULL){
            cout << "Nothing to sort" << endl;
            return;
        }

        Node <T> *iterator, *min;

        while(curr != NULL){
            //save the smallest val in order to place it on the start of unsorted part of the array
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
    void Linked_List <T> :: countingsort(int exp, int max_int) {
        cout << "You cannot use this sort for this type of data" << endl;
    }
template <>
    inline void Linked_List <int> :: countingsort(int exp, int max_int){

        //exp is used to radix algorithm. If u want to use this sort in default conditions
        //the value of exp and ten must be = 1 and 50 respectively (just don't touch it)

        //I use "49" as maximum possible value to the given integer


        Node <int>* start = head;
        int num = get_node_sum();
        if (num < 2){
            cout << "nothing to sort" << endl;                  //if number of elements are 0 or 1
            return;
        }

        if (get_max_int() > 49){
            cout << "this algorithm is valid only for integers that <50" << endl;
            return;
        }

        int index[max_int];
        fill_array_0(index,max_int);                    //creating index array

        int out[num];                                   //output array
        int temp;

        //creating the index array
        while (start != NULL){
            temp = (start->data / exp) % max_int;
            index[temp]++;                         //incrementing the index val of the current value
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
    }
template <class T>
    void Linked_List <T> :: bucketsort() {
        cout << "You cannot use this sort for this type of data" << endl;
    }
template <>
    inline void Linked_List <int> :: bucketsort(){

        if (get_node_sum() < 2){
            cout<<"nothing to sort"<<endl;                  //if number of elements are 0 or 1
            return;
        }

        Linked_List <int> arr[10];
        Node <int>* start = head;
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
    void Linked_List <T> :: radixsort() {
        cout << "You cannot use this sort for this type of data" << endl;
    }
template <>
    inline void Linked_List <int> :: radixsort(){

        int exp = 1;
        int max = get_max_int();

        while (max / exp > 0){
            countingsort(exp, 10);

            exp = exp * 10;
        }
    }

