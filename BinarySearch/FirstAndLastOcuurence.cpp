//
//  FirstAndLastOcuurence.cpp
//  DSA
//
//  Created by Vipul Devnani on 17/09/23.
//

#include <stdio.h>
#include <iostream>
#include <vector>



using namespace std;



vector<int>* findFirstAndLastOccurence(vector<int>* arr,int target){
    vector<int>* ans = new vector<int>();
    int firstOccurence = -1 , lastOccurence = -1;
    ans->push_back(-1);
    ans->push_back(-1);
    
    //finding the first occurence first
    int start = 0,end = arr->size() - 1;
    
    while(start<=end){
        int mid = start + (end-start)/2;
        if((*arr)[mid] < target)
            start = mid + 1;
        else if((*arr)[mid] > target)
            end = mid - 1;
        else {//element at mid == target , possible ans found , keep searching on the left for finding the first occurence
            end = mid - 1;
            firstOccurence = mid;
        }
            
    }
    (*ans)[0] = firstOccurence;
    
    //find the last occurence
    start = 0;
    end = arr->size()-1;
    while(start<=end){
        int mid = start + (end-start)/2;
        if((*arr)[mid] < target)
            start = mid + 1;
        else if((*arr)[mid] > target)
            end = mid - 1;
        else {//element at mid == target , possible ans found , keep searching on the right for finding the last occurence
            start = mid + 1;
            lastOccurence = mid;
        }
            
    }
    (*ans)[1] = lastOccurence;
    
    return ans;
}



int main()
{
    
    vector<int> arr;
    
    arr.push_back(5);
    arr.push_back(7);
    arr.push_back(7);
    arr.push_back(7);
    arr.push_back(7);
    arr.push_back(8);
    arr.push_back(8);
    arr.push_back(10);
    
    vector<int>* ptr = findFirstAndLastOccurence(&arr,10);
    cout<<(*ptr)[0]<<" "<<(*ptr)[1]<<endl;
    
}
