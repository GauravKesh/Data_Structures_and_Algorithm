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
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
	int minDepth(TreeNode* root) {
		if (!root)
			return 0;
		return depth(root);
	}


private:
	int depth(TreeNode* root) {

		if (!root)
			return 0;

		if (!root->left && !root->right) {
			return 1;
		}
		if (!root->left) {
			return 1+depth(root->right);
		}
		if (!root->right) {
			return 1+depth(root->left);
		}
		return 1+ min(depth(root->right),
					  depth(root->left));
	}
};