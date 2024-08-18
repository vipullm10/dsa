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
#if 0
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
    
    
    LinkedListLinearQueueImplementation *linkedListLinearQueue = new LinkedListLinearQueueImplementation();
    if(!linkedListLinearQueue->enqueue(1))
        cout<<"Could not enqueue 1"<<endl;
    cout<<linkedListLinearQueue->peek()<<endl;
    int removed = linkedListLinearQueue->dequeue();
    if(removed!=-1)
        cout<<removed<<" was removed from the queue"<<endl;
    removed = linkedListLinearQueue->dequeue();
    if(removed!=-1)
        cout<<removed<<" was removed from the queue"<<endl;
    if(!linkedListLinearQueue->enqueue(2))
        cout<<"Could not enqueue 2"<<endl;
    cout<<linkedListLinearQueue->peek()<<endl;
    if(!linkedListLinearQueue->enqueue(3))
        cout<<"Could not enqueue 3"<<endl;
    cout<<linkedListLinearQueue->peek()<<endl;
    if(!linkedListLinearQueue->enqueue(4))
        cout<<"Could not enqueue 4"<<endl;
    cout<<linkedListLinearQueue->peek()<<endl;
    removed = linkedListLinearQueue->dequeue();
    if(removed!=-1)
        cout<<removed<<" was removed from the queue"<<endl;
    removed = linkedListLinearQueue->dequeue();
    if(removed!=-1)
        cout<<removed<<" was removed from the queue"<<endl;
    removed = linkedListLinearQueue->dequeue();
    if(removed!=-1)
        cout<<removed<<" was removed from the queue"<<endl;
    
    if(!linkedListLinearQueue->enqueue(5))
        cout<<"Could not enqueue 5"<<endl;
    cout<<linkedListLinearQueue->peek()<<endl;
    removed = linkedListLinearQueue->dequeue();
    if(removed!=-1)
        cout<<removed<<" was removed from the queue"<<endl;
    
#endif
    
    Deque *dequeuObj = new Deque(7);
    if(!dequeuObj->pushBack(1))
        cout<<"Could not pushBack 1"<<endl;
    if(!dequeuObj->pushBack(2))
        cout<<"Could not pushBack 2"<<endl;
    if(!dequeuObj->pushFront(3))
        cout<<"Could not pushFront 3"<<endl;
    if(!dequeuObj->pushFront(4))
        cout<<"Could not pushFront 4"<<endl;
    if(!dequeuObj->pushFront(5))
        cout<<"Could not pushFront 5"<<endl;
    if(!dequeuObj->pushFront(6))
        cout<<"Could not pushFront 6"<<endl;
    if(!dequeuObj->pushFront(7))
        cout<<"Could not pushFront 7"<<endl;
    cout<<dequeuObj->front()<<endl;
    cout<<dequeuObj->back()<<endl;
    if(!dequeuObj->pushFront(8))
        cout<<"Could not pushFront 8"<<endl;
    int removed = dequeuObj->popBack();
    if(removed!=-1)
        cout<<removed<<" was removed from the rear of the queue"<<endl;
    cout<<dequeuObj->front()<<endl;
    cout<<dequeuObj->back()<<endl;
    if(!dequeuObj->pushFront(8))
        cout<<"Could not pushFront 8"<<endl;
    cout<<dequeuObj->front()<<endl;
    cout<<dequeuObj->back()<<endl;
    if(!dequeuObj->pushFront(9))
        cout<<"Could not pushFront 9"<<endl;
    removed = dequeuObj->popBack();
    if(removed!=-1)
        cout<<removed<<" was removed from the rear of the queue"<<endl;
    removed = dequeuObj->popBack();
    if(removed!=-1)
        cout<<removed<<" was removed from the rear of the queue"<<endl;
    removed = dequeuObj->popBack();
    if(removed!=-1)
        cout<<removed<<" was removed from the rear of the queue"<<endl;
    removed = dequeuObj->popBack();
    if(removed!=-1)
        cout<<removed<<" was removed from the rear of the queue"<<endl;
    removed = dequeuObj->popBack();
    if(removed!=-1)
        cout<<removed<<" was removed from the rear of the queue"<<endl;
    removed = dequeuObj->popBack();
    if(removed!=-1)
        cout<<removed<<" was removed from the rear of the queue"<<endl;
    removed = dequeuObj->popBack();
    if(removed!=-1)
        cout<<removed<<" was removed from the rear of the queue"<<endl;
    removed = dequeuObj->popBack();
    if(removed!=-1)
        cout<<removed<<" was removed from the rear of the queue"<<endl;
    if(!dequeuObj->pushFront(9))
        cout<<"Could not pushFront 9"<<endl;
    cout<<dequeuObj->front()<<endl;
    
    
    
    cout<<endl;
    cout<<"DequeLL TEST"<<endl;
    
    
    
    DequeLL *dequeuLLObj = new DequeLL();
    if(!dequeuLLObj->pushBack(1))
        cout<<"Could not pushBack 1"<<endl;
    if(!dequeuLLObj->pushBack(2))
        cout<<"Could not pushBack 2"<<endl;
    if(!dequeuLLObj->pushFront(3))
        cout<<"Could not pushFront 3"<<endl;
    if(!dequeuLLObj->pushFront(4))
        cout<<"Could not pushFront 4"<<endl;
    if(!dequeuLLObj->pushFront(5))
        cout<<"Could not pushFront 5"<<endl;
    if(!dequeuLLObj->pushFront(6))
        cout<<"Could not pushFront 6"<<endl;
    if(!dequeuLLObj->pushFront(7))
        cout<<"Could not pushFront 7"<<endl;
    cout<<dequeuLLObj->front()<<endl;
    cout<<dequeuLLObj->back()<<endl;
    //if(!dequeuLLObj->pushFront(8))
        //cout<<"Could not pushFront 8"<<endl;
    removed = dequeuLLObj->popBack();
    if(removed!=-1)
        cout<<removed<<" was removed from the rear of the queue"<<endl;
    cout<<dequeuLLObj->front()<<endl;
    cout<<dequeuLLObj->back()<<endl;
    if(!dequeuLLObj->pushFront(8))
        cout<<"Could not pushFront 8"<<endl;
    cout<<dequeuLLObj->front()<<endl;
    cout<<dequeuLLObj->back()<<endl;
    //if(!dequeuLLObj->pushFront(9))
        //cout<<"Could not pushFront 9"<<endl;
    removed = dequeuLLObj->popBack();
    if(removed!=-1)
        cout<<removed<<" was removed from the rear of the queue"<<endl;
    removed = dequeuLLObj->popBack();
    if(removed!=-1)
        cout<<removed<<" was removed from the rear of the queue"<<endl;
    removed = dequeuLLObj->popBack();
    if(removed!=-1)
        cout<<removed<<" was removed from the rear of the queue"<<endl;
    removed = dequeuLLObj->popBack();
    if(removed!=-1)
        cout<<removed<<" was removed from the rear of the queue"<<endl;
    removed = dequeuLLObj->popBack();
    if(removed!=-1)
        cout<<removed<<" was removed from the rear of the queue"<<endl;
    removed = dequeuLLObj->popBack();
    if(removed!=-1)
        cout<<removed<<" was removed from the rear of the queue"<<endl;
    removed = dequeuLLObj->popBack();
    if(removed!=-1)
        cout<<removed<<" was removed from the rear of the queue"<<endl;
    removed = dequeuLLObj->popBack();
    if(removed!=-1)
        cout<<removed<<" was removed from the rear of the queue"<<endl;
    if(!dequeuLLObj->pushFront(9))
        cout<<"Could not pushFront 9"<<endl;
    cout<<dequeuLLObj->front()<<endl;
    removed = dequeuLLObj->popFront();
    cout<<removed<<" was removed from the front of the queue"<<endl;
    if(!dequeuLLObj->pushBack(1))
        cout<<"Could not pushBack 1"<<endl;
    if(!dequeuLLObj->pushBack(2))
        cout<<"Could not pushBack 2"<<endl;
    removed = dequeuLLObj->popFront();
    if(removed!=-1)
        cout<<removed<<" was removed from the front of the queue"<<endl;
    removed = dequeuLLObj->popFront();
    if(removed!=-1)
        cout<<removed<<" was removed from the front of the queue"<<endl;
    removed = dequeuLLObj->popFront();
    if(removed!=-1)
        cout<<removed<<" was removed from the front of the queue"<<endl;
}
