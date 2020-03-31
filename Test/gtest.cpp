/**
 * 2nd Course K-29
 * Lab 1. Variant 2-10
 *
 * Purpose : Provide google tests to the project
 *
 * @author Vitaliy Datsiuk
 * @version 2 26/03/20
 */

#include <iostream>
#include <gtest/gtest.h>
#include "Lists.cpp"
#include "Literature.cpp"

using namespace std;

/**
 * Structure that created in order to test the Array_List
 */
struct Test_Arr_List : public testing::Test{
protected:
    Arr_List<int> *list_int_selfmade;
    Arr_List<int> *list_int_generated1;
    Arr_List<int> *list_int_generated2;
    Arr_List<float> *list_float;
    Arr_List<char> *list_char;
    Arr_List<string> *list_string;
    Array_literature *list_literature;

    void SetUp(){
        list_int_selfmade = new Arr_List<int>();
        list_int_generated1 = new Arr_List<int>();
        list_int_generated2 = new Arr_List<int>();
        list_float = new Arr_List<float>();
        list_char = new Arr_List<char>();
        list_string = new Arr_List<string>();
        list_literature = new Array_literature();

        list_int_selfmade->add_node(2);
        list_int_selfmade->add_node(14);
        list_int_selfmade->add_node(33);
        list_int_selfmade->add_node(23);
        list_int_generated1->generate();
        list_int_generated2->generate();
        list_char->generate();
        list_string->generate();
        list_literature->generate_Books();
    }

    void TearDown(){
        delete list_int_selfmade;
        delete list_int_generated1;
        delete list_int_generated2;
        delete list_float;
        delete list_char;
        delete list_string;
        delete list_literature;
    }
};

/**
 * Test that tests the basic functions of the Array_List
 */
TEST_F(Test_Arr_List, Basic_Test){
    EXPECT_EQ(list_float->get_curr_size(), 0);
    EXPECT_EQ(list_float->get_max_size(), 1);
    EXPECT_EQ(list_float->get_head(), 0);
    EXPECT_EQ(list_float->get_tail(), -1);
    ASSERT_NO_THROW(list_float->pop_node());

    list_float->add_node(3);

    EXPECT_EQ(list_float->get_curr_size(), 1);
    EXPECT_EQ(list_float->get_max_size(), 1);
    EXPECT_EQ(list_float->get_head(), 0);
    EXPECT_EQ(list_float->get_tail(), 0);
    EXPECT_EQ(list_float->arr[0], 3);

    list_float->add_node(0);

    EXPECT_EQ(list_float->get_curr_size(), 2);
    EXPECT_EQ(list_float->get_max_size(), 21);
    EXPECT_EQ(list_float->get_head(), 0);
    EXPECT_EQ(list_float->get_tail(), 1);
    EXPECT_EQ(list_float->arr[1],  0);

    list_float->quicksort();

    EXPECT_EQ(list_float->get_curr_size(), 2);
    EXPECT_EQ(list_float->get_max_size(), 21);
    EXPECT_EQ(list_float->get_head(), 0);
    EXPECT_EQ(list_float->get_tail(), 1);
    EXPECT_EQ(list_float->arr[1],  3);

    list_float->pop_node();

    EXPECT_EQ(list_float->get_curr_size(), 1);
    EXPECT_EQ(list_float->get_max_size(), 21);
    EXPECT_EQ(list_float->get_head(), 0);
    EXPECT_EQ(list_float->get_tail(), 0);
    EXPECT_EQ(list_float->arr[0], 0);
}

/**
 * Test that tests all of the sort functions of the Array_List
 */
TEST_F(Test_Arr_List, Sorts_Test){
    ASSERT_NO_THROW(list_int_selfmade->selection_sort());
    for(size_t  i = 0; i < list_int_selfmade->get_curr_size() - 1; i++)
        ASSERT_LE(list_int_selfmade->arr[i],list_int_selfmade->arr[i + 1]);
    ASSERT_NO_THROW(list_int_generated1->insertion_sort());
    for(size_t  i = 0; i < list_int_generated1->get_curr_size() - 1; i++)
        ASSERT_LE(list_int_generated1->arr[i],list_int_generated1->arr[i + 1]);
    ASSERT_NO_THROW(list_int_generated2->quicksort());
    for(size_t  i = 0; i < list_int_generated2->get_curr_size() - 1; i++)
        ASSERT_LE(list_int_generated2->arr[i],list_int_generated2->arr[i + 1]);
    ASSERT_NO_THROW(list_char->mergesort());
    for(size_t  i = 0; i < list_char->get_curr_size() - 1; i++)
        ASSERT_LE(list_char->arr[i],list_char->arr[i + 1]);
    ASSERT_NO_THROW(list_string->selection_sort());
    for(size_t  i = 0; i < list_string->get_curr_size() - 1; i++)
        ASSERT_LE(list_string->arr[i],list_string->arr[i + 1]);
    ASSERT_NO_THROW(list_literature->sort_books());
    for(size_t  i = 0; i < list_literature->Books.get_curr_size() - 1; i++)
        ASSERT_TRUE(list_literature->Books.arr[i] <= list_literature->Books.arr[i + 1]);

    TearDown();
    SetUp();

    ASSERT_NO_THROW(list_int_selfmade->bucketsort());
    for(size_t  i = 0; i < list_int_selfmade->get_curr_size() - 1; i++)
        ASSERT_LE(list_int_selfmade->arr[i],list_int_selfmade->arr[i + 1]);

    TearDown();
    SetUp();

    ASSERT_NO_THROW(list_int_selfmade->radixsort());
    for(size_t  i = 0; i < list_int_selfmade->get_curr_size() - 1; i++)
        ASSERT_LE(list_int_selfmade->arr[i],list_int_selfmade->arr[i + 1]);
}

/**
 * Structure that created in order to test the Linked_List
 */
struct Test_Linked_List : public testing::Test{
protected:
    Linked_List<int> *list_int_selfmade;
    Linked_List<int> *list_int_generated1;
    Linked_List<int> *list_int_generated2;
    Linked_List<float> *list_float;
    Linked_List<char> *list_char;
    Linked_List<string> *list_string;
    Linked_literature *list_literature;

    void SetUp(){
        list_int_selfmade = new Linked_List<int>();
        list_int_generated1 = new Linked_List<int>();
        list_int_generated2 = new Linked_List<int>();
        list_float = new Linked_List<float>();
        list_char = new Linked_List<char>();
        list_string = new Linked_List<string>();
        list_literature = new Linked_literature();

        list_int_selfmade->add_node(2);
        list_int_selfmade->add_node(14);
        list_int_selfmade->add_node(33);
        list_int_selfmade->add_node(23);
        list_int_generated1->generate();
        list_int_generated2->generate();
        list_char->generate();
        list_string->generate();
        list_literature->generate_Books();
    }

    void TearDown(){
        delete list_int_selfmade;
        delete list_int_generated1;
        delete list_int_generated2;
        delete list_float;
        delete list_char;
        delete list_string;
        delete list_literature;
    }
};

/**
 * Test that tests the basic functions of the Linked_List
 */
TEST_F(Test_Linked_List, Basic_Test){
    EXPECT_EQ(list_float->get_node_sum(), 0);
    EXPECT_TRUE(list_float->get_head() == NULL);
    EXPECT_TRUE(list_float->get_tail() == NULL);
    ASSERT_NO_THROW(list_float->pop_node());

    list_float->add_node(3);

    EXPECT_EQ(list_float->get_node_sum(), 1);
    EXPECT_EQ(list_float->get_head()->data, 3);
    EXPECT_EQ(list_float->get_tail()->data, 3);

    list_float->add_node(0);

    EXPECT_EQ(list_float->get_node_sum(), 2);
    EXPECT_EQ(list_float->get_head()->data, 3);
    EXPECT_EQ(list_float->get_tail()->data, 0);
    EXPECT_EQ(list_float->get_head()->next->data,  0);

    list_float->quicksort();

    EXPECT_EQ(list_float->get_node_sum(), 2);
    EXPECT_EQ(list_float->get_head()->data, 0);
    EXPECT_EQ(list_float->get_tail()->data, 3);
    EXPECT_EQ(list_float->get_head()->next->data,  3);

    list_float->pop_node();

    EXPECT_EQ(list_float->get_node_sum(), 1);
    EXPECT_EQ(list_float->get_head()->data, 0);
    EXPECT_EQ(list_float->get_tail()->data, 0);
}

/**
 * Test that tests all of the sort functions of the Linked_List
 */
TEST_F(Test_Linked_List, Sorts_Test){
    ASSERT_NO_THROW(list_int_selfmade->selection_sort());
    Node<int> *temp_self = list_int_selfmade->get_head();
    for(size_t  i = 0; i < list_int_selfmade->get_node_sum() - 1; i++){
        ASSERT_LE(temp_self->data, temp_self->next->data);
        temp_self = temp_self->next;
    }
    ASSERT_NO_THROW(list_int_generated1->insertion_sort());
    Node<int> *temp_gen1 = list_int_generated1->get_head();
    for(size_t  i = 0; i < list_int_generated1->get_node_sum() - 1; i++){
        ASSERT_LE(temp_gen1->data, temp_gen1->next->data);
        temp_gen1 = temp_gen1->next;
    }
    ASSERT_NO_THROW(list_int_generated2->quicksort());
    Node<int> *temp_gen2 = list_int_generated2->get_head();
    for(size_t  i = 0; i < list_int_generated2->get_node_sum() - 1; i++){
        ASSERT_LE(temp_gen2->data, temp_gen2->next->data);
        temp_gen2 = temp_gen2->next;
    }
    ASSERT_NO_THROW(list_char->mergesort());
    Node<char> *temp_char = list_char->get_head();
    for(size_t  i = 0; i < list_char->get_node_sum() - 1; i++){
        ASSERT_LE(temp_char->data, temp_char->next->data);
        temp_char = temp_char->next;
    }
    ASSERT_NO_THROW(list_string->selection_sort());
    Node<string> *temp_string = list_string->get_head();
    for(size_t  i = 0; i < list_string->get_node_sum() - 1; i++){
        ASSERT_LE(temp_string->data, temp_string->next->data);
        temp_string = temp_string->next;
    }
    ASSERT_NO_THROW(list_literature->sort_books());
    Node<Book> *temp_book = list_literature->Books.get_head();
    for(size_t  i = 0; i < list_literature->Books.get_node_sum() - 1; i++){
        ASSERT_TRUE(temp_book->data <= temp_book->next->data);
        temp_book = temp_book->next;
    }

    TearDown();
    SetUp();

    ASSERT_NO_THROW(list_int_selfmade->bucketsort());
    Node<int> *temp_self1 = list_int_selfmade->get_head();
    for(size_t  i = 0; i < list_int_selfmade->get_node_sum() - 1; i++){
        ASSERT_LE(temp_self1->data, temp_self1->next->data);
        temp_self1 = temp_self1->next;
    }
    TearDown();
    SetUp();

    ASSERT_NO_THROW(list_int_selfmade->radixsort());
    Node<int> *temp_self2 = list_int_selfmade->get_head();
    for(size_t  i = 0; i < list_int_selfmade->get_node_sum() - 1; i++){
        ASSERT_LE(temp_self2->data, temp_self2->next->data);
        temp_self2 = temp_self2->next;
    }
}

/**
 * Structure that created in order to test the Vector_List
 */
struct Test_Vector_List : public testing::Test{
protected:
    Vector_List<int> *list_int_selfmade;
    Vector_List<int> *list_int_generated1;
    Vector_List<int> *list_int_generated2;
    Vector_List<float> *list_float;
    Vector_List<char> *list_char;
    Vector_List<string> *list_string;
    Vector_literature *list_literature;

    void SetUp(){
        list_int_selfmade = new Vector_List<int>();
        list_int_generated1 = new Vector_List<int>();
        list_int_generated2 = new Vector_List<int>();
        list_float = new Vector_List<float>();
        list_char = new Vector_List<char>();
        list_string = new Vector_List<string>();
        list_literature = new Vector_literature();

        list_int_selfmade->add_node(2);
        list_int_selfmade->add_node(14);
        list_int_selfmade->add_node(33);
        list_int_selfmade->add_node(23);
        list_int_generated1->generate();
        list_int_generated2->generate();
        list_char->generate();
        list_string->generate();
        list_literature->generate_Books();
    }

    void TearDown(){
        delete list_int_selfmade;
        delete list_int_generated1;
        delete list_int_generated2;
        delete list_float;
        delete list_char;
        delete list_string;
        delete list_literature;
    }
};

/**
 * Test that tests the basic functions of the Vector_List
 */
TEST_F(Test_Vector_List, Basic_Test){
    EXPECT_EQ(list_float->get_curr_size(), 0);
    EXPECT_EQ(list_float->get_head(), 0);
    EXPECT_EQ(list_float->get_tail(), -1);
    ASSERT_NO_THROW(list_float->pop_node());

    list_float->add_node(3);

    EXPECT_EQ(list_float->get_curr_size(), 1);
    EXPECT_EQ(list_float->get_head(), 0);
    EXPECT_EQ(list_float->get_tail(), 0);
    EXPECT_EQ(list_float->arr[0], 3);

    list_float->add_node(0);

    EXPECT_EQ(list_float->get_curr_size(), 2);
    EXPECT_EQ(list_float->get_head(), 0);
    EXPECT_EQ(list_float->get_tail(), 1);
    EXPECT_EQ(list_float->arr[1],  0);

    list_float->quicksort();

    EXPECT_EQ(list_float->get_curr_size(), 2);
    EXPECT_EQ(list_float->get_head(), 0);
    EXPECT_EQ(list_float->get_tail(), 1);
    EXPECT_EQ(list_float->arr[1],  3);

    list_float->pop_node();

    EXPECT_EQ(list_float->get_curr_size(), 1);
    EXPECT_EQ(list_float->get_head(), 0);
    EXPECT_EQ(list_float->get_tail(), 0);
    EXPECT_EQ(list_float->arr[0], 0);
}

/**
 * Test that tests all of the sort functions of the Vector_List
 */
TEST_F(Test_Vector_List, Sorts_Test){
    ASSERT_NO_THROW(list_int_selfmade->selection_sort());
    for(size_t  i = 0; i < list_int_selfmade->get_curr_size() - 1; i++)
        ASSERT_LE(list_int_selfmade->arr[i],list_int_selfmade->arr[i + 1]);
    ASSERT_NO_THROW(list_int_generated1->insertion_sort());
    for(size_t  i = 0; i < list_int_generated1->get_curr_size() - 1; i++)
        ASSERT_LE(list_int_generated1->arr[i],list_int_generated1->arr[i + 1]);
    ASSERT_NO_THROW(list_int_generated2->quicksort());
    for(size_t  i = 0; i < list_int_generated2->get_curr_size() - 1; i++)
        ASSERT_LE(list_int_generated2->arr[i],list_int_generated2->arr[i + 1]);
    ASSERT_NO_THROW(list_char->mergesort());
    for(size_t  i = 0; i < list_char->get_curr_size() - 1; i++)
        ASSERT_LE(list_char->arr[i],list_char->arr[i + 1]);
    ASSERT_NO_THROW(list_string->selection_sort());
    for(size_t  i = 0; i < list_string->get_curr_size() - 1; i++)
        ASSERT_LE(list_string->arr[i],list_string->arr[i + 1]);
    ASSERT_NO_THROW(list_literature->sort_books());
    for(size_t  i = 0; i < list_literature->Books.get_curr_size() - 1; i++)
        ASSERT_TRUE(list_literature->Books.arr[i] <= list_literature->Books.arr[i + 1]);

    TearDown();
    SetUp();

    ASSERT_NO_THROW(list_int_selfmade->bucketsort());
    for(size_t  i = 0; i < list_int_selfmade->get_curr_size() - 1; i++)
        ASSERT_LE(list_int_selfmade->arr[i],list_int_selfmade->arr[i + 1]);

    TearDown();
    SetUp();

    ASSERT_NO_THROW(list_int_selfmade->radixsort());
    for(size_t  i = 0; i < list_int_selfmade->get_curr_size() - 1; i++)
        ASSERT_LE(list_int_selfmade->arr[i],list_int_selfmade->arr[i + 1]);
}
