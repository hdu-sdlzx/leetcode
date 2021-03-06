class Solution
{
public:
	bool hasCycle(ListNode* head)
	{
		set<ListNode*> vis;
		while (head) {
			if (vis.count(head)) {
				break;
			}
			vis.insert(head);
			head = head->next;
		}
		return head != nullptr;
	}
};
