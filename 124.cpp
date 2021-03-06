class Solution
{
	int res = INT_MIN;
	int dfs(TreeNode* root)
	{
		if (root == nullptr) {
			return INT_MIN / 3;
		}
		int l_path = dfs(root->left), r_path = dfs(root->right);
		int path = max(max(l_path, r_path), 0) + root->val;
		res = max(res, path);
		res = max(res, l_path + r_path + root->val);
		return path;
	}
public:
	int maxPathSum(TreeNode* root)
	{
		dfs(root);
		return res;
	}
};
