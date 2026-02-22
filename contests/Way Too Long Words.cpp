//
// Created by Gaurav Kesh Roushan on 08/10/24.
//
#include <iostream>
#include <string>
using namespace std;

string abbrevation(string a){
	long long n =a.size();
	if(n<=10){
		return a;
	}
	string b;
	int len =(int) n-2 ;
	b+=a[0]+to_string(len)+a[n-1];
	return b;
}


int main(){

	string input;
	int n;
	cin>>n;
	for(int i = 0;i<n;i++){
		string abbr;
		cin>>input;
		abbr = abbrevation(input);
		cout<<abbr<<endl;
	}

}