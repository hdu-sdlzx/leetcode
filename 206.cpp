class Solution
{
public:
	ListNode* reverseList(ListNode* head)
	{
		ListNode* res = nullptr;
		while (head) {
			auto t = head->next;
			head->next = res;
			res = head;
			head = t;
		}
		return res;
	}
};
