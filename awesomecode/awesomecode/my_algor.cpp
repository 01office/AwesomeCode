//
//  my_algor.cpp
//  awesomecode
//
//  Created by heyong on 16/8/30.
//  Copyright © 2016年 heyong. All rights reserved.
//

#include <iostream>

#include "my_algor.hpp"

void manacher(std::string &str)
{
    int *p = new int[str.size() + 1];
    memset(p, 0, sizeof(p) * str.size());
    
    int mx = 0, id = 0;
    for (int i = 1; i < str.size(); ++i) {
        if (i < mx) {
            p[i] = (p[2 * id - i] < (mx - i)) ? p[2 * id - i] : (mx - i);
        }
        else
        {
            p[i] = 1;
        }
        
        while (str[i - p[i]] == str[i + p[i]]) {
            p[i]++;
        }
        
        if (mx < i + p[i]) {
            mx = i + p[i];
            id = i;
        }
    }
    
    int max = 0, ii = 0;
    for (int i = 1; i < str.size(); ++i) {
        if (max < p[i]) {
            max = p[i];
            ii = i;
        }
    }
    max--;
    
    int start = ii - max;
    int end = ii + max;
    for (int i = start; i <= end; ++i) {
        if (str[i] != '#') {
            std::cout << str[i];
        }
    }
    std::cout << std::endl;
}

double my_sqrt(double N)
{
    double x = 1.0;
    while (fabs(x * x - N) > 0.0001) {
        x = (x + N / x) / 2;
    }
    
    return x;
}

int my_add(int a, int b)
{
    int result = a;
    for (int i = 0; i < b; ++i) {
        result++;
    }
    return result;
}

int my_minus(int a, int b)
{
    if (a < b) {
        return -1;
    }
    int result = 0;
    for (; ; ++result) {
        if (a == my_add(result, b)) {
            break;
        }
    }
    return result;
}
