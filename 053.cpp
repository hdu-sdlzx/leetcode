class Solution
{
public:
	int maxSubArray(vector<int>& nums)
	{
		int res = nums[0];
		int sum = 0;
		for (auto x : nums) {
			if (sum < 0) {
				sum = 0;
			}
			sum += x;
			res = max(res, sum);
		}
		return res;
	}
};
