//
// Created by Gaurav Kesh Roushan on 08/04/24.
//
#include <iostream>
#include <vector>
using namespace std;

class GettingSingleElement {
public:
	// to get a specific element from the pascal triangle
	void getElement(int r, int c) {
		int res = 1;
//		inr den =1;
		for (int i = 0; i < c; i++) {
			res = res * (r - i);
			cout << res << ".....";
			res = res / (i + 1);
			cout << res << ".....";

		}
		cout << endl << "The Element is at given row" << r + 1 << " at column" << c + 1 << " is :- " << res << endl;
	}

	void getRowElement(int rr, int cc) {
		int r = rr - 1;
		int c = cc - 1;
		getElement(r, c);
	}

};
// ...

class GetAllRowElement {
public:
	void getElement(int row) {
		vector<int> rowElementArray;
//		rowElementArray.push_back(1);
		int element = 1;
		for (int i = 1; i <= row; i++) {
			element = element * (row - i);
			element = element / i;
			rowElementArray.push_back(element);
		}

		for (int i = 0; i < row; i++) {
			cout << rowElementArray[i] << " ";
		}
		cout << endl << "End of 2nd type " << endl;
	}

};


class GetPascalTriangle {
public:
	vector<int> generateRow(int row) {
		long long ans = 1;
		vector<int> ansRow;
		ansRow.push_back(1); //inserting the 1st element

		//calculate the rest of the elements:
		for (int col = 1; col < row; col++) {
			ans = ans * (row - col);
			ans = ans / col;
			ansRow.push_back(ans);
		}
		return ansRow;
	}

	void pascalTriangle(int r) {
		vector<vector<int>> ans;

		//store the entire pascal's triangle:
		for (int row = 1; row <= r; row++) {
			ans.push_back(generateRow(row));
		}
		for(int i=0;i<r;i++){
			for(int j = 0;j<i;j++){
				cout<<ans[i][j]<<" ";
			}
			cout<<endl;

		}
		cout<<endl;

	}


};


int main() {
	int row, col;
	cout << "Enter row:- ";
	cin >> row;
	cout << "Enter col:- ";
	cin >> col;
	GettingSingleElement element;
	element.getRowElement(row, col);
	GetAllRowElement rowElement;
	rowElement.getElement(row);
	GetPascalTriangle num;
	num.pascalTriangle(row);

}