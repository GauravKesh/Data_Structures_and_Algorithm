//
// Created by Gaurav Kesh Roushan on 29/11/24.
//
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
	ListNode* deleteDuplicates(ListNode* head) {
		if (head == nullptr) return nullptr;

		ListNode* current = head;
		while (current != nullptr && current->next != nullptr) {
			if (current->val == current->next->val) {
				ListNode* temp = current->next;
				current->next = temp->next;
				delete temp;
			} else {
				current = current->next;
			}
		}

		return head;
	}
};