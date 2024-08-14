//
//  Queues.h
//  DSA
//
//  Created by Vipul Devnani on 12/08/24.
//

#ifndef Queues_h
#define Queues_h


#endif /* Queues_h */

class AbstractQueue{
protected:
    int front;
    int rear;
    int queueSize;
    int *queuePtr;
public:
    AbstractQueue(int queueSize);
    virtual ~AbstractQueue();
    virtual bool enqueue(int data) = 0;
    virtual int dequeue() = 0;
    int peek();
    virtual bool isEmpty() = 0;
    virtual bool isFull() = 0;
};


class LinearQueueImplementation : public AbstractQueue{
public:
    LinearQueueImplementation(int queueSize);
    ~LinearQueueImplementation();
    bool enqueue(int data) override;
    int dequeue() override;
    bool isEmpty() override;
    bool isFull() override;
};


class CircularQueueImplementation : public AbstractQueue{
public:
    CircularQueueImplementation(int queueSize);
    ~CircularQueueImplementation();
    bool enqueue(int data) override;
    int dequeue() override;
    bool isEmpty() override;
    bool isFull() override;
    void display();
};


struct node{
    int data;
    node* next;
};


class LinkedListAbstractQueue{
protected:
    node *front;
    node *rear;
public:
    LinkedListAbstractQueue();
    virtual ~LinkedListAbstractQueue();
    virtual bool enqueue(int data) = 0;
    virtual int dequeue() = 0;
    int peek();
    virtual bool isEmpty() = 0;
    //virtual bool isFull() = 0; no queusize hence this queue can never be full

};


class LinkedListLinearQueueImplementation : public LinkedListAbstractQueue{
public:
    LinkedListLinearQueueImplementation();
    ~LinkedListLinearQueueImplementation();
    bool enqueue(int data) override;
    int dequeue() override;
    bool isEmpty() override;
};
