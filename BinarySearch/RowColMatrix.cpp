//
//  RowColMatrix.cpp
//  DSA
//
//  Created by Vipul Devnani on 21/10/23.
//

#include <stdio.h>
#include <iostream>
#include <vector>


using namespace std;



vector<int> search(vector<vector<int>> &matrix , int target){
    vector<int> result;
    int row = 0 , col = matrix.size()-1;
    while(row < matrix.size() && col >= 0){
        if(matrix[row][col] == target){
            result.insert(result.end(),{row,col});
            return result;
        }
        else if(matrix[row][col] < target)
            row++;
        else
            col--;
    }
    result.push_back(-1);
    result.push_back(-1);
    return result;
}


int main(){
    vector<vector<int>> matrix;
    vector<int> v1;
    v1.insert(v1.end(), {10,20,30,40});
    vector<int> v2;
    v2.insert(v2.end(),{15,25,35,45});
    vector<int> v3;
    v3.insert(v3.end(),{28,29,37,49});
    vector<int> v4;
    v4.insert(v4.end(),{33,34,38,50});
    matrix.insert(matrix.end(), {v1,v2,v3,v4});
    
    vector<int> res = search(matrix, 80);
    cout<<res[0]<<" "<<res[1]<<endl;
}
