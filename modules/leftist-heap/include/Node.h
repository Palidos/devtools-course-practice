// Copyright 2018 Krasikova Ekaterina

#ifndef MODULES_LEFTIST_HEAP_INCLUDE_NODE_H_
#define MODULES_LEFTIST_HEAP_INCLUDE_NODE_H_

struct node {
    int key;
    int rank;
    node* parent;
    node* left;
    node* right;
    node();
    explicit node(int k);
};
#endif  // MODULES_LEFTIST_HEAP_INCLUDE_NODE_H_
