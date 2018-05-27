// Copyright 2018 Chernenko Valery

#include <gtest/gtest.h>
#include "include/RBTree.h"

TEST(RBTree, can_create_empty_tree) {
    ASSERT_NO_THROW(RBTree T);
}

TEST(RBTree, creation_empty_tree_not_added_node) {
    RBTree T;

    EXPECT_EQ(RBTree::NIL, T.findNode(5));
}

TEST(RBTree, can_not_found_node_with_NIL_data_in_empty_tree) {
    RBTree T;

    EXPECT_EQ(RBTree::NIL, T.findNode(RBTree::NIL->data));
}

TEST(RBTree, can_found_NIL_data) {
    RBTree T;

    T.insertNode(RBTree::NIL->data);

    EXPECT_NE(RBTree::NIL, T.findNode(RBTree::NIL->data));
}

TEST(RBTree, can_create_tree) {
    ASSERT_NO_THROW(RBTree T(5));
}

TEST(RBTree, creation_tree_add_data) {
    RBTree T(5);

    EXPECT_NE(RBTree::NIL, T.findNode(5));
}

TEST(RBTree, creation_tree_add_correct_data) {
    RBTree T(5);

    EXPECT_EQ(5, T.findNode(5)->data);
}

TEST(RBTree, creation_tree_add_correct_child) {
    RBTree T;

    T.insertNode(5);
    T.insertNode(8);

    EXPECT_EQ(T.findNode(8)->left, T.findNode(8)->right);
}

TEST(RBTree, creation_tree_add_correct_parent) {
    RBTree T(5);

    EXPECT_EQ(T.findNode(5)->parent, nullptr);
}

TEST(RBTree, can_create_tree_from_array) {
    int array[10];

    for (int i = 0; i < 5; i++)
        array[i] = i * 2;
    for (int i = 5; i < 10; i++)
        array[i] = 30 - i * 2;

    ASSERT_NO_THROW(RBTree T(array, 10));
}

TEST(RBTree, can_create_tree_from_array_inverted) {
    int array[10];

    for (int i = 0; i < 5; i++)
        array[i] = 30 - i * 2;
    for (int i = 5; i < 10; i++)
        array[i] = i * 2;

    ASSERT_NO_THROW(RBTree T(array, 10));
}

TEST(RBTree, creation_tree_from_array_add_node) {
    int array[10];
    bool check = true;

    for (int i = 0; i < 5; i++)
        array[i] = i * 2;
    for (int i = 5; i < 10; i++)
        array[i] = -i * 2;
    RBTree T(array, 10);
    for (int i = 0; i < 5; i++)
        if (RBTree::NIL == T.findNode(i * 2)) check = false;
    for (int i = 5; i < 10; i++)
        if (RBTree::NIL == T.findNode(-i * 2)) check = false;

    EXPECT_TRUE(check);
}

TEST(RBTree, creation_tree_from_array_add_node_inverted) {
    int array[20];
    bool check = true;

    for (int i = 0; i < 10; i++)
        array[i] = -i * 3 + 10;
    for (int i = 10; i < 20; i++)
        array[i] = i * 2;
    RBTree T(array, 20);
    for (int i = 0; i < 10; i++)
        if (RBTree::NIL == T.findNode(-i * 3 + 10)) check = false;
    for (int i = 10; i < 20; i++)
        if (RBTree::NIL == T.findNode(i * 2)) check = false;

    EXPECT_TRUE(check);
}

TEST(RBTree, correctly_working_insertFixup) {
    RBTree T;
    bool check = true;

    for (int i = 1; i < 10; i++)
        T.insertNode(i * 5);
    for (int i = 1; i < 20; i++)
        T.insertNode(i * 4);
    for (int i = 1; i < 10; i++)
        T.insertNode(i * 3);
    for (int i = 1; i < 10; i++)
        T.insertNode(i * 2);
    for (int i = 1; i < 10; i++)
        if (T.findNode(i * 5) == RBTree::NIL) check = false;
    for (int i = 1; i < 20; i++)
        if (T.findNode(i * 4) == RBTree::NIL) check = false;
    for (int i = 1; i < 10; i++)
        if (T.findNode(i * 3) == RBTree::NIL) check = false;
    for (int i = 1; i < 10; i++)
        if (T.findNode(i * 2) == RBTree::NIL) check = false;

    EXPECT_TRUE(check);
}

TEST(RBTree, can_delete_nonexistent_node) {
    RBTree T(5);

    ASSERT_NO_THROW(T.deleteNode(8));
}

TEST(RBTree, can_delete_node) {
    RBTree T;

    T.insertNode(5);
    T.deleteNode(5);

    EXPECT_EQ(RBTree::NIL, T.findNode(5));
}

TEST(RBTree, can_delete_root) {
    RBTree T;

    T.insertNode(5);
    T.insertNode(8);
    T.deleteNode(5);

    EXPECT_EQ(RBTree::NIL, T.findNode(5));
}

TEST(RBTree, can_delete_node_in_huge_tree) {
    int array[20];

    for (int i = 0; i < 10; i++)
        array[i] = i * 2;
    for (int i = 10; i < 20; i++)
        array[i] = -i * 2;
    RBTree T(array, 20);

    T.deleteNode(0);
    T.deleteNode(10);
    T.deleteNode(-2);
    T.deleteNode(-6);

    EXPECT_EQ(RBTree::NIL, T.findNode(0));
    EXPECT_EQ(RBTree::NIL, T.findNode(10));
    EXPECT_EQ(RBTree::NIL, T.findNode(-2));
    EXPECT_EQ(RBTree::NIL, T.findNode(-6));
}


TEST(RBTree, can_delete_node_in_huge_tree_2) {
    int array[100];

    array[0] = 0;
    for (int i = 1; i < 99; i += 2) {
        array[i] = 100000 / i;
        array[i + 1] = -100000 / i;
    }
    array[99] = 1;
    RBTree T(array, 100);

    T.deleteNode(0);
    T.deleteNode(100000 / 7);
    T.deleteNode(-100000 / 12);
    T.deleteNode(-100000 / 14);
    T.deleteNode(-100000 / 16);
    T.deleteNode(-100000 / 18);
    T.deleteNode(-100000 / 80);

    EXPECT_EQ(RBTree::NIL, T.findNode(0));
    EXPECT_EQ(RBTree::NIL, T.findNode(100000 / 7));
    EXPECT_EQ(RBTree::NIL, T.findNode(-100000 / 14));
    EXPECT_EQ(RBTree::NIL, T.findNode(-100000 / 16));
    EXPECT_EQ(RBTree::NIL, T.findNode(-100000 / 18));
    EXPECT_EQ(RBTree::NIL, T.findNode(-100000 / 80));
}

TEST(RBTree, can_delete_node_in_huge_tree_3) {
    int array[100];
    bool check = true;

    array[0] = 0;
    for (int i = 1; i < 99; i += 2) {
        array[i] = 125125 / i;
        array[i + 1] = -125125 / i + 1;
    }
    array[99] = 1;
    RBTree T(array, 100);

    for (int i = 1; i < 19; i += 2) {
        T.deleteNode(125125 / i);
        T.deleteNode(-125125 / i + 1);
    }

    for (int i = 1; i < 19; i += 2) {
        if (T.findNode(125125 / i) != RBTree::RBTree::NIL) check = false;
        if (T.findNode(125125 / i + 1) != RBTree::RBTree::NIL) check = false;
    }

    EXPECT_TRUE(check);
}

TEST(RBTree, can_delete_node_in_very_hude_tree) {
    int array[1000];
    bool check = true;

    for (int i = 0; i < 100; i+=10) {
        array[i] = i;
        array[i + 1] = -i;
        array[i + 2] = i * 2;
        array[i + 3] = - i * 2;
        array[i + 4] = i * 3;
        array[i + 5] = - i * 3;
        array[i + 6] = i * 5;
        array[i + 7] = i * 9;
        array[i + 8] = i * 7;
        array[i + 9] = - i * 7;
    }

    RBTree T(array, 1000);
    for (int i = 0; i < 100; i+=10) {
        int ccount = T.findNode(i * 5)->count;
        T.deleteNode(i * 5);
        if (ccount != T.findNode(i * 5)->count + 1) check = false;
    }

    EXPECT_TRUE(check);
}

TEST(RBTree, can_delete_node_in_very_hude_tree_2) {
    int array[10000];
    bool check = true;

    for (int i = 9999; i >=0; i -= 10) {
        array[i] = i;
        array[i - 1] = -i;
        array[i - 2] = i * 2;
        array[i - 3] = -i * 2;
        array[i - 4] = i * 3;
        array[i - 5] = -i * 3;
        array[i - 6] = i * 5;
        array[i - 7] = i * 9;
        array[i - 8] = i * 7;
        array[i - 9] = -i * 7;
    }

    RBTree T(array, 10000);
    for (int i = 9999; i >= 0; i-=10) {
        int ccount = T.findNode(i * 5)->count;
        T.deleteNode(i * 5);
        if (ccount != T.findNode(i * 5)->count + 1) check = false;
    }

    EXPECT_TRUE(check);
}

TEST(RBTree, can_add_two_node) {
    RBTree T;

    T.insertNode(5);
    T.insertNode(5);

    EXPECT_NE(RBTree::NIL, T.findNode(5));
}

TEST(RBTree, can_add_more_nodes) {
    RBTree T;

    for (int i = 0; i < 100; i++)
        T.insertNode(i);

    EXPECT_NE(RBTree::NIL, T.findNode(5));
}

TEST(RBTree, can_add_more_nodes_inverted) {
    RBTree T;

    for (int i = 0; i < 100; i++)
        T.insertNode(-i);

    EXPECT_NE(RBTree::NIL, T.findNode(-5));
}

TEST(RBTree, can_delete_two_node) {
    RBTree T;

    T.insertNode(5);
    T.insertNode(5);
    T.deleteNode(5);

    EXPECT_NE(RBTree::NIL, T.findNode(5));
}
