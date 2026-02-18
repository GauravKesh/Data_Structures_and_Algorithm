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
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
	bool pathSum(TreeNode* root, int tgs) {
		if (!root)
			return false;

		int rv = tgs - root->val;
		if (!root->left && !root->right)
			return rv == 0;
		return pathSum(root->left, rv) || pathSum(root->right, rv);
	}

	bool hasPathSum(TreeNode* root, int targetSum) {
		return pathSum(root, targetSum);    }
};


/**
 * 🔹 LeetCode 112 – Path Sum
 *
 * PROBLEM:
 * Check if there exists a root → leaf path such that
 * sum of node values == targetSum.
 *
 * CORE IDEA (DFS):
 * At each node:
 *   remainingSum = targetSum - node->val
 * Delegate the rest of the work to children.
 *
 * BASE CASES:
 * 1️⃣ If node is NULL → no path → return false
 * 2️⃣ If leaf node →
 *        check remainingSum == 0  ✅
 *
 * WHY LEAF CHECK?
 * Path must end at a leaf (not at an intermediate node).
 *
 * RECURSION:
 * A path is valid if:
 *   left subtree has valid path OR right subtree has valid path
 *
 * return left || right;
 *
 * COMPLEXITY:
 * Time  : O(N)   → visit each node once
 * Space : O(H)   → recursion stack (H = tree height)
 *
 * PATTERN:
 * Tree + root-to-leaf + “any valid path” → DFS with subtraction
 *
 * COMMON MISTAKES:
 * ❌ Trying to greedily choose left/right
 * ❌ Checking sum before reaching leaf
 * ❌ Accessing child->val without NULL check
 * ❌ Using int instead of bool return type
 *
 * RECURSION MENTAL MODEL:
 * "Assume current node is part of the path,
 *  can any subtree complete the remaining sum?"
 */