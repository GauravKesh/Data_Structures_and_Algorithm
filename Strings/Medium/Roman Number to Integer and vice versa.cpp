//
// Created by Gaurav Kesh Roushan on 14/05/24.
//
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
/*
	Symbol       Value
	I             1
	V             5
	X             10
	L             50
	C             100
	D             500
	M             1000
*/
class Solution {
public:
	static int romanToInt(std::string s) {
		if(s.empty()) return 0;
		int num =0;
		int n =  s.length();
		for(int i=0;i<n;i++){
			if(s[i]=='V'){
				num+=5;
			}
			if(s[i]=='L'){
				num+=50;
			}
			if(s[i]=='D'){
				num+=500;
			}
			if(s[i]=='M'){
				num+=1000;
			}
			if(s[i] == 'I'){
				if(s[i+1] == 'V') {
					num += 4;i++;
					continue;
				}
				else if(s[i+1] == 'X'){
					num+=9;
					i++;
					continue;
				}
				num+=1;
			}
			if(s[i] == 'X'){
				if(s[i+1] == 'L') {
					num += 40;i++;
					continue;

				}
				else if(s[i+1] == 'C') {
					num += 90;
					i++;
					continue;
				}
				num+=10;
			}
			if(s[i] == 'C'){
				if(s[i+1] == 'D') {
					num += 400;i++;
					continue;

				}
				else if(s[i+1] == 'M') {
					num += 900;
					i++;
					continue;
				}
				num+=100;
			}

		}

		return num;
	}
};

class SolutionOptimal {
public:
	static int romanToInt(const std::string& s) {
		if (s.empty()) return 0;

		std::unordered_map<char, int> roman_values = {
				{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50},
				{'C', 100}, {'D', 500}, {'M', 1000}
		};

		int num = 0;
		int n = s.length();

		for (int i = 0; i < n; ++i) {
			if (i + 1 < n && roman_values[s[i]] < roman_values[s[i + 1]]) {
				num += roman_values[s[i + 1]] - roman_values[s[i]];
				++i;
			} else {
				num += roman_values[s[i]];
			}
		}

		return num;
	}
};

int main() {
	std::string s = "III";
	std::string s1 = "LVIII";
	std::string s2 = "MCMXCIV";

	int n = Solution::romanToInt(
			s2);
	int n1 = SolutionOptimal::romanToInt(
			s2);
	std::cout << n<<std::endl;
	std::cout << n1<<std::endl;

}

/*Header and Includes:



// Created by Gaurav Kesh Roushan on 14/05/24.
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
These lines include necessary headers for input-output operations, string manipulation, and algorithm functions. However, vector and algorithm are not used in the code.

Class Declaration:



class Solution {
public:
    static int romanToInt(std::string s) {
This defines a class named Solution with a public static method romanToInt that takes a string s and returns an integer.

Initial Checks and Variable Declarations:



        if(s.empty()) return 0;
        int num = 0;
        int n = s.length();
The code checks if the input string s is empty and returns 0 if true.
It initializes num to store the final integer value.
n is assigned the length of the input string s.
Iterating Over the String:



        for(int i = 0; i < n; i++) {
This starts a loop that iterates through each character in the string s.

Processing Individual Characters:



            if(s[i]=='V'){
                num += 5;
            }
            if(s[i]=='L'){
                num += 50;
            }
            if(s[i]=='D'){
                num += 500;
            }
            if(s[i]=='M'){
                num += 1000;
            }
These conditional statements add the corresponding values of the Roman numeral characters V, L, D, and M to num.

Handling Subtractive Notation for 'I':



            if(s[i] == 'I'){
                if(s[i + 1] == 'V') {
                    num += 4;
                    i++;
                    continue;
                }
                else if(s[i + 1] == 'X'){
                    num += 9;
                    i++;
                    continue;
                }
                num += 1;
            }
When encountering 'I', it checks if the next character is 'V' or 'X'.
If the next character is 'V', it adds 4 to num (since IV = 4) and increments i to skip the next character.
If the next character is 'X', it adds 9 to num (since IX = 9) and increments i to skip the next character.
If neither condition is met, it adds 1 to num (since I = 1).
Handling Subtractive Notation for 'X':



            if(s[i] == 'X'){
                if(s[i + 1] == 'L') {
                    num += 40;
                    i++;
                    continue;
                }
                else if(s[i + 1] == 'C') {
                    num += 90;
                    i++;
                    continue;
                }
                num += 10;
            }
When encountering 'X', it checks if the next character is 'L' or 'C'.
If the next character is 'L', it adds 40 to num (since XL = 40) and increments i.
If the next character is 'C', it adds 90 to num (since XC = 90) and increments i.
If neither condition is met, it adds 10 to num (since X = 10).
Handling Subtractive Notation for 'C':



            if(s[i] == 'C'){
                if(s[i + 1] == 'D') {
                    num += 400;
                    i++;
                    continue;
                }
                else if(s[i + 1] == 'M') {
                    num += 900;
                    i++;
                    continue;
                }
                num += 100;
            }
When encountering 'C', it checks if the next character is 'D' or 'M'.
If the next character is 'D', it adds 400 to num (since CD = 400) and increments i.
If the next character is 'M', it adds 900 to num (since CM = 900) and increments i.
If neither condition is met, it adds 100 to num (since C = 100).
Return the Result:



        }

        return num;
    }
};
After processing all characters in the string, the method returns the final value of num.

Main Function:



int main() {
    std::string s = "III";
    std::string s1 = "LVIII";
    std::string s2 = "MCMXCIV";

    int n = Solution::romanToInt(s2);
    std::cout << n << std::endl;

    return 0;
}
This defines the main function to test the romanToInt method.
It declares some test strings: "III", "LVIII", and "MCMXCIV".
It calls the romanToInt method with "MCMXCIV" and prints the result.

Summary:-
 code correctly implements the conversion of Roman numerals to integers by:

Iterating through each character in the string.
Checking for specific Roman numeral characters and their subtractive notation cases.
Adjusting the index i appropriately to handle characters involved in subtractive notation.*/