//
//  SortedMatrix.cpp
//  DSA
//
//  Created by Vipul Devnani on 21/10/23.
//

#include <stdio.h>
#include <vector>
#include <iostream>


using namespace std;


int binarySearch(vector<int> row, int target){
    int start = 0 , end = row.size()-1;
    while(start <= end){
        int mid = start + (end - start)/2;
        if(row[mid] == target)
            return mid;
        else if (row[mid] < target)
            start = mid + 1;
        else
            end = mid - 1;
    }
    return -1;
}


vector<int> search(vector<vector<int>> matrix , int target){
    vector<int> result;
    int startRow = 0 , endRow = matrix.size()-1;
    int midCol = matrix[0].size()-1 / 2;
    while(abs(endRow - startRow) > 1){
        int midRow = startRow + (endRow - startRow)/2;
        if(matrix[midRow][midCol] < target)
            startRow = midRow;
        else
            endRow = midRow;
    }
    int row = startRow;
    if(target > matrix[startRow][matrix[startRow].size()-1])
        row = endRow;
    int col = binarySearch(matrix[row], target);
    if(col == -1)
        result.insert(result.end(),{-1,-1});
    else
        result.insert(result.end(),{row,col});
    return result;
}



int main(){
    vector<vector<int>> matrix;
    vector<int> v1;
    v1.insert(v1.end(), {1,3,5,7});
    vector<int> v2;
    v2.insert(v2.end(),{10,11,16,20});
    vector<int> v3;
    v3.insert(v3.end(),{23,30,34,60});
    matrix.insert(matrix.end(), {v1,v2,v3});
    
    vector<int> result = search(matrix,3);
    cout<<result[0]<<" "<<result[1]<<endl;
    if(result[0]!=-1)
        cout<<matrix[result[0]][result[1]]<<endl;
}
