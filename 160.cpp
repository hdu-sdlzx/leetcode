class Solution
{
	void move(ListNode*& head)
	{
		head = head->next;
	}
	int len(ListNode* head)
	{
		int res = 0;
		while (head) {
			++res;
			move(head);
		}
		return res;
	}
public:
	ListNode* getIntersectionNode(ListNode* headA, ListNode* headB)
	{
		int n1 = len(headA), n2 = len(headB);
		if (n1 > n2) {
			swap(n1, n2);
			swap(headA, headB);
		}
		while (n2 > n1) {
			move(headB);
			--n2;
		}
		while (headA != headB) {
			move(headA);
			move(headB);
		}
		return headA;
	}
};
