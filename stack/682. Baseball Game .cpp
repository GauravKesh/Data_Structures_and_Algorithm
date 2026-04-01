//
// Created by Gaurav Kesh Roushan on 01/04/26.
//
class Solution {
	stack<int> stk;
	int sum = 0;

public:
	int calPoints(vector<string>& operations) {

		for (auto &op : operations) {
			if (op == "C") {
				sum -= stk.top();
				stk.pop();
			}
			else if (op == "D") {
				int v = 2 * stk.top();
				stk.push(v);
				sum += v;
			}
			else if (op == "+") {
				int top1 = stk.top(); stk.pop();
				int top2 = stk.top();
				stk.push(top1);

				int v = top1 + top2;
				stk.push(v);
				sum += v;
			}
			else {
				int num = stoi(op);
				stk.push(num);
				sum += num;
			}
		}
		return sum;
	}
};