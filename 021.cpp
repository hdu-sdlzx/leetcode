class Solution
{
public:
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2)
	{
		ListNode* res = nullptr;
		ListNode* head = new ListNode(0), * tail = head;
		while (l1 && l2) {
			if (l1->val > l2->val) {
				swap(l1, l2);
			}
			tail->next = l1;
			tail = tail->next;
			l1 = l1->next;
		}
		tail->next = (ListNode*)((intptr_t)l1 | (intptr_t)l2);
		res = head->next;
		delete head;
		return res;
	}
};
