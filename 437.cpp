class Solution
{
	map<int, int> val_cnt;
public:
	int pathSum(TreeNode* root, int sum)
	{
		if (root == nullptr) {
			return 0;
		}
		int v = root->val;
		if (root->left) {
			root->left->val += v;
		}
		if (root->right) {
			root->right->val += v;
		}
		int res = val_cnt[v - sum] + (sum == v);
		++val_cnt[v];
		res += pathSum(root->left, sum) + pathSum(root->right, sum);
		--val_cnt[v];
		return res;
	}
};
