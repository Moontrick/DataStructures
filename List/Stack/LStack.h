//
//  LStack.h
//  List
//
//  Created by Marcus Novak on 12/20/14.
//
//  Implementation of a linked stack
//
//  Copyright (c) 2014 Marcus Novak. All rights reserved.
//

#ifndef __List__LStack__
#define __List__LStack__

#include <iostream>
#include "Stack.h"
#include "Link.h"

#define DEFAULT_SIZE 100

template <typename T> class LStack : public Stack<T>
{
private:
    Link<T>* top;           // Pointer to the first element
    int size;               // Number of elements
    
public:
    LStack(int sz = DEFAULT_SIZE);
    ~LStack();
    
    void Clear();
    void Push(const T& it);
    T Pop();
    const T& TopValue() const;
    int Length() const;
};

#endif /* defined(__List__LStack__) */
