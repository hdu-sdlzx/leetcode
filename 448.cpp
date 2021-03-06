class Solution
{
public:
	vector<int> findDisappearedNumbers(vector<int>& nums)
	{
		vector<int> res;
		int n = (int)nums.size();
		for (int i = 0; i < n; ++i) {
			while (nums[i] != i + 1 && nums[nums[i] - 1] != nums[i]) {
				swap(nums[nums[i] - 1], nums[i]);
			}
		}
		for (int i = 0; i < n; ++i) {
			if (nums[i] != i + 1) {
				res.push_back(i + 1);
			}
		}
		return res;
	}
};
