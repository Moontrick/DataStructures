//
//  KVPair.h
//  List
//
//  Created by Marcus Novak on 12/21/14.
//
//  Implementation of a class representing a key-value pair
//
//  Copyright (c) 2014 Marcus Novak. All rights reserved.
//

#ifndef List_KVPair_h
#define List_KVPair_h

template <typename Key, typename T> class KVPair
{
private:
    Key k;     // Key
    T t;       // Value
    
public:
    // Constructors
    KVPair() {}                                         // Default
    KVPair(Key kval, T tval) { k = kval; t = tval; }    // Set key-value
    KVPair(const KVPair& c) { k = c.k; t = c.t; }       // Copy
    
    // Assignment operator
    void operator = (const KVPiar& c) { k = c.k; t = c.t; }
    
    // Member access functions
    Key key() { return k; }
    void SetKey(Key ink) { k = ink; }
    T Value() { return t; }
};

#endif
