//
//  ThreeSum.cpp
//  DSA
//
//  Created by Vipul Devnani on 06/11/23.
//

#include <stdio.h>
#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;


struct indices{
    int j;
    int k;
};

int binarySearch(vector<int>& nums , int target){
    int start = 0 , end = nums.size()-1;
    while(start <= end){
        int mid = start + (end - start) / 2;
        if(nums[mid] == target)
            return mid;
        else if(nums[mid] < target)
            start = mid + 1;
        else
            end = mid - 1;
    }
    return -1;
}

vector<indices> findTwoSum(vector<int> &nums , int target){
    vector<indices> vec;
    for(int i = 0;i<nums.size();i++){
        int twoSumTarget = target - nums[i];
        int result = binarySearch(nums,twoSumTarget);
        if(result != -1){
            indices obj;
            obj.j = i;
            obj.k = result;
            cout<<nums[obj.j]<<"+"<<nums[obj.k]<<"="<<target<<endl;
            vec.push_back(obj);
        }
    }
    return vec;
}

vector<vector<int>> threeSum(vector<int>& nums) {
    vector<vector<int>> result;
    unordered_set<string> triplets;
    sort(nums.begin(),nums.end());
    for(int i = 0;i<nums.size();i++){
        int target = nums[i] * (-1);
        vector<indices> vec_indices = findTwoSum(nums,target);
        for(indices obj : vec_indices){
            if(obj.j != -1 && obj.k != -1 && i != obj.j && i!= obj.k && obj.j != obj.k){
                vector<int> triplet;
                int indicesSum = i + obj.j + obj.k;
                triplet.insert(triplet.end(),{nums[i],nums[obj.j],nums[obj.k]});
                sort(triplet.begin(),triplet.end());
                string key = "";
                for(int item : triplet){
                    key += to_string(item)+"_";
                }
                if(triplets.find(key) != triplets.end())
                    continue;
                triplets.insert(key);
                result.push_back(triplet);
            }
        }
    }
    return result;
}

int main(){
    vector<int> nums;
    nums.insert(nums.end(), {3,0,-2,-1,1,2});
    vector<vector<int>> result = threeSum(nums);
    for(vector<int> triplet : result){
        cout<<"[";
        for(int item : triplet){
            cout<<item<<",";
        }
        cout<<"]"<<endl;
    }
}
