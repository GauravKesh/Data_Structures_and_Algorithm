//
// Created by Gaurav Kesh Roushan on 25/11/24.
//

/*JUST SOLUTION*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
	bool
	hasCycle(ListNode *head) {
		if (head == NULL ||
			head->next ==
			NULL) {
			return false;
		}
		ListNode *slow = head;
		ListNode *fast = head;
		while (fast != NULL &&
			   fast->next !=
			   NULL) {
			slow = slow->next;
			fast = fast->next->next;
			if (slow ==
				fast) {
				return true;
			}
		}
		return false;
	}
};

bool has_cycle(
		SinglyLinkedListNode *head) {
	if (head == NULL ||
		head->next == NULL) {
		return false;
	}
	SinglyLinkedListNode *slow = head;
	SinglyLinkedListNode *fast = head;
	while (fast != NULL &&
		   fast->next !=
		   NULL) {
		slow = slow->next;
		fast = fast->next->next;
		if (slow == fast) {
			return true;
		}
	}
	return false;

}