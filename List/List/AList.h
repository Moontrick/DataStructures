//
//  AList.h
//
//  Created by Marcus Novak on 12/13/14.
//
//  Implementation of an array based List
//
//  Copyright (c) 2014 Marcus Novak. All rights reserved.
//

#ifndef __List__AList__
#define __List__AList__

#include <assert.h>
#include "List.h"

#define DEFAULT_SIZE 100

template <typename T>
class AList : public List<T>
{
private:
    int maxSize;     // Maximum size of the List
    int listSize;    // Current number of list items
    int curr;        // Position of current element
    T* listArray;    // Array that will hold our list elements
public:
    AList(int size = DEFAULT_SIZE);
    ~AList();
    
    void Clear();
    void Insert(const T& it);
    void Append(const T& it);
    T Remove();
    void MoveToStart();
    void MoveToEnd();
    void Prev();
    void Next();
    int Length();
    int CurrPos();
    void MoveToPos(int pos);
    const T& GetValue();
    
};

#endif /* defined(__List__AList__) */
