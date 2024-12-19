//
// Created by Gaurav Kesh Roushan on 19/12/24.
//
class Solution {
private:
	// Function to calculate the length of the linked list
	int getLength(ListNode* head) {
		int cnt = 0;
		ListNode* temp = head;
		while (temp != nullptr) {
			temp = temp->next;
			cnt++;
		}
		return cnt;
	}

public:
	ListNode* rotateRight(ListNode* head, int k) {
		if (head == nullptr || head->next == nullptr || k == 0) {
			return head;
		}

		int leng = getLength(head);
		k = k % leng;

		if (k == 0) {
			return head;
		}

		ListNode* temp = head;

		for (int i = 0; i < leng - k - 1; i++) {
			temp = temp->next;
		}
		ListNode* newHead = temp->next;
		temp->next = nullptr;
		ListNode* tail = newHead;
		while (tail->next != nullptr) {
			tail = tail->next;
		}
		tail->next = head;

		return newHead;
	}
};
