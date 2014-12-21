//
//  SAList.h
//  List
//
//  Created by Marcus Novak on 12/21/14.
//
//  Implementation of a sorted array-based list for dictionary use
//
//  Copyright (c) 2014 Marcus Novak. All rights reserved.
//

#ifndef __List__SAList__
#define __List__SAList__

#include <iostream>
#include "Dictionary.h"
#include "KVPair.h"
#include "../List/AList.h"


template <typename Key, typename T> class SAList : protected AList<KVPair<Key, T>>
{
public:
    SAList(int size = DEFAULT_SIZE) : AList<KVPair<Key, T>>(size) {}   // Constructor
    ~SAList() {}                                                       // Destructor
    
    // Redefine the Insert function to keep the values sorted
    void Insert(KVPair<Key, T>& it)
    {
        KVPair<Key, T> curr;
        for (MoveToStart(); CurrPos() < Length(); Next())
        {
            curr = GetValue();
            if (curr.Key() > it.Key())
                break;
        }
        AList<KVPair<Key, T>>::Insert(it);   // Insert the element
    }
    
    // All remaining methods are exposed from AList.  Append is not available to SAList
    // as that would defeat the purpose of keeping the list nice and sorted
    using AList<KVPair<Key, T>>::Clear;
    using AList<KVPair<Key, T>>::Remove;
    using AList<KVPair<Key, T>>::MoveToStart;
    using AList<KVPair<Key, T>>::MoveToEnd;
    using AList<KVPair<Key, T>>::Prev;
    using AList<KVPair<Key, T>>::Next;
    using AList<KVPair<Key, T>>::Length;
    using AList<KVPair<Key, T>>::CurrPos;
    using AList<KVPair<Key, T>>::MoveTosPos;
    using AList<KVPair<Key, T>>::GetValue;
};

#endif /* defined(__List__SAList__) */
