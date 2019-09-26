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
#include <vector>

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


    vector<string> authors1,authors2,authors3,authors4,authors5;
    authors1.push_back("andrey");
    authors2.push_back("Vasya");
    authors3.push_back("Oleg");authors3.push_back("Egor");
    authors4.push_back("Maxim");
    authors5.push_back("Mykola");authors5.push_back("Vanya");authors5.push_back("Stas");
    Date date1,date2,date3,date4,date5;
    date1.day = 1;date1.month = 2; date1.year = 1221;
    date2.day = 12;date2.month = 2; date2.year = 234;
    date3.day = 23;date3.month = 7; date3.year = 1467;
    date4.day = 31;date4.month = 12; date4.year = 2012;
    date5.day = 15;date5.month = 3; date5.year = 2009;
    Character a1,b1,c1,d1,e1,f1,g1,h1,s1,r1,t1;
    vector <string> ment1,ment2,ment3;
    ment1.push_back("simple book");ment1.push_back("empty city");
    ment2.push_back("empty city");ment2.push_back("dead city");ment2.push_back("full city");
    ment3.push_back("otherwise");ment3.push_back("hollywood");ment2.push_back("simple book");
    vector <int> imp1,imp2,imp3;
    imp1.push_back(1);imp1.push_back(2);
    imp2.push_back(2);imp2.push_back(3);imp2.push_back(3);
    imp3.push_back(1);imp3.push_back(2);imp3.push_back(1);
    vector<Character> char1,char2,char3,char4,char5;
    a1.new_character("Batman",ment1,imp1);
    b1.new_character("Superman",ment3,imp3);
    c1.new_character("Bobby",ment3,imp3);
    d1.new_character("Hlory",ment2,imp2);
    e1.new_character("deddy",ment3,imp2);
    f1.new_character("manny",ment1,imp1);
    char1.push_back(a1);char1.push_back(c1);char1.push_back(d1);
    char2.push_back(f1);char2.push_back(a1);
    char3.push_back(e1);char3.push_back(d1);char3.push_back(c1);char3.push_back(b1);
    char4.push_back(a1);char4.push_back(e1);
    char5.push_back(f1);char5.push_back(d1);char5.push_back(c1);


    Book q1;
    q1.new_book("Name 1",authors1,date1,15,"annotation1",char1);

    Book q2;
    q2.new_book("Name 2",authors2,date2,25,"annotation2",char4);

    Book q3;
    q3.new_book("Name 3",authors3,date3,35,"annotation3",char3);

    q1.display_book_full();

    List<Book> booklist;
    booklist.add_node(q1);
    booklist.add_node(q2);
    booklist.add_node(q3);

    booklist.find_series("Batman");

/*    List<int> i;
    i.add_node(42);
    i.add_node(48);
    i.add_node(31);
    i.add_node(22);
    i.add_node(20);
    i.add_node(33);
    i.display(i.get_head());
    cout << endl;
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
    s.selection_sort();
    s.display(s.get_head());*/

    return 0;
}
