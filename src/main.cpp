// Copyright 2022 NNTU-CS
#include <iostream>
#include <vector>
#include <random>
#include <chrono>
#include <fstream>
#include "tree.h"

int main() {
  srand(time(0));
  std::vector<char> v;

  for (int i = 1; i < 5; i++) {
    for (int j = i; j > 0; j--)
      v.push_back('1');
      PMTree tree(v);
      int pc = tree.fct();
      std::cout << '\n' << '\n' << "Alphabet size: " << v.size();
      int perm = i;
    auto start1 = std::chrono::high_resolution_clock::now();
    getPerm1(tree, perm);
    auto end1 = std::chrono::high_resolution_clock::now();
    auto start2 = std::chrono::high_resolution_clock::now();
    getPerm2(tree, perm);
    auto end2 = std::chrono::high_resolution_clock::now();
    auto start3 = std::chrono::high_resolution_clock::now();
    getAllPerms(tree);
    auto end3 = std::chrono::high_resolution_clock::now();
    auto duration1 = 
    std::chrono::duration_cast<std::chrono::microseconds>
    (end1 - start1);
    auto duration2 = 
    std::chrono::duration_cast<std::chrono::microseconds>
    (end2 - start2);
    auto duration3 = 
    std::chrono::duration_cast<std::chrono::microseconds>
    (end3 - start3);
    std::cout << '\n' << "Perm's number: " << perm << '\n' << '\n'
        << "getPerm1 time: " << duration1.count() << "ms" << '\n'
        << "getPerm2 time: " << duration2.count() << "ms" << '\n'
        << "getAllPerms time: " << duration3.count() << "ms" << '\n';
    v.clear();
  }
  return 0;
}
