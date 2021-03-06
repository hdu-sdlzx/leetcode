class Solution
{
public:
	int rob(vector<int>& nums)
	{
		if (nums.size() < 4) {
			nums.resize(4);
		}
		vector<int> res(nums.begin(), nums.begin() + 4);
		res[2] += res[0];
		int n = (int)nums.size();
		for (int i = 3; i < n; ++i) {
			res[i % 4] = nums[i] + max(res[(i + 2) % 4], res[(i + 1) % 4]);
		}
		return *max_element(res.begin(), res.end());
	}
};
