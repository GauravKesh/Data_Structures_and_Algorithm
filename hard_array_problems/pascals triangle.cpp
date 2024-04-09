//
// Created by Gaurav Kesh Roushan on 08/04/24.
//
#include <iostream>

using namespace std;

class Dsa{
public:
    void pascalTriangle(int r, int c){


        cout<<r<<endl<<c;

    }

    void getRowElement(int r){
        pascalTriangle(r);
    }

};



int main(){
    Dsa pascaltri;
    int row,col;
    cin>>row>>col;
    cin>>row;
    pascaltri.pascalTriangle(row,col);
    pascaltri.getRowElement(r);

}