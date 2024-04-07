//
// Created by Gaurav Kesh Roushan on 29/01/24.
//
#include <iostream>
#include <algorithm>
#include <vector>
//using namespace std;
int count =0;


void print(){
    if(count==3) return;
    std::cout<<count<<std::endl;
    count++;
    print();
}

void sumN(int n){
    int c =0;
    for(int i=1;i<=n;i++){
        c+=i;
    }
    std::cout<<c;
}

void factorialNum(int n){
    int f =1;
    for (int i =1; i <=n ; ++i) {
        f = f*i;
    }
    std::cout<<f;

}



int main(){
    int n;
    std::cout<<"Enter the number:- ";
    std::cin>>n;
    if(n==0 || n==1) {
        std::cout << 1;
    } else{
        factorialNum(n);
    }

    return 0;
}