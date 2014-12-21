//
//  LQueue.h
//  List
//
//  Created by Marcus Novak on 12/21/14.
//
//  Implementation of a linked Queue data structure
//
//  Copyright (c) 2014 Marcus Novak. All rights reserved.
//

#ifndef __List__LQueue__
#define __List__LQueue__

#include <iostream>
#include "Queue.h"
#include "Link.h"

#define DEFAULT_SIZE 100

template <typename T> class LQueue : public Queue<T>
{
private:
    Link<T>* front;             // Pointer to the front queue node
    Link<T>* rear;              // Pointer to the rear queue node
    int size;                   // Number of elements in queue
    
public:
    LQueue(int sz = DEFAULT_SIZE);
    ~LQueue();
    
    void Clear();
    void Enqueue(const T& it);
    T Dequeue();
    const T& FrontValue() const;
    int Length() const;
};

#endif /* defined(__List__LQueue__) */
