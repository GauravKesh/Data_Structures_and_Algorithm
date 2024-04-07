//
// Created by Gaurav Kesh Roushan on 09/02/24.
//
#include <iostream>
#include <vector>
#include <map>
using namespace std;

void twoSum_brute(vector<int>& nums, int target) {
    int n = nums.size();
    int sum = 0;
    vector<int> temp(2);
    for (int i = 0; i < n - 1;) {
        for (int j = i+1; j < n;) {
            if (i != j && i < j) {
                sum = nums[i] + nums[j];
                if (sum == target) {
                    temp[0]=i;
                    temp[1] =j;
                    break;
                }
                else{
                    j++;
                }
            }
        }
        i++;
    }
    for(int i =0;i<temp.size();i++){
        cout<<temp[i]<<" ";
    }
}

void twoSum_better(vector<int>& nums, int target) {
    map<int,int> mpp;
    int n = nums.size();
    for(int i=0;i<n;i++){
        int a = nums[i];
        int req =target-a;
        if(mpp.find(req) != mpp.end()){
            cout<<"YES";
        }
        mpp[a] =i;
    }
    cout<<"NO";


}

int twoSum_betterA(vector<int>& nums, int target){
    int n = nums.size();
    int tar =0;
    int right =n-1,left =0;
    sort(nums.begin(),nums.end());
    while(left<right){
        int sum =nums[left]+nums[right];
        if(sum==target){
            tar =1;
        }
        else if(sum>target)left++;

        else right--;

    }
    return (tar!=0)?1:0;
}
int main(){
    vector<int> arr ={2,7,11,15};
    int target =9;
//    twoSum_brute(arr,target);
//    twoSum_better(arr,target);
    int out =twoSum_betterA(arr,target);
    cout<<out;
}