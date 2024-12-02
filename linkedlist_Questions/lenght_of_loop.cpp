//
// Created by Gaurav Kesh Roushan on 02/12/24.
//
//{ Driver Code Starts
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Node {
	int data;
	struct Node *next;

	Node(int x) {
		data = x;
		next = NULL;
	}
};

void printList(Node *node) {
	while (node != NULL) {
		cout << node->data << " ";
		node = node->next;
	}
	cout << "\n";
}

void loopHere(Node *head, Node *tail, int position) {
	if (position == 0)
		return;

	Node *walk = head;
	for (int i = 1; i < position; i++)
		walk = walk->next;
	tail->next = walk;
}


// } Driver Code Ends
/*

struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/
class Solution {
public:
	// Function to find the length of a loop in the linked list.
	int countNodesinLoop(Node *head) {
		Node* slow = head;
		Node* fast = head;
		while(fast!=NULL && fast->next != NULL){
			slow = slow->next;
			fast= fast->next->next;
			if(slow == fast) {
				return lenOfLoop(slow,fast);
			}
		}
		return 0;
	}
	int lenOfLoop(Node* slow,Node* fast){
		int cnt = 1; fast = fast->next;
		while(fast!=slow){
			cnt++;
			fast = fast->next;
		}
		return cnt;
	}
};

//{ Driver Code Starts.

int main() {
	int t;
	cin >> t;
	cin.ignore();
	while (t--) {
		vector<int> arr;
		string input;
		getline(cin, input);
		stringstream ss(input);
		int number;
		while (ss >> number) {
			arr.push_back(number);
		}
		int k;
		cin >> k;
		cin.ignore();
		struct Node *head = new Node(arr[0]);
		struct Node *tail = head;
		for (int i = 1; i < arr.size(); ++i) {
			tail->next = new Node(arr[i]);
			tail = tail->next;
		}
		loopHere(head, tail, k);

		Solution ob;
		cout << ob.countNodesinLoop(head) << endl;
	}
	return 0;
}

// } Driver Code Ends