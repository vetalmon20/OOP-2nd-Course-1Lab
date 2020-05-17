/**
 * 2nd Course K-29
 * Lab 1. Variant 2-10
 * Task: make a structure of linked list and realise different sort algorithms
 *
 * Purpose: the main function that user have access to.
 *
 *@author Vitaliy Datsiuk
 *@version 2 08/10/19
 */

#include "demo.cpp"
#include <gtest/gtest.h>
#include <QtWidgets/QApplication>
#include "mainwindow.h"
#include "Lists.h"

//Here you can use the test functions in order to test the program whatever You like

int main(int argc, char* argv[]) {

    testing::InitGoogleTest(&argc, argv);

    QApplication app(argc, argv);
    mainwindow *window = new mainwindow;

    window->show();
    app.exec();

   // Linked_List<float> temp;
   // temp.generate();
   // temp.display();
   // cout << temp[3];

    //demo();
    // Arr_List<int> a;
    // a.generate();
    //a.display();

    return RUN_ALL_TESTS();
    //return 0;
}
