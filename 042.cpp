class Solution
{
public:
	int trap(vector<int>& height)
	{
		if (height.size() < 3) {
			return 0;
		}
		int res = 0;
		int n = (int)height.size();
		vector<int> left_max(n), right_max(n);
		left_max[0] = 0;
		for (int i = 1; i < n; ++i) {
			left_max[i] = max(left_max[i - 1], height[i - 1]);
		}
		right_max[n - 1] = 0;
		for (int i = n - 2; i >= 0; --i) {
			right_max[i] = max(right_max[i + 1], height[i + 1]);
		}
		for (int i = 0; i < n; ++i) {
			res += max(0, min(left_max[i], right_max[i]) - height[i]);
		}
		return res;
	}
};
