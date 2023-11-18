//
//  BinarySearch.cpp
//  DSA
//
//  Created by Vipul Devnani on 18/11/23.
//

#include <stdio.h>
#include <iostream>



using namespace std;





int binarySearch(int arr[],int start, int end , int target){
    if(!(start<=end)){
        return -1;
    }
    int mid = start + (end - start) / 2;
    if(arr[mid] == target)
        return mid;
    int ans = 0;
    if(arr[mid] < target){
        return binarySearch(arr, mid+1, end, target);
    }else{
        return binarySearch(arr, start, mid-1, target);
    }
}




int main(){
    int arr[] = {1,2,3,4,5,6};
    int index = binarySearch(arr, 0, 5, 8);
    cout<<index<<endl;
}
