//
// Created by Gaurav Kesh Roushan on 29/01/24.
//

#include <iostream>

void fibonacciSeries(int n){
    if(n==0){
        std::cout<<"0"<<std::endl;
    }
    else if(n==1){
        std::cout<<"1"<<std::endl;
    } else{
        int f[n];
        f[0]=0;
        f[1]=1;
        for(int i=2;i<n;i++){
            f[i]=f[i-1]+f[i-2];
        }
        for (int i=0;i<n;i++){
            std::cout<<f[i]<<" ";
        }

    }


}

int main(){
    int n=5;
    fibonacciSeries(n);
    return 0;
}