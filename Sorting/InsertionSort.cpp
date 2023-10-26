//
//  InsertionSort.cpp
//  DSA
//
//  Created by Vipul Devnani on 27/10/23.
//

#include <stdio.h>
#include <iostream>
#include <vector>


using namespace std;


void insertionSort(vector<int> &arr){
    for(int i=0;i<arr.size()-1;i++){
        for(int j = i+1;j>0;j--){
            if(arr[j] < arr[j-1]){
                int temp = arr[j];
                arr[j] = arr[j-1];
                arr[j-1] = temp;
            }else{
                break;
            }
        }
    }
}



int main(){
    vector<int> nums;
    nums.insert(nums.end(),{5,4,3,2,1});
    insertionSort(nums);
    for(int num : nums){
        cout<<num<<" ";
    }
    
}
