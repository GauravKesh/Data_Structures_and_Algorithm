//
// Created by Gaurav Kesh Roushan on 01/02/25.
//
#include <iostream>
#include <vector>

using namespace std;

class Stack {
private:
	 int size;
	 int top;
	 vector<int> stk;

public:
	Stack(int siz = 10) {
		size = siz;
		top = -1;
		stk.resize(size);
	}

	 bool isStackEmpty() {
		return top == -1;
	}

	 bool isStackFull() {
		return top == size - 1;
	}

	 void push(int val) {
		if (isStackFull()) {
			cout << "Stack Overflow" << endl;
			return;
		}
		stk[++top] = val;
		cout << val << " Pushed into the stack!!" << endl;
	}

	 int peek() {
		if (isStackEmpty()) {
			cout << "Stack Underflow" << endl;
			return -1;
		}
		return stk[top];
	}

	 void pop() {
		if (isStackEmpty()) {
			cout << "Stack Underflow" << endl;
			return;
		}
		cout << stk[top--] << " Removed from stack" << endl;
	}

	 void display() {
		if (isStackEmpty()) {
			cout << "Stack is empty!" << endl;
			return;
		}
		cout << "Stack elements: ";
		for (int i = 0; i <= top; i++) {
			cout << stk[i] << " <- ";
		}
		cout << "TOP" << endl;
	}
};

int main() {
	Stack s(5);  // Stack of size 5

	s.push(10);
	s.push(20);
	s.push(30);
	s.display();

	cout << "Top element: " << s.peek() << endl;

	s.pop();
	s.display();

	cout << (s.isStackEmpty() ? "Stack is empty" : "Stack is not empty") << endl;
	return 0;
}
