class Solution
{
public:
	void moveZeroes(vector<int>& nums)
	{
		int n = (int)nums.size(), k = 0;
		for (int i = 0; i < n; ++i) {
			if (nums[i]) {
				nums[k++] = nums[i];
			}
		}
		fill(nums.begin() + k, nums.end(), 0);
	}
};
