// Copyright 2022 NNTU-CS
#include  <iostream>
#include  <fstream>
#include  <locale>
#include  <cstdlib>
#include  "tree.h"



std::vector<std::vector<char>> getAllPerms(const Tree& tree) {
  std::vector<std::vector<char>> out;
  std::vector<char> buffer;
  tree.gap_helper(tree.getRoot(), buffer, out);
  return out;
}

std::vector<char> getPerm1(Tree& tree, int num)
{
  if (tree.fct() < num)
    return std::vector<char>();
  std::vector<std::vector<char>> allPerms = getAllPerms(tree);
  return allPerms[num - 1];
}

std::vector<char> getPerm2(Tree& tree, int num)
{
  if (tree.fct() < num)
    return std::vector<char>();
  std::vector<char> out;
  tree.gp2_helper(tree.getRoot(), num, out);
  return out;
}
