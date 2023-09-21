//
//  Ceiling.cpp
//  DSA
//
//  Created by Vipul Devnani on 16/09/23.
//

#include <stdio.h>
#include<iostream>
#include<vector>


using namespace std;

int findFloor(vector<int> *arr,int target){
    int start = 0 , end = arr->size();
    int ans = -1;
    while(start <= end){
        int mid = start + (end - start)/2;
        if((*arr)[mid] < target){
            start = mid + 1;
        }
        else if((*arr)[mid] > target){
            end = mid - 1;
        }
        else{
            ans = (*arr)[mid];
            break;
        }
    }
    return (*arr)[end];
}


int main(){
    vector<int> arr;
    arr.push_back(2);
    arr.push_back(3);
    arr.push_back(5);
    arr.push_back(9);
    arr.push_back(14);
    arr.push_back(16);
    arr.push_back(17);
    arr.push_back(18);
    int floor = findFloor(&arr,4);
    cout<<floor<<endl;
}
