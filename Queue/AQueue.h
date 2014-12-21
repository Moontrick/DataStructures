//
//  AQueue.h
//  List
//
//  Created by Marcus Novak on 12/21/14.
//
//  Implementation of an array-based Queue
//
//  Copyright (c) 2014 Marcus Novak. All rights reserved.
//

#ifndef __List__AQueue__
#define __List__AQueue__

#include <iostream>
#include "Queue.h"

#define DEFAULT_SIZE 100

template <typename T> class AQueue : public Queue<T>
{
private:
    int maxSize;                // Max size of the Queue
    int front;                  // Index of front element
    int rear;                   // Index of rear element
    T *listArray;               // Array holding queue of elements
    
public:
    AQueue(int size = DEFAULT_SIZE);
    ~AQueue();
    
    void Clear();
    void Enqueue(const T& it);
    T Dequeue();
    const T& FrontValue() const;
    int Length() const;
};

#endif /* defined(__List__AQueue__) */
