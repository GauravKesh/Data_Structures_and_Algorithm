//
// Created by Gaurav Kesh Roushan on 30/11/24.
//
#include <iostream>
#include <vector>

using namespace std;




int main(){
	int t;
	cin>>t;
	while(t--){
		int a,b;
		cin>>a>>b;
		int m = INT_MAX;
		for(int i=a;i<=b;i++){
			if(i%a == i%b){
				m = min(m,i);

			}
		}
		cout<<m;
	}

}