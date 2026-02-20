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
private:
	int lh(TreeNode* root){
		int h = 0;
		while(root){
			h++;
			root = root->left;
		}
		return h;
	}
	int rh(TreeNode* root){
		int h = 0;
		while(root){
			h++;
			root=root->right;
		}
		return h;
	}
public:
	int countNodes(TreeNode* root) {
		if(!root) return 0;
		int lhs= lh(root);
		int rhs = rh(root);
		if(lhs==rhs) return (1<<lhs)-1;
		return 1 + countNodes(root->left) + countNodes(root->right);    }
public:
	int countNodes(TreeNode* root) {
		if(!root) return 0;
		if(!root->right) return 1+countNodes(root->left);
		if(!root->left) return 1;
		return 1+countNodes(root->left)+countNodes(root->right);
	}
};