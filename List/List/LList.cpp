//
//  LList.cpp
//  List
//
//  Created by Marcus Novak on 12/20/14.
//  Copyright (c) 2014 Marcus Novak. All rights reserved.
//

#include "LList.h"


// Constructor
template <typename T>
LList<T>::LList(int size)
{ Init(); }


// Destructor
template <typename T>
LList<T>::~LList()
{ RemoveAll(); }


// Helper function for initialization
template <typename T>
void LList<T>::Init()
{
    curr = tail = head = new Link<T>;
    cnt = 0;
}


// Remove all elements
template <typename T>
void LList<T>::RemoveAll()
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
void LList<T>::Print() const
{
    Link<T>* tmp = head;
    while (tmp != NULL)
        std::cout << tmp->element << std::endl;
}


// Clear the list
template <typename T>
void LList<T>::Clear()
{
    RemoveAll();
    Init();
}


// Insert "it" at the current position
template <typename T>
void LList<T>::Insert(const T& it)
{
    curr->next = new Link<T>(it, curr->next);
    if (curr == tail) tail = curr->next;   // New tail if needed
    cnt++;
}


// Append "it" to the list
template <typename T>
void LList<T>::Append(const T& it)
{
    tail = tail->next = new Link<T>(it, NULL);
    cnt++;
}


// Remove and return current element
template <typename T>
T LList<T>::Remove()
{
    Assert(curr->next != NULL, "No element!");
    
    T it = curr->next->element;       // Remember value
    Link<T>* tmp = curr->next;        // Remember link node
    
    if (tail == curr->next)           // Reset tail if needed
        tail == curr;
    
    curr->next = curr->next->next;    // Remove from list
    delete tmp;                       // Reclaim space
    
    cnt--;                            // Decrement the count
    return it;
}


// Place curr at list start
template <typename T>
void LList<T>::MoveToStart()
{ curr = head; }


// Place curr at list end
template <typename T>
void LList<T>::MoveToEnd()
{ curr = tail; }


// Move curr one step left; no change if already at the head
template <typename T>
void LList<T>::Prev()
{
    if (curr == head) return;   // No previous element
    
    // March down the list until we find the previous element
    Link<T>* tmp = head;
    while(tmp->next != curr)
        tmp = tmp->next;
    
    curr = tmp;
}


// Move curr one step right; no change if already at the tail
template <typename T>
void LList<T>::Next()
{ if (curr != tail) curr = curr->next; }


// Return the length of the list
template <typename T>
int LList<T>::Length() const
{ return cnt; }


// Return the position of the current element
template <typename T>
int LList<T>::CurrPos() const
{
    Link<T>* tmp = head;
    
    int i;
    for (i = 0; curr != tmp; i++) tmp = tmp->next;
    return i;
}


// Move down list to "pos"
template <typename T>
void LList<T>::MoveToPos(int pos)
{
    Assert((pos >= 0) && (pos <= cnt), "Position out of range!");
    
    curr = head;
    for (int i = 0; i < pos; i++) curr = curr->next;
}


// Return the current element
template <typename T>
const T& LList<T>::GetValue() const
{
    Assert(curr->next != NULL, "No value!");
    return curr->next->element;
}



























