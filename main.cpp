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
    Node <T> *head,*tail;
public:
    List(){
        head = NULL;
        tail = NULL;
    }
    Node <T>* get_tail(){
        return tail;
    }
    Node <T>* get_head(){
        return head;
    }
    void add_node(T val){
        Node <T> *new_node = new Node <T>;
        T tmp;
        tmp = val;
        new_node->data = tmp;
        new_node->next = NULL;
        if (head == NULL){
            head = new_node;
            tail = new_node;
            new_node->prev = NULL;
        } else {
            new_node->prev = tail;
            tail->next = new_node;
            tail = tail->next;
        }
    }
    void display(Node <T> *start){
        if(start != NULL)
        {
            cout << start->data << " ";
            display(start->next);
        }
    }


};

struct point  {
    int x;
    int y;
    friend std::ostream& operator<< (std::ostream &out, const point &Point);
};

std::ostream& operator<< (std::ostream &out, const point &Point)
{
    out <<" "<<Point.x<<" "<<Point.y<<" ";

    return out;
}

int main() {

    List<int> t;
    t.add_node(4);
    t.add_node(5);
    point t1;
    t1.x=11;
    t1.y=22;
    List<point> te;
    te.add_node(t1);
    t.display(t.get_head());






    return 0;
}