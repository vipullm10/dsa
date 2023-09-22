//
//  KthMissingPositiveNumber.cpp
//  DSA
//
//  Created by Vipul Devnani on 22/09/23.
//

#include <stdio.h>
#include <vector>
#include <iostream>



using namespace std;



int findKthMissingPositiveNumber(vector<int> &arr , int k){
    int start = 0 , end = arr.size() - 1;
    while(start <= end){
        int mid = start + (end - start)/2;
        int elementsMissedUpToMid = arr[mid] - (mid+1);
        if(elementsMissedUpToMid < k){
            start = mid + 1;
        }
        else{
            end = mid - 1;
        }
    }
    return start + k;
}



int main(){
    
    
    
    vector<int> nums;
    nums.push_back(2);
    nums.push_back(3);
    nums.push_back(4);
    nums.push_back(7);
    nums.push_back(11);
    
    
    cout<<findKthMissingPositiveNumber(nums, 5)<<endl;
}
