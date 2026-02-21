//
// Created by Gaurav Kesh Roushan on 21/02/26.
//
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
private:
	TreeNode* prev = nullptr;
	int diff = INT_MAX;

public:
	void inorder(TreeNode* node) {
		if (!node)
			return;
		inorder(node->left);
		// arr.push_back(node->val);
		if (prev) {
			diff = min(abs(prev->val - node->val), diff);
		}
		prev = node;
		inorder(node->right);
	}
	int getMinimumDifference(TreeNode* root) {
		inorder(root);
		return diff;
	}
};