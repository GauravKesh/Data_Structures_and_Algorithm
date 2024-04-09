//
// Created by Gaurav Kesh Roushan on 08/04/24.
//
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void removeElement(vector<int> &nums, int val) {
        int n = nums.size();
        int count = 0;
        const char si = '_';
        for (int i = 0; i < n; i++) {
            if (nums[i] == val   ) {
                count++;
                nums.erase(nums.begin() + i);
                nums.push_back(si);
                if(i!=0 && nums[i-1]==val){
                    nums.erase(nums.begin()+i-1);
                    nums.push_back(si);
                    count++;
                    i--;
                }

            }
            else {
                if (i != 0 && nums[i - 1] == val) {
                    nums.erase(nums.begin() + i - 1);
                    nums.push_back(si);
                    count++;
                }
            }
        }
        for (int i = 0; i < n; i++) {
            cout << nums[i] << " ,";
        }

    }


};


int main() {
//    vector<int> students = {0, 1, 2, 2, 3, 0, 4, 2};
    vector<int> students = {0,4,4,0,4,4,4,0,2};
    int val = 2;
    Solution st;
    st.removeElement(students, val);
}
