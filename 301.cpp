class Solution
{
	string s;
	set<pair<string, int>> vis;
	vector<string> res;
	void dfs(string t, int left, int right, size_t pos)
	{
		auto state = make_pair(t, pos);
		if (vis.count(state)) {
			return;
		}
		vis.insert(state);
		bool valid = true;
		int cnt = 0;
		for (auto c : t) {
			if (c == '(') {
				++cnt;
			} else if (c == ')') {
				--cnt;
				if (cnt < 0) {
					valid = false;
					break;
				}
			}
		}
		if (!valid) {
			return;
		} else if (pos == s.size()) {
			res.push_back(t);
			return;
		}
		t += s[pos];
		if (s[pos] == '(') {
			++left;
			if (left <= right) {
				dfs(t, left, right, pos + 1);
				return;
			}
			int n = (int)t.size();
			for (int i = 0; i < n; ++i) {
				if (t[i] == '(') {
					dfs(t.substr(0, i) + t.substr(i + 1), left - 1, right, pos + 1);
				}
			}
		} else if (s[pos] == ')') {
			if (left > 0 && left <= right) {
				dfs(t, left - 1, right - 1, pos + 1);
				return;
			}
			--right;
			int n = (int)t.size();
			for (int i = 0; i < n; ++i) {
				if (t[i] == ')') {
					dfs(t.substr(0, i) + t.substr(i + 1), left, right, pos + 1);
				}
			}
		} else {
			dfs(t, left, right, pos + 1);
		}
	}
public:
	vector<string> removeInvalidParentheses(string s)
	{
		this->s = s;
		int cnt = count_if(s.begin(), s.end(), [](char c) {return c == ')'; });
		dfs("", 0, cnt, 0);
		return res;
	}
};
