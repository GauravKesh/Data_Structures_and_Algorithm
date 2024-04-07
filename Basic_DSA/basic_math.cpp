//
// Created by Gaurav Kesh Roushan on 24/01/24.
//
#include <iostream>
using namespace std;


int countDigit(int n){

    int num =n;
    int count =0;
    while(num!=0){
        num =num/10;
        count++;
    }
    cout<<endl;
    return count;


}


int reverseNumber(int n){
    int num =n;
    int rnum=0;
    while(num!=0){
        int rem= num % 10;
        rnum =rnum*10+rem;
        num=num/10;
    }
    return rnum;
//    cout<<"The reversed number is:- "<<rnum;

}

void pallindromeCheck(int n){
    int num = n;
    int rnum= reverseNumber(num);
    if(rnum==num){
        cout<<"The given number is a pallindrome number";
    } else{
        cout<<"The given number is not a pallindrome number";
    }

}

void gcd(int n1,int n2){
    int num;
    for(int i =1;i<=min(n1,n2);i++){
        if(n1%i==0 && n2%i==0){
            num =i;
        }
    }
    cout<< "The GCD of the two numbers is "<<num;

}

void divisor(int n){
    for(int i=1;i<=n;i++){
        if(n%i==0){
            cout<<i<<",";
        }
    }

}

void primeCheck(int n){
    int count =0;
    for(int i=2;i<=n;i++){
        if(n%i==0){
            count++;
        }
    }
    if(count==1 && n!=1){
        cout<<" The number is prime";
    } else{
        cout<<"The given number is not prime";
    }
}

void armstrongNumber(int n){
    int num =n;
    int arm =0;
    int c = countDigit(num);
    while(num!=0){
        int rem = num%10;
        int k=1;
        for (int i = 0; i < c; ++i) {
            k= rem*k;
        }
        arm+=k;
        num=num/10;
    }
    if(arm==n){
        cout<<"The given number is an armstrong number";
    } else{
        cout<<"Not a armstrong number";
    }


}
int main(){
    cout<<"Enter the number1:- ";
    int num1;
    cin>>num1;
//    cout<<"Enter the number2:- ";
//    int num2;
//    cin>>num2;
    armstrongNumber(num1);
}