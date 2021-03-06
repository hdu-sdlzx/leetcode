class Solution
{
public:
	int minDistance(string word1, string word2)
	{
		int n1 = word1.size(), n2 = word2.size();
		vector<vector<int>> res(n1 + 1, vector<int>(n2 + 1));
		for (int i = 0; i <= n1; ++i) {
			res[i][0] = i;
		}
		for (int i = 0; i <= n2; ++i) {
			res[0][i] = i;
		}
		for (int i = 1; i <= n1; ++i) {
			for (int j = 1; j <= n2; ++j) {
				res[i][j] = word1[i - 1] == word2[j - 1] ? res[i - 1][j - 1] : min(res[i - 1][j - 1], min(res[i][j - 1], res[i - 1][j])) + 1;
			}
		}
		return res[n1][n2];
	}
};
