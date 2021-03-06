class Solution
{
	deque<pair<int, int>> descend;
	void insert(int v, int p)
	{
		while (!descend.empty() && descend.back().first < v) {
			descend.pop_back();
		}
		descend.emplace_back(v, p);
	}
public:
	vector<int> maxSlidingWindow(vector<int>& nums, int k)
	{
		vector<int> res;
		if (nums.empty()) {
			return res;
		}
		for (int i = 0; i < k; ++i) {
			insert(nums[i], i);
		}
		res.push_back(descend.front().first);
		for (int i = k; i < (int)nums.size(); ++i) {
			if (descend.front().second == i - k) {
				descend.pop_front();
			}
			insert(nums[i], i);
			res.push_back(descend.front().first);
		}
		return res;
	}
};
