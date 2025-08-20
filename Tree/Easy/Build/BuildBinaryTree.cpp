#include <iostream>
#include <queue>
#include "TreeNode.h"
#include "TraversalSolution.h"
using namespace std;

TreeNode *buildWithLevelOrder()
{
  int data;
  cout << "Enter root Node : ";
  cin >> data;
  TreeNode *root = new TreeNode(data);
  queue<TreeNode *> q;
  q.push(root);

  while (!q.empty())
  {
    TreeNode *front = q.front();
    q.pop();

    int leftData;
    cout << "Enter left Node of " << front->data << " : ";
    cin >> leftData;
    if (leftData != -1)
    {
      front->left = new TreeNode(leftData);
      q.push(front->left);
    }

    int rightData;
    cout << "Enter right Node of " << front->data << " : ";
    cin >> rightData;
    if (rightData != -1)
    {
      front->right = new TreeNode(rightData);
      q.push(front->right);
    }
  }

  return root;
}

int main()
{
  TreeNode *root = buildWithLevelOrder();
  TraversalSolution obj;
  cout << "Pre Order Traversal : ";
  obj.preOrderTraversal(root);
  return 0;
}