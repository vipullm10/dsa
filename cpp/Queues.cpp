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


/**********************
 DEQUE IMPLEMENTATION
 **********************/

Deque::Deque(int queueSize):queueSize(queueSize){
    frontPtr = -1;
    rearPtr = -1;
    queuePtr = new int[queueSize];
}

Deque::~Deque(){
    delete queuePtr;
}

bool Deque::isFull(){
    if(frontPtr == -1 && rearPtr == queueSize-1){
        cout<<"all insertion was done from the rear end and the rear pointer is at the last position"<<endl;
        return true;
    }
    if(rearPtr == -1 && frontPtr == 0){
        cout<<"all insertion was done from the front end and the front pointer is at the last position"<<endl;
        return true;
    }
    int nextInsertionIndex = rearPtr == queueSize - 1 ? 0 : rearPtr + 1; //checking if there is any space left between rear and front to allow insertion
    if(nextInsertionIndex == frontPtr) //no gap exists between rear and front , hence we cannot insert from either end
        return true;
    return false;
}

bool Deque::isEmpty(){
    if(frontPtr == -1 && rearPtr == -1) //if no element was inserted
        return true;
    return false;
}

bool Deque::pushBack(int data){
    if(isFull()){
        return false;
    }
    if(frontPtr == -1)
        frontPtr = 0;
    if(rearPtr == queueSize-1 || rearPtr == -1){
        rearPtr = 0;
    }
    else
        rearPtr = rearPtr + 1;
    queuePtr[rearPtr] = data;
    return true;
}

bool Deque::pushFront(int data){
    if(isFull())
        return false;
    if(rearPtr == -1)
        rearPtr = queueSize-1;
    if(frontPtr == 0 || frontPtr == -1){
        frontPtr = queueSize-1;
    }
    else
        frontPtr = frontPtr - 1;
    queuePtr[frontPtr] = data;
    return true;
}

int Deque::popBack(){
    if(isEmpty())
        return false;
    if(rearPtr == -1)
        rearPtr = queueSize - 1;
    if(rearPtr == frontPtr || (frontPtr == -1 && rearPtr == 0)){
        int removedData = queuePtr[rearPtr];
        rearPtr = -1;
        frontPtr = -1;
        return true;
    }
    int removedData = queuePtr[rearPtr];
    if(rearPtr == 0)
        rearPtr = queueSize - 1;
    else
        rearPtr = rearPtr - 1;
    return true;
}

int Deque::popFront(){
    if(isEmpty())
        return false;
    if(frontPtr == -1)
        frontPtr = 0;
    if(rearPtr == frontPtr || (rearPtr == -1 && frontPtr == queueSize-1)){
        int removedData = queuePtr[frontPtr];
        frontPtr = -1;
        rearPtr = -1;
        return true;
    }
    int removedData = queuePtr[frontPtr];
    if(frontPtr == queueSize - 1)
        frontPtr = 0;
    else
        frontPtr = frontPtr + 1;
    return true;
}

int Deque::front(){
    if(frontPtr == -1)
        return -1;
    return queuePtr[frontPtr];
}

int Deque::back(){
    if(rearPtr == -1)
        return -1;
    return queuePtr[rearPtr];
}

/**********************
 DEQUE USING DOUBLY LINKED LIST IMPLEMENTATION
 **********************/

DequeLL::DequeLL(){
    frontPtr = NULL;
    rearPtr = NULL;
}

DequeLL::~DequeLL(){
    
}

bool DequeLL::isEmpty(){
    if(frontPtr == NULL && rearPtr == NULL)
        return true;
    return false;
}

bool DequeLL::pushBack(int data){
    dequeNode * node = (dequeNode*)malloc(sizeof(dequeNode));
    if(node == NULL)
        return false;
    node->data = data;
    if(rearPtr == NULL && frontPtr == NULL){
        rearPtr = node;
        frontPtr = node;
        node->next = NULL;
        node->prev = NULL;
    }
    else{
        rearPtr->next = node;
        node->prev = rearPtr;
        rearPtr = node;
    }
    return true;
}

bool DequeLL::pushFront(int data){
    dequeNode *node = (dequeNode*)malloc(sizeof(dequeNode));
    if(node == NULL)
        return false;
    node->data = data;
    if(frontPtr == NULL && rearPtr == NULL){
        frontPtr = node;
        rearPtr = node;
        frontPtr->next = NULL;
        frontPtr->prev = NULL;
    }
    else{
        frontPtr->prev = node;
        node->next = frontPtr;
        frontPtr = node;
    }
    return true;
}

int DequeLL::popBack(){
    if(isEmpty())
        return -1;
    int removed = rearPtr->data;
    if(rearPtr == frontPtr){
        frontPtr = NULL;
        free(rearPtr);
        rearPtr = NULL;
    }
    else{
        dequeNode *newRear = rearPtr->prev;
        free(rearPtr);
        rearPtr = newRear;
        rearPtr->next = NULL;
    }
    return removed;
}

int DequeLL::popFront(){
    if(isEmpty())
        return -1;
    int removed = frontPtr->data;
    if(rearPtr == frontPtr){
        rearPtr = NULL;
        free(frontPtr);
        frontPtr = NULL;
    }
    else{
        dequeNode *newfront = frontPtr->next;
        free(frontPtr);
        frontPtr = newfront;
        frontPtr->prev = NULL;
    }
    return removed;
}

int DequeLL::back(){
    if(isEmpty())
        return -1;
    return rearPtr->data;
}

int DequeLL::front(){
    if(isEmpty())
        return -1;
    return frontPtr->data;
}
