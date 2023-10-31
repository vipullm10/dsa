//
//  MissingNumber.cpp
//  DSA
//
//  Created by Vipul Devnani on 31/10/23.
//

#include <stdio.h>
#include <vector>
#include <iostream>

using namespace std;




int missingNumber(vector<int>& nums) {
    int i = 0;
    while(i!=nums.size()){
        while(true){
            if(i == nums[i])
                break;
            int correctIndex = nums[i];
            if(correctIndex > nums.size()-1)
                break;
            int temp = nums[correctIndex];
            nums[correctIndex] = nums[i];
            nums[i] = temp;
        }
        i++;
    }
    for(int j = 0;j<nums.size();j++){
        if(nums[j] != j)
            return j;
    }
    return nums.size();
}



int main(){
    
    vector<int> nums;
    nums.insert(nums.end(),{0,2,3,4});
    int missingNum = missingNumber(nums);
    cout<<missingNum<<endl;
}
