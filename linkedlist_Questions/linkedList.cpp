//
// Created by Gaurav Kesh Roushan on 02/10/24.
//
#include <iostream>
#include <vector>

using namespace std;

class Node {
public:
	int data;
	Node *next;
public:
	explicit Node(int data1) {
		data = data1;
		next = nullptr;
	}
};

//Convert Array to list
Node *arrayToLinkedList(vector<int> &arr) {
	Node *head = new Node(arr[0]);
	Node *mov = head;
	int n = arr.size();
	for (int i=1;i<n;i++) {
		Node *temp = new Node(arr[i]);
		mov->next = temp;
		mov = temp;
	}
	return head;
};

/// Print Last Element of the LL

int lastElementOfNode(Node* head){
	Node *mov = head;
	while(mov->next!= nullptr){
		mov = mov->next;
	}
	int data = mov->data;
	return data;
}

void elementOfNode(Node *head){
	Node* mov = head;
	while(mov){
		cout<<mov->data<<" ";
		mov = mov->next;
	}
	cout<<endl;
};

void addElementInLastOfLL(Node *head,int value){
	Node *mov = head;
	while(mov->next!= nullptr){
		mov = mov->next;
	};
	Node *n = new Node(value);
	mov->next = n;
	n->next = nullptr;
	elementOfNode(head);
}

void addElementAtParticularPosition(Node*& head, int value, int pos) { // pass head by reference
	// Handle inserting at the head (position 0)
	if (pos == 0) {
		Node* n = new Node(value);
		n->next = head;
		head = n;
		elementOfNode(head);
		return;
	}

	Node *mov = head;
	int track = 0;

	// Traverse to the node just before the desired position
	while (track != pos - 1 && mov != nullptr) {
		mov = mov->next;
		cout << track << " ";
		track++;
	}

	// If the position is beyond the current length of the list
	if (mov == nullptr) {
		cout << "Position is out of bounds." << endl;
		return;
	}

	cout << endl;

	// Create the new node and adjust pointers
	Node* n = new Node(value);
	n->next = mov->next; // Point new node to the next node
	mov->next = n;

	elementOfNode(head); // Print the list after insertion
	cout << endl;
}


void removeElementFromEnd(Node*& head) {
	// Edge case: if the list is empty
	if (head == nullptr) {
		cout << "The list is already empty." << endl;
		return;
	}

	// Edge case: if the list has only one node
	if (head->next == nullptr) {
		delete head; // Free the only node
		head = nullptr;
		cout << "The list is now empty." << endl;
		return;
	}

	Node *mov = head;

	// Traverse to the second-to-last node
	while (mov->next->next != nullptr) {
		mov = mov->next;
	}

	// Delete the last node
	Node *temp = mov->next;
	mov->next = nullptr;
	delete temp;

	cout << "Element removed from the end." << endl;
	elementOfNode(head);
}





int main() {
	vector<int> arr = {1, 2,
					   3,
					   4,
					   5, 6,7,8};
	Node *y = new Node(
			arr[0]);
	Node *head = arrayToLinkedList(
			arr);
//	int tail = lastElementOfNode(head);
	elementOfNode(head);
//	addElementInLastOfLL(head,29);
//	addElementAtParticularPosition(head,21,0);
	removeElementFromEnd(head);
	cout << head->data
		 << endl;
//	cout << tail;
//		 << endl;
	cout << y << endl;
	cout << y->data;
}