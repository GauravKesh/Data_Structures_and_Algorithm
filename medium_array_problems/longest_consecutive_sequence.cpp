//
// Created by Gaurav Kesh Roushan on 15/02/24.
//
#include <iostream>
#include <vector>
#include <unordered_set>


bool linearSearch(std::vector<int> &arr, int n, int k) {
    for (int m = 0; m < n; m++) {
        if (arr[m] == k) {
            return true;
            break;
        }
    }
    return false;
}

void longestConsecutiveSequence_brute(std::vector<int> &arr) {
    int n = arr.size();

    int longest = 1;
    for (int i = 0; i < n; i++) {
        int x = arr[i];
        int cnt = 1;
        while (linearSearch(arr, n, x + 1)) {
            x = x + 1;
            cnt += 1;
        }
        longest = std::max(longest, cnt);
    }

    std::cout << longest;
}

void longestConsecutiveSequence_better(std::vector<int> &arr) {
    int n = arr.size();
    int longest =1;
    // sorting in ascending order
    sort(arr.begin(),arr.end());
    int cnt =1;
    int ls =INT_MIN;
    for(int i=0;i<n;i++){
        int x = arr[i];
        if(arr[i]-1==ls){
            cnt+=1;
            ls =arr[i];
        }
        else if(x!=ls){
            cnt =1;
            ls =arr[i];
        }
        longest =std::max(longest,cnt);
    }
    std::cout<<longest<<" ";

}

int longestSuccessiveElements(std::vector<int>&a) {
    int n = a.size();
    if (n == 0) return 0;
    int longest = 1;
    std::unordered_set<int> st;
    //put all the array elements into set:
    for (int i = 0; i < n; i++) {
        st.insert(a[i]);
    }

    //Find the longest sequence:
    for (auto it : st) {
        //if 'it' is a starting number:
        if (st.find(it - 1) == st.end()) {
            //find consecutive numbers:
            int cnt = 1;
            int x = it;
            while (st.find(x + 1) != st.end()) {
                x = x + 1;
                cnt = cnt + 1;
            }
            longest = std::max(longest, cnt);
        }
    }
    return longest;

}

int main() {

//    std::vector<int> arr = {102, 4, 100, 1, 101, 3, 2, 1, 1};
    std::vector<int> arr = {100,102,100,101,101,4,3,2,3,2,1,1,1,2,5};
//    longestConsecutiveSequence_brute(arr);
//    longestConsecutiveSequence_better(arr);
//    longestConsecutiveSequence_Optimal(arr);
    std::vector<int> a = {100, 200, 1, 2, 3, 4};
    int ans = longestSuccessiveElements(a);
    std::cout << "The longest consecutive sequence is " << ans << "\n";
    return 0;
}