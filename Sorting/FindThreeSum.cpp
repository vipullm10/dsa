//
//  FindThreeSum.cpp
//  DSA
//
//  Created by Vipul Devnani on 07/11/23.
//

#include <stdio.h>
#include <vector>
#include <iostream>
#include <unordered_map>
#include <unordered_set>

using namespace std;


struct indices{
    int j;
    int k;
};
unordered_map<int,vector<int>> elementIndices;

vector<indices> findTwoSum(vector<int> &nums , int target){
    vector<indices> vec;
    for(int i = 0;i<nums.size();i++){
        int twoSumTarget = target - nums[i];
        if(elementIndices.find(twoSumTarget)!=elementIndices.end()){
            vector<int> indicesList = elementIndices[twoSumTarget];
            for(int index : indicesList){
                indices obj;
                obj.j = i;
                obj.k = index;
                //cout<<nums[obj.j]<<"+"<<nums[obj.k]<<"="<<target<<endl;
                vec.push_back(obj);
            }
        }
    }
    return vec;
}

vector<vector<int>> threeSum(vector<int>& nums) {
    for(int i=0;i<nums.size();i++){
        if(elementIndices.find(nums[i])!=elementIndices.end()){
            vector<int> indicesList = elementIndices[nums[i]];
            indicesList.push_back(i);
            elementIndices[nums[i]] = indicesList;
        }else{
            vector<int> indicesList;
            indicesList.push_back(i);
            elementIndices[nums[i]] = indicesList;
        }
    }
    vector<vector<int>> result;
    unordered_set<string> triplets;
    //sort(nums.begin(),nums.end());
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
    nums.insert(nums.end(), {0,1,-1});
    vector<vector<int>> result = threeSum(nums);
    for(vector<int> triplet : result){
        cout<<"[";
        for(int item : triplet){
            cout<<item<<",";
        }
        cout<<"]"<<endl;
    }
}

