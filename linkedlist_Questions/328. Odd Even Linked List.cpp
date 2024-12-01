//
// Created by Gaurav Kesh Roushan on 01/12/24.
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

/*Only solution*/

class Solution {
public:
	static ListNode* oddEvenList(const ListNode* head) {
		if (head == nullptr || head->next == nullptr) {
			return head;
		}
		ListNode* odd = head;
		ListNode* even = head->next;
		ListNode* evenHead = head->next;
		while (even != nullptr && even->next != nullptr) {
			odd->next = odd->next->next;
			even->next = even->next->next;
			odd = odd->next;
			even = even->next;
		}
		odd->next = evenHead;
		return head;
	}
};