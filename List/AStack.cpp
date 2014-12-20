//
//  AStack.cpp
//  List
//
//  Created by Marcus Novak on 12/20/14.
//  Copyright (c) 2014 Marcus Novak. All rights reserved.
//

#include "AStack.h"


// Constructor
template <typename T>
AStack<T>::AStack(int size)
{
    maxSize = size;
    top = 0;
    listArray = new T[size];
}


// Destructor
template <typename T>
AStack<T>::~AStack()
{ delete [] listArray; }


// Reinitialize the stack.  User is responsible for reclaiming storage
template <typename T>
AStack<T>::Clear()
{ top = 0; }


// Push "it" on top of the stack
template <typename T>
AStack<T>::Push(const T& it)
{
    Assert(top != maxSize, "Stack is full!");
    listArray[top++] = it;
}


// Remove and return the top element in the stack
template <typename T>
T AStack<T>::Pop()
{
    Assert(top != 0, "Stack is empty!");
    return listArray[--top];
}


// Return a copy of the top element
template <typename T>
const T& AStack<T>::TopValue() const
{
    Assert(top != 0, "Stack is empty!");
    return listArray[top - 1];
}


// Return the number of elements in the stack
template <typename T>
int AStack<T>::Length() const
{ return top; }



















