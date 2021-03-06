class Solution
{
public:
	int findUnsortedSubarray(vector<int>& nums)
	{
		int n = (int)nums.size();
		int l = n, r = 0;
		int min_right = nums[n - 1];
		for (int i = n - 2; i >= 0; --i) {
			if (min_right < nums[i]) {
				l = min(l, i);
			}
			min_right = min(min_right, nums[i]);
		}
		int max_left = nums[0];
		for (int i = 1; i < n; ++i) {
			if (max_left > nums[i]) {
				r = max(r, i + 1);
			}
			max_left = max(max_left, nums[i]);
		}
		return r > l ? r - l : 0;
	}
};
