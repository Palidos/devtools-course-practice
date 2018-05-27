// Copyright 2018 Krasikova Ekaterina
#include "include/Node.h"

node::node() {
    key = 0;
    rank = 1;
    parent = left = right = nullptr;
}
node::node(int k) {
    key = k;
    rank = 1;
    parent = left = right = nullptr;
}
