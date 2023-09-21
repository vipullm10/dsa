//
//  PeakIndexMountainArray.cpp
//  DSA
//
//  Created by Vipul Devnani on 17/09/23.
//

#include <stdio.h>
#include <iostream>
#include <vector>



using namespace std;



int getPeakIndex(vector<int> &arr){
    int start = 0 , end = arr.size() - 1;
    
    while(start <= end){
        int mid = start + (end - start)/2;
        if(arr[mid] < arr[mid+1])//continue searching for peak index as order is ascending
            start = mid + 1;
        else
            end = mid - 1;
            
    }
    return start;
}





int main()
{
    
    
    vector<int> arr;
    arr.push_back(11);
    arr.push_back(10);
    arr.push_back(5);
    arr.push_back(2);
//    arr.push_back(3);
//    arr.push_back(2);
//    arr.push_back(1);
    
    
    
    cout<<getPeakIndex(arr)<<endl;
}
