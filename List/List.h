//
//  List.h
//
//  Created by Marcus Novak on 12/13/14.
//
//  Template for the List data structure from which
//  all specific List implementation will derive from
//
//  Copyright (c) 2014 Marcus Novak. All rights reserved.
//

#ifndef List_List_h
#define List_List_h

template <typename T> class List
{
private:
    void operator = (const List&) {}     // Assignment operator
    List (const List&) {}                // Copy constructor
public:
    List() {}                            // Default constructor
    virtual ~List() {}                   // Base destructor
    
    // Clear contents from the list, make it empty
    virtual void Clear() = 0;
    
    // Insert an element at the current location
    // item: The element to be inserted
    virtual void Insert(const T& item) = 0;
    
    // Append an element to the end of the List
    // item: The element to be appended
    virtual void Append(const T& item) = 0;
    
    // Remove and return the current element
    // Return: The element that was removed
    virtual T Remove() = 0;
    
    // Set the current position to the start of the List
    virtual void MoveToStart() = 0;
    
    // Set the current position to the end of the List
    virtual void MoveToEnd() = 0;
    
    // Move the current position one step to the left.  No change if already at beginning
    virtual void Prev() = 0;
    
    // Move the current position one step to the right.  No change if already at the end
    virtual void End() = 0;
    
    // Return: The current number of elements in the List
    virtual int Length() const = 0;
    
    // Return: The position of the current element
    virtual void CurrPos() const = 0;
    
    // Set the current position
    // pos: The position to make current
    virtual void MoveToPos(int pos) = 0;
    
    // Return: The current element
    virtual const T& GetValue() const = 0;
};

#endif
