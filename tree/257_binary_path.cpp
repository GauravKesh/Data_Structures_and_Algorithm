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
	void possiblePaths(TreeNode* root, vector<string>& pathArray, string currentPath = "") {
		if (!root)
			return;
		currentPath += to_string(root->val);
		if (!root->left && !root->right) {
			pathArray.push_back(currentPath);
			return;
		}
		currentPath += "->";
		if (root->left) {
			possiblePaths(root->left, pathArray, currentPath);
		}
		if (root->right) {
			possiblePaths(root->right, pathArray, currentPath);
		}
	}

public:
	vector<string> binaryTreePaths(TreeNode* root) {
		vector<string> path;
		possiblePaths(root, path);
		return path;
	}
};