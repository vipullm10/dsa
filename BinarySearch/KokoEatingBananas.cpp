//
//  KokoEatingBananas.cpp
//  DSA
//
//  Created by Vipul Devnani on 08/10/23.
//

#include <stdio.h>
#include <iostream>
#include <vector>




using namespace std;

long getNumberOfHours(int speed,vector<int> &piles){ //function to calculate no. of hours taken to eat pile of bananas at given speed
    long noOfHours = 0;
    for(int i = 0;i<piles.size();i++){
        if(piles[i] <= speed){
            noOfHours += 1;
        }
        else{
            noOfHours += piles[i]/speed + ( (piles[i]%speed!=0) ? 1 : 0);
        }
    }
    return noOfHours;
}

int minEatingSpeed(vector<int>& piles, int h) {
    int start = 1; //start = 1 since koko will eat at a minimum speed of 1 banana per hour
    int end = piles[0];
    for(int i = 0;i<piles.size();i++){
        if(piles[i] > end)
            end = piles[i]; //end = pile with max number of bananas since coco can eat maximum of largest pile of bananas
    }
    while(start <= end){
        int mid = start + (end - start)/2;
        long noOfHours = getNumberOfHours(mid,piles);
        if(noOfHours <= h)
            end = mid - 1;
        else
            start = mid + 1;
    }
    return start;
}




int main()
{
    vector<int> piles;
    piles.push_back(3);
    piles.push_back(6);
    piles.push_back(7);
    piles.push_back(11);
    
    
    cout<<minEatingSpeed(piles, 8)<<endl;
}




