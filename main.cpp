/**
 * 2nd Course K-29
 * Lab 1. Variant 2-10
 * Task: make a structure of linked list and realise different sort algorithms
 *
 *@author Vitaliy Datsiuk
 *@version 1.4 25/09/19
 */

#include <iostream>
#include "Linked_List.cpp"

using namespace std;

/*};*/

/*struct point:List<point>  {
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
}*/

int main() {

/*    string q;
    string as;
    int l;
    if(typeid(q).name() == typeid(as).name())
        cout<<"ya";
    if(typeid(q).name() == typeid("sss").name())
        cout<<"da";
    if(typeid(q).name() == typeid(l).name())
        cout<<"qa";*/

    List<string> a;
    a.generate_string();
    a.display(a.get_head());
    cout<<"-------"<<endl;

    List<int> i;
    i.add_node(42);
    i.add_node(48);
    i.add_node(31);
    i.add_node(22);
    i.add_node(20);
    i.add_node(33);
    i.display(i.get_head());
    cout << endl;
    //i.quicksort();
    //i.insertion_sort();;
    //i.mergesort();
    //i.countingsort();
    //i.bucketsort();
    //i.radixsort();
    i.selection_sort();
    i.display(i.get_head());

    List<string> s;
    s.add_node("my");
    s.add_node("name");
    s.add_node("is");
    s.add_node("Vitaliy");
    s.add_node("Datsiuk");
    s.add_node("thx");
    s.display(s.get_head());
    cout << endl;
    Node<string> *SA1 = s.get_head();
    s.selection_sort();
    s.display(s.get_head());

    //point t1;
    //t1.x=11;
    //t1.y=22;
    //point te;
    //te.add_node(t1);
    //te.display(te.get_head());


    return 0;
}
