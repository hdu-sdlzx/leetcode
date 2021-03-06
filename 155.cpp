class MinStack
{
	stack<int> normal, min_element;
public:
	MinStack()
	{
	}

	void push(int x)
	{
		normal.push(x);
		if (min_element.empty() || x <= min_element.top()) {
			min_element.push(x);
		}
	}

	void pop()
	{
		if (normal.top() == min_element.top()) {
			min_element.pop();
		}
		normal.pop();
	}

	int top()
	{
		return normal.top();
	}

	int getMin()
	{
		return min_element.top();
	}
};
