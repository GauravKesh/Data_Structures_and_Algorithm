//
// Created by Gaurav Kesh Roushan on 15/02/24.
//
#include <iostream>
#include <vector>

void leaderInArray(std::vector<int> &arr) {
    int n = arr.size();
    std::vector<int> atemp;
    for (int i = 0; i < n; i++) {
        int temp = arr[i];
        bool leader = true;
        for (int j = i + 1; j < n; j++) {
            if (temp < arr[j]) {
                leader = false;
                break;
            }
        }
        if (leader) {
            atemp.push_back(arr[i]);
        }
    }
    for (auto it: atemp) {
        std::cout << it << " ";
    }
}
void leaderInArrayOptimal(std::vector<int> &arr) {
    int n = arr.size();
    int temp = INT_MIN;
    std::vector<int> atemp;
    for(int i=n-1;i>=0;i--){
        if(arr[i]>temp){
            atemp.push_back(arr[i]);

        }
        temp =std::max(temp,arr[i]);
    }
    for (auto it: atemp) {
        std::cout << it << " ";
    }
}


int main() {
//    vector<int> arr ={2,1,5,4,3,0,0};
//    vector<int> arr ={3,1,2};
    std::vector<int> arr = {10, 22, 12, 3, 0, 6,};
//    leaderInArray(arr);
    leaderInArrayOptimal(arr);

}
