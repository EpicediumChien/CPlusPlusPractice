// InorderTraversal.cpp : This file contains the 'main' function. Program execution begins and ends there.
// https://leetcode.com/problems/binary-tree-inorder-traversal/

#include <iostream>
#include <vector>
#include <string>
#include <numeric>  // for std::iota
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
 
class Solution {
private:
    void inorder(TreeNode* cursor, vector<int>& result) {
        if (cursor == nullptr)
            return;
        inorder(cursor->left, result);
        result.push_back(cursor->val);
        inorder(cursor->right, result);
    }
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        inorder(root, res);
        return res;
    }
};