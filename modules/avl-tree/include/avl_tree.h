// Copyright 2018 Sannikova Vika

#ifndef MODULES_AVL_TREE_INCLUDE_AVL_TREE_H_
#define MODULES_AVL_TREE_INCLUDE_AVL_TREE_H_
#include <iostream>

struct AVLNode {
    int key;
    AVLNode* left;
    AVLNode* right;
    unsigned char height;
    explicit AVLNode(int w) {
        key = w;
        left = NULL;
        right = NULL;
        height = 1;
    }
};

class AVL {
 private:
    AVLNode *root;
    int bFactor(AVLNode* p);
    unsigned char height(AVLNode* p);
    void fixheight(AVLNode* p);
    AVLNode* rightRotate(AVLNode* p);
    AVLNode* leftRotate(AVLNode* q);
    AVLNode* balance(AVLNode* p);
 public:
    AVL();
    AVLNode* getRoot();
    AVLNode* insert(AVLNode* r, int w);
    AVLNode* findMin(AVLNode* p);
    AVLNode* removeMin(AVLNode* p);
    AVLNode* remove(AVLNode* p, int k);
    AVLNode* search(AVLNode* r, int key);
};

#endif  // MODULES_AVL_TREE_INCLUDE_AVL_TREE_H_
