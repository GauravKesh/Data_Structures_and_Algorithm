//
// Created by Gaurav Kesh Roushan on 09/04/24.
//
#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
	int timeRequiredToBuy(vector<int>& tickets, int k) {
		int np = tickets.size();
		vector<int> ticketsBought(np, 0); // Array to track tickets bought by each person
		int timeTaken = 0;

		while (tickets[k] > 0) {  // Continue until the person at position k has bought all their tickets
			for (int i = 0; i < np; i++) {  // Iterate through each person in the line
				if (tickets[i] > 0) { // If the person still wants tickets
					tickets[i] = tickets[i] - 1;  // Simulate the person buying a ticket
					ticketsBought[i]++; // Increment tickets bought by this person
					timeTaken++;  // Increment timeTaken for each ticket bought

					if (i == k && tickets[i] == 0)  // Check if the person at position k has finished buying tickets
						return timeTaken;
				}
			}
		}
		return timeTaken;
	}
};

int main() {
//    vector<int> students = {0, 1, 2, 2, 3, 0, 4, 2};
    vector<int> students = {2,3,2};
    int val = 2;
    Solution st;
    int n = st.timeRequiredToBuy(students, val);
	cout<<n;

}