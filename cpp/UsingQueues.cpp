//
//  UsingQueues.cpp
//  DSA
//
//  Created by Vipul Devnani on 12/08/24.
//
#include<iostream>
#include <stdio.h>
#include "Queues.h"

using namespace std;


int main(){

    AbstractQueue * queueObj = new LinearQueueImplementation(5);
    if(!queueObj->enqueue(1))
        cout<<"Could not enqueue 1"<<endl;
    if(!queueObj->enqueue(2))
        cout<<"Could not enqueue 2"<<endl;
    /*
    if(!queueObj->enqueue(3))
        cout<<"Could not enqueue 3"<<endl;
    if(!queueObj->enqueue(4))
        cout<<"Could not enqueue 4"<<endl;
    if(!queueObj->enqueue(5))
        cout<<"Could not enqueue 5"<<endl;
     */
    int removed = queueObj->dequeue();
    if(removed!=-1)
        cout<<removed<<" was removed from the queue"<<endl;
    cout<<queueObj->peek()<<endl;
    removed = queueObj->dequeue();
    if(removed!=-1)
        cout<<removed<<" was removed from the queue"<<endl;
    cout<<queueObj->peek()<<endl;
    removed = queueObj->dequeue();
    if(removed!=-1)
        cout<<removed<<" was removed from the queue"<<endl;
    cout<<queueObj->peek()<<endl;
    /*
    removed = queueObj->dequeue();
    if(removed!=-1)
        cout<<removed<<" was removed from the queue"<<endl;
    cout<<queueObj->peek()<<endl;
    removed = queueObj->dequeue();
    if(removed!=-1)
        cout<<removed<<" was removed from the queue"<<endl;
    cout<<queueObj->peek()<<endl;
     */
    if(!queueObj->enqueue(3))
        cout<<"Could not enqueue 3"<<endl;
    removed = queueObj->dequeue();
    if(removed!=-1)
        cout<<removed<<" was removed from the queue"<<endl;
    cout<<queueObj->peek()<<endl;
    delete queueObj;
    
    AbstractQueue *circularQueueObj = new CircularQueueImplementation(5);
    if(!circularQueueObj->enqueue(1))
        cout<<"Could not enqueue 1"<<endl;
    cout<<circularQueueObj->peek()<<endl;
//    int removed = circularQueueObj->dequeue();
//    if(removed!=-1)
//        cout<<removed<<" was removed from the queue"<<endl;
//    cout<<circularQueueObj->peek()<<endl;
    if(!circularQueueObj->enqueue(2))
        cout<<"Could not enqueue 2"<<endl;
    cout<<circularQueueObj->peek()<<endl;
    if(!circularQueueObj->enqueue(3))
        cout<<"Could not enqueue 3"<<endl;
    cout<<circularQueueObj->peek()<<endl;
    if(!circularQueueObj->enqueue(4))
        cout<<"Could not enqueue 4"<<endl;
    cout<<circularQueueObj->peek()<<endl;
    if(!circularQueueObj->enqueue(5))
        cout<<"Could not enqueue 5"<<endl;
    cout<<circularQueueObj->peek()<<endl;
   
    removed = circularQueueObj->dequeue();
    if(removed!=-1)
        cout<<removed<<" was removed from the queue"<<endl;
    cout<<circularQueueObj->peek()<<endl;
    if(!circularQueueObj->enqueue(1))
        cout<<"Could not enqueue 1"<<endl;
    cout<<circularQueueObj->peek()<<endl;
    
    if(!circularQueueObj->enqueue(6))
        cout<<"Could not enqueue 6"<<endl;
    cout<<circularQueueObj->peek()<<endl;
    
    //circularQueueObj->display();
    delete circularQueueObj;
}
