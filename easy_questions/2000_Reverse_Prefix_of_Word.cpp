//
// Created by Gaurav Kesh Roushan on 21/11/24.
//
#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
	static string reversePrefix(string word, char ch) {
		int i,j,n;
		j=0;
		bool exist = false;
		n = word.size();
		for( i=0;i<n;i++){
			if(word[i]==ch){
				exist=true;
				break;
			}
			j++;
		}
		i=0;
		while(i<j && exist){
			swap(word[i++],word[j--]);
		}
		return word;
	}
};


int main(){
	string word = "abcdefd";
	char ch = 'd';
	cout<<Solution::reversePrefix(word,ch);
}