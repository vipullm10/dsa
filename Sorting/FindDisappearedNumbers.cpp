//
//  FindDisappearedNumbers.cpp
//  DSA
//
//  Created by Vipul Devnani on 04/11/23.
//

#include <stdio.h>
#include <iostream>
#include <vector>



using namespace std;


vector<int> findDisappearedNumbers(vector<int> &nums){
    int i = 0;
    vector<int> result;
    while(i!=nums.size()){
        while(true){
            if(i == nums[i] - 1)
                break;
            int correctIndex = nums[i] - 1;
            int temp = nums[correctIndex];
            if(temp == nums[i]) //no. to be swapped is equal with the current number
                break;
            nums[correctIndex] = nums[i];
            nums[i] = temp;
        }
        i++;
    }
    for(int i=0;i<nums.size();i++){
        if(nums[i] - 1 != i)
            result.push_back(i+1);
    }
    return result;
}



int main(){
    vector<int> nums;
    nums.insert(nums.end(),{4,3,2,7,8,2,3,1});
    vector<int> result = findDisappearedNumbers(nums);
    for(int item : result){
        cout<<item<<" ";
    }
}
