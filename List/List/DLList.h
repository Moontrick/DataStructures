//
//  DLList.h
//  List
//
//  Created by Marcus Novak on 12/20/14.
//
//  Implementation of a doubly linked list
//
//  Copyright (c) 2014 Marcus Novak. All rights reserved.
//

#ifndef __List__DLList__
#define __List__DLList__

#include <iostream>
#include "List.h"
#include "DLLink.h"

#define DEFAULT_SIZE 100

template <typename T>
class DLList : public List<T>
{
private:
    DLLink<T>* head;     // Pointer to list header
    DLLink<T>* tail;     // Pointer to list tail
    DLLink<T>* curr;     // Access to current element
    int cnt;           // Size of the list
    
    void Init();       // Initialize helper method
    void RemoveAll();  // Return link nodes to free store
    
public:
    DLList (int size = DEFAULT_SIZE);        // Constructor
    ~DLList();                               // Destructor
    void Print() const;                     // Print list contents
    void Clear();                           // Clear list
    void Insert(const T& it);               // Insert "it" at current position
    void Append(const T& it);               // Append "it" to list
    T Remove();                             // Remove and return current element
    void MoveToStart();                     // Place curr at list start
    void MoveToEnd();                       // Place curr at list end
    void Prev();                            // Move curr one step left; no change if already at front
    void Next();                            // Move curr one step right; no change if already at end
    int Length() const;                     // Return length of list
    int CurrPos() const;                    // Return position of current element
    void MoveToPos(int pos);                // Move down list to "pos"
    const T& GetValue() const;              // Return current element
};

#endif /* defined(__List__DLList__) */
