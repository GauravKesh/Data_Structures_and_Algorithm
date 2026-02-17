//
// Created by Gaurav Kesh Roushan on 17/02/26.
//

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;

	TreeNode() : val(0),
				 left(nullptr),
				 right(nullptr) {}

	TreeNode(int x) : val(x),
					  left(nullptr),
					  right(nullptr) {}

	TreeNode(int x,
			 TreeNode *left,
			 TreeNode *right)
			: val(x),
			  left(left),
			  right(right) {}
};

class Solution {
public:
	bool
	isSameTree(TreeNode *p,
			   TreeNode *q) {

		if (!p && !q)
			return true;
		if (!p || !q)
			return false;

		return (p->val ==
				q->val) &&
			   isSameTree(
					   p->left,
					   q->right) &&
			   isSameTree(
					   p->right,
					   q->left);
	}

	bool isSymmetric(
			TreeNode *root) {
		TreeNode *p = root->left;
		TreeNode *q = root->right;
		if (!root)
			return false;
		return isSameTree(
				root->left,
				root->right);
	}
};