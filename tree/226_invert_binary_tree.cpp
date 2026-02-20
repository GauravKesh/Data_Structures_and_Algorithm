//
// Created by Gaurav Kesh Roushan on 20/02/26.
//
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
	TreeNode* invertTreeMethod2 (TreeNode* root) {
		if (!root) return nullptr;

		TreeNode* temp = root->left;   // store left

		root->left = root->right;      // move right → left
		root->right = temp;            // move stored left → right

		invertTree(root->left);
		invertTree(root->right);

		return root;
	}
	TreeNode* invertTree(TreeNode* root) {
		if(!root) return root;
		if (!root) return nullptr;

		swap(root->left, root->right);

		invertTree(root->left);
		invertTree(root->right);

		return root;
	}
};