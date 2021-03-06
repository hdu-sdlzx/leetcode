class Solution
{
public:
	bool isPalindrome(ListNode* head)
	{
		vector<int> origin;
		for (auto p = head; p; p = p->next) {
			origin.push_back(p->val);
		}
		return equal(origin.begin(), origin.end(), origin.rbegin());
	}
};
