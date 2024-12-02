//
// Created by Gaurav Kesh Roushan on 02/12/24.
//
class Solution {
public:
	int isPrefixOfWord(string sentence, string searchWord) {
		int sz = searchWord.size();
//		The sentence string is passed to a stringstream object s,
//		which allows easy extraction of words using the >> operator.
		stringstream s(sentence);
		string t;  // to store the word from s
		for (int i=1;s>>t;i++){
			if(t.substr(0,sz)==searchWord) return i;
		}
		return -1;

	}
};

/*Python code*/

//class Solution:
//		def isPrefixOfWord(self, sentence: str, searchWord: str) -> int:
//a = sentence.split()
//for i in range(len(a)):
//if a[i].startswith(searchWord):
//return i + 1
//return -1
