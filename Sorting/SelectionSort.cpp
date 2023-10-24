//
//  SelectionSort.cpp
//  DSA
//
//  Created by Vipul Devnani on 24/10/23.
//

#include <stdio.h>
#include <iostream>
#include <vector>


using namespace std;

//the main idea behind selection sort is to select one element inside an array and place it at it's correct position
void selectionSort(vector<int> &nums){
    int currentIndex = nums.size()-1;
    while(currentIndex >= 0){
        //select the maximum element in the current range of elenents and place it at it's correct index
        int maxIndex = 0 , i = 0;
        while(i<=currentIndex){
            if(nums[i] > nums[maxIndex]){
                maxIndex = i;
            }
            i++;
        }
        int temp = nums[maxIndex];
        nums[maxIndex] = nums[currentIndex];
        nums[currentIndex] = temp;
        currentIndex--;
    }
}


int main(){
    
    vector<int> arr;
    arr.insert(arr.end(),{5,4,3,2,1});
    selectionSort(arr);
    for(int item : arr){
        cout<<item<<" ";
    }
}
