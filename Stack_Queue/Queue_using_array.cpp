//
// Created by Gaurav Kesh Roushan on 01/02/25.
//
#include <iostream>
#include <vector>

using namespace std;

class Queue {
private:
	int size;
	int cSize;
	int start;
	int end;
	vector<int> que;

public:
	Queue(int sz) {
		this->size = sz;
		this->cSize = 0;
		this->start = -1;
		this->end = -1;
		que.resize(sz);
	}

	bool isQueueEmpty() {
		return cSize == 0;
	}

	bool isQueueFull() {
		return size == cSize;
	}

	void push(int val) {
		if (isQueueFull()) {
			cout << "Queue is Full" << endl;
			return;  // Exit function if queue is full
		}
		if (start == -1) {
			start = 0;
		}
		end = (end + 1) % size;
		que[end] = val;
		cSize++;
		cout << val << " inserted into the queue." << endl;
	}

	void pop() {
		if (isQueueEmpty()) {
			cout << "Queue is Empty" << endl;
			return;  // Exit function if queue is empty
		}
		cout << "Popped: " << que[start] << endl;
		start = (start + 1) % size;
		cSize--;
	}

	void peek() {
		if (isQueueEmpty()) {
			cout << "Queue is Empty" << endl;
			return;
		}
		cout << "First Element in queue: " << que[start] << endl;
	}

	void display() {
		if (isQueueEmpty()) {
			cout << "Queue is Empty" << endl;
			return;
		}
		cout << "Queue elements: ";
		for (int i = 0; i < cSize; i++) {
			cout << que[(start + i) % size] << " ";
		}
		cout << endl;
	}
};

int main() {
	Queue q(5);
	q.push(10);
	q.push(20);
	q.push(30);
	q.push(40);
	q.push(50);
	q.push(60);  // Corrected missing semicolon

	q.display();

	q.pop();
	q.pop();

	q.display();

	return 0;
}
