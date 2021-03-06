class Solution
{
public:
	vector<int> twoSum(vector<int>& nums, int target)
	{
		vector<int> res;
		map<int, int> nums_idx;
		int n = (int)nums.size();
		for (int i = 0; i < n && res.empty(); ++i) {
			int x = nums[i], y = target - x;
			if (nums_idx.count(y)) {
				res = { nums_idx[y], i };
			}
			nums_idx[x] = i;
		}
		return res;
	}
};
