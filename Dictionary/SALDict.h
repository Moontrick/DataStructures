//
//  SALDict.h
//  List
//
//  Created by Marcus Novak on 12/21/14.
//
//  Implementation of a sorted array-based dictionary
//
//  Copyright (c) 2014 Marcus Novak. All rights reserved.
//

#ifndef __List__SALDict__
#define __List__SALDict__

#include <iostream>
#include "Dictionary.h"
#include "KVPair.h"
#include "SAList.h"

#define DEFAULT_SIZE 100

template <typename Key, typename T> class SALDict : public Dictionary<Key, T>
{
};

#endif /* defined(__List__SALDict__) */
