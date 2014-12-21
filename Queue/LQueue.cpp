//
//  LQueue.cpp
//  List
//
//  Created by Marcus Novak on 12/21/14.
//  Copyright (c) 2014 Marcus Novak. All rights reserved.
//

#include "LQueue.h"



// Constructor
template <typename T>
LQueue<T>::LQueue(int sz)
{
    front = rear = new Link<T>();
    size = 0;
}


// Destructor
template <typename T>
LQueue<T>::~LQueue()
{
    Clear();
    delete front;
}


// Reinitialize the queue
template <typename T>
void LQueue<T>::Clear()
{
    while (front->next != NULL)
    {
        rear = front;
        delete rear;
    }
    
    rear = front;
    size = 0;
}


// Place "it" at the rear of the Queue
template <typename T>
void LQueue<T>::Enqueue(const T& it)
{
    rear->next = new Link<T>(it, NULL);
    rear = rear->next;
    size++;
}


// Remove and return the element at the front of the queue
template <typename T>
T LQueue<T>::Dequeue()
{
    Assert(size != 0, "Queue is empty!");
    
    T it = front->next->element;         // Store dequeued value
    Link<T>* tmp = front->next;          // Hold dequeued link
    front->next = tmp->next;             // Advance the front
    if (rear == tmp) rear = front;       // Dequeue the last element
    delete tmp;                          // Delete link
    size--;
    return it;
}


// Return a copy of the front element in the queue
template <typename T>
const T& LQueue<T>::FrontValue() const
{
    Assert(size != 0, "Queue is empty!");
    return front->next->element;
}


// Return the number of elements in the queue
template <typename T>
int LQueue<T>::Length() const
{ return size; }



































