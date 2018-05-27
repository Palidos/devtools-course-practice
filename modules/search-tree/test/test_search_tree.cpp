// Copyright 2018 Gorelova Ksenia

#include <gtest/gtest.h>

#include "include/search_tree.h"

TEST(Gorelova_Ksenia_SearchTree_Test, can_create_tree) {
    ASSERT_NO_THROW(new SearchTree());
}

TEST(Gorelova_Ksenia_SearchTree_Test, can_delete_empty_tree) {
    SearchTree * tree = new SearchTree();
    ASSERT_NO_THROW(delete tree);
}


TEST(Gorelova_Ksenia_SearchTree_Test, can_insert_element_in_empty_tree) {
    SearchTree tree;
    int key = 11;

    ASSERT_NO_THROW(tree.Insert(key));
}

TEST(Gorelova_Ksenia_SearchTree_Test, can_insert_element_in_left_branch) {
    SearchTree tree;

    tree.Insert(10);
    tree.Insert(7);

    ASSERT_EQ(nullptr, tree.Search(7)->left);
    ASSERT_EQ(nullptr, tree.Search(7)->right);
}

TEST(Gorelova_Ksenia_SearchTree_Test, can_insert_element_in_right_branch) {
    SearchTree tree;

    tree.Insert(10);
    tree.Insert(17);

    ASSERT_EQ(nullptr, tree.Search(17)->left);
    ASSERT_EQ(nullptr, tree.Search(17)->right);
}

TEST(Gorelova_Ksenia_SearchTree_Test, can_search_empty_element) {
    SearchTree tree;
    int key = 11;

    ASSERT_EQ(nullptr, tree.Search(key));
}

TEST(Gorelova_Ksenia_SearchTree_Test, can_search_element) {
    SearchTree tree;
    int key = 5;

    tree.Insert(key + 5);
    tree.Insert(key + 10);
    tree.Insert(key);
    tree.Insert(key - 1);

    ASSERT_EQ(key, tree.Search(key)->value);
}

TEST(Gorelova_Ksenia_SearchTree_Test, can_search_element_in_right_branch) {
    SearchTree tree;
    int key = 25;

    tree.Insert(20);
    tree.Insert(10);
    tree.Insert(1);
    tree.Insert(key);

    EXPECT_EQ(key, tree.Search(key)->value);
}

TEST(Gorelova_Ksenia_SearchTree_Test, can_search_element_in_left_branch) {
    SearchTree tree;
    int key = 1;

    tree.Insert(20);
    tree.Insert(10);
    tree.Insert(5);
    tree.Insert(key);

    EXPECT_EQ(key, tree.Search(key)->value);
}

TEST(Gorelova_Ksenia_SearchTree_Test, can_destroy_empty_tree) {
    SearchTree * tree = new SearchTree();

    ASSERT_NO_THROW(tree->~SearchTree());
    delete tree;
}
