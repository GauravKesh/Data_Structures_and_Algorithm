#include <iostream>
#include <vector>
using namespace std;

int main() {
	int t;
	cin >> t;

	while (t--) {
		int n;
		cin >> n;
		vector<int> b(n - 2);
		for (int i = 0; i < n - 2; ++i) {
			cin >> b[i];
		}
		bool possible = true;
		for (int i = 0; i < n - 3; ++i) {
			if (b[i] == 1 && b[i + 1] == 1) {
				possible = false;
				break;
			}
		}
		if (possible) {
			cout << "YES" << endl;
		} else {
			cout << "NO" << endl;
		}
	}

	return 0;
}
