//
//  Fibonacci.cpp
//  DSA
//
//  Created by Vipul Devnani on 18/11/23.
//

#include <stdio.h>
#include <iostream>



using namespace std;


int printFibonacci(int n){
    if(n < 2){
        //cout<<n<<" ";
        return n;
    }
    int ans = printFibonacci(n-1) + printFibonacci(n-2);
    cout<<ans<<" ";
    return ans;
}



int main(){
    
    printFibonacci(5);
    cout<<endl;
    
}
