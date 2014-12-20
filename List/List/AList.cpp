//
//  AList.cpp
//  List
//
//  Created by Marcus Novak on 12/13/14.
//  Copyright (c) 2014 Marcus Novak. All rights reserved.
//

#include "AList.h"



// Constructor
template <typename T>
AList<T>::AList(int size)
{
    maxSize = size;
    listSize = curr = 0;
    listArray = new T[maxSize];
}


// Destructor
template <typename T>
AList<T>::~AList()
{ delete [] listArray; }


// Reinitialize the AList
template <typename T>
void AList<T>::Clear()
{
    delete [] listArray;
    listSize = curr = 0;
    listArray = new T[maxSize];
}


// Insert it at the current position
template <typename T>
void AList<T>::Insert(const T& it)
{
    Assert(listSize < maxSize, "List capacity exceeded!");
    
    // Shift everything over to make room for the new element
    for (int i = listSize; i > curr; i--)
        listArray[i] = listArray[i - 1];
    
    // Insert the new element and increment the list size
    listArray[curr] = it;
    listSize++;
}


// Append it at the end of the list
template <typename T>
void AList<T>::Append(const T& it)
{
    Assert(listSize < maxSize, "List capacity exceeded!");
    listArray[listSize++] = it;
}


// Remove and return the current element
template <typename T>
T AList<T>::Remove()
{
    Assert((curr >= 0) && (curr < listSize), "No elements in list");
    
    T it = listArray[curr];                       // Copy the element
    for (int i = curr; i < listSize - 1; i++)     // Shift elements down
        listArray[i] = listArray[i + 1];
    
    listSize--;                                   // Decrement size
    return it;
}


// Reset position to the beginning of the list
template <typename T>
void AList<T>::MoveToStart()
{ curr = 0; }


// Set position at end of list
template <typename T>
void AList<T>::MoveToEnd()
{ curr = listSize; }


// Set position to the previous element
template <typename T>
void AList<T>::Prev()
{ if (curr != 0) curr--; }


// Set position to the next element
template <typename T>
void AList<T>::Next()
{ if (curr < listSize) curr++; }


// Returns list size
template <typename T>
int AList<T>::Length() const
{ return listSize; }


// Return the current position
template <typename T>
int AList<T>::CurrPos() const
{ return curr; }


// Set current list position to 'pos'
template <typename T>
void AList<T>::MoveToPos(int pos)
{
    Assert((pos >= 0) && (pos <= listSize), "Position out of range");
    curr = pos;
}


// Return the current element
template <typename T>
const T& AList<T>::GetValue()
{
    Assert((curr >= 0) && (curr < listSize), "No current element");
    return listArray[curr];
}










