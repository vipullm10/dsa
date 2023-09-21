//
//  FairCandySwap.cpp
//  DSA
//
//  Created by Vipul Devnani on 21/09/23.
//

#include <stdio.h>
#include <iostream>
#include <vector>
#include <math.h>


using namespace std;


int binarySearch(vector<int> &nums , int target){
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
    return -1;
}


vector<int>* findSwappedCandies(vector<int>& alice , vector<int>& bob){
    
    vector<int> *ans = new vector<int>();
    ans->push_back(1);
    ans->push_back(1);
    
    int aliceTotalCandies = 0 , bobTotalCandies = 0;
    
    for(int i = 0 ; i < alice.size() ; i++){
        aliceTotalCandies += alice[i];
    }
    
    for(int i = 0 ; i < bob.size() ; i++){
        bobTotalCandies += bob[i];
    }
    
    int equalCandies = std::min(aliceTotalCandies,bobTotalCandies) + abs(bobTotalCandies - aliceTotalCandies)/2 ; //target will be the no of candies left after swapping current candy box 
    
    sort(bob.begin(),bob.end());
    
    for(int i = 0 ; i < alice.size() ; i++){
        int target = equalCandies - (aliceTotalCandies - alice[i]);
        int result = binarySearch(bob, target);
        if(result != -1){
            (*ans)[0] = alice[i];
            (*ans)[1] = target;
            break;
        }
    }
    
    return ans;
}





int main()
{
    vector<int> alice;
    vector<int> bob;
    
    alice.push_back(35);
    alice.push_back(17);
    alice.push_back(4);
    alice.push_back(24);
    alice.push_back(10);
    
    bob.push_back(63);
    bob.push_back(21);
    
    vector<int> *ans = findSwappedCandies(alice, bob);
    cout<<"["<<(*ans)[0]<<","<<(*ans)[1]<<"]"<<endl;
}
