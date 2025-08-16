// Time Complexity: O(N)
// Space Complexity: O(1)
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class TreeNode
{
public:
  int data;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : data(0), left(nullptr), right(nullptr) {}
  TreeNode(int val, TreeNode *l, TreeNode *r) : data(val), left(l), right(r) {};
  // leetcode : 94 (InOrder Traversal of binary tree)
  void InOrderTraversal(TreeNode *root)
  {
    TreeNode *curr = root;
    while (curr)
    {
      if (!curr->left)
      {
        cout << curr->data << " ";
        curr = curr->right;
      }
      else
      {
        TreeNode *IP = findPredecessor(curr);
        if (!IP->right)
        {
          IP->right = curr;
          curr = curr->left;
        }
        else
        {
          IP->right = nullptr;
          cout << curr->data << " ";
          curr = curr->right;
        }
      }
    }
  }
  // leetcode : 144 (PreOrder Traversal of binary tree)
  void PreOrderTraversal(TreeNode *root)
  {
    TreeNode *curr = root;
    while (curr)
    {
      if (!curr->left)
      {
        cout << curr->data << " ";
        curr = curr->right;
      }
      else
      {
        TreeNode *IP = findPredecessor(curr);
        if (!IP->right)
        {
          cout << curr->data << " ";
          IP->right = curr;
          curr = curr->left;
        }
        else
        {
          IP->right = nullptr;
          curr = curr->right;
        }
      }
    }
  }
  // leetcode : 145 (PostOrder Traversal of binary tree)
  void PostOrderTraversal(TreeNode *root)
  {
    vector<int> ans;
    TreeNode *curr = root;
    while (curr)
    {
      if (!curr->right)
      {
        ans.push_back(curr->data);
        curr = curr->left;
      }
      else
      {
        TreeNode *IP = findPostOrderPredecessor(curr);
        if (!IP->left)
        {
          ans.push_back(curr->data);
          IP->left = curr;
          curr = curr->right;
        }
        else
        {
          IP->left = nullptr;
          curr = curr->left;
        }
      }
    }

    reverse(ans.begin(), ans.end());
    for (int e : ans)
    {
      cout << e << " ";
    }
  }

private:
  TreeNode *findPostOrderPredecessor(TreeNode *curr)
  {
    TreeNode *root = curr;
    curr = curr->right;
    while (curr->left && curr->left != root)
    {
      curr = curr->left;
    }
    return curr;
  }

  TreeNode *findPredecessor(TreeNode *curr)
  {
    TreeNode *root = curr;
    curr = curr->left;
    while (curr->right && curr->right != root)
    {
      curr = curr->right;
    }
    return curr;
  }
};

int main()
{

  TreeNode *c11 = new TreeNode(3, nullptr, nullptr);
  TreeNode *c12 = new TreeNode(4, nullptr, nullptr);
  TreeNode *c1 = new TreeNode(1, c11, c12);
  TreeNode *c21 = new TreeNode(5, nullptr, nullptr);
  TreeNode *c22 = new TreeNode(6, nullptr, nullptr);
  TreeNode *c2 = new TreeNode(2, c21, c22);
  TreeNode *root = new TreeNode(0, c1, c2);

  TreeNode obj;
  cout << "InOrder Traversal: [ ";
  obj.InOrderTraversal(root);
  cout << "]" << endl;
  cout << "PreOrder Traversal: [ ";
  obj.PreOrderTraversal(root);
  cout << "]" << endl;
  cout << "PostOrder Traversal: [ ";
  obj.PostOrderTraversal(root);
  cout << "]" << endl;
  return 0;
}