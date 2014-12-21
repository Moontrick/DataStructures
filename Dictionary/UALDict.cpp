//
//  UALDict.cpp
//  List
//
//  Created by Marcus Novak on 12/21/14.
//  Copyright (c) 2014 Marcus Novak. All rights reserved.
//

#include "UALDict.h"



// Constructor
template <typename Key, typename T>
UALDict<Key, T>::UALDict(int size)
{ list = new AList<KVPair<Key, T>>(size); }



// Destructor
template <typename Key, typename T>
UALDict<Key, T>::~UALDict()
{ delete list; }


// Insert an element, append to list
template <typename Key, typename T>
void UALDict<Key, T>::Insert(const Key& k, const T& t)
{
    KVPair<Key, T> tmp(k, t);
    list->Append(tmp);
}


// Sequentially search to find the element to remove
template <typename Key, typename T>
T UALDict<Key, T>::Remove(const Key& k)
{
    T tmp = Find(k);
    if (tmp != NULL) list->Remove();
    return tmp;
}


// Remove the last element
template <typename Key, typename T>
T UALDict<Key, T>::RemoveAny()
{
    Assert(Size() != 0, "Dictionary is empty!");
    
    list->MoveToEnd();
    list->prev();
    KVPair<Key, T> t = list->Remove();
    return t.Value();
}


// Find "k" using sequential search, return NULL if it doesn't exist
template <typename Key, typename T>
T UALDict<Key, T>::Find(const Key& k) const
{
    for(list->MoveToStart(); list->CurrPos() < list->Length(); list->Next())
    {
        KVPair<Key, T> tmp = list->GetValue();
        if (k == tmp.Key())
            return tmp.Value();
    }
    
    return NULL;
}


// Return the number of elements in the list
template <typename Key, typename T>
int UALDict<Key, T>::Size()
{ return list->Length(); }






























