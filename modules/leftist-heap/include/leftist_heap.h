// Copyright 2018 Krasikova Ekaterina

#ifndef MODULES_LEFTIST_HEAP_INCLUDE_LEFTIST_HEAP_H_
#define MODULES_LEFTIST_HEAP_INCLUDE_LEFTIST_HEAP_H_
#include "Node.h"

class leftist_heap {
 public:
    node *root;
    leftist_heap();
    explicit leftist_heap(node *root_);
    leftist_heap(const leftist_heap& h);
    ~leftist_heap();
    leftist_heap& operator=(const leftist_heap& h);
    void merge(leftist_heap* h);
    void insert(int k);
    int minKey();
    void deleteMin();
};
#endif  // MODULES_LEFTIST_HEAP_INCLUDE_LEFTIST_HEAP_H_

