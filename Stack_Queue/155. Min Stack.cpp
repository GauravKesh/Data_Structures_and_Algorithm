//
// Created by Gaurav Kesh Roushan on 03/02/25.
//
class MinStack {
private:
	stack<int> stk;
	stack<int> minstk;
public:
	MinStack() {
	}
	void push(int val) {
		stk.push(val);
		if(minstk.empty() || minstk.top()>=val){
			minstk.push(val);
		}
	}

	void pop() {
		if(minstk.top()==stk.top()){
			minstk.pop();
		}
		stk.pop();
	}

	int top() {
		return stk.top();
	}

	int getMin() {
		return minstk.top();
	}
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */