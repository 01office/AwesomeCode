//
//  bit_map.cpp
//  awesomecode
//
//  Created by heyong on 2016/12/21.
//  Copyright © 2016年 heyong. All rights reserved.
//

#include "bit_map.hpp"

const int NUM = 10000000;

int bitarray[1 + NUM / BITSPERNUM];

void set_num(int n)
{
    bitarray[n >> SHIFT] |= (1 << (n & MASK));
}

void clr_num(int n)
{
    bitarray[n >> SHIFT] &= ~(1 >> (n & MASK));
}

int test_num(int n)
{
    return bitarray[n >> SHIFT] & (1 << (n & MASK));
}

