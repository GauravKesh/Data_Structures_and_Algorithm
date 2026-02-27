//
// Created by Gaurav Kesh Roushan on 27/02/26.
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
	vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
		if (!root)
			return {};
		vector<vector<int>> v;
		queue<TreeNode*> qu;
		qu.push(root);
		bool reverse = false;
		while (!qu.empty()) {
			int s = qu.size();
			vector<int> level(s);

			for (int i = 0; i < s; i++) {
				TreeNode* node = qu.front();
				qu.pop();
				int idx = reverse ? (s - 1 - i) : i;
				level[idx] = node->val;
				if (node->left)
					qu.push(node->left);
				if (node->right)
					qu.push(node->right);
			}
			reverse = !reverse;
			v.push_back(level);
		}

		return v;
	}
};