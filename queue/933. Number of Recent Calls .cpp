//
// Created by Gaurav Kesh Roushan on 31/03/26.
//
class RecentCounter {
public:
	queue<int> q;

	RecentCounter() {

	}

	int ping(int t) {
		q.push(t);
		while (!q.empty() && q.front() < t - 3000) {
			q.pop();
		}

		return q.size();
	}
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */