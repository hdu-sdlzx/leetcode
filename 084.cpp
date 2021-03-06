class Solution
{
public:
	int largestRectangleArea(vector<int>& heights)
	{
		heights.push_back(0);
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
};
