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

class StackLL {
private:
	Node* top;

public:
	StackLL() {
		this->top = nullptr;
	}

	bool isStackEmpty() {
		return top == nullptr;
	}

	void push(int val) {
		Node *node = new Node(val);
		if (top == nullptr) {
			top = node;
		} else {
			node->next = top;
			top = node;
		}
	}

	void pop() {
		if (isStackEmpty()) {
			cout << "Stack underflow! Cannot pop from an empty stack." << endl;
			return;
		}
		Node *temp = top;
		top = top->next;
		delete temp;
	}

	int peek() {
		if (isStackEmpty()) {
			cout << "Stack is empty!" << endl;
			return -1; // Return a sentinel value
		}
		return top->data;
	}

	void display() {
		if (isStackEmpty()) {
			cout << "Stack is empty!" << endl;
			return;
		}
		Node *temp = top;
		cout << "Stack elements: ";
		while (temp != nullptr) {
			cout << temp->data << " ";
			temp = temp->next;
		}
		cout << endl;
	}

	~StackLL() {
		while (!isStackEmpty()) {
			pop();
		}
	}
};

int main() {
	StackLL stack;

	stack.push(10);
	stack.push(20);
	stack.push(30);

	stack.display(); // Output: Stack elements: 30 20 10

	cout << "Top element: " << stack.peek() << endl; // Output: Top element: 30

	stack.pop();
	stack.display(); // Output: Stack elements: 20 10

	return 0;
}
