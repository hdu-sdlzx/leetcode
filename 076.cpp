class Solution
{
public:
	string minWindow(string s, string t)
	{
		string res;
		map<char, int> total, cnt;
		for (auto c : t) {
			++total[c];
		}
		int i = 0, j = 0, n = (int)s.size();
		size_t sum = 0;
		for (i = 0; i < n && sum < t.size(); ++i) {
			char c = s[i];
			++cnt[c];
			if (cnt[c] <= total[c]) {
				++sum;
			}
		}
		while (cnt[s[j]] > total[s[j]]) {
			--cnt[s[j]];
			++j;
		}
		if (sum < t.size()) {
			return res;
		}
		res = s.substr(j, i - j);
		for (; i < n; ++i) {
			char c = s[i];
			++cnt[c];
			if (cnt[c] <= total[c]) {
				++sum;
			} else if (c == s[j]) {
				while (cnt[s[j]] > total[s[j]]) {
					--cnt[s[j]];
					++j;
				}
			}
			if (res.size() > (i - j + 1)) {
				res = s.substr(j, i - j + 1);
			}
		}
		return res;
	}
};
