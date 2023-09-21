//
//  RotatedBinarySearch.cpp
//  DSA
//
//  Created by Vipul Devnani on 19/09/23.
//

#include <stdio.h>
#include <iostream>
#include <vector>



using namespace std;




int getPivotIndex(vector<int> &arr){
    int start = 0 , end = arr.size() - 1;
    while(start <= end){
        int mid = start + (end - start)/2;
        if(arr[mid] > arr[mid+1])
            return mid;
        else if(arr[mid-1] > arr[mid])
            return mid-1;
        else if(arr[start] < arr[mid]){
            start = mid + 1;
        }
        else{
            end = mid - 1;
        }
      
    }
    return -1;
}


int binarySearch(int target , vector<int> &arr , int start , int end){
    while(start <= end){
        int mid = start + (end - start)/2;
        if(arr[mid] < target)
            start = mid + 1;
        else if(arr[mid] > target)
            end = mid - 1;
        else
            return mid;
    }
    return -1;
}



int searchInRotatedSortedArray(vector<int> &arr , int target){
    int pivot = getPivotIndex(arr);
    if(pivot == -1){ //means array was not rotated , apply binary search to entire array
        return binarySearch(target, arr, 0, arr.size()-1);
    }
    int firstHalfResult = binarySearch(target, arr, 0, pivot); //result of binary search from start to pivot
    if(firstHalfResult != -1)
        return firstHalfResult;
    return binarySearch(target, arr, pivot + 1, arr.size() - 1); //return result of binary search from pivot + 1 to end
}


int main()
{
    vector<int> arr;
    arr.push_back(3);
    arr.push_back(4);
    arr.push_back(5);
    arr.push_back(5);
    //arr.push_back(0);
    arr.push_back(1);
    arr.push_back(2);
    
    cout<< searchInRotatedSortedArray(arr, 2)<<endl;
    
    
    
}
