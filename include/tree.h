// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TREE_H_
#define INCLUDE_TREE_H_

#include <vector>
#include <algorithm>
class Tree {
  struct Node {
    char c;
    std::vector<Node*> tree_childs;
  };
  std::vector<char> perm;
  Node* root = nullptr;
  void create(std::vector<char> elements, Node* root) {
    for (auto i : elements) {
      if (i == root->c) {
        elements.erase(std::remove(elements.begin(), elements.end(), i), elements.end());
        for (auto ch : elements) {
          Node* temp = new Node;
          temp->c = ch;
          root->tree_childs.push_back(temp);
        }
      }
    }
    for (auto i : root->tree_childs) {
      create(elements, i);
    }
  }
  void Perm(Node* root) {
    if (root->tree_childs.empty()) {
      perm.push_back(root->c);
      permutations.push_back(perm);
      perm.clear();
    }
    for (auto p : root->tree_childs) {
      perm.push_back(root->c);
      Perm(p);
    }
  }

 public:
  std::vector<std::vector<char>> permutations;
  Tree(std::vector<char> elements) {
    root = new Node;
    root->c = ' ';
    for (auto q : elements) {
      Node* temp = new Node;
      temp->c = q;
      root->tree_childs.push_back(temp);
    }
    for (auto q : root->tree_childs) {
      create(elements, q);
      Perm(q);
      perm.clear();
    }
  }
};
#endif  // INCLUDE_TREE_H_
