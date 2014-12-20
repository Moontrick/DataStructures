//
//  DLList.cpp
//  List
//
//  Created by Marcus Novak on 12/20/14.
//  Copyright (c) 2014 Marcus Novak. All rights reserved.
//

#include "DLList.h"


// Constructor
template <typename T>
DLList<T>::DLList(int size)
{ Init(); }


// Destructor
template <typename T>
DLList<T>::~DLList()
{ RemoveAll(); }


// Helper function for initialization
template <typename T>
void DLList<T>::Init()
{
    curr = tail = head = new DLLink<T>;
    cnt = 0;
}


// Remove all elements
template <typename T>
void DLList<T>::RemoveAll()
{
    while (head != NULL)
    {
        curr = head;
        head = head->next;
        delete curr;
    }
}


// Print the contents of the list
template <typename T>
void DLList<T>::Print() const
{
    DLLink<T>* tmp = head;
    while (tmp != NULL)
        std::cout << tmp->element << std::endl;
}


// Clear the list
template <typename T>
void DLList<T>::Clear()
{
    RemoveAll();
    Init();
}


// Insert "it" at the current position
template <typename T>
void DLList<T>::Insert(const T& it)
{
    curr->next = curr->next->prev = new DLLink<T>(it, tail->prev, tail);
    cnt++;
}


// Append "it" to the list
template <typename T>
void DLList<T>::Append(const T& it)
{
    tail->prev = tail->prev->next = new DLLink<T>(it, tail->prev, tail);
    cnt++;
}


// Remove and return current element
template <typename T>
T DLList<T>::Remove()
{
    Assert(curr->next != NULL, "No element!");
    
    T it = curr->next->element;       // Remember value
    DLLink<T>* tmp = curr->next;      // Remember link node
    
    curr->next->next->prev = curr;
    
    curr->next = curr->next->next;    // Remove from list
    delete tmp;                       // Reclaim space
    
    cnt--;                            // Decrement the count
    return it;
}


// Place curr at list start
template <typename T>
void DLList<T>::MoveToStart()
{ curr = head; }


// Place curr at list end
template <typename T>
void DLList<T>::MoveToEnd()
{ curr = tail; }


// Move curr one step left; no change if already at the head
template <typename T>
void DLList<T>::Prev()
{
    if (curr == head) return;   // No previous element
    curr = curr->prev;
}


// Move curr one step right; no change if already at the tail
template <typename T>
void DLList<T>::Next()
{ if (curr != tail) curr = curr->next; }


// Return the length of the list
template <typename T>
int DLList<T>::Length() const
{ return cnt; }


// Return the position of the current element
template <typename T>
int DLList<T>::CurrPos() const
{
    DLLink<T>* tmp = head;
    
    int i;
    for (i = 0; curr != tmp; i++) tmp = tmp->next;
    return i;
}


// Move down list to "pos"
template <typename T>
void DLList<T>::MoveToPos(int pos)
{
    Assert((pos >= 0) && (pos <= cnt), "Position out of range!");
    
    curr = head;
    for (int i = 0; i < pos; i++) curr = curr->next;
}


// Return the current element
template <typename T>
const T& DLList<T>::GetValue() const
{
    Assert(curr->next != NULL, "No value!");
    return curr->next->element;
}



























