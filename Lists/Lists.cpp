/**
 * 2nd Course K-29
 * Lab 1. Variant 2-10
 * Task: make a structure of linked list and realise different sort algorithms
 *
 * Purpose: this file contains all the methods that are written in the Lists.h
 *
 *@author Vitaliy Datsiuk
 *@version 2 08/10/19
 */


#include <iostream>
#include "Lists.h"
#include "..//Books/headers/Book.h"
#include "..//Books/headers/Global_Character.h"

using namespace std;;

template<class T>
Node<T>::Node() {
    next = prev = nullptr;
}

template <class T>
    int Arr_List <T> :: get_max_int(){
        cout << "You cannot use this sort for this type of data" << endl;
        return 0;
    }

/**
 * Returns the max int in the list
 *
 * @return the max int in the list
 */
template <>
    inline int Arr_List <int> :: get_max_int(){

        int max = arr[0];
        for (int i = 1; i < curr_size; i++)
            if (arr[i] > max)
                max = arr[i];
        return max;
    }

/**
* Function that randomly generates the List of the int data
*/
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

/**
* Function that randomly generates the List of the float data
*/
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

/**
* Function that randomly generates the List of the char data
*/
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

/**
* Function that randomly generates the List of the string data
*/
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

/**
* Function that show the error message for this type of data
*/
template <>
    inline void Arr_List <Book> :: generate(){
        cout << "for generating Books pls use the Literature structure" << endl;
    }

/**
* Function that show the error message for this type of data
*/
template <>
    inline void Arr_List <Global_Character> :: generate(){
        cout << "for generating Books pls use the Literature structure" << endl;
    }

/**
* Function that allocates additional memory of *new_size* to an array
*
* @param new_size The new size for the array
*/
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

/**
* Function that swaps the data between indexes
*
* @param a Index a to swap
* @param b Index b to swap
*/
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

/**
 * Utility function for countingsort that fills the input arrays with zeros
 *
 * @param in The input array to fill
 * @param length The length of this array
 */
template <class T>
    void Arr_List <T> :: fill_array_0(int in[], int length){
        for (int i = 0; i < length; i++){
            in[i] = 0;
        }
    }

/**
* Utility function for quicksort that sorts the array relatively to the pivot(< or > than pivot)
*
* @param start The start of the array to sort
* @param finish The finish of the array to sort
* @return the Index of the end of the sorted part of the array
*/
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

/**
* Function that performs the quicksort algorithm
*
* @param start The start of the subarray to sort
* @param finish The end of the subarray to sort
*/
template <class T>
    void Arr_List <T> :: _quicksort(int start, int finish){

        if (finish != 0 && start != finish && start != finish + 1){
            int pivot = partition_quicksort(start, finish);   //finding the place to pivot
            _quicksort(start, pivot-1);                   //doing the same to the left part
            _quicksort(pivot+1, finish);                  //doing the same to the right part
        }
    }

/**
* The function that divides the array in two subarrays and then merges them into one in ascending order
*
* @param left The start of the first array
* @param middle The end of the first array and the start of the second array
* @param right The end of the second array
*/
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

/**
* Function that performs the mergesort algorithm
*
* @param left The left border of the array
* @param right The right border of the array
*/
template <class T>
    void Arr_List <T> :: _mergesort(int left, int right){
        if(left < right) {
            int middle = left + (right - left) / 2;         //avoids the excessing of maxint error
            _mergesort(left, middle);
            _mergesort(middle + 1, right);
            merge(left, middle, right);
        }
    }

/**
 * The default constructor
 */
template <class T>
    Arr_List <T> :: Arr_List() {
        arr = new T[1];
        curr_size = 0;
        max_size = 1;
    }

/**
* The default destructor
*/
template<class T>
    Arr_List<T>::~Arr_List() {
        // delete(arr);
    }

/**
 * Function that get the data by index
*/
template<class T>
T Arr_List<T>::get_by_index(int index)
{
    return arr[index];
}

/**
* Returns the index of the head of the list
*
* @return the index of the head of the list
*/
template <class T>
    int Arr_List <T> :: get_head() {
        return 0;
}

/**
 * Returns the index of the tail of the list
 *
 * @return the index of the tail of the list
 */
template <class T>
    int Arr_List <T> :: get_tail() {
        return curr_size - 1;
}

/**
 * Returns the current size of the array
 *
 * @return the current size of the array
 */
template<class T>
    int Arr_List <T> :: get_curr_size() {
        return curr_size;
    }

/**
 * Returns the maximum size of the array
 *
 * @return the maximum size of the array
 */
template<class T>
    int Arr_List <T> ::get_max_size() {
        return max_size;
    }

/**
* Adds the input value to the list
*
* @param val The value that will be added to the list
*/
template <class T>
    void Arr_List <T> :: add_node(T val) {
        if (curr_size == max_size)
            incr_size(max_size + 20);
        arr[curr_size] = val;
        curr_size++;
    }

/**
* Function that prints all the data from the list on the screen
*/
template <class T>
    void Arr_List <T> :: display() {
        for (int i = 0; i < curr_size; i++)
            cout << arr[i] << " ";
        cout << endl;
    }

/**
* Function that performs the insertion sort algorithm
*/
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

/**
* Function that basically calls the _quicksort function that is in private section
*/
template <class T>
    void Arr_List <T> :: quicksort() {
        _quicksort(get_head(), get_tail());  //calls the function
    }

/**
* Function that basically calls the _mergesort function that is in private section
*/
template <class T>
    void Arr_List <T> :: mergesort() {
        _mergesort(0, curr_size - 1);          //calls the function
    }

/**
* Function that performs the selection sort algorithm
*/
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

/**
* Function that shows the error message for all types of data that are not expected to use
*/
template <class T>
    void Arr_List <T> :: countingsort(int exp, int max_int) {
        cout << "You cannot use this sort for this type of data" << endl;
    }

/**
* Function that performs the counting sort algorithm for the int type of data.
* Uses default arguments for simple countingsort.
* The default values are changed in radixsort algorithm as countingsort is a part of radix sort.
* This sorting algorithm is valid only for the integers in [0,50)
*
* @param exp The default argument that equals 1 for the default countingsort. Contains the value that equals
*        10^(exp-1) in radixsort algorithm where i is number of recursive iteration
* @param max_int The default argument that equals 50 for the default countingsort. Means the maximum possible
*        value for a sorted integer
*/
template <>
    inline void Arr_List<int> :: countingsort(int exp, int max_int) {
            //exp is used to radix algorithm. If u want to use this sort in default conditions
            //the value of exp and max_int must be = 1 and 50 respectively (just don't touch it)

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

/**
* Function that shows the error message for all types of data that are not expected to use
*/
template <class T>
    void Arr_List <T> :: bucketsort() {
        cout << "You cannot use this sort for this type of data" << endl;
    }

/**
* Function that performs the bucketsort algorithm for the int type of data
* This sorting algorithm is valid only for the integers in [0,100)
*/
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
            if (temparr[l].get_head() != nullptr){
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
            if (temparr[k].get_head() != nullptr){
                tail->next = temparr[k].get_head();
                tail = temparr[k].get_tail();
            }
        }

        //rewriting the sorted list in our array
        Node<int> *iter = head;
        int k = 0;
        while (iter != nullptr){
            arr[k] = iter->data;
            iter = iter->next;
            k++;
        }
    }

/**
* Function that shows the error message for all types of data that are not expected to use
*/
template <class T>
    void Arr_List <T> :: radixsort() {
    cout << "You cannot use this sort for this type of data" << endl;
    }

/**
* Deletes the last element of the list
*/
template<class T>
void Arr_List<T>::pop_node() {
    if (curr_size == 0)
        return;
    curr_size = curr_size - 1;

}

/**
* Function that performs the radix sort algorithm for the int type of data
* This sorting algorithm is valid only for the integers in [0,100)
* This algorithm uses modificated countingsort!
*/
template <>
    inline void Arr_List <int> :: radixsort() {

        int exp = 1;
        int max = get_max_int();

        while (max / exp > 0){
            countingsort(exp, 10);

            exp = exp * 10;
        }
    }

    /**
     * operator [] gets the element of the input index
     * @param i input index
     * @return the element of the input index
     */
    template<class T>
    T &Arr_List<T>::operator[](int i)
    {
        return this->arr[i];
    }



/**
* Function that randomly generates the List of the int data
*/
template <>
    inline void Linked_List <int> :: generate(){

    head = nullptr;
    tail = nullptr;
    node_sum = 0;

    int length = rand() % 7 + 5;    //the length of the list

    for (int i = 0; i < length; i++){
        add_node(rand() % 49 + 1);
    }
}

/**
* Function that randomly generates the List of the float data
*/
template <>
    inline void Linked_List <float> :: generate(){

    head = nullptr;
    tail = nullptr;
    node_sum = 0;

    int length = rand() % 7 + 5;    //the length of the list

    for (int i = 0; i < length; i++){
        add_node((float)rand() / RAND_MAX);
    }
}

/**
* Function that randomly generates the List of the char data
*/
template <>
    inline void Linked_List <char> :: generate(){

    head = nullptr;
    tail = nullptr;
    node_sum = 0;

    int length = rand() % 7 + 5;    //the length of the list

    for (int i = 0; i < length; i++){
        add_node(rand() % 95 + 32);
    }
}

/**
* Function that randomly generates the List of the string data
*/
template <>
    inline void Linked_List <string> :: generate(){

    head = nullptr;
    tail = nullptr;
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

/**
* Function that show the error message for this type of data
*/
template <>
    inline void Linked_List <Book> :: generate(){
    cout << "for generating Books pls use the Literature structure" << endl;
    }

/**
* Function that show the error message for this type of data
*/
template <>
    inline void Linked_List <Global_Character> :: generate(){
        cout << "for generating Books pls use the Literature structure" << endl;
    }
/**
* Function returns the current size of the list
*/
template<class T>
    int Linked_List<T>::get_curr_size()
    {
        Node<T>* temp = this->head;
        int size = 0;
        while(temp !=  nullptr){
            size++;
            temp = temp->next;
        }
        return size;
    }

/**
* Returns the max int in the list
*
* @return the max int in the list
*/
template <class T>
    int Linked_List <T> :: get_max_int(){
    if (typeid(T).name() != typeid(int).name()){
        cout << "Sorry, your values are not integers"<<endl;    //if elements are not int
        return 0;
    }
    int a = head->data;                 //parcing all the list. The biggest int is saved in 'a'
    Node <T> *start = head;
    while (start != nullptr){
        if (a < start->data)
            a = start->data;
        start = start->next;
    }
    return a;
}

/**
 * Function that swaps the data between indexes
 *
 * @param a Index a to swap
 * @param b Index b to swap
 */
template <class T>
    void Linked_List <T> :: swap(Node <T> *a, Node <T> *b) {

        //cathing the possible error
        if(a == nullptr || b == nullptr){
            cout << "One of the nodes is empty. Nothing to swap." << endl;
            return;
        }

        T temp;
        temp = a->data;
        a->data = b->data;
        b->data = temp;
    }

/**
* Utility function for quicksort that sorts the linked list relatively to the pivot(< or > than pivot)
*
* @param start The start of the linked list to sort
* @param finish The finish of the linked list to sort
* @return the Index of the end of the sorted part of the linked list
*/
template <class T>
    Node <T>* Linked_List <T> :: partition_quicksort(Node <T> *start, Node <T> *finish){

        T piv_data = finish->data;      //data that pivot contain
        Node <T>* temp = start->prev;   //pointer on the place to swap the values
        Node <T>* j;                    //iterator

        //partition part
        for (j = start; j !=finish; j = j->next) {
            if (j->data <= piv_data) {
                if (temp == nullptr)
                    temp = start;
                else
                    temp = temp->next;
                swap(temp, j);
            }
        }

        //swapping the pivot
        if (temp == nullptr )
            temp = start;
        else
            temp = temp->next;
        swap (temp, j);

        return temp;
    }

/**
* Function that performs the quicksort algorithm
*
* @param start The start of the sublist to sort
* @param finish The end of the sublist to sort
*/
template <class T>
    void Linked_List <T> :: _quicksort(Node <T> *start, Node <T> *finish){

        if (finish != nullptr && start != finish && start != finish->next){
            Node <T> *pivot = partition_quicksort(start, finish);   //finding the place to pivot
            _quicksort(start, pivot->prev);            //doing the same to the left part
            _quicksort(pivot->next, finish);           //doing the same to the right part
        }
    }

/**
* The function that divides the linked list in two linked lists
* The first linked list is saved in the **first, the second linked list is saved in the **second
*
* @param start The linked list to divide
* @param first The first part of the input linked list
* @param second The second part of the input linked list
*/
template <class T>
    void Linked_List <T> :: listsplit_mergesort(Node <T> *start, Node <T> **first, Node <T> **second){

        //Catching the possible error
        if (start == nullptr){
            cout<<"Unexpected error."<<endl;
            return;
        }

        Node <T> *fast, *slow; //used in fast/slow pointer method to divide list on 2 halves
        fast = start->next;
        slow = start;

        //the algorithm on dividing the list on two lists
        while (fast != nullptr){
            fast = fast->next;
            if (fast != nullptr){
                slow = slow->next;
                fast = fast->next;
            }
        }

        *first = start;
        *second = slow->next;
        slow->next = nullptr;
    }

/**
* The function that merges two linked lists in one
*
* @param first The first linked list
* @param second The second linked list
* @return The merged linked list
*/
template <class T>
    Node <T>* Linked_List<T> :: merge(Node <T> *first, Node <T> *second){

        Node <T> *result;               //pointer on the result linked

        if (first == nullptr)              //basic cases
            return second;
        if (second == nullptr)
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

/**
* Function that performs the mergesort algorithm
*
* @param source The pointer on the linked list that would be sorted
*/
template <class T>
    void Linked_List <T> :: _mergesort(Node <T> **source)
    {
        Node <T> *start = *source;
        Node <T> *first;
        Node <T> *second;

        //Basic case
        if (start == nullptr || start->next == nullptr) {
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
        if (temp == nullptr)
            return;
        while (temp->next != nullptr){
            temp = temp->next;
        }
        tail = temp;
    }

/**
* Utility function for countingsort that fills the input arrays with zeros.
*
* @param in The input array to fill
* @param length The length of this array
*/
template <class T>
    void Linked_List <T> :: fill_array_0(int in[], int length){
        for (int i = 0; i < length; i++){
            in[i] = 0;
        }
    }

/**
 * Default constructor
 */
template <class T>
    Linked_List <T> :: Linked_List(){

        head = nullptr;
        tail = nullptr;
        node_sum = 0;
    }

    template<class T>
    T Linked_List<T>::get_by_index(int index)
    {

        Node<T>* temp = this->head;
        for(int i = 0; i < index; i++){
            temp = temp->next;
            cout <<"here";
        }
        return temp->data;
    }

/**
* Returns the pointer on the tail of the list
*
* @return the pointer on the tail of the list
*/
template <class T>
    Node <T>* Linked_List <T> :: get_tail(){
        return tail;
    }

/**
 * Returns the pointer on the head of the list
 *
 * @return the pointer on the head of the list
 */
template <class T>
    Node <T>* Linked_List <T> :: get_head(){
        return head;
    }

/**
* Returns the number of the nodes in the list
*
* @return the number of the nodes in the list
*/
template <class T>
    int Linked_List <T> :: get_node_sum(){
        return node_sum;
    }

/**
* Function that adds the Node to the List
*
* @param val The value that would be added to the List
*/
template <class T>
    void Linked_List <T> :: add_node(T val){

        Node <T> *new_node = new Node <T>;
        new_node->data = val;
        new_node->next = nullptr;
        new_node->prev = nullptr;

        if (head == nullptr){
            head = new_node;
            tail = new_node;
        } else {
            new_node->prev = tail;
            tail->next = new_node;
            tail = tail->next;
        }

        node_sum ++;                    //updated the number of the nodes
    }

/**
* Function that prints all the data from the list on the screen
*/
template <class T>
    void Linked_List <T> :: display(){

        Node<T> *temp = head;
        while(temp != nullptr)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

/**
* Function that performs the insertion sort algorithm
*/
template <class T>
    void Linked_List <T> :: insertion_sort(){

        Node <T> *current_p, *insertion_p;                //creating two auxillary pointers
        current_p = insertion_p = head;                     //marking them on the head of the list

        while (current_p != nullptr || insertion_p != nullptr){ //if both pointer in the end - finish
            current_p = insertion_p->next;
            while (current_p != nullptr){
                if (current_p->data <= insertion_p->data)
                    swap(current_p, insertion_p);
                current_p = current_p->next;
            }
            insertion_p = insertion_p->next;
        }
    }

/**
* Function that basically calls the _quicksort function that is in private section
*/
template <class T>
    void Linked_List <T> :: quicksort(){
        _quicksort(get_head(),get_tail());  //calls the function
    }

/**
* Function that basically calls the _mergesort function that is in private section
*/
template <class T>
    void Linked_List <T> :: mergesort(){
        _mergesort(&head);          //calls the function
    }

/**
* Function that performs the selection sort algorithm
*/
template <class T>
    void Linked_List <T> :: selection_sort() {

        Node <T> *curr = head;

        if (curr == nullptr || curr->next == nullptr){
            cout << "Nothing to sort" << endl;
            return;
        }

        Node <T> *iterator, *min;

        while(curr != nullptr){
            //save the smallest val in order to place it on the start of unsorted part of the array
            min = curr;
            iterator = curr->next;
            while(iterator != nullptr){
                if(iterator->data <= min->data)
                    min = iterator;
                iterator = iterator->next;
            }
            swap(curr, min);
            curr = curr->next;
        }
    }

/**
* Function that shows the error message for all types of data that are not expected to use
*/
template <class T>
    void Linked_List <T> :: countingsort(int exp, int max_int) {
        cout << "You cannot use this sort for this type of data" << endl;
    }

/**
* Function that performs the counting sort algorithm for the int type of data.
* Uses default arguments for simple countingsort.
* The default values are changed in radixsort algorithm as countingsort is a part of radix sort.
* This sorting algorithm is valid only for the integers in [0,50)
*
* @param exp The default argument that equals 1 for the default countingsort. Contains the value that equals
*        10^(exp-1) in radixsort algorithm where i is number of recursive iteration
* @param max_int The default argument that equals 50 for the default countingsort. Means the maximum possible
*        value for a sorted integer
*/
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
        while (start != nullptr){
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
           while (start != nullptr){
                temp = start->data;
                out[index[(temp / exp) % max_int] - 1] = temp;
                index[(temp / exp) % max_int]--;
                start = start->prev;
            }
        } else {
            start = head;
            while (start != nullptr) {
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

/**
* Function that shows the error message for all types of data that are not expected to use
*/
template <class T>
    void Linked_List <T> :: bucketsort() {
        cout << "You cannot use this sort for this type of data" << endl;
    }

/**
* Function that performs the bucketsort algorithm for the int type of data.
* This sorting algorithm is valid only for the integers in [0,100)
*/
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
        while (start != nullptr){
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
            if (arr[l].get_head() != nullptr){
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
           if (arr[k].get_head() != nullptr){
               tail->next = arr[k].get_head();
               tail = arr[k].get_tail();
           }
        }
    }

/**
* Function that shows the error message for all types of data that are not expected to use
*/
template <class T>
    void Linked_List <T> :: radixsort() {
        cout << "You cannot use this sort for this type of data" << endl;
    }

template<class T>
void Linked_List<T>::pop_node() {
    if(tail == nullptr)
        return;
    Node<T>* temp = tail;
    tail = tail->prev;
    tail->next = nullptr;
    node_sum--;
    delete temp;
}

/**
* Function that performs the radix sort algorithm for the int type of data.
* This sorting algorithm is valid only for the integers in [0,100)
* This algorithm uses modificated countingsort!
*/
template <>
    inline void Linked_List <int> :: radixsort(){

        int exp = 1;
        int max = get_max_int();

        while (max / exp > 0){
            countingsort(exp, 10);

            exp = exp * 10;
        }
    }

    template<class T>
    T &Linked_List<T>::operator[](int i)
    {
        Node<T>* temp = this->head;
        for(int j = 0; j < i; j++){
            temp = temp->next;
        }
        return temp->data;
    }

/**
* Function that swaps the data between indexes
*
* @param a Index a to swap
* @param b Index b to swap
*/
template<class T>
void Vector_List<T>::swap(int a, int b) {

    T temp = arr[a];
    arr[a] = arr[b];
    arr[b] = temp;
}
/**
* Returns the max int in the list
*
* @return the max int in the list
*/
template<class T>
int Vector_List<T>::get_max_int() {
    int temp = arr[0];
    for(int i = 1; i < arr.size(); i++){
        if(arr[i] > temp)
            temp = arr[i];
    }
    return temp;
}
/**
 * Utility function for countingsort that fills the input arrays with zeros
 *
 * @param in The input array to fill
 * @param length The length of this array
 */
template<class T>
void Vector_List<T>::fill_array_0(int *in, int length) {
    for (int i = 0; i < length; i++){
        in[i] = 0;
    }
}

/**
 * Utility function for quicksort that sorts the array relatively to the pivot(< or > than pivot)
 *
 * @param start The start of the array to sort
 * @param finish The finish of the array to sort
 * @return the Index of the end of the sorted part of the array
 */
template<class T>
int Vector_List<T>::partition_quicksort(int start, int finish) {
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

/**
 * Function that performs the quicksort algorithm
 *
 * @param start The start of the subarray to sort
 * @param finish The end of the subarray to sort
 */
template<class T>
void Vector_List<T>::_quicksort(int start, int finish) {
    if (finish != 0 && start != finish && start != finish + 1){
        int pivot = partition_quicksort(start, finish);   //finding the place to pivot
        _quicksort(start, pivot-1);                   //doing the same to the left part
        _quicksort(pivot+1, finish);                  //doing the same to the right part
    }
}

/**
 * The function that divides the array in two subarrays and then merges them into one in ascending order
 *
 * @param left The start of the first array
 * @param middle The end of the first array and the start of the second array
 * @param right The end of the second array
 */
template<class T>
void Vector_List<T>::merge(int left, int middle, int right) {
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

/**
 * Function that performs the mergesort algorithm
 *
 * @param left The left border of the array
 * @param right The right border of the array
 */
template<class T>
void Vector_List<T>::_mergesort(int left, int right) {
    if(left < right) {
        int middle = left + (right - left) / 2;         //avoids the excessing of maxint error
        _mergesort(left, middle);
        _mergesort(middle + 1, right);
        merge(left, middle, right);
    }
}

/**
 * The default constructor
 */
template<class T>
Vector_List<T>::Vector_List() {
    arr.clear();
}

template<class T>
T Vector_List<T>::get_by_index(int index)
{
    return this->arr[index];
}

/**
 * Returns the index of the head of the list
 *
 * @return the index of the head of the list
 */
template<class T>
int Vector_List<T>::get_head() {
    return 0;
}

/**
 * Returns the index of the tail of the list
 *
 * @return the index of the tail of the list
 */
template<class T>
int Vector_List<T>::get_tail() {
    return arr.size() - 1;
}

template<class T>
int Vector_List<T>::get_curr_size() {
    return arr.size();
}

/**
 * Adds the input value to the list
 *
 * @param val The value that will be added to the list
 */
template<class T>
void Vector_List<T>::add_node(T val) {
    arr.push_back(val);
}

/**
* Function that randomly generates the List of the int data
*/
template <>
inline void Vector_List <int> :: generate(){

    arr.clear();

    int length = rand() % 7 + 5;    //the length of the list

    for (int i = 0; i < length; i++){
        add_node(rand() % 49 + 1);
    }
}

/**
* Function that randomly generates the List of the float data
*/
template <>
inline void Vector_List<float> :: generate(){
    arr.clear();

    int length = rand() % 7 + 5;    //the length of the list

    for (int i = 0; i < length; i++){
        add_node((float)rand() / RAND_MAX);
    }
}

/**
* Function that randomly generates the List of the char data
*/
template <>
inline void Vector_List <char> :: generate(){
    arr.clear();

    int length = rand() % 7 + 5;    //the length of the list

    for (int i = 0; i < length; i++){
        add_node(rand() % 95 + 32);
    }
}

/**
* Function that randomly generates the List of the string data
*/
template <>
inline void Vector_List <string> :: generate(){
    arr.clear();

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

/**
* Function that show the error message for this type of data
*/
template <>
inline void Vector_List <Book> :: generate(){
    cout << "for generating Books pls use the Literature structure" << endl;
}

/**
* Function that show the error message for this type of data
*/
template <>
inline void Vector_List <Global_Character> :: generate(){
    cout << "for generating Books pls use the Literature structure" << endl;
}

/**
* Function that prints all the data from the list on the screen
*/
template<class T>
void Vector_List<T>::display() {
    for (int i = 0; i < arr.size(); i++)
        cout << arr[i] << " ";
    cout << endl;
}


/**
* Function that performs the insertion sort algorithm
*/
template<class T>
void Vector_List<T>::insertion_sort() {

    int current_p, insertion_p;               //creating two auxillary pointers
    current_p = insertion_p = 0;              //marking them on the head of the list

    while (current_p < arr.size()  || insertion_p < arr.size() ){ //if both pointer in the end - finish
        current_p = insertion_p + 1;
        while (current_p < arr.size() ){
            if (arr[current_p] <= arr[insertion_p])
                swap(current_p, insertion_p);
            current_p = current_p + 1;
        }
        insertion_p = insertion_p + 1;
    }
}

/**
* Function that basically calls the _quicksort function that is in private section
*/
template<class T>
void Vector_List<T>::quicksort() {
    _quicksort(get_head(), get_tail());  //calls the function
}

/**
* Function that basically calls the _mergesort function that is in private section
*/
template<class T>
void Vector_List<T>::mergesort() {
    _mergesort(0, arr.size() - 1);          //calls the function
}

/**
* Function that performs the selection sort algorithm
*/
template<class T>
void Vector_List<T>::selection_sort() {

    if (get_tail() < 1){
        cout << "Nothing to sort" << endl;
        return;
    }

    int iterator, min;  //indexes
    int curr = 0;

    while(curr < arr.size()){
        //save the smallest val in order to place it on the start of unsorted part of the array
        min = curr;
        iterator = curr + 1;
        while(iterator < arr.size()){
            if(arr[iterator] <= arr[min])
                min = iterator;
            iterator = iterator + 1;
        }
        swap(curr, min);
        curr = curr + 1;
    }
}

/**
* Function that shows the error message for all types of data that are not expected to use
*/
template <class T>
void Vector_List <T> :: countingsort(int exp, int max_int) {
    cout << "You cannot use this sort for this type of data" << endl;
}

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
template<>
inline void Vector_List<int>::countingsort(int exp, int max_int) {
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
    while (start < arr.size()){
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
        while (start < arr.size()) {
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

/**
* Function that shows the error message for all types of data that are not expected to use
*/
template <class T>
inline void Vector_List <T> :: bucketsort() {
    cout << "You cannot use this sort for this type of data" << endl;
}

/**
 * Function that performs the bucketsort algorithm.
 * This sorting algorithm is valid only for the integers in [0,100)
 */
template<>
inline void Vector_List<int>::bucketsort() {

    if (get_tail() < 1){
        cout<<"nothing to sort"<<endl;                  //if number of elements are 0 or 1
        return;
    }

    Linked_List <int> temparr[10];
    int start = get_head();
    int base;                            //the basis dividing
    Node<int> *head, *tail;                 //used to mark head and tail of list in array of list

    //determine the index of the integer to put in
    while (start < arr.size()){
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
        if (temparr[l].get_head() != nullptr){
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
        if (temparr[k].get_head() != nullptr){
            tail->next = temparr[k].get_head();
            tail = temparr[k].get_tail();
        }
    }

    //rewriting the sorted list in our array
    Node<int> *iter = head;
    int k = 0;
    while (iter != nullptr){
        arr[k] = iter->data;
        iter = iter->next;
        k++;
    }
}

/**
* Function that shows the error message for all types of data that are not expected to use
*/
template <class T>
void Vector_List <T> :: radixsort() {
    cout << "You cannot use this sort for this type of data" << endl;
}

/**
 * Deletes the last element of the list
 */
template<class T>
void Vector_List<T>::pop_node() {
    if(arr.size() == 0)
        return;
    arr.pop_back();
}

/**
 * Function that performs the radix sort algorithm.
 * This sorting algorithm is valid only for the integers in [0,100)
 * This algorithm uses modificated countingsort!
 */
template<>
inline void Vector_List<int>::radixsort() {


    int exp = 1;
    int max = get_max_int();

    while (max / exp > 0){
        countingsort(exp, 10);

        exp = exp * 10;
    }
}

template<class T>
T &Vector_List<T>::operator[](int i)
{
    return arr[i];
}
