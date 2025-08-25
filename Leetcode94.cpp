#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};

class Solution {
  public:

    // Left Root Right
    void traversal(Node* root, vector<int> &temp){
        if(root == NULL) return;
        traversal(root->left, temp);
        temp.push_back(root->data);
        traversal(root->right, temp);
    }
    vector<int> inOrder(Node* root) {
        vector<int> store;
        traversal(root, store);
        return store;
    }
};

int main(){

    return 0;
}