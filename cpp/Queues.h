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


//note : as according to my experience , it would make no sense to implement a circular queue using a linked list because the main point of a circular queue is to make efficient use of a limited storage space (fixed size) while implementing a queue
//the advantage of linked lists implementation is only in the case where the size of the queue is dynamic / not known
//if we are sure about the size of the queue , the circular queue implementation using arrays/sequential memory will offer the best performance as it doesn't come with the pointer overhead
class LinkedListLinearQueueImplementation : public LinkedListAbstractQueue{
public:
    LinkedListLinearQueueImplementation();
    ~LinkedListLinearQueueImplementation();
    bool enqueue(int data) override;
    int dequeue() override;
    bool isEmpty() override;
};



//double ended queue using a circular buffer
//we shall use a circular buffer
class Deque{
private:
    int frontPtr;
    int rearPtr;
    int queueSize;
    int* queuePtr;
public:
    Deque(int queueSize);
    ~Deque();
    bool pushBack(int data);
    bool pushFront(int data);
    int popBack();
    int popFront();
    int front();
    int back();
    bool isFull();
    bool isEmpty();
};

struct dequeNode{
    int data;
    dequeNode *next;
    dequeNode *prev;
};

class DequeLL{
private:
    dequeNode *frontPtr;
    dequeNode *rearPtr;
public:
    DequeLL();
    ~DequeLL();
    bool pushBack(int data);
    bool pushFront(int data);
    int popBack();
    int popFront();
    int front();
    int back();
    bool isEmpty();
};
