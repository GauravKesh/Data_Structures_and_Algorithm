//
// Created by Gaurav Kesh Roushan on 29/01/24.
//
#include <iostream>
#include <string>
using namespace std;
bool stringPallindrome(string s){
    int l =0;
    int r = s.length()-1;
    while(l<r){
        if(!isalnum(s[l])){
            return true;
        }
        else if(!isalnum(s[r])){
            return true;
        }
        else if (tolower(s[l])!= tolower(s[r])){
            return false;
        } else{
            l++;
            r--;
        }
    }
    return true;


}


int  main(){
    string str ="Joker";
    bool ans =stringPallindrome(str);
    if(ans){
        cout<<"The string is a pallindrome";
    }else{
        cout<<"The string is  not a pallindrome";
    }
}
