#include <iostream>
#include <vector>

using namespace std;

class Node {
public:
	int data;
	Node *next;
	Node *prev;

	explicit Node(int data1, Node *next1, Node *prev1) {
		data = data1;
		next = next1;
		prev = prev1;
	}

	explicit Node(int data1) {
		data = data1;
		next = nullptr;
		prev = nullptr;
	}
};

Node *arrayToDoublyLinkedList(vector<int> &arr) {
	Node *head = new Node(arr[0]);
	Node *mov = head;
	int n = arr.size();
	for (int i = 1; i < n; i++) {
		Node *newNode = new Node(arr[i], nullptr, mov);
		mov->next = newNode; // Link current node to new node
		mov = newNode;
	}
	return head;
}

void displayAllElementOfDLL(Node *head) {
	Node *mov = head;
	cout << "All the elements of the DLL are :- ";
	while (mov != nullptr) {
		cout << mov->data << " ";
		mov = mov->next;
	}
	cout << endl;
}

void getTailOfDLL(Node *head) {
	Node *mov = head;
	while (mov->next != nullptr) {
		mov = mov->next;
	}
	cout << "Tail of the DLL is: " << mov->data << endl;
}

int sizeOfDLL(Node *head) {
	Node *mov = head;
	int count = 0;
	while (mov != nullptr) {
		count++;
		mov = mov->next;
	}
	return count;
}

Node *deleteHead(Node *head) {
	if (head == nullptr) {
		cout << "DLL is empty" << endl;
		return nullptr;
	}
	Node *temp = head; // Store the old head
	head = head->next; // Move the head to the next node
	if (head != nullptr) {
		head->prev = nullptr; // Set the new head's prev pointer to nullptr
	}
	delete temp; // Free the memory of the old head
	return head;
}

Node *deleteTail(Node *head) {
	Node *temp = head;
	if (head == nullptr) {
		cout << "DLL is empty" << endl;
		return nullptr;
	}
	if (head->next == nullptr) { // If there's only one node in the list
		return deleteHead(head);
	}
	while (temp->next != nullptr) {
		temp = temp->next;
	}
	temp->prev->next = nullptr;
	delete temp;
	return head;
}

Node *deleteElementAtGivenPosition(Node *head, int pos) {
	if (head == nullptr) {
		cout << "DLL is empty" << endl;
		return nullptr;
	}

	Node *temp = head;
	int tracker = 1;
	while (temp != nullptr && tracker < pos) {
		temp = temp->next;
		tracker++;
	}

	if (temp == nullptr) {
		cout << "Position out of bounds" << endl;
		return head;
	}

	if (temp == head) {
		head = head->next;  // Update head to the next node
		if (head != nullptr) {
			head->prev = nullptr;
		}
	} else {
		if (temp->prev != nullptr) {
			temp->prev->next = temp->next;
		}
		if (temp->next != nullptr) {
			temp->next->prev = temp->prev;
		}
	}

	delete temp;
	return head;
}

int main() {
	vector<int> arr = {1, 2, 3, 4, 5, 6, 7};
	Node *head = arrayToDoublyLinkedList(arr);

	cout << "Head of the DLL is: " << head->data << endl;
	cout << "Size of the DLL is: " << sizeOfDLL(head) << endl;
	getTailOfDLL(head);
	displayAllElementOfDLL(head);

	cout << endl << "Delete head function was called:- " << endl;
	head = deleteHead(head);
	displayAllElementOfDLL(head);

	cout << endl << "Delete tail function was called:- " << endl;
	head = deleteTail(head);
	displayAllElementOfDLL(head);

	int pos = 3;
	cout << endl << "Delete element at position " << pos << " was called:- " << endl;
	head = deleteElementAtGivenPosition(head, pos);
	displayAllElementOfDLL(head);

	return 0;
}
