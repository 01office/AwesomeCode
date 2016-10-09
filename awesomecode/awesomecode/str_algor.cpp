//
//  str_algor.cpp
//  awesomecode
//
//  Created by heyong on 16/10/9.
//  Copyright © 2016年 heyong. All rights reserved.
//

#include <algorithm>

#include "str_algor.hpp"

void get_next()
{
    memset(next, 0, sizeof(next));
    
    int k = -1;
    int j = 0;
    next[0] = -1;
    
    while (j < p.size()) {
        if (k == -1 || p[k] == p[j]) {
            k++;
            j++;
            next[j] = k;
        }
        else {
            k = next[k];
        }
    }
}
