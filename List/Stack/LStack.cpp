//
//  LStack.cpp
//  List
//
//  Created by Marcus Novak on 12/20/14.
//  Copyright (c) 2014 Marcus Novak. All rights reserved.
//

#include "LStack.h"



// Constructor
template <typename T>
LStack<T>::LStack(int sz)
{
    top = NULL;
    size = sz;
}


// Destructor
template <typename T>
LStack<T>::~LStack()
{ Clear(); }


// Reinitialize the stack
template <typename T>
void LStack<T>::Clear()
{
    while (top != NULL)
    {
        Link<T>* tmp = top;
        top = top->next;
        delete tmp;
    }
    
    size = 0;
}


// Put "it" on the stack
template <typename T>
void LStack<T>::Push(const T& it)
{
    top = new Link<T>(it, top);
    size++;
}


// Remove and return, or pop the top element of the stack
template <typename T>
T LStack<T>::Pop()
{
    Assert(top != NULL, "Stack is empty!");
    
    T it = top->element;         // Top element
    Link<T>* tmp = top->next;    // Get the next node
    delete top;                  // Delete the top of the stack
    top = tmp;                   // Set top to the next node
    size--;                      // Decrement the size
    return it;
}


// Return a copy of the top element
template <typename T>
const T& LStack<T>::TopValue() const
{
    Assert(top != 0, "Stack is empty!");
    return top->element;
}


// Return the number of elements in the stack
template <typename T>
int LStack<T>::Length() const
{ return size; }


















