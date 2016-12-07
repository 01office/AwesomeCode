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
#include <ctime>

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

class LinkSolution
{
public:
    LinkNode *find_first_common_node(LinkNode *ph1, LinkNode *ph2);
    
private:
    int get_length(LinkNode *ph);
};

// 查找字符串中第一个只出现一次的字符，如“abcccad”中‘b’
void first_appear_once(std::string str);

// 数组中出现次数超过数组长度一半的数字
int more_than_half_num(std::vector<int> &nums);

// Catalan

// add two number
long adddd(int, int);
// recursion
int add2(int a, int b);
// iteration
int add3(int a, int b);

int convert_num(int a, int b);
int count_one(int x);

// replace M's bit i to j with N
int replace_bits(int m, int n, int i, int j);

// whether the char in a string is unique
bool is_unique_1(std::string s);
// whether the char in a string is unique (use bit)
bool is_unique_2(std::string s);

int count_i_s(int n, int i);

void reverse_ch(char *pBegin, char *pEnd);
char *reverse_sentence(char *pData);

// replace blank with %20
void replace_blank(std::string &str);

bool is_2_de_n(int n);

void random_shuffle(std::vector<int> &iv);

int xpower(int x, unsigned int n);

// is 5 poker a sequence, King can be anyone
bool is_sequence(std::vector<int> &ivec);

// jump game II
int can_jump_2(std::vector<int> &nums);

// longest consequence in an array

int inverse_pairs(std::vector<int> &iv);

class Temp
{
public:
    Temp();
    static void Reset();
    static unsigned int Getsum();
    
private:
    static unsigned int N;
    static unsigned int Sum;
};

bool find_numbers_with_sum(int array[], int len, int sum, int &a, int &b);
void find_continuous_sequence(int sum);

#endif /* my_algor_hpp */
