class Solution
{
	int max_len = 0;
	int depth(TreeNode* root)
	{
		if (root == nullptr) {
			return 0;
		}
		int l = depth(root->left), r = depth(root->right);
		max_len = max(max_len, l + r);
		return max(l, r) + 1;
	}
public:
	int diameterOfBinaryTree(TreeNode* root)
	{
		depth(root);
		return max_len;
	}
};
