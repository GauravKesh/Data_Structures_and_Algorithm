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
	int currentCount = 0;
	int maxCount = 0;
	vector<int> modes;

	void inorder(TreeNode* root) {
		if (!root) return;

		inorder(root->left);

		if (prev && prev->val == root->val)
			currentCount++;
		else
			currentCount = 1;

		if (currentCount > maxCount) {
			maxCount = currentCount;
			modes = {root->val};
		}
		else if (currentCount == maxCount) {
			modes.push_back(root->val);
		}

		prev = root;

		inorder(root->right);
	}
public:
	vector<int> findMode(TreeNode* root) {  inorder(root); return modes;}
};