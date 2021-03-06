class Solution
{
	map<char, char> left;
public:
	Solution()
	{
		left[')'] = '(';
		left['}'] = '{';
		left[']'] = '[';
	}
	bool isValid(string s)
	{
		stack<char> brackets;
		for (char c : s) {
			char t = left[c];
			if (t == 0) {
				brackets.push(c);
			} else if (!brackets.empty() && brackets.top() == t) {
				brackets.pop();
			} else {
				brackets.push('*');
				break;
			}
		}
		return brackets.empty();
	}
};
