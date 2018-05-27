// Copyright 2018 Kamelina Julia

#include "include/huffman.h"

#include <string.h>
#include <stdexcept>
#include <queue>
#include <utility>
#include <vector>
#include <map>

using std::priority_queue;
using std::vector;
using std::map;

Huffman::Huffman(char* text) {
  if (text == nullptr) {
    throw std::invalid_argument("Text is null");
  }

  H_tree = nullptr;

  int i = 0;
  while (text[i] != '\0') {  // gets the number of each letter is text
    bool f = true;
    char* val = new char[2];
    val[0] = text[i];
    val[1] = '\0';

    int size = frequency.size();
    for (int j = 0; j < size; j++) {
      if (strcmp(frequency[j]->value, val) == 0) {
        frequency[j]->count += 1;
        f = false;
        break;
      }
    }
    if (f == true) {
      CNode* letter = new CNode(val, 1);
      frequency.push_back(letter);
    }
    i++;
  }
}

Huffman::~Huffman() {
  std::queue<CNode*> q;
  if (H_tree != nullptr) {
    q.push(H_tree);
  }
  while (!q.empty()) {
    CNode* tmp = q.front();
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

void Huffman::BuildTree() {
  if (frequency.empty()) {
    throw std::logic_error("Frequency array is null");
  }

  priority_queue<CNode*, vector<CNode*>, CNode> q;
  int size = frequency.size();
  if (size == 1) {  // if only 1 letter in text
    H_tree = new CNode(frequency[0]->value, frequency[0]->count,
                        0, 0, const_cast<char*>("1"));
  }

  for (int i = 0; i < size; i++) {
    q.push(frequency[i]);
  }

  while (q.size() != 1) {
    // get 2 least frequent letters
    auto leaf1 = q.top();
    q.pop();
    auto leaf2 = q.top();
    q.pop();

    // merge letters
    size_t len = strlen(leaf1->value) + strlen(leaf2->value) + 1;
    char* vals = new char[len];
    snprintf(vals, len, "%s%s", leaf1->value, leaf2->value);
    CNode* parent = new CNode(vals, leaf1->count + leaf2->count, leaf1, leaf2);
    q.push(parent);

    H_tree = parent;
    leaf1->code = const_cast<char*>("0");
    leaf2->code = const_cast<char*>("1");
  }
  q.pop();
}

map<char, char*> Huffman::Encode() {
  BuildTree();
  map<char, char*> encoded_text;
  std::queue<CNode*> q;
  q.push(H_tree);

  while (!q.empty()) {
    auto root = q.front();
    q.pop();

    // tree traversal and encode
    int i = 0;
    while (root->value[i] != '\0') {
      char letter = root->value[i];
      auto it = encoded_text.find(letter);
      if (it == encoded_text.end()) {
        encoded_text.insert(std::pair<char, char*>(letter, root->code));
      } else {
        char* old_code = encoded_text[letter];
        char* new_code = nullptr;

        if (old_code != nullptr) {
          size_t len = strlen(old_code) + 2;
          new_code = new char[len];
          snprintf(new_code, len, "%s%s", old_code, root->code);
        } else {
          new_code = root->code;
        }

        encoded_text[letter] = new_code;
      }
      i++;
    }
    if (root->left != nullptr) {
      q.push(root->left);
    }
    if (root->right != nullptr) {
      q.push(root->right);
    }
  }
  return encoded_text;
}
