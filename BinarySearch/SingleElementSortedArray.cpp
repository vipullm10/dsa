//
//  SingleElementSortedArray.cpp
//  DSA
//
//  Created by Vipul Devnani on 26/09/23.
//

#include <stdio.h>
#include <vector>
#include <iostream>



using namespace std;

int singleNonDuplicate(vector <int> &nums){
    int start = 0 , end = nums.size() - 1;
    while (start <= end) {
        int mid = start + (end - start)/2;
        
        if( ((mid-1> 0) && nums[mid] != nums[mid-1]) && ((mid+1 < nums.size()-1) && nums[mid]!=nums[mid+1] ))
            return nums[mid];
        
        if(start == mid && mid == end)
            return nums[mid];
        
        if(nums[mid] == nums[mid+1]){
            int forwardArrayLength = abs(end - (mid+2)) + 1;
            int backwardArrayLength = abs(start - (mid-1)) + 1;
            if(forwardArrayLength%2 == 1)
                start = mid + 2;
            else
                end = mid - 1;
        }
        
        if(nums[mid] == nums[mid-1]){
            int forwardArrayLength = abs(end - (mid+1)) + 1;
            int backwardArrayLength = abs(start - (mid-2)) + 1;
            if(forwardArrayLength%2 == 1)
                start = mid + 1;
            else
                end = mid - 2;
        }
    }
    
    return -1;
}





int main()
{
    vector<int> nums;
    nums.push_back(3);
    nums.push_back(3);
    nums.push_back(7);
    //nums.push_back(7);
    //nums.push_back(10);
    //nums.push_back(11);
    //nums.push_back(11);
    //nums.push_back(8);
    //nums.push_back(8);
    
    cout<<singleNonDuplicate(nums)<<endl;
}
