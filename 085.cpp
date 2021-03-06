class Solution
{
	vector<int> heights;
	int largestRectangleArea()
	{
		int res = 0;
		stack<int> pos;
		pos.push(-1);
		int n = (int)heights.size();
		for (int i = 0; i < n; ++i) {
			while (pos.size() > 1) {
				int p = pos.top(), h = heights[p];
				if (h < heights[i]) {
					break;
				}
				pos.pop();
				res = max(res, h * (i - pos.top() - 1));
			}
			pos.push(i);
		}
		return res;
	}
public:
	int maximalRectangle(vector<vector<char>>& matrix)
	{
		if (matrix.empty() || matrix[0].empty()) {
			return 0;
		}
		int res = 0;
		int n = (int)matrix.size(), m = (int)matrix[0].size();
		heights.resize(m + 1, 0);
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				if (matrix[i][j] == '1') {
					++heights[j];
				} else {
					heights[j] = 0;
				}
			}
			res = max(res, largestRectangleArea());
		}
		return res;
	}
};
