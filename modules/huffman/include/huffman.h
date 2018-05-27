// Copyright 2018 Kamelina Julia

#ifndef MODULES_HUFFMAN_INCLUDE_HUFFMAN_H_
#define MODULES_HUFFMAN_INCLUDE_HUFFMAN_H_

#include <map>
#include <vector>

using std::map;
using std::vector;

struct CNode {
  CNode* left;
  CNode* right;
  char* value;
  char* code;
  int count;

  CNode(char* v = 0, int c = 0,
        CNode* l = 0, CNode* r = 0, char* _code = 0) {
    value = v;
    count = c;
    left = l;
    right = r;
    code = _code;
  }

  bool operator() (const CNode* x, const CNode* y) const {
    return (x->count > y->count) || ((x->count == y->count)
            && (static_cast<int>(x->value[0]) > static_cast<int>(y->value[0])));
  }
};

class Huffman {
 private:
    CNode* H_tree;
    vector<CNode*> frequency;

 private:
    void BuildTree();  // Builds Huffam tree

 public:
    Huffman() {
      H_tree = nullptr;
    }
    explicit Huffman(char* text);  // constructor fills frequency array
    ~Huffman();
    map<char, char*> Encode();  // Encode function
};

#endif  // MODULES_HUFFMAN_INCLUDE_HUFFMAN_H_
