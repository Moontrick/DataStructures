//
//  Queue.h
//  List
//
//  Created by Marcus Novak on 12/21/14.
//
//  Abstract Queue template implementation
//
//  Copyright (c) 2014 Marcus Novak. All rights reserved.
//

#ifndef List_Queue_h
#define List_Queue_h

template <typename T> class Queue
{
private:
    void operator = (const Queue&) {}       // Protect assignment
    Queue(const Queue&) {}                  // Protect copy instructor
    
public:
    Queue() {}                              // Default
    virtual ~Queue() {}                     // Base destructor
    
    virtual void Clear() = 0;               // Reinitialize Queue
    virtual void Enqueue(const T& it) = 0;  // Place element at rear of Queue
    virtual T Dequeue() = 0;                // Remove and return element at front of Queue
    virtual const T& FrontValue() const = 0;// Return a copy of the element at front of Queue
    virtual int Length() = 0;               // Return the number of elements in the Queue
};

#endif
