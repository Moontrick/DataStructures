//
//  LList.h
//  List
//
//  Created by Marcus Novak on 12/20/14.
//
//  Linked list implementation, inherits from generic List class
//
//  Copyright (c) 2014 Marcus Novak. All rights reserved.
//

#ifndef __List__LList__
#define __List__LList__

#include <iostream>
#include "List.h"
#include "Link.h"

#define DEFAULT_SIZE 100

template <typename T>
class LList : public List<T>
{
private:
    Link<T>* head;     // Pointer to list header
    Link<T>* tail;     // Pointer to list tail
    Link<T>* curr;     // Access to current element
    int cnt;           // Size of the list
    
    void Init();       // Initialize helper method
    void RemoveAll();  // Return link nodes to free store
    
public:
    //LList (int size)
};

#endif /* defined(__List__LList__) */
