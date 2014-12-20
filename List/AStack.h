//
//  AStack.h
//  List
//
//  Created by Marcus Novak on 12/20/14.
//
//  Implementation of an array-based stack
//
//  Copyright (c) 2014 Marcus Novak. All rights reserved.
//

#ifndef __List__AStack__
#define __List__AStack__

#include <iostream>
#include "Stack.h"

#define DEFAULT_SIZE 100

template <typename T> class AStack : public Stack<T>
{
private:
    int maxSize;      // Max size of the stack
    int top;          // Index for top element
    T *listArray;      // Array holding stack elements
    
public:
    AStack(int size = DEFAULT_SIZE);
    ~AStack();
    
    void Clear();
    void Push(const T& it);
    T Pop();
    const T& TopValue() const;
    int Length() const;
};

#endif /* defined(__List__AStack__) */
