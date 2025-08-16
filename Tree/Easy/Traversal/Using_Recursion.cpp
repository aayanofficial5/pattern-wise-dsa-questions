//Time Complexity: O(N) 
//Space Complexity: O(N)
#include <iostream>
using namespace std;

class TreeNode
{
public:
  int data;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int data)
  {
    this->data = data;
    this->left = nullptr;
    this->right = nullptr;
  }
  TreeNode(int val,TreeNode* left,TreeNode* right):data(val),left(left),right(right){}
};

// leetcode : 94 (InOrder Traversal of binary tree)
void InOrderTraversal(TreeNode *root)
{
  if (!root)
    return;
  InOrderTraversal(root->left);
  cout << root->data<<" ";
  InOrderTraversal(root->right);
}
// leetcode : 144 (PreOrder Traversal of binary tree)
void PreOrderTraversal(TreeNode *root)
{
  if (!root)
    return;
  cout << root->data<<" ";
  PreOrderTraversal(root->left);
  PreOrderTraversal(root->right);
}
// leetcode : 145 (PostOrder Traversal of binary tree)
void PostOrderTraversal(TreeNode *root)
{
  if (!root)
    return;
  PostOrderTraversal(root->left);
  PostOrderTraversal(root->right);
  cout << root->data<<" ";
}

int main()
{
  TreeNode *c11 = new TreeNode(3);
  TreeNode *c12 = new TreeNode(4);
  TreeNode *c1 = new TreeNode(1,c11,c12);
  TreeNode *c21 = new TreeNode(5);
  TreeNode *c22 = new TreeNode(6);
  TreeNode *c2 = new TreeNode(2,c21,c22);
  TreeNode *root = new TreeNode(0,c1,c2);
  
  // root->left = c1;
  // root->right = c2;

  // c1->left = c11;
  // c1->right = c12;
  
  // c2->left = c21;
  // c2->right = c22;

  cout<<"InOrder Traversal: [ ";
  InOrderTraversal(root);
  cout<<"]"<<endl;
  cout<<"PreOrder Traversal: [ ";
  PreOrderTraversal(root);
  cout<<"]"<<endl;
  cout<<"PostOrder Traversal: [ ";
  PostOrderTraversal(root);
  cout<<"]"<<endl;
  return 0;
}