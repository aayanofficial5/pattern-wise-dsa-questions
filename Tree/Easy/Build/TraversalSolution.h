#include<iostream>

#include "TreeNode.h"

#ifndef TRAVERSALSOLUTION_H
#define TRAVERSALSOLUTION_H

class TraversalSolution
{
public:
  void preOrderTraversal(TreeNode *root)
  {
    if (!root)
      return;
    std::cout << root->data << " ";
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
  }
};

#endif