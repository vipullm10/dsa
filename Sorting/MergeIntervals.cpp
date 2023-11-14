//
//  MergeIntervals.cpp
//  DSA
//
//  Created by Vipul Devnani on 14/11/23.
//

#include <stdio.h>
#include <iostream>
#include <vector>



using namespace std;


void sortIntervals(vector<vector<int>> &intervals){
    sort(intervals.begin(),intervals.end(),[] (const auto& lhs, const auto& rhs) {
        return lhs[0] < rhs[0];
    });
}



vector<vector<int>> merge(vector<vector<int>>& intervals) {
    sortIntervals(intervals);
    vector<vector<int>> result;
    int i = 1;
    int initialStartInterval = intervals[0][0];
    int initialEndInterval = intervals[0][1];
    while(i!=intervals.size()){
        int currentStartInterval = intervals[i][0];
        if(currentStartInterval <= initialEndInterval){ //overlapping
            if(initialEndInterval < intervals[i][1])
                initialEndInterval = intervals[i][1]; //update initialEndInterval to merge this interval
            i++;
        }else{ //not overlapping
            vector<int> interval;
            interval.insert(interval.end(),{initialStartInterval,initialEndInterval}); //add the previously merged intervals to the result
            result.push_back(interval);
            initialStartInterval = intervals[i][0]; //update initialStartInterval to currentStartInterval
            initialEndInterval = intervals[i][1]; //update initialEndInterval to currentEndInterval
            i++;
        }
    }
    vector<int> interval;
    interval.insert(interval.end(),{initialStartInterval,initialEndInterval}); //add the last merged/non merged interval to result
    result.push_back(interval);
    return result;
}



int main()
{
    vector<vector<int>> intervals;
    vector<int> i1;
    i1.insert(i1.end(),{1,3});
    vector<int> i2;
    i2.insert(i2.end(),{2,6});
    vector<int> i3;
    i3.insert(i3.end(),{8,10});
    vector<int> i4;
    i4.insert(i4.end(),{15,18});
    intervals.insert(intervals.end(),{i1,i2,i3,i4});
    
    vector<vector<int>> result = merge(intervals);
    cout<<"[";
    int i = 0;
    for(vector<int> interval : result){
        cout<<"["<<interval[0]<<","<<interval[1]<<"]"<<((i!=result.size()-1)?",":"");
        i++;
    }
    cout<<"]"<<endl;
}
