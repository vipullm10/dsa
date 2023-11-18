//
//  InheritanceFun.cpp
//  DSA
//
//  Created by Vipul Devnani on 22/07/24.
//

#include <stdio.h>
#include <iostream>

using namespace std;

class Employee {
    public:
    Employee(string firstName,char middleInitial , string lastName){
        cout<<"Constructing Employee"<<endl;
        first_name = firstName;
        middle_initial = middleInitial;
        family_name = lastName;
    }
    void print() const{
        cout<<"First name : " << first_name<<" Family name : "<<family_name<<endl;
    };
    string full_name() const { return first_name + ' ' + middle_initial + ' ' + family_name; }
    virtual ~Employee(){
        cout<<"Employee Desctructor"<<endl;
    }
    // ...
    private:
    string first_name , family_name;
    char middle_initial;
    // ...
    
};


class Manager : public Employee {
    public:
    Manager() : Employee("VIPUL", 'A', "DEVNANI"){
        
    }
    Manager(string firstName , char middleInitital , string lastName ,int level) : Employee(firstName, middleInitital, lastName){
        cout<<"Constructing Manager"<<endl;
        this->level = level;
    }
    void print() const{
        cout<<"Print Manager"<<endl;
    };
    ~Manager(){
        cout<<"Manager destructor"<<endl;
    }
    // ...
    private:
    int level;
    int getLevel() const{
        return level;
    }
    
};

int areaFunc(int a,int b){
    return a*b;
}

typedef int (*area)(int length,int breadth);


class Shape{
public:
    int numberOfSides;
    area areaPtr;
    unsigned long long area;
    Shape(){
        area = 40;
        uint64_t *area_ptr = &area;
        cout<<"Area is : "<<*area_ptr<<endl;
        areaPtr = areaFunc;
    }
};



int main(){
    cout<<"Hello world"<<endl;
//    Employee e;
//    e.print();
//    cout<<e.full_name()<<endl;
    Manager *m = new Manager("VIPUL",'A',"DEVNANI",1);
    Employee *e = m;
    e->print();
    delete e;
    cout<<"Sizeof(long)"<<sizeof(long)<<endl;
    cout<<"Sizeof(long int)"<<sizeof(long int)<<endl;
    cout<<"Sizeof(long long)"<<sizeof(long long)<<endl;
    cout<<"Sizeof(long long int)"<<sizeof(long long int)<<endl;
    Shape s;
    area funcPtr = &areaFunc;
    cout<<funcPtr(1,2);
}
