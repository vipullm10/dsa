//
//  pointers.cpp
//  DSA
//
//  Created by Vipul Devnani on 28/06/24.
//

#include <stdio.h>
#include "iostream"

using namespace std;



float average(int* arr , int size){
    int sum = 0;
    for(size_t i = 0;i<size;i++)
        sum += arr[i];
    return (sum * 1.0f)/size;
}

int main()
{
//    int vector[] = {1,2,3};
//    int *ptr = vector;
//    cout<<*ptr<<endl;
//    ptr = ptr + 1;
//    cout<<*ptr<<endl;
//    ptr = ptr + 1;
//    cout<<*ptr<<endl;
//    
//    int num = -10;
//    long test = (long)num;
//    cout<<"test : "<<test<<endl;
//    intptr_t *p = &test;
//    unsigned long ul = 10;
//    uintptr_t *up = static_cast<uintptr_t*>(&ul);
//    cout<<"intptr_t *p = "<<*p<<" uintptr_t *up = "<<*up<<endl;
//    cout<<"sizeof(long*) = "<<sizeof(long*)<<" sizeof(int*) = "<<sizeof(int*)<<endl;
//    
//    char *string1;
//    char *string2;
//    
//
//    string1 = static_cast<char*>(malloc(16));
//    strcpy(string1,"0123456789AB");
//    string2 = static_cast<char*>(realloc(string1,64));
//    
//    printf("string1 value %p [%s]\n",string1,string1);
//    printf("string2 value %p [%s]\n",string2,string2);
//    
//    free(string2);
//    string2 = NULL;
//    
//    
    
    
    int* arr = (int*)malloc(sizeof(int)*4);
    int element = 1;
    for(size_t i = 0;i<4;i++)
        arr[i] = element++;
    float avg = average(arr, 4);
    printf("average : %.2f",avg);
    free(arr);
    return 0;
}


