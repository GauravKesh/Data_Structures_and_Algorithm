//
// Created by Gaurav Kesh Roushan on 08/04/24.
//
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void countStudents(vector<int> &students, vector<int> &sandwiches) {
        int nst = students.size();
        int san = sandwiches.size();
        int n = nst; // stud no...
        int s = san; // sand no...
        int eat = 0;  // eaten no...
        for (int i = 0; i < students.size(); i++) {
            cout<<i<<"..."<<endl<<"  ";
            if (students[i] == sandwiches[i]) {
                eat++;
                students.erase(students.begin(), students.end() - (n - 1));
                sandwiches.erase(students.begin(), students.end() - n + 1);
                n--;
//                nr = (nr==0 || nr<0)? 0:nr--;
                cout << "eaten...." << endl;
            } else {
                reverse(students.begin(), students.end());
                reverse(students.begin(), students.end() - (n - 1));
//                nr++;
                cout << "replaced...." << endl;

            }
            cout << "++";
        }
        cout << nst - eat;
    }
};


int main() {
    vector<int> students = {1, 1, 0, 0};
    vector<int> sandwich = {0, 1, 0, 1};
    Solution st;
    st.countStudents(students, sandwich);
}