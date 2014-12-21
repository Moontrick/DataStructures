//
//  UALDict.h
//  List
//
//  Created by Marcus Novak on 12/21/14.
//
//  Implementation of an unsorted array-based dictionary data structure
//
//  Copyright (c) 2014 Marcus Novak. All rights reserved.
//

#ifndef __List__UALDict__
#define __List__UALDict__

#include <iostream>
#include "Dictionary.h"
#include "KVPair.h"

#define DEFAULT_SIZE 100

template <typename Key, typename T> class UALDict : public Dictionary<Key, T>
{
};

#endif /* defined(__List__UALDict__) */
