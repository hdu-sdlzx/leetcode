class Solution
{
	vector<vector<int>> res;
	vector<int> a;
	int dfs(int x, int y)
	{
		if (res[x][y] > -1) {
			return res[x][y];
		}
		res[x][y] = 0;
		for (int i = x; i < y; ++i) {
			res[x][y] = max(res[x][y], dfs(x, i) + dfs(i + 1, y) + a[i] * a[x - 1] * a[y]);
		}
		return res[x][y];
	}
public:
	int maxCoins(vector<int>& nums)
	{
		int n = (int)nums.size();
		res.resize(n + 2, vector<int>(n + 2, -1));
		a.push_back(1);
		copy(nums.begin(), nums.end(), back_inserter(a));
		a.push_back(1);
		return dfs(1, n + 1);
	}
};
