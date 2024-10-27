#include <iostream>
#include <vector>

using namespace std;

class DLLNode {
public:
	int data;
	DLLNode *next;
	DLLNode *prev;

	explicit DLLNode(int data1, DLLNode *next1 = nullptr, DLLNode *prev1 = nullptr) {
		data = data1;
		next = next1;
		prev = prev1;
	}
};

DLLNode *arrayToDoublyLinkedList(vector<int> &arr) {
	if (arr.empty()) return nullptr;

	DLLNode *head = new DLLNode(arr[0]);
	DLLNode *mov = head;
	int n = arr.size();
	for (int i = 1; i < n; i++) {
		DLLNode *newDLLNode = new DLLNode(arr[i], nullptr, mov);
		mov->next = newDLLNode;
		mov = newDLLNode;
	}
	return head;
}

void displayAllElementOfDLL(DLLNode *head) {
	if (head == nullptr) {
		cout << "The list is empty!" << endl;
		return;
	}
	DLLNode *mov = head;
	cout << "Elements of the DLL: ";
	while (mov != nullptr) {
		cout << mov->data << " ";
		mov = mov->next;
	}
	cout << endl;
}

int sizeOfDLL(DLLNode *head) {
	DLLNode *mov = head;
	int count = 0;
	while (mov != nullptr) {
		count++;
		mov = mov->next;
	}
	return count;
}


DLLNode *reverseADLL(DLLNode *head){
	DLLNode *temp = head;
	DLLNode *mov = temp;
	while(mov->next !=nullptr){
		DLLNode *prev = mov->prev;
		mov->prev = mov->next;
		mov->next = prev;
		mov = mov->prev;
	}
	mov->next = mov->prev;
	mov->prev = nullptr;
	head = mov;
	return head;
}

DLLNode *deleteHead(DLLNode *head) {
	if (head == nullptr) {
		cout << "The list is empty, nothing to delete!" << endl;
		return nullptr;
	}
	DLLNode *temp = head;
	head = head->next;
	if (head != nullptr) {
		head->prev = nullptr;
	}
	delete temp;
	return head;
}

DLLNode *deleteTail(DLLNode *head) {
	if (head == nullptr) {
		cout << "The list is empty, nothing to delete!" << endl;
		return nullptr;
	}
	if (head->next == nullptr) {
		return deleteHead(head);
	}
	DLLNode *temp = head;
	while (temp->next != nullptr) {
		temp = temp->next;
	}
	temp->prev->next = nullptr;
	delete temp;
	return head;
}

DLLNode *deleteElementAtGivenPosition(DLLNode *head, int pos) {
	if (head == nullptr) {
		cout << "The list is empty, nothing to delete!" << endl;
		return nullptr;
	}

	if (pos <= 0 || pos > sizeOfDLL(head)) {
		cout << "Invalid position!" << endl;
		return head;
	}

	if (pos == 1) {
		return deleteHead(head);
	}

	DLLNode *temp = head;
	int tracker = 1;
	while (tracker < pos) {
		temp = temp->next;
		tracker++;
	}

	if (temp->next != nullptr) {
		temp->next->prev = temp->prev;
	}
	if (temp->prev != nullptr) {
		temp->prev->next = temp->next;
	}
	delete temp;
	return head;
}

int main() {
	DLLNode *head = nullptr;
	vector<int> arr;
	int choice, num, pos;

	cout << "Welcome to the Interactive Doubly Linked List program!" << endl;

	while (true) {
		cout << "\nChoose an operation:" << endl;
		cout << "1. Create a new doubly linked list from an array" << endl;
		cout << "2. Display the elements of the doubly linked list" << endl;
		cout << "3. Delete the head of the list" << endl;
		cout << "4. Delete the tail of the list" << endl;
		cout << "5. Delete an element at a specific position" << endl;
		cout << "6. Get the size of the list" << endl;
		cout << "7. Reverse the List" << endl;
		cout << "8. Exit" << endl;

		cout << "Enter your choice (1-8): ";
		cin >> choice;

		switch (choice) {
			case 1:
				arr.clear();
				cout << "Enter the number of elements: ";
				cin >> num;
				cout << "Enter the elements:" << endl;
				for (int i = 0; i < num; i++) {
					int element;
					cin >> element;
					arr.push_back(element);
				}
				head = arrayToDoublyLinkedList(arr);
				cout << "Doubly linked list created!" << endl;
				break;

			case 2:
				displayAllElementOfDLL(head);
				break;

			case 3:
				head = deleteHead(head);
				cout << "Head deleted!" << endl;
				break;

			case 4:
				head = deleteTail(head);
				cout << "Tail deleted!" << endl;
				break;

			case 5:
				cout << "Enter the position to delete (starting from 1): ";
				cin >> pos;
				head = deleteElementAtGivenPosition(head, pos);
				cout << "Element at position " << pos << " deleted!" << endl;
				break;

			case 6:
				cout << "The size of the list is: " << sizeOfDLL(head) << endl;
				break;
			case 7:
				cout << "Reversed Double Linked List is:-  ";
				head = reverseADLL(head);
				displayAllElementOfDLL(head);
				break;

			case 8:
				cout << "Exiting program..." << endl;
				return 0;

			default:
				cout << "Invalid choice! Please enter a number between 1 and 7." << endl;
				break;
		}
	}

	return 0;
}
