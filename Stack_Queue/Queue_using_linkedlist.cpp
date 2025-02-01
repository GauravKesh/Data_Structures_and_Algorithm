//
// Created by Gaurav Kesh Roushan on 01/02/25.
//

#include <iostream>

using namespace std;

class Node {
public:
	int data;
	Node *next;

	Node(int dat) {
		this->data = dat;
		this->next = nullptr;
	}
};

class QueueLL {
private:
	int size;
	Node *start;
	Node *end;

public:
	QueueLL() {
		this->start = nullptr;
		this->end = nullptr;
		this->size = 0;
	}

	bool isQueueEmpty() {
		return start == nullptr;
	}

	void push(int val) {
		Node* temp = new Node(val);
		if (isQueueEmpty()) {
			start = temp;
			end = temp;
		} else {
			end->next = temp;
			end = temp;
		}
		size++;
	}

	void pop() {
		if (isQueueEmpty()) {
			cout << "Queue is Empty" << endl;
			return;
		}
		Node* temp = start;
		start = start->next;
		delete temp;
		size--;

		if (start == nullptr) {
			end = nullptr; // Reset end when queue becomes empty
		}
	}

	int peek() {
		if (isQueueEmpty()) {
			cout << "Queue is Empty" << endl;
			return -1;
		}
		return start->data;
	}

	void display() {
		if (isQueueEmpty()) {
			cout << "Queue is Empty" << endl;
			return;
		}
		Node *temp = start;
		cout << "Queue Elements: ";
		while (temp != nullptr) {
			cout << temp->data << " <- ";
			temp = temp->next;
		}
		cout << "NULL" << endl;
	}

	~QueueLL() {
		while (!isQueueEmpty()) {
			pop();
		}
	}
};

int main() {
	QueueLL queue;

	queue.push(10);
	queue.push(20);
	queue.push(30);

	queue.display(); // Output: Queue Elements: 10 <- 20 <- 30 <- NULL

	cout << "Front of Queue: " << queue.peek() << endl; // Output: Front of Queue: 10

	queue.pop();
	queue.display(); // Output: Queue Elements: 20 <- 30 <- NULL

	return 0;
}
