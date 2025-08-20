#ifndef TREENODE_H
#define TREENODE_H

class TreeNode {
public:
    int data;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int data) : data(data), left(nullptr), right(nullptr) {}
    TreeNode(int val, TreeNode* left, TreeNode* right) : data(val), left(left), right(right) {}
};

#endif
