// Copyright 2018 Gorelova Ksenia

#ifndef MODULES_SEARCH_TREE_INCLUDE_SEARCH_TREE_H_
#define MODULES_SEARCH_TREE_INCLUDE_SEARCH_TREE_H_

struct Tree {
 public:
    int value;
    Tree * left;
    Tree * right;
};

class SearchTree {
 private:
    Tree * pRoot;
    void DestroyBTree(Tree * pRoot);
    void AddTree(int val, Tree** pRoot);
    Tree * SearchNode(Tree * pRoot, int key);
 public:
    explicit SearchTree(Tree * pRoot = nullptr);
    ~SearchTree() { DestroyBTree(pRoot); }

    void Insert(int val);
    Tree * Search(int val);
};

#endif   // MODULES_SEARCH_TREE_INCLUDE_SEARCH_TREE_H_
