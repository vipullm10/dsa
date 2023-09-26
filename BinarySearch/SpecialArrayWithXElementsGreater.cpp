//
//  SpecialArrayWithXElementsGreater.cpp
//  DSA
//
//  Created by Vipul Devnani on 24/09/23.
//

#include <stdio.h>
#include <iostream>
#include <vector>



using namespace std;



int findPossibleIndex(vector<int> &nums , int target){ //returns the index of target if it exists , else returns possible insert posiiton
    
    
    int start = 0 , end = nums.size() - 1;
    while(start <= end){
        int mid = start + (end - start)/2;
        if(nums[mid] < target)
            start = mid + 1;
        else if (nums[mid] > target)
            end = mid - 1;
        else
            return mid;
    }
    return start;
    
}



int specialArray(vector<int> &nums){
    int ans = -1;
    sort(nums.begin(),nums.end());
    for(int i = 1;i<=nums.size();i++){
        //check for possible position of i in this sorted array to find out count of elements greater than or equal to i
        int index = findPossibleIndex(nums, i);
        int count = nums.size() - index;
        if(count == i){
            ans = i;
            break;
        }
    }
    return ans;
}



int main()
{
    
    
    
    vector <int> nums;
    //nums.push_back(0);
    //nums.push_back(4);
    nums.push_back(3);
    //nums.push_back(0);
    nums.push_back(5);
    
    
    cout<<specialArray(nums)<<endl;
}
