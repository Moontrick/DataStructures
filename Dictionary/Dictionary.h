//
//  Dictionary.h
//  List
//
//  Created by Marcus Novak on 12/21/14.
//
//  Abstract template for Dictionary data structure
//
//  Copyright (c) 2014 Marcus Novak. All rights reserved.
//

#ifndef List_Dictionary_h
#define List_Dictionary_h

template <typename Key, typename T> class Dictionary
{
private:
    void operator = (const Dictionary&) {}
    Dictionary(const Dictionary&) {}
    
public:
    Dictionary() {}
    virtual ~Dictionary () {}
    
    // Reinitialize Dictionary
    virtual void Clear() = 0;
    
    // Insert a record
    // k: The key for the record being inserted
    // t: The record being inserted
    virtual void Insert(const Key& k, const T& t) = 0;
    
    // Remove and return a record
    // k: The key of the record being removed
    // Return: A matching record.  If multiple records match "k", remove an arbitrary one
    // return NULL if no record matching "k" exists
    virtual T Remove(const Key& k) = 0;
    
    // Remove and reutrn and arbitrary record from dictionary
    // Return: The record removed, or NULL if none exists
    virtual T RemoveAny() = 0;
    
    // Return: A record matching "k" (NULL if none exists)
    // If multiple records match, return an arbitrary one
    // k: The key of the record to find
    virtual T Find(const Key& k) const = 0;
    
    // Return the number of records in the dictionary
    virtual int Size() = 0;
};

#endif
