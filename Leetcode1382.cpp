#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    vector<int> inorder;

    void inorderTraversal(TreeNode* root) {
        if (root == NULL) return;
        inorderTraversal(root->left);
        inorder.push_back(root->val);
        inorderTraversal(root->right);
    }

    TreeNode* buildBalancedBST(int l, int r) {
        if (l > r) return NULL;

        int mid = l + (r - l) / 2;
        TreeNode* root = new TreeNode(inorder[mid]);

        root->left = buildBalancedBST(l, mid - 1);
        root->right = buildBalancedBST(mid + 1, r);

        return root;
    }

    TreeNode* balanceBST(TreeNode* root) {
        inorderTraversal(root);
        return buildBalancedBST(0, inorder.size() - 1);
    }
};


int main(){


    /*
    Given the root of a binary search tree, return a balanced binary search tree with the same 
    node values. If there is more than one answer, return any of them.
    A binary search tree is balanced if the depth of the two subtrees of every node never 
    differs by more than 1.
    */

    // Step 1: Inorder Traversal
    // Step 2: Build Balanced BST




    return 0;
}