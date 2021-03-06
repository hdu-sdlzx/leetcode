class Solution
{
public:
	ListNode* mergeKLists(vector<ListNode*>& lists)
	{
		ListNode* head = new ListNode(0), * tail = head, * res = nullptr;
		priority_queue<pair<int, int>> min_head;
		int n = (int)lists.size();
		for (int i = 0; i < n; ++i) {
			if (lists[i]) {
				min_head.emplace(-lists[i]->val, i);
			}
		}
		while (!min_head.empty()) {
			auto x = min_head.top();
			int p = x.second;
			min_head.pop();
			tail->next = lists[p];
			tail = tail->next;
			lists[p] = tail->next;
			if (lists[p]) {
				min_head.emplace(-lists[p]->val, p);
			}
		}
		res = head->next;
		delete head;
		return res;
	}
};
