// Copyright 2022 NNTU-CS
#include <vector>
#include <algorithm>
#ifndef INCLUDE_TREE_H_
#define INCLUDE_TREE_H_

class Tree {
 private:
  struct Node {
    char val;
    std::vector<Node*> desc;
    explicit Node(const char& vl) : val(vl) {}
    ~Node() { for (Node* d : desc) delete d; }
  };
  Node* root = new Node(0);

  void c_helper(Node* node, const std::vector<char>& rem) {
    if (rem.empty()) return;
    for (int i = 0; i < rem.size(); i++) {
      Node* newn = new Node(rem[i]);
      node->desc.push_back(newn);
      std::vector<char> temp = rem;
      temp.erase(temp.begin() + i);
      c_helper(newn, temp);
    }
  }

  int dev(int a, int b) {
    double out = a / static_cast<double>(b);
    if (out != static_cast<int>(out))
      return static_cast<int>(out) + 1;
    return out;
  }

  int mod(int a, int b) {
    int out = a % b;
    if (!out) return b;
    return out;
  }

 public:
  void gap_helper(Node* node, std::vector<char>& buffer,
    std::vector<std::vector<char>>& out) const {
    if (node->val) buffer.push_back(node->val);
    if (node->desc.empty()) {
      out.push_back(buffer);
    } else {
      for (Node* n : node->desc)
        gap_helper(n, buffer, out);
    }
    if (node->val) buffer.pop_back();
  }

  Tree(std::vector<char> in) {
    std::sort(in.begin(), in.end());
    c_helper(root, in);
  }

  ~Tree() {
    delete root;
  }

  Node* getRoot() const { return root; }

  void gp2_helper(Node* node, int& num, std::vector<char>& out) {
    if (node->val) out.push_back(node->val);
    if (node->desc.empty()) return;
    int branch = dev(num, fct(node->desc.size() - 1)) - 1;
    num = mod(num, fct(node->desc.size() - 1));
    gp2_helper(node->desc[branch], num, out);
  }

  int fct(int n) {
    if (n < 2)
      return 1;
    return n * fct(n - 1);
  }

  int fct() {
    return fct(root->desc.size());
  }
};

std::vector<std::vector<char>> getAllPerms(const Tree& tree);
std::vector<char> getPerm1(Tree& tree, int num);
std::vector<char> getPerm2(Tree& tree, int num);

#endif  // INCLUDE_TREE_H_
