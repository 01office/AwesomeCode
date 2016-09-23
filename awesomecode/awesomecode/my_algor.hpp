//
//  my_algor.hpp
//  awesomecode
//
//  Created by heyong on 16/8/30.
//  Copyright © 2016年 heyong. All rights reserved.
//

#ifndef my_algor_hpp
#define my_algor_hpp

#include <string>
#include <cmath>

void manacher(std::string &str);

double my_sqrt(double N);

int maxSubSum(int a[], int n);

bool is_match(char a, char b);
bool my_match(char *s, int n);

class my_string
{
public:
    my_string(const char *str = NULL);
    my_string(const my_string &another);
    my_string &operator = (const my_string &rhs);
    ~my_string();
    
private:
    char *m_data;
};

bool is_prime(int n);

void shaixuanfa(int n);

int my_atoi(const std::string &str);

class Solution
{
public:
    std::string simplify_path(const std::string &path);
    bool is_valid(const std::string &s);
};

void get_str_from_timestamp(time_t iTimeStamp, char *pTime);

class myClass
{
public:
    // largest rectangle
    int largest_rectangle(std::vector<int> &height);
    int largest_rectangle_with_stack(std::vector<int> &height);
};

struct LinkNode
{
    int va;
    LinkNode *next;
};

// die dai
LinkNode *reverse_link_1(LinkNode *head);
// di gui
LinkNode *reverse_link_2(LinkNode *head);

void f1();

// 查找字符串中第一个只出现一次的字符，如“abcccad”中‘b’
void first_appear_once(std::string str);

#endif /* my_algor_hpp */
