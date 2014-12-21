//
//  SAList.h
//  List
//
//  Created by Marcus Novak on 12/21/14.
//
//  Implementation of a sorted array-based list for dictionary use
//
//  Copyright (c) 2014 Marcus Novak. All rights reserved.
//

#ifndef __List__SAList__
#define __List__SAList__

#include <iostream>
#include "Dictionary.h"
#include "KVPair.h"
#include "../List/AList.h"

template <typename Key, typename T> class SAList : protected AList<KVPair<Key, T>>
{
};

#endif /* defined(__List__SAList__) */
