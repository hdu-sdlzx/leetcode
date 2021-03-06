class Solution
{
	int _longestValidParentheses(string s)
	{
		int res = 0;
		int n = (int)s.size(), i = 0, j = 0, cnt = 0;
		for (; i < n; ++i) {
			if (s[i] == '(') {
				++cnt;
				continue;
			}
			--cnt;
			if (cnt == 0) {
				res = max(res, i - j + 1);
			}
			if (cnt < 0) {
				res = max(res, i - j);
				j = i + 1;
				cnt = 0;
			}
		}
		return res;
	}
public:
	int longestValidParentheses(string s)
	{
		string t(s.rbegin(), s.rend());
		for (auto& c : t) {
			c ^= '(' ^ ')';
		}
		return max(_longestValidParentheses(s), _longestValidParentheses(t));
	}
};
