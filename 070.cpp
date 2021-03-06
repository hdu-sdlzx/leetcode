class Solution
{
	int fibonacci(int n)
	{
		int a = 1, b = 1;
		for (int i = 1; i < n; ++i) {
			int t = a;
			a += b;
			b = t;
		}
		return a;
	}
public:
	int climbStairs(int n)
	{
		return fibonacci(n);
	}
};
