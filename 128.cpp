class Solution
{
public:
	int longestConsecutive(vector<int>& nums)
	{
		int res = 0;
		map<int, int> exist, len;
		for (auto x : nums) {
			exist[x] = 1;
		}
		for (auto x : nums) {
			if (len.count(x) != 0) {
				continue;
			}
			int t = x;
			while (exist[t + 1]) {
				++t;
			}
			int cnt = 0;
			for (; exist[t]; --t) {
				len[t] = ++cnt;
			}
			res = max(res, cnt);
		}
		return res;
	}
};
