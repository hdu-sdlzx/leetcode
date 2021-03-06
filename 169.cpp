class Solution
{
public:
	int majorityElement(vector<int>& nums)
	{
		int res = 0;
		int cnt = 0;
		for (auto x : nums) {
			if (x == res) {
				++cnt;
			} else {
				--cnt;
			}
			if (cnt == -1) {
				res = x;
				cnt = 1;
			}
		}
		return res;
	}
};
