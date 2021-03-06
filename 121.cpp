class Solution
{
public:
	int maxProfit(vector<int>& prices)
	{
		if (prices.empty()) {
			return 0;
		}
		int res = 0;
		int min_buy = prices[0];
		for (auto p : prices) {
			res = max(res, p - min_buy);
			min_buy = min(min_buy, p);
		}
		return res;
	}
};
