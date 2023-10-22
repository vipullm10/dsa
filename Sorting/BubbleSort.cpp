//
//  BubbleSort.cpp
//  DSA
//
//  Created by Vipul Devnani on 22/10/23.
//

#include <stdio.h>
#include <iostream>
#include <vector>


using namespace std;


void bubbleSort(vector<int> &arr){
    bool swapped = false;
    for(int i = 0;i<arr.size()-1;i++){
        for(int j = 1;j<arr.size() - i;j++){
            if(arr[j-1] > arr[j]){
                int temp = arr[j-1];
                arr[j-1] = arr[j];
                arr[j] = temp;
                swapped = true;
            }
        }
        //if no swap occured in this pass , that means all the elements are already sorted .
        if(!swapped){
            break;
        }
    }
}


int main(){
    
    vector<int> arr;
    arr.insert(arr.end(),{1,2,3,4,5});
    bubbleSort(arr);
    for(int item : arr){
        cout<<item<<" ";
    }
}
