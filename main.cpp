/**
 * 2nd Course K-29
 * Lab 1. Variant 2-10
 * Task: make a structure of linked list and realise different sort algorithms
 *
 *@author Vitaliy Datsiuk
 *@version 1.5 30/09/19
 */

#include <iostream>
#include "Linked_List.cpp"
#include "Literature.cpp"
#include <vector>


using namespace std;

int main() {

    List<string> s;
    s.add_node("This");
    s.add_node("is");
    s.add_node("a");
    s.add_node("random");
    s.add_node("sentence");
    s.add_node("_02z");
    s.display(s.get_head());
    cout << endl;
    s.selection_sort();
    s.display(s.get_head());
    cout << endl << endl;


    Book B1,B2,B3,B4;
    vector <string> auth1;
    auth1.push_back("Igor");auth1.push_back("OLya");
    Date D1; D1.month = 1; D1.day = 10; D1.year = 2000;
    Character Batman1,Batman2,Batman3, Superman,Superman2, Harry, Kenny,Mohr;
    Batman3.new_character("Batman","Mention2",3);
    Batman2.new_character("Batman","Mention3",2);
    Batman1.new_character("Batman","Book_1",1);
    Superman.new_character("Superman","Mention",1);
    Superman2.new_character("Superman","Mention",2);
    Harry.new_character("Harry","Mention",3);
    Kenny.new_character("Kenny","Mention",1);
    Mohr.new_character("Mohr","Mention",1);
    vector<Character> CH1; CH1.push_back(Batman1);CH1.push_back(Superman);
    vector<Character> CH2; CH2.push_back(Batman2);CH2.push_back(Superman2);
    vector<Character> CH3; CH3.push_back(Batman3);CH3.push_back(Kenny);
    vector<Character> CH4; CH4.push_back(Batman1);CH4.push_back(Mohr);
    B1.new_book("Simple_city",auth1,D1,111,"Annotation1",CH1);
    D1.month = 9;
    B2.new_book("The Great Gatsby",auth1,D1,111,"Annotation2",CH2);
    D1.day = 11;
    B3.new_book("Don Quixote",auth1,D1,111,"Annotation3",CH3);
    D1.year=1111;
    B4.new_book("Moby Dick",auth1,D1,111,"Annotation4",CH4);


    List<Book> b;
    b.add_node(B1);
    b.add_node(B2);
    b.add_node(B3);
    b.add_node(B4);
    b.display(b.get_head());
    cout << endl;
    b.quicksort();
    b.display(b.get_head());
    cout << endl << endl;


    Literature <int> a;
    a.generate_Books();
    a.Books.display(a.Books.get_head());
    cout<<endl;
    a.Characters.display(a.Characters.get_head());
    a.find_series("Batman");
    cout << endl << endl;

    List <double> d;
    d.generate_basic();
    d.display(d.get_head());
    d.mergesort();
    cout << endl;
    d.display(d.get_head());
    cout << endl << endl;

    List<int> i;
    i.add_node(42);
    i.add_node(48);
    i.add_node(31);
    i.add_node(22);
    i.add_node(20);
    i.add_node(33);
    i.display(i.get_head());
    cout << endl;
    i.countingsort();
    //i.radixsort();
    //i.bucketsort();
    i.display(i.get_head());
    cout << endl << endl;



    return 0;
}
