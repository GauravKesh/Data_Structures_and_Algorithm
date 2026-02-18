//
// Created by Gaurav Kesh Roushan on 18/02/26.
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
	int sl(TreeNode* root, int sm = 0) {
		// Base case: empty node contributes 0
		if (root == nullptr) return sm;

		// If left child is a leaf → add its value
		if (root->left &&
			root->left->left == nullptr &&
			root->left->right == nullptr) {
			sm += root->left->val;
		}

		// Collect contribution from left & right subtrees
		sm += sl(root->left);
		sm += sl(root->right);

		return sm;
	}

	int sumOfLeftLeaves(TreeNode* root) {
		return sl(root);
	}
};


/**
 * 404. Sum of Left Leaves
 *
 * 🔹 Pattern:
 * Each recursion returns → sum of left leaves in its subtree
 * (pure return-based DFS, no path accumulation needed)
 *
 * 🔹 Key observation:
 * A left leaf = node->left exists AND it has no children
 *
 * 🔹 At every node:
 * 1. Check if my left child is a leaf → add its value
 * 2. Recurse on left subtree
 * 3. Recurse on right subtree
 *
 * 🔹 Why no carry parameter?
 * We are not computing a root-to-leaf path sum.
 * Every subtree independently returns its contribution.
 *
 * 🔹 Base case:
 * null → contributes 0
 *
 * 🔹 Complexity:
 * Time  : O(n)
 * Space : O(h)   (recursion stack)
 *
 * 🔹 Common mistakes (⚠ revision triggers):
 * - Don’t do sm + root->val → this is NOT a path-sum problem
 * - Don’t jump to root->right->left → always move one level
 * - Always use return values from recursion
 */
