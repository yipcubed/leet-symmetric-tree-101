#include <iostream>

using namespace std;

/**
 * Definition for a binary tree node.
 */
 struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 };
 

class Solution {
public:

    bool isSymmetric(TreeNode* l, TreeNode* r) {
      // empty trees
      if (!l && !r) return true;
      // only one empty
      if (!l || !r) return false;
      // mismatched children
      if (l->val != r->val) return false;

      return isSymmetric(l->left, r->right) &&
        isSymmetric(l->right, r->left);
    }

    bool isSymmetric(TreeNode* root) {
        return !root || isSymmetric(root->left, root->right);
    }
};

void print(TreeNode* root) {
  if (root) {
    print(root->left);
    cout << root->val << ", ";
    print(root->right);
  }
}

int main() {

  Solution S;

  cout << boolalpha;

  // [1,2,2,3,4,4,3]

  TreeNode *t1 = new TreeNode(1);
  t1->left = new TreeNode(2);
  t1->right = new TreeNode(2);
  t1->left->left = new TreeNode(3);
  t1->left->right = new TreeNode(4);
  t1->right->left = new TreeNode(4);
  t1->right->right = new TreeNode(3);

  print(t1);
  cout << endl;
  cout << "1: true?" << S.isSymmetric(t1) << endl;

  // [1,2,2,null,3,null,3]

  TreeNode *t2 = new TreeNode(1);
  t2->left = new TreeNode(2);
  t2->right = new TreeNode(2);
  t2->left->left = nullptr;
  t2->left->right = new TreeNode(3);
  t2->right->left = nullptr;
  t2->right->right = new TreeNode(3);

  cout << "2: false?" << S.isSymmetric(t2) << endl;

  cout << "Done!" << endl;

  return 0;
}