/*
* https://leetcode.com/problems/invert-binary-tree/
*
*/

#include <iostream>
#include <vector>

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


TreeNode* invertTree(TreeNode* root) {
	if (root == NULL)
		return NULL;

	TreeNode* left = invertTree(root->left);
	TreeNode* right = invertTree(root->right);
	
	root->left = right;
	root->right = left;

	return root;
}

int main()
{
	//TODO write some test cases

	
	system("pause");
	return 0;
}