// Copyright 2018 Sannikova Vika

#include <gtest/gtest.h>
#include "include/avl_tree.h"

TEST(Sannikova_Vika_AVLTreeTest, Can_Find_Min_In_AVL_Tree) {
    // Arrange
    AVL avltree;
    int numbers[11] = {0, 2, 4, 5, 6, 15, 42, 82, 90, 91, 6};
    for (int i = 0; i < 11; i++) {
        avltree.insert(avltree.getRoot(), numbers[i]);
    }

    // Act
    int res = avltree.findMin(avltree.getRoot())->key;

    // Assert
    int exp_res = 0;
    EXPECT_EQ(exp_res, res);
}

TEST(Sannikova_Vika_AVLTreeTest, Can_Find_Min_In_NULL_AVL_Tree) {
    // Arrange
    AVL avltree;

    // Act
    AVLNode* res = avltree.findMin(avltree.getRoot());

    // Assert
    AVLNode* exp_res = NULL;
    EXPECT_EQ(exp_res, res);
}

TEST(Sannikova_Vika_AVLTreeTest, Can_Remove_Min_From_AVL_Tree) {
    // Arrange
    AVL avltree;
    int numbers[11] = {6, 5, 4, 2, 0, 91, 90, 82, 42, 15, 6};
    for (int i = 0; i < 11; i++) {
        avltree.insert(avltree.getRoot(), numbers[i]);
    }

    // Act
    avltree.removeMin(avltree.getRoot());

    // Assert
    int exp_res = 2;
    EXPECT_EQ(exp_res, avltree.findMin(avltree.getRoot())->key);
}

TEST(Sannikova_Vika_AVLTreeTest, Can_Remove_Min_From_NULL_AVL_Tree) {
    // Arrange
    AVL avltree;

    // Act
    AVLNode* res = avltree.removeMin(avltree.getRoot());

    // Assert
    AVLNode* exp_res = NULL;
    EXPECT_EQ(exp_res, res);
}

TEST(Sannikova_Vika_AVLTreeTest, Can_Find_Val_In_AVL_Tree) {
    // Arrange
    AVL avltree;
    int numbers[11] = {91, 90, 82, 42, 15, 6, 5, 4, 2, 0, 6};
    for (int i = 0; i < 11; i++) {
        avltree.insert(avltree.getRoot(), numbers[i]);
    }

    // Act
    AVLNode* res = avltree.search(avltree.getRoot(), 91);

    // Assert
    AVLNode* exp_res = NULL;
    EXPECT_NE(exp_res, res);
}

TEST(Sannikova_Vika_AVLTreeTest, Can_NOT_Find_Val_In_AVL_Tree) {
    // Arrange
    AVL avltree;
    int numbers[11] = {91, 90, 82, 42, 15, 0, 2, 4, 5, 6, 6};
    for (int i = 0; i < 11; i++) {
        avltree.insert(avltree.getRoot(), numbers[i]);
    }

    // Act
    AVLNode* res = avltree.search(avltree.getRoot(), 55);

    // Assert
    AVLNode* exp_res = NULL;
    EXPECT_EQ(exp_res, res);
}

TEST(Sannikova_Vika_AVLTreeTest, Can_Remove_From_AVL_Tree1) {
    // Arrange
    AVL avltree;
    int numbers[11] = { 0, 2, 4, 5, 6, 15, 82, 90, 91, 3 };
    for (int i = 0; i < 12; i++) {
        avltree.insert(avltree.getRoot(), numbers[i]);
    }

    // Act
    AVLNode* res1 = avltree.search(avltree.getRoot(), 4);
    avltree.remove(avltree.getRoot(), 4);
    AVLNode* res2 = avltree.search(avltree.getRoot(), 4);

    // Assert
    EXPECT_NE(res1, res2);
}

TEST(Sannikova_Vika_AVLTreeTest, Can_Remove_From_AVL_Tree2) {
    // Arrange
    AVL avltree;
    int numbers[11] = { 0, 2, 4, 5, 6, 15, 82, 90, 91, 3 };
    for (int i = 0; i < 12; i++) {
        avltree.insert(avltree.getRoot(), numbers[i]);
    }

    // Act
    AVLNode* res1 = avltree.search(avltree.getRoot(), 15);
    avltree.remove(avltree.getRoot(), 15);
    AVLNode* res2 = avltree.search(avltree.getRoot(), 15);

    // Assert
    EXPECT_NE(res1, res2);
}

TEST(Sannikova_Vika_AVLTreeTest, Can_Remove_From_AVL_Tree3) {
    // Arrange
    AVL avltree;

    // Act
    avltree.remove(avltree.getRoot(), 4);
    AVLNode* res = avltree.search(avltree.getRoot(), 4);

    // Assert
    AVLNode* exp_res = NULL;
    EXPECT_EQ(exp_res, res);
}
