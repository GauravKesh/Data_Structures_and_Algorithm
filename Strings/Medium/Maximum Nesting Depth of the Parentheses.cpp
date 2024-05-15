//
// Created by Gaurav Kesh Roushan on 13/05/24.
//
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

class Solution {
public:
	static int maxDepth(std::string s) {
		int res = 0;
		int count =0;
		for(int i=0;i<s.length();i++){
			if(s[i] == '('){
				count++;
			}
			else if(s[i] == ')'){
				count--;
			}
			res = std::max(res,count);
		}

		return res;
	}
};
class Solution1 {
public:
	static int maxDepth(std::string &s) {
		if(s.empty()) return 0;
		int ans=0, p=0;
		for(char c: s){
			p+=(c=='(')-(c==')');
			ans=std::max(ans, p);
		}
		return ans;

	}
};
//  " (()(())) "
int main() {
	std::string s = "(1+(2*3)+((8)/4))+1";
	int n = Solution::maxDepth(
			s);
	int n1 = Solution1::maxDepth(
			s);
	std::cout << n<<std::endl;
	std::cout << n1;

}


/// EXOLANATION...
/*Function Definition and Signature



static int maxDepth(std::string &s)
The function is static, meaning it can be called without creating an instance of the Solution class.
It takes a reference to a std::string as an argument and returns an integer.
Empty String Check



if(s.empty()) return 0;
If the input string s is empty, the function returns 0 immediately because there are no parentheses to evaluate.
Variable Initialization



int ans = 0, p = 0;
ans is used to keep track of the maximum depth encountered.
p is used to track the current depth of nested parentheses.
Iterate Through the String



for(char c: s) {
    p += (c == '(') - (c == ')');
    ans = std::max(ans, p);
}
The function loops through each character c in the string s.
For each character:
If c is '(', p is incremented by 1.
If c is ')', p is decremented by 1.
This adjustment is done using (c == '(') - (c == ')'), which adds 1 if c is '(' and subtracts 1 if c is ')'.
std::max(ans, p) updates ans to be the maximum value between the current ans and p.
Return the Result



return ans;
After the loop finishes, the function returns ans, which contains the maximum depth of nested parentheses found in the string.
Example
Consider the input string s = "(1+(2*3)+((8)/4))+1". The function calculates the depth as follows:

Read '(': p becomes 1, ans becomes 1.
Read '1': p stays 1, ans stays 1.
Read '+': p stays 1, ans stays 1.
Read '(': p becomes 2, ans becomes 2.
Read '2': p stays 2, ans stays 2.
Read '*': p stays 2, ans stays 2.
Read '3': p stays 2, ans stays 2.
Read ')': p becomes 1, ans stays 2.
Read '+': p stays 1, ans stays 2.
Read '(': p becomes 2, ans stays 2.
Read '(': p becomes 3, ans becomes 3.
Read '8': p stays 3, ans stays 3.
Read ')': p becomes 2, ans stays 3.
Read '/': p stays 2, ans stays 3.
Read '4': p stays 2, ans stays 3.
Read ')': p becomes 1, ans stays 3.
Read ')': p becomes 0, ans stays 3.
Read '+': p stays 0, ans stays 3.
Read '1': p stays 0, ans stays 3.
Final result: ans = 3.

Thus, the maximum depth of nested parentheses in the string is 3.*/