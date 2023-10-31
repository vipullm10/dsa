//
//  CyclicSort.cpp
//  DSA
//
//  Created by Vipul Devnani on 29/10/23.
//

#include <stdio.h>
#include <iostream>
#include <vector>


using namespace std;



void cyclicSort(vector<int> &nums){
    int i = 0;
    while(i!=nums.size()-1){
        while(true){
            if(i == nums[i] - 1)
                break;
            int correctIndex = nums[i] - 1;
            int temp = nums[correctIndex];
            nums[correctIndex] = nums[i];
            nums[i] = temp;
        }
        i++;
    }
}



int main(){
    
    vector<int> arr;
    arr.insert(arr.end(),{5,4,3,2,1});
    cyclicSort(arr);
    for(int item : arr){
        cout<<item<<" "<<endl;
    }
}
