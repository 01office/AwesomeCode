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

void Base::getout()
{
    std::cout << "Base getout" << std::endl;
}

void Derived::getout()
{
    std::cout << "Derived getout" << std::endl;
}

void Derived::hello()
{
    std::cout << "World" << std::endl;
}

int count_one(int n)
{
    int count = 0, lower = 0, current = 0, higher = 0, factor = 1;
    
    while (n / factor != 0) {
        lower = n - (n / factor) * factor;
        current = (n / factor) % 10;
        higher = n / (factor * 10);
        
        if (current < 1) {
            count += higher * factor;
        } else if (current == 1) {
            count += (higher * factor + lower + 1);
        } else {
            count += (higher + 1) * factor;
        }
        
        factor *= 10;
    }
    
    return count;
}
