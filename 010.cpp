class Solution
{
public:
	bool isMatch(string s, string p)
	{
		int n = (int)p.size(), m = (int)s.size();
		vector<int> match(m + 1);
		match[0] = 1;
		for (int i = 0; i < n; ++i) {
			if (i + 1 < n && p[i + 1] == '*') {
				int star = 0;
				for (int j = 0; j <= m; ++j) {
					if (star) {
						if (p[i] == '.' || p[i] == s[j - 1]) {
							match[j] = 1;
						} else {
							star = 0;
						}
					}
					if (!star && match[j]) {
						star = true;
					}
				}
				++i;
			} else {
				for (int j = m; j > 0; --j) {
					match[j] = match[j - 1] && (p[i] == '.' || p[i] == s[j - 1]);
				}
				match[0] = false;
			}
		}
		return match.back();
	}
};
