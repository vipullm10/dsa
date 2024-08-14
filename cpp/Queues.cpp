//
//  Queues.cpp
//  DSA
//
//  Created by Vipul Devnani on 12/08/24.
//
#include <iostream>
#include <stdio.h>
#include "Queues.h"
 

using namespace std;


/**********************
    ABSTRACT QUEUE IMPLEMENTATION
**********************/
AbstractQueue::AbstractQueue(int queueSize){
    this->front = -1;
    this->rear = -1;
    this->queueSize = queueSize;
    this->queuePtr = new int[this->queueSize];
}
AbstractQueue::~AbstractQueue(){
    cout<<"Desctructor of AbstractQueue"<<endl;
    delete this->queuePtr;
    cout<<"Destroyed Queue"<<endl;
}
int AbstractQueue::peek(){
    if(isEmpty())
        return -1;
    return this->queuePtr[this->front];
}


/**********************
 LINKED LIST ABSTRACT QUEUE IMPLEMENTATION
**********************/
LinkedListAbstractQueue::LinkedListAbstractQueue(){
    this->front = NULL;
    this->rear = NULL;
}

LinkedListAbstractQueue::~LinkedListAbstractQueue(){
    cout<<"Destructor of LinkedListAbstractQueue"<<endl;
    cout<<"Destroyed LinkedList"<<endl;
}

int LinkedListAbstractQueue::peek(){
    if(isEmpty())
        return -1;
    return front->data;
}







/**********************
    LINEAR QUEUE IMPLEMENTATION
**********************/
LinearQueueImplementation::LinearQueueImplementation(int queueSize):AbstractQueue(queueSize){
    
}
LinearQueueImplementation::~LinearQueueImplementation(){
    cout<<"Destructor of LinearQueueImplementation"<<endl;
}
bool LinearQueueImplementation::enqueue(int data){
    if(isFull()){
        return false;
    }
    if(rear == -1)
        front = 0;
    this->queuePtr[++this->rear] = data;
    //cout<<"front : "<<front<<" rear : "<<rear<<endl;
    return true;
}
int LinearQueueImplementation::dequeue(){
    if(isEmpty())
        return -1;
    return this->queuePtr[this->front++];
}
bool LinearQueueImplementation::isEmpty(){
    if(this->rear == -1 || this->front > this->rear)
        return true;
    return false;
}
bool LinearQueueImplementation::isFull(){
    if(this->rear == this->queueSize-1)
        return true;
    return false;
}



/**********************
    CIRCULAR QUEUE IMPLEMENTATION
**********************/
CircularQueueImplementation::CircularQueueImplementation(int queueSize):AbstractQueue(queueSize){}

CircularQueueImplementation::~CircularQueueImplementation(){
    cout<<"Destructor of CircularQueueImplementation"<<endl;
}

bool CircularQueueImplementation::enqueue(int data){
    if(isFull())
        return false;
    if(front == -1)
        front = 0;
    if(rear == queueSize-1)
        rear = 0;
    else
        rear = rear + 1;
    queuePtr[rear] = data;
    return true;
}
int CircularQueueImplementation::dequeue(){
    if(isEmpty())
        return -1;
    int element = queuePtr[front];
    if(front == rear){
        front = -1;
        rear = -1;
        return element;
    }
    if(front == queueSize - 1)
        front = 0;
    else
        front++;
    return element;
}
bool CircularQueueImplementation::isFull(){
    if((front == 0 && rear == queueSize -1) || (rear + 1 == front) ) //queue overflow
        return true;
    return false;
}
bool CircularQueueImplementation::isEmpty(){
    if(front == -1) //queue underflow
        return true;
    return false;
}
void CircularQueueImplementation::display(){
    if(front <= rear){
        for(size_t i = front;i<=rear;i++)
            cout<<queuePtr[i]<<" ";
        cout<<endl;
    }
    else{
        for(size_t i = front;i<queueSize;i++)
            cout<<queuePtr[i]<<" ";
        for(size_t i = 0;i<=rear;i++)
            cout<<queuePtr[i]<<" ";
        cout<<endl;
    }
}



/**********************
    LINKED LIST LINEAR QUEUE IMPLEMENTATION
**********************/

LinkedListLinearQueueImplementation::LinkedListLinearQueueImplementation(){
    
}

LinkedListLinearQueueImplementation::~LinkedListLinearQueueImplementation(){
    cout<<"Destructor of LinkedListLinearQueueImplementation"<<endl;
}

bool LinkedListLinearQueueImplementation::enqueue(int data){
    //no overflow condition can occur in this case as we will allocate new nodes dynamically
    node* listNode = (node*)malloc(sizeof(node));
    if(listNode == NULL)
        return false; //malloc fail/memory full,etc
    listNode->data = data;
    listNode->next = NULL;
    if(isEmpty()){
        front = listNode;
    }
    else{
        rear->next = listNode;
    }
    rear = listNode;
    return true;
}

int LinkedListLinearQueueImplementation::dequeue(){
    if(front == NULL) //queue underflow
        return -1;
    int data = front->data; //data value which indicates which element is removed
    node* temp = front; //storing front pointer which we will use to deallocate memory
    front = front->next; //incrementing front
    free(temp); //freeing old front memory
    return data;
}
 
bool LinkedListLinearQueueImplementation::isEmpty(){
    if(front == NULL)
        return true;
    return false;
}
