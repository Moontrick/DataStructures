//
//  SALDict.cpp
//  List
//
//  Created by Marcus Novak on 12/21/14.
//  Copyright (c) 2014 Marcus Novak. All rights reserved.
//

#include "SALDict.h"



// Constructor
template <typename Key, typename T>
SALDict<Key, T>::SALDict(int size)
{ list = new SAList<Key, T>(size); }



// Destructor
template <typename Key, typename T>
SALDict<Key, T>::~SALDict()
{ delete list; }


// Insert an element, insert into list
template <typename Key, typename T>
void SALDict<Key, T>::Insert(const Key& k, const T& t)
{
    KVPair<Key, T> tmp(k, t);
    list->Insert(tmp);      // Keeps things sorted since we're using the sorted array list class
}


// Sequentially search to find the element to remove
template <typename Key, typename T>
T SALDict<Key, T>::Remove(const Key& k)
{
    T tmp = Find(k);
    if (tmp != NULL) list->Remove();
    return tmp;
}


// Remove the last element
template <typename Key, typename T>
T SALDict<Key, T>::RemoveAny()
{
    Assert(Size() != 0, "Dictionary is empty!");
    
    list->MoveToEnd();
    list->prev();
    KVPair<Key, T> t = list->Remove();
    return t.Value();
}


// Find "k" using sequential search, return NULL if it doesn't exist
template <typename Key, typename T>
T SALDict<Key, T>::Find(const Key& k) const
{
    int x = -1;
    int y = list->Length();
    while (x + 1 != y)    // Stop when x and y meet
    {
        int i = (x + y ) / 2;  // Check middle of remaining subarray
        list->MoveToPos(i);
        KVPair<Key, T> tmp =  list->GetValue();
        
        if (k == tmp.Key()) return tmp.Value();   // Found it
        if (k < tmp.Key()) y = i;   // In Left
        if (k > tmp.Key()) x = i;   // In Right
    }
    
    return NULL;   // "k" is not in the dictionary
}


// Return the number of elements in the list
template <typename Key, typename T>
int SALDict<Key, T>::Size()
{ return list->Length(); }


































