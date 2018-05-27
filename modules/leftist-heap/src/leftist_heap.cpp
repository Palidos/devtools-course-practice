// Copyright 2018 Krasikova Ekaterina
#include "include/leftist_heap.h"
#include <queue>
#include <stdexcept>
leftist_heap::leftist_heap() {
    root = nullptr;
}
leftist_heap::leftist_heap(node *root_) {
    root = root_;
}
leftist_heap::leftist_heap(const leftist_heap& h) {
    if (h.root == nullptr) {
        root = nullptr;
        return;
    }
    std::queue<node*> q1, q2;
    q1.push(h.root);
    root = new node;
    q2.push(root);
    while (!q1.empty()) {
        node *tmp1, *tmp2;
        tmp1 = q1.front();
        q1.pop();
        tmp2 = q2.front();
        q2.pop();
        tmp2->key = tmp1->key;
        tmp2->rank = tmp1->rank;
        if (tmp1->left != nullptr) {
            q1.push(tmp1->left);
            tmp2->left = new node;
            q2.push(tmp2->left);
        }
        if (tmp1->right != nullptr) {
            q1.push(tmp1->right);
            tmp2->right = new node;
            q2.push(tmp2->right);
        }
    }
}
leftist_heap::~leftist_heap() {
    if (root == nullptr) {
        return;
    }
    std::queue<node*> q;
    q.push(root);
    while (!q.empty()) {
        node *tmp;
        tmp = q.front();
        q.pop();
        if (tmp->left != nullptr) {
            q.push(tmp->left);
        }
        if (tmp->right != nullptr) {
            q.push(tmp->right);
        }
        delete tmp;
    }
    root = 0;
}
leftist_heap& leftist_heap::operator=(const leftist_heap& h) {
    if (root == h.root) {
        return *this;
    }
    if (root != 0) {
        std::queue<node*> q;
        q.push(root);
        while (!q.empty()) {
            node *tmp;
            tmp = q.front();
            q.pop();
            if (tmp->left != nullptr) {
                q.push(tmp->left);
            }
            if (tmp->right != nullptr) {
                q.push(tmp->right);
            }
            delete tmp;
        }
    }
    leftist_heap *new_heap_pointer = new leftist_heap(h);
    root = new_heap_pointer->root;
    return *this;
}

void leftist_heap::merge(leftist_heap* h) {
    node *tmp;
    if (root == nullptr) {
        root = h->root;
        h->root = nullptr;
        return;
    }
    if (h->root == nullptr) {
        return;
    }
    if (root->key > h->root->key) {
        tmp = h->root;
        h->root = root;
        root = tmp;
    }
    leftist_heap right(root->right);
    right.merge(h);
    root->right = right.root;
    right.root = nullptr;
    if (root->left == nullptr || root->right->rank > root->left->rank) {
        tmp = root->right;
        root->right = root->left;
        root->left = tmp;
    }
    if (root->right == nullptr) {
        root->rank = 1;
    } else {
        root->rank = root->left->rank < root->right->rank ?
            root->left->rank + 1 : root->right->rank + 1;
    }
    h->root = nullptr;
}
void leftist_heap::insert(int k) {
    node * new_node = new node;
    new_node->key = k;
    new_node->rank = 1;
    leftist_heap *new_heap = new leftist_heap(new_node);
    merge(new_heap);
}
int leftist_heap::minKey() {
    if (root == nullptr)
        throw std::logic_error("Can't find minimum in empty heap");
    return root->key;
}
void leftist_heap::deleteMin() {
    if (root == nullptr)
        throw std::logic_error("Can't delete node from empty heap");
    leftist_heap left(root->left), *right = new leftist_heap(root->right);
    left.merge(right);
    root = left.root;
    left.root = nullptr;
}
