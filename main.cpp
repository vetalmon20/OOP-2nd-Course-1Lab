/**
 * 2nd Course K-29
 * Lab 1. Variant 2-10
 * Task: make a structure of linked list and realise different sort algorithms
 *
 *@author Vitaliy Datsiuk
 *@version 1.1 16/09/19
 */

#include <iostream>

using namespace std;

//Structure of the Node used in structure of the Linked List
template <typename T>
struct Node{
    T data;
    Node* next;         //Pointer on the next element
    Node* prev;         //Pointer on the previous element
};

//Structure of the Linked list
template <typename T>
struct  List {
private:

    Node <T> *head, *tail;                     //two pointers on the first and the last node
    int node_sum;                              //number of the nodes is list

    void swap(Node <T> *a, Node <T> *b) {

        //cathing the possible error
        if(a == NULL || b == NULL){
            cout << "One of the nodes is empty. Nothing to swap." << endl;
            return;
        }

        T temp;
        temp = a->data;
        a->data = b->data;
        b->data = temp;
    }   //swaps the data between nodes

    Node <T>* partition_quicksort(Node <T>* start, Node <T>* finish){

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
    } //util.funct.for quicksort

    void _quicksort(Node <T>* start, Node <T>* finish){

        if (finish != NULL && start != finish && start != finish->next){
            Node <T> *pivot = partition_quicksort(start, finish);
            _quicksort(start, pivot->prev);
            _quicksort(pivot->next, finish);
        }
    }    //actually quicksort

    //splits the list on two halves. Used in mergesort
    void listsplit_mergesort(Node <T> *start, Node <T> **first, Node <T> **second){

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
        slow->next = NULL;          //sssssssssssssssssssssssssssssssssss
    }

    //merges two lists
    Node <T> *merge(Node <T> *first, Node <T> *second){

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

    void _mergesort(Node <T> **source)
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

public:
    List(){

        head = NULL;
        tail = NULL;
        node_sum = 0;
    }
    Node <T>* get_tail(){
        return tail;
    }

    Node <T>* get_head(){
        return head;
    }

    int get_node_sum(){
        return node_sum;
    }

    void add_node(T val){

        Node <T> *new_node = new Node <T>;
        new_node->data = val;
        new_node->next = NULL;
        new_node->prev = NULL;

        if (head == NULL){
            head = new_node;
            tail = new_node;
        } else {
            if (head != tail)
                new_node->prev = tail;
            tail->next = new_node;
            tail = tail->next;
        }

        node_sum ++;                    //updated the number of the nodes
    }

    virtual void display(Node <T> *start){

        if(start != NULL)
        {
            cout << start->data << " ";
            display(start->next);
        }
    }  //printing all the data from the list on the screen

    void insertion_sort(){

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

    void quicksort(){
        _quicksort(head,tail);  //calls the function
    }           //just calls the recursive _quicksort function in private

    void mergesort(){
        _mergesort(&head);
    }           //just calls the recursive _quicksort function in private

};

struct point:List<point>  {
    int x;
    int y;
    void display(Node <point> *start) override {
        cout<<"I AM HERE";
    }
    friend std::ostream& operator<< (std::ostream &out, const point &Point);
};

std::ostream& operator<< (std::ostream &out, const point &Point)
{
    out <<" "<<Point.x<<" "<<Point.y<<" ";

    return out;
}

int main() {


    List<int> i;
    i.add_node(4);
    i.add_node(5);
    i.add_node(3);
    i.add_node(2);
    i.add_node(10);
    i.add_node(7);
    i.display(i.get_head());
    cout<<endl;
    //i.quicksort();
    //i.insertion_sort();
    Node <int> *SA=i.get_head();
    i.mergesort();
    i.display(i.get_head());

    // cout<<"number of the nodes is:"<<i.get_node_sum()<<endl;

    List<string> s;
    s.add_node("my");
    s.add_node("name");
    s.add_node("is");
    s.add_node("Vitaliy");
    s.add_node("Datsiuk");
    s.add_node("thx");
    s.display(s.get_head());
    cout<<endl;
    Node <string> *SA1=s.get_head();
    s.mergesort();
    s.display(s.get_head());

    //point t1;
    //t1.x=11;
    //t1.y=22;
    //point te;
    //te.add_node(t1);
    //te.display(te.get_head());


    return 0;
}