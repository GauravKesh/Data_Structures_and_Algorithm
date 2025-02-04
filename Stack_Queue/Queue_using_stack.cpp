//
// Created by Gaurav Kesh Roushan on 01/02/25.
//
class MyQueue {
private:
	std::stack<int> stk1;
	std::stack<int> stk2;

public:
	MyQueue() {}

	void push(int x) { stk1.push(x); }

	int pop() {
		if (!stk2.empty()) {
			int temp = stk2.top();
			stk2.pop();
			return temp;
		}
		while (!stk1.empty()) {
			int temp = stk1.top();
			stk1.pop();
			stk2.push(temp);
		}
		int temp = stk2.top();
		stk2.pop();
		return temp;
	}

	int peek() {
		if (!stk2.empty()) {
			return stk2.top();
		}
		while (!stk1.empty()) {
			int temp = stk1.top();
			stk1.pop();
			stk2.push(temp);
		}
		return stk2.top();
	}

	bool empty() { return stk1.empty() && stk2.empty();
	}
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */