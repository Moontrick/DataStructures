//
//  DLLink.h
//  List
//
//  Created by Marcus Novak on 12/20/14.
//
//  Doubly linked list link node implementation with freelist support
//  Probably could have inherited from Link if I'd arranged it right
//  but I'm not going to worry about it in this demonstration
//
//  Copyright (c) 2014 Marcus Novak. All rights reserved.
//

#ifndef List_DLLink_h
#define List_DLLink_h

template <typename T> class DLLink
{
private:
    static DLLink<T>* freelist;   // Reference to freelist head
    
public:
    T element;     // Value for this node
    DLLink *next;    // Pointer to the next node in the list
    DLLink *prev;    // Pointer to the prev node in the list
    
    // Constructor with option for setting initial element
    DLLink(const T& elemval, DLLink* nextp, DLLink* prevp)
    {
        element = elemval;
        next = nextp;
        prev = prevp;
    }
    
    // Constructor that does not set initial element
    DLLink(DLLink* nextp = NULL, DLLink* prevp = NULL)
    {
        next = nextp;
        prev = prevp;
    }
    
    // Overloaded new operator for accomodating freelists into Links
    void* operator new(size_t)
    {
        if (freelist == NULL) return ::new DLLink;   // Create the space
        DLLink<T>* tmp = freelist;                   // Can take from the freelist
        freelist = freelist->next;
        return tmp;
    }
    
    // Overloaded delete operator for accomodating freelists into Links
    void operator delete(void* ptr)
    {
        ((DLLink<T>*)ptr)->next = freelist;    // Put in the freelist
        freelist = (DLLink<T>*)ptr;
    }
};

// Create freelist head pointer
template <typename T>
DLLink<T>* DLLink<T>::freelist = NULL;

#endif
