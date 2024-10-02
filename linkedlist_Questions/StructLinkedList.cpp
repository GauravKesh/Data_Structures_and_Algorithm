//
// Created by Gaurav Kesh Roushan on 02/10/24.
//
#include <iostream>
#include <vector>

using namespace std;

struct Node{
public:
	int data;
	Node *next;
public:
	explicit Node(int data1){
		data = data1;
		next = nullptr;
	};
};

int main() {
	int a = 16;
	Node *y = new Node(a);
	cout << y->data<<endl; // prints the data in the node
	cout << y; // address of the node
	return 0;
}