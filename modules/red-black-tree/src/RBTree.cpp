// Copyright 2018 Chernenko Valery
#include "include/RBTree.h"

Node *RBTree::NIL = new Node(RBTree::NIL, RBTree::NIL, nullptr, BLACK, 0, 0);

RBTree::RBTree() {
    root = NIL;
}

RBTree::RBTree(T data) {
    root = NIL;
    insertNode(data);
}

RBTree::RBTree(T datas[], int count) {
    root = NIL;
    for (int i = 0; i < count; i++)
        insertNode(datas[i]);
}

RBTree::~RBTree() {
    deleteTree(root);
}

void RBTree::rotateLeft(Node* x) {
    Node *y = x->right;
    x->right = y->left;
    if (y->left != NIL) y->left->parent = x;
    if (y != NIL) {
        y->parent = x->parent;
        if (x->parent) {
            if (x == x->parent->left) {
                x->parent->left = y;
            } else {
                x->parent->right = y;
            }
        } else {
            root = y;
        }
        y->left = x;
        if (x != NIL) x->parent = y;
    }
}

void RBTree::rotateRight(Node* x) {
    Node *y = x->left;
    x->left = y->right;
    if (y->right != NIL) y->right->parent = x;
    if (y != NIL) {
        y->parent = x->parent;
        if (x->parent) {
            if (x == x->parent->right) {
                x->parent->right = y;
            } else {
                x->parent->left = y;
            }
        } else {
            root = y;
        }
        y->right = x;
        if (x != NIL) x->parent = y;
    }
}

void RBTree::insertFixup(Node* x) {
    while (x != root && x->parent->color == RED) {
        if (x->parent == x->parent->parent->left) {
            Node *y = x->parent->parent->right;
            if (y->color == RED) {
                x->parent->color = BLACK;
                y->color = BLACK;
                x->parent->parent->color = RED;
                x = x->parent->parent;
            } else {
                if (x == x->parent->right) {
                    x = x->parent;
                    rotateLeft(x);
                }
                x->parent->color = BLACK;
                x->parent->parent->color = RED;
                rotateRight(x->parent->parent);
            }
        } else {
                Node *y = x->parent->parent->left;
                if (y->color == RED) {
                    x->parent->color = BLACK;
                    y->color = BLACK;
                    x->parent->parent->color = RED;
                    x = x->parent->parent;
                } else {
                    if (x == x->parent->left) {
                        x = x->parent;
                        rotateRight(x);
                    }
                    x->parent->color = BLACK;
                    x->parent->parent->color = RED;
                    rotateLeft(x->parent->parent);
                }
            }
        }
    root->color = BLACK;
}

void RBTree::deleteFixup(Node* x) {
    while (x != root && x->color == BLACK) {
        if (x == x->parent->left) {
            Node* w = x->parent->right;
            if (w->color == RED) {
                w->color = BLACK;
                x->parent->color = RED;
                rotateLeft(x->parent);
                w = x->parent->right;
            }
            if (w->left->color == BLACK && w->right->color == BLACK) {
                w->color = RED;
                x = x->parent;
            } else {
                if (w->right->color == BLACK) {
                    w->left->color = BLACK;
                    w->color = RED;
                    rotateRight(w);
                    w = x->parent->right;
                }
                w->color = x->parent->color;
                x->parent->color = BLACK;
                w->right->color = BLACK;
                rotateLeft(x->parent);
                x = root;
            }
        } else {
            Node* w = x->parent->left;
            if (w->color == RED) {
                w->color = BLACK;
                x->parent->color = RED;
                rotateRight(x->parent);
                w = x->parent->left;
            }
            if (w->right->color == BLACK && w->left->color == BLACK) {
                w->color = RED;
                x = x->parent;
            } else {
                if (w->left->color == BLACK) {
                    w->right->color = BLACK;
                    w->color = RED;
                    rotateLeft(w);
                    w = x->parent->left;
                }
                w->color = x->parent->color;
                x->parent->color = BLACK;
                w->left->color = BLACK;
                rotateRight(x->parent);
                x = root;
            }
        }
    }
    x->color = BLACK;
}

void RBTree::deleteTree(Node* x) {
    if (!x || x == NIL) {
        return;
    } else {
        deleteTree(x->left);
        deleteTree(x->right);
        delete x;
    }
}

Node* RBTree::insertNode(T data) {
    Node* current;
    Node* parent;
    Node* x;
    current = root;
    parent = nullptr;
    while (current != NIL) {
        if (data == current->data) {
            current->count++;
            return current;
        }
        parent = current;
        current = data < current->data ? current->left : current->right;
    }
    x = new Node(NIL, NIL, parent, RED, data);
    if (parent) {
        if (data < parent->data)
            parent->left = x;
        else
            parent->right = x;
    } else {
        root = x;
    }
    insertFixup(x);
    return x;
}

void RBTree::deleteNode(T data) {
    Node* x;
    Node* y;
    Node* z = findNode(data);
    if (!z || z == NIL) return;
    if (z->count > 1) {
        z->count--;
        return;
    }
    if (z->left == NIL || z->right == NIL) {
        y = z;
    } else {
        y = z->right;
        while (y->left != NIL) y = y->left;
    }
    if (y->left != NIL)
        x = y->left;
    else
        x = y->right;
    x->parent = y->parent;
    if (y->parent) {
        if (y == y->parent->left) {
            y->parent->left = x;
        } else {
            y->parent->right = x;
        }
    } else {
        root = x;
    }
    if (y != z) z->data = y->data;
    if (y->color == BLACK)
        deleteFixup(x);
    delete y;
}

Node* RBTree::findNode(T data) {
    Node* current = root;
    while (current != NIL) {
        if (data == current->data) return current;
        current = data < current->data ? current->left : current->right;
    }
    return current;
}
