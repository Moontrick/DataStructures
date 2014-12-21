//
//  UALDict.h
//  List
//
//  Created by Marcus Novak on 12/21/14.
//
//  Implementation of an unsorted array-based dictionary data structure
//
//  Copyright (c) 2014 Marcus Novak. All rights reserved.
//

#ifndef __List__UALDict__
#define __List__UALDict__

#include <iostream>
#include "Dictionary.h"
#include "KVPair.h"
#include "../List/AList.h"

#define DEFAULT_SIZE 100

template <typename Key, typename T> class UALDict : public Dictionary<Key, T>
{
private:
    AList<KVPair<Key, T>>* list;       // Array to hold key-value pairs
    
public:
    UALDict(int size = DEFAULT_SIZE);
    ~UALDict();
    
    void Clear();
    void Insert(const Key& k, const T& t);
    T Remove(const Key& k);
    T RemoveAny();
    T Find(const Key& k) const;
    int Size();
};

#endif /* defined(__List__UALDict__) */
