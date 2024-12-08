//
// Created by Gaurav Kesh Roushan on 08/12/24.
//
class Solution {
public:
	ListNode* removeElements(ListNode* head, int val) {

		while (head != nullptr && head->val == val) {
			ListNode* del = head;
			head = head->next;
			delete del;
		}

		if (head == nullptr)
			return head;

		ListNode* temp = head;
		while (temp->next != nullptr) {
			if (temp->next->val == val) {
				ListNode* del = temp->next;
				temp->next = del->next;
				delete del;
			} else {
				temp = temp->next;
			}
		}

		return head;
	}
};
