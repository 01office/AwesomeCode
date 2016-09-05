//
//  my_algor.cpp
//  awesomecode
//
//  Created by heyong on 16/8/30.
//  Copyright © 2016年 heyong. All rights reserved.
//

#include <iostream>

#include "my_algor.hpp"

my_string::my_string(const char *str)
{
    if (str == NULL) {
        m_data = new char[1];
        m_data[0] = '\0';
    }
    else
    {
        m_data = new char[strlen(str) + 1];
        strcpy(m_data, str);
    }
}
my_string::my_string(const my_string &another)
{
    m_data  = new char[strlen(another.m_data) + 1];
    strcpy(m_data, another.m_data);
}
my_string &my_string::operator = (const my_string &rhs)
{
    if (this == &rhs) {
        return *this;
    }
    delete []m_data;
    m_data = new char[strlen(rhs.m_data) + 1];
    strcpy(m_data, rhs.m_data);
    return *this;
}
my_string::~my_string()
{
    delete []m_data;
}

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

int maxSubSum(int a[], int n)   // 子数组的最大和
{
    int b = 0, sum = 0x80000000;
    for (int i = 0; i < n; ++i) {
        if (b > 0) {
            b += a[i];
        }
        else
        {
            b = a[i];
        }
        
        if (sum < b) {
            sum = b;
        }
    }
    
    return sum;
}

bool is_match(char a, char b)
{
    if (a == '(' && b == ')') {
        return true;
    }
    if (a == '[' && b == ']') {
        return true;
    }
    if (a == '{' && b == '}') {
        return true;
    }
    
    return false;
}

bool my_match(char *s, int n)
{
    int *st = new int[n];
    int top = -1;
    for (int i = 0; i < n; ++i) {
        if (s[i] == ')' || s[i] == ']' || s[i] == '}') {
            if (top >= 0 && is_match(st[top], s[i])) {
                top--;
            }
            else
            {
                return false;
            }
        }
        else if (s[i] == '(' || s[i] == '[' || s[i] == '{')
        {
            st[++top] = s[i];
        }
    }
    
    if (top == -1) {
        return true;
    }
    return false;
}

bool is_prime(int n)
{
    if (n < 2) {        // prime >= 2
        return false;
    }
    for (int i = 2; i * i <= n; ++i) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

void shaixuanfa(int n)
{
    int i, j;
    bool prime[n + 1];
    for (i = 2; i <= n; ++i) {
        if (i % 2 == 0) {
            prime[i] = false;
        }
        else {
            prime[i] = true;
        }
    }
    
    for (i = 3; i * i <= n; ++i) {
        if (prime[i]) {
            for (j = i + i; j <= n; j += i) {
                prime[j] = false;
            }
        }
    }
    
    for (i = 2; i <= n; ++i) {
        if (prime[i]) {
            std::cout << i << " ";
        }
    }
    std::cout << std::endl;
}

