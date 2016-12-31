//
//  bit_map.hpp
//  awesomecode
//
//  Created by heyong on 2016/12/21.
//  Copyright © 2016年 heyong. All rights reserved.
//

#ifndef bit_map_hpp
#define bit_map_hpp

#include <iostream>

#include "common_def.h"

void set_num(int n);

void clr_num(int n);

int test_num(int n);

class Base
{
public:
    virtual void getout();
};

class Derived : public Base
{
public:
    virtual void getout();
    virtual void hello();
};

#endif /* bit_map_hpp */
