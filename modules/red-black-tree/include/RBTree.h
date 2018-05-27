// Copyright 2018 Chernenko Valery
#ifndef MODULES_RED_BLACK_TREE_INCLUDE_RBTREE_H_
#define MODULES_RED_BLACK_TREE_INCLUDE_RBTREE_H_

typedef int T;
typedef enum { BLACK, RED } nColor;    /*Possible colors for the node*/
struct Node {
    Node* left;  /*Pointer on "left" child*/
    Node* right;  /*Pointer on "right" child*/
    Node* parent;  /*Pointer on "parent"*/
    nColor color;  /*Color of Node*/
    T data;  /*Stored data*/
    int count;  /*Count of Elements*/

    Node(Node* _l, Node* _r, Node* _p, nColor _c, T _d, int _count = 1) {
        left = _l; right = _r; parent = _p;
        color = _c; data = _d; count = _count;
    }
};

class RBTree {
 private:
    void deleteTree(Node* x);  /*Delete the tree*/
 protected:
    Node* root;  /*Pointer to the root of the tree*/
    void rotateLeft(Node* x);   /*"Left rotate"*/
    void rotateRight(Node* x);  /*"Right rotate"*/
    void insertFixup(Node* x);  /*Inserting a node with balancing*/
    void deleteFixup(Node* x);  /*Removing a node with balancing*/
 public:
    static Node* NIL;
    RBTree();
    explicit RBTree(T data);
    RBTree(T datas[], int count);
    ~RBTree();
    Node* insertNode(T data);  /*Inserting node by value*/
    Node* findNode(T data);  /*Searching node by value*/
    void deleteNode(T data);  /*Deleting node by value*/
};

#endif  // MODULES_RED_BLACK_TREE_INCLUDE_RBTREE_H_
