class Solution
{
public:
	TreeNode* invertTree(TreeNode* root)
	{
		if (root == nullptr) {
			return root;
		}
		auto t = root->left;
		root->left = invertTree(root->right);
		root->right = invertTree(t);
		return root;
	}
};
