//
//  AQueue.cpp
//  List
//
//  Created by Marcus Novak on 12/21/14.
//  Copyright (c) 2014 Marcus Novak. All rights reserved.
//

#include "AQueue.h"


// Constructor
template <typename T>
AQueue<T>::AQueue(int size)
{
    maxSize = size + 1;    // Array size one position larger for empty slot
    rear = 0;
    front = 1;
    listArray = new T[maxSize];
}


// Destructor
template <typename T>
AQueue<T>::~AQueue()
{ delete [] listArray; }


// Reinitialize the queue
template <typename T>
void AQueue<T>::Clear()
{
    rear = 0;
    front = 1;
}


// Place "it" at the rear of the Queue
template <typename T>
void AQueue<T>::Enqueue(const T& it)
{
    Assert(((rear + 2) % maxSize) != front, "Queue is full!");
    rear = (rear + 1) % maxSize;        // Circular increment
    listArray[rear] = it;
}


// Remove and return the element at the front of the queue
template <typename T>
T AQueue<T>::Dequeue()
{
    Assert(Length() != 0, "Queue is empty!");
    T it = listArray[front];
    front = (front + 1) % maxSize;      // Circular increment
    return it;
}


// Return a copy of the front element in the queue
template <typename T>
const T& AQueue<T>::FrontValue() const
{
    Assert(Length() != 0, "Queue is empty!");
    return listArray[front];
}


// Return the number of elements in the queue
template <typename T>
int AQueue<T>::Length() const
{ return ((rear + maxSize) - front + 1) % maxSize; }



































