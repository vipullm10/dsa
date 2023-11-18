//
//  Log.cpp
//  DSA
//
//  Created by Vipul Devnani on 11/08/24.
//

#include <iostream>

using namespace std;



int main(){
    
    
    int i = 2;
    while(true){
        
        int n = i;
        int nlogn_8 = 8*log2(n);
        cout<<"n : "<<n<<" 8nlogn : "<<nlogn_8<<endl;
        if(n>nlogn_8)
            break;
        i++;
    }
}
