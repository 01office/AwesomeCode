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

#define SHIFT 5
#define BITSPERNUM 32
#define MASK 0x1F

void set_num(int n);

void clr_num(int n);

int test_num(int n);

#endif /* bit_map_hpp */
