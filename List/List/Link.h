//
//  Link.h
//  List
//
//  Created by Marcus Novak on 12/20/14.
//
//  Generic implementation of a node that can be used for linked lists, queues, and stacks
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
public:
    T element;    // Value for this node
    Link *next    // Pointer to the next node in the list
    
    // Constructor with option for setting initial element
    Link(const T& elemval, Link* nextval = NULL) { element = elemval;  next = nextval; }
    // Constructor that does not set initial element
    Link(Link* nextval = NULL) { next = nextval; }
};

#endif
