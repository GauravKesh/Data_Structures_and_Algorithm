//
// Created by Gaurav Kesh Roushan on 16/12/24.
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
private:

	ListNode* reverseList(ListNode* head) {
		if (head == nullptr) {
			return nullptr;
		}
		ListNode* prev = nullptr;
		ListNode* curr = head;
		while (curr!= nullptr) {
			ListNode *nextTemp = curr->next;
			curr->next = prev;
			prev = curr;
			curr = nextTemp;
		}
		return prev;
	}

	ListNode* getKthNode(ListNode* temp, int k) {
		k -= 1;
		while (temp != nullptr && k>0) {
			temp = temp->next;
			k--;
		}
		return temp;
	}

public:
	ListNode* reverseKGroup(ListNode* head, int k) {
		ListNode* temp = head;
		ListNode* prev = nullptr;

		while (temp != nullptr) {
			ListNode* kthNode = getKthNode(temp,k);
			if (kthNode==nullptr) {
				if (prev) prev->next = temp;
				break;
			}
			ListNode* nextNode = kthNode->next;
			kthNode->next =nullptr;
			reverseList(temp);
			if(temp==head){
				head= kthNode;
			}else{
				prev->next = kthNode;
			}
			prev = temp;
			temp = nextNode;
		}
		return head;
	}
};
