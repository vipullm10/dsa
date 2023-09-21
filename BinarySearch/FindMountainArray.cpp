//
//  FindMountainArray.cpp
//  DSA
//
//  Created by Vipul Devnani on 18/09/23.
//

#include <stdio.h>
#include <iostream>
#include <vector>



using namespace std;



class MountainArray{
public:
    vector<int> items;
    int get(int index){
        return items[index];
    }
    int length(){
        return items.size();
    }
};




int findInMountainArray(int target, MountainArray &mountainArr) {
    
    int start = 0 , end = mountainArr.length()-1;
    while(start <= end){
        int mid = start + (end - start)/2;
        if(mountainArr.get(mid) < mountainArr.get(mid+1))
            start = mid + 1;
        else
            end = mid - 1;
    }
    int peakIndex = start;
    
    //start searching from 0 to peakIndex , if found return that index , else search from peakIndex + 1 to end
    
    
    start = 0;
    end = peakIndex;
    while(start <= end){
        int mid = start + (end - start)/2;
        if(mountainArr.get(mid) < target)
            start = mid + 1;
        else if (mountainArr.get(mid) > target)
            end = mid - 1;
        else
            return mid;
    }
    
    start = peakIndex + 1;
    end = mountainArr.length()-1;
    while(start <= end){
        int mid = start + (end - start)/2;
        if(mountainArr.get(mid) < target)
            end = mid - 1;
        else if (mountainArr.get(mid) > target)
            start = mid + 1;
        else return mid;
    }
    
    return -1;
}





int main()
{
    MountainArray obj;
    obj.items.push_back(1);
    obj.items.push_back(2);
    obj.items.push_back(3);
    obj.items.push_back(4);
    obj.items.push_back(5);
    obj.items.push_back(3);
    obj.items.push_back(1);
    
    
    cout << findInMountainArray(3, obj);
}
