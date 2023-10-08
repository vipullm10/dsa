//
//  PeakElement.cpp
//  DSA
//
//  Created by Vipul Devnani on 01/10/23.
//

#include <stdio.h>
#include <iostream>
#include <vector>



using namespace std;

bool checkIfMidIsAns(int mid , vector<int> &nums){
    if(mid == 0){
        if(nums[mid] > nums[mid+1])
            return true;
    }
    if(mid == nums.size()-1){
        if(nums[mid] > nums[mid-1])
            return true;
    }
    if((mid-1)>=0 && (mid+1)<=nums.size()){
        if(nums[mid] > nums[mid-1] && nums[mid] > nums[mid+1])
            return true;
    }
    return false;
}

int findPeakElement(vector<int>& nums) {
    if(nums.size()==1)
        return 0;
    int start = 0 , end = nums.size() - 1;
    while(start <= end){
        int mid = start + (end - start)/2;
        if(checkIfMidIsAns(mid,nums))
            return mid;
        if(nums[mid] < nums[mid+1])
            start = mid + 1;
        else
            end = mid;
    }
    return -1;
}


int main()
{
    
    vector<int> nums;
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(1);
    nums.push_back(3);
    nums.push_back(5);
    nums.push_back(6);
    nums.push_back(4);
    
    
    cout<<findPeakElement(nums)<<endl;
    
}
