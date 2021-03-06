class MedianFinder
{
	priority_queue<int> left, right;
public:
	/** initialize your data structure here. */
	MedianFinder()
	{

	}

	void addNum(int num)
	{
		if (left.empty() || num <= left.top()) {
			left.push(num);
		} else {
			right.push(-num);
		}
		if (left.size() > right.size() + 1) {
			num = left.top();
			left.pop();
			right.push(-num);
		} else if (right.size() > left.size()) {
			num = -right.top();
			right.pop();
			left.push(num);
		}
	}

	double findMedian()
	{
		return left.size() == right.size() ? (left.top() + -right.top()) * 0.5 : left.top();
	}
};
