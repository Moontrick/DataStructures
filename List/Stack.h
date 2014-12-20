//
//  Stack.h
//  List
//
//  Created by Marcus Novak on 12/20/14.
//
//  Stack abstract template
//
//  Copyright (c) 2014 Marcus Novak. All rights reserved.
//

#ifndef List_Stack_h
#define List_Stack_h

// Stack abstract class
template <typename T> class Stack
{
private:
    void operator = (const Stack&)      // Protect assignment
    Stack(const Stack&) {}              // Protect copy constructor
    
public:
    Stack() {}                          // Default constructor
    virtual ~Stack() {}                 // Base deconstructor
    
    virtual void Clear() = 0;           // Reinitialize stack.  User responsible for reclaiming storage
    virtual void Push(const T& it) = 0; // Push element to the top of the stack
    virtual T Pop() = 0;                // Remove and return element on top of the stack
    virtual const T& TopValue() const = 0;  // Return a copy of the top element
    virtual int Length() const = 0;     // Returns number of elements in the stack
};

#endif
