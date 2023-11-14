//
//  Largestnumber.cpp
//  DSA
//
//  Created by Vipul Devnani on 12/11/23.
//

#include <stdio.h>
#include <iostream>
#include <vector>



using namespace std;

string getLargestNumber(vector<int> &nums){
    string result = "";
    for(int i = 0;i<nums.size();i++){
        for(int j = i + 1;j<nums.size();j++){
            string a = to_string(nums[i]);
            string b = to_string(nums[j]);
            if(a + b < b + a){
                int temp = nums[i];
                nums[i] = nums[j];
                nums[j] = temp;
            }
        }
    }
    for(int item : nums){
        result+=to_string(item);
    }
    return result;
    
}


int main(){
    
    vector<int> nums;
    nums.insert(nums.end(),{3,30,34,5,9});
    
    string largest = getLargestNumber(nums);
    
    cout<<largest<<endl;
}
