//
// Created by Gaurav Kesh Roushan on 05/03/26.
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
/*
 *
--------------- APPROACH ---------------
1. BST Rule
left  < root
		right > root

2. Start from root and compare value.

3. If val < root->val
→ go left

4. If val > root->val
→ go right

5. When child == NULL
→ create new node and attach.

6. Return original root.

Time  : O(h)
Space : O(h)
		(h = height of tree)
*/
class Solution {
private:
	TreeNode* k(int ins){
		return new TreeNode(ins);
	}
	TreeNode* ins(TreeNode* root, int v){
		if(root->val>v){
			if(!root->left){
				root->left = k(v);
			}else{
				ins(root->left,v);
			}
		}else{
			if(!root->right){
				root->right = k(v);
			}else{
				ins(root->right,v);
			}
		}
		return root;
	}
public:
	TreeNode* insertIntoBST(TreeNode* root, int val) {
		if(!root) return  k(val);
		return ins(root,val);
	}
};


