//
//  Link.h
//  List
//
//  Created by Marcus Novak on 12/20/14.
//
//  Generic implementation of a node that can be used for linked lists, queues, and stacks
//  Implemented with freelist support to make new and delete operators more efficient
//
//  Copyright (c) 2014 Marcus Novak. All rights reserved.
//

#ifndef List_Link_h
#define List_Link_h

// Link for linked list, queues, or stacks.
// In practice this would be a private class in whatever data structure was using it
// in order to maintain encapsulation, but for the purposes of this demonstration
// and for simplicity I'm making it public in order to use it for multilple structures
template <typename T> class Link
{
private:
    static Link<T>* freelist;    // Reference to freelist head
    
public:
    T element;     // Value for this node
    Link *next;    // Pointer to the next node in the list
    
    // Constructor with option for setting initial element
    Link(const T& elemval, Link* nextval = NULL) { element = elemval;  next = nextval; }
    
    // Constructor that does not set initial element
    Link(Link* nextval = NULL) { next = nextval; }
    
    // Overloaded new operator for accomodating freelists into Links
    void* operator new(size_t)
    {
        if (freelist == NULL) return ::new Link;   // Create the space
        Link<T>* tmp = freelist;                   // Can take from the freelist
        freelist = freelist->next;
        return tmp;
    }
    
    // Overloaded delete operator for accomodating freelists into Links
    void operator delete(void* ptr)
    {
        ((Link<T>*)ptr)->next = freelist;    // Put in the freelist
        freelist = (Link<T>*)ptr;
    }
};

#endif
