//
//  my_algor.cpp
//  awesomecode
//
//  Created by heyong on 16/8/30.
//  Copyright © 2016年 heyong. All rights reserved.
//

#include <iostream>
#include <vector>
#include <sstream>
#include <stack>

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

int my_atoi(const std::string &str)
{
    int num = 0;
    int sign = 1;
    const size_t len = str.length();
    size_t i = 0;
    
    while (str[i] == ' ' && i < len) {
        ++i;
    }
    
    if (str[i] == '-') {
        sign = -1;
        ++i;
    } else if (str[i] == '+') {
        ++i;
    }

    for (; i < len; ++i) {
        if (str[i] < '0' || str[i] > '9') {
            break;
        }
        
        if ((num > INT_MAX / 10) || ((num == INT_MAX / 10) && (str[i] - '0' > INT_MAX % 10))) {
            return sign == -1 ? INT_MIN : INT_MAX;
        }
        
        num = num * 10 + (str[i] - '0');
    }
    
    return num * sign;
}

std::string Solution::simplify_path(const std::string &path)
{
    std::vector<std::string> dirs;
    
    for (auto i = path.begin(); i != path.end(); ) {
        ++i;
        
        auto j = find(i, path.end(), '/');
        auto dir = std::string(i, j);
        
        if (!dir.empty() && dir != ".") {
            if (dir == "..") {
                if (!dirs.empty()) {
                    dirs.pop_back();
                }
            } else {
                dirs.push_back(dir);
            }
        }
        
        i = j;
    }
    
    std::stringstream out;
    if (dirs.empty()) {
        out << "/";
    } else {
        for (auto dir : dirs) {
            out << "/" << dir;
        }
    }
    
    return out.str();
}

bool Solution::is_valid(const std::string &s)
{
    std::string left = "([{";
    std::string right = ")]}";
    std::stack<char> stk;
    
    for (auto c : s) {
        if (left.find(c) != std::string::npos) {
            stk.push(c);
        }
        else if (right.find(c) != std::string::npos) {
            if (stk.empty() || stk.top() != left[right.find(c)]) {
                return false;
            }
            else {
                stk.pop();
            }
        }
    }
    
    return stk.empty();
}

void get_str_from_timestamp(time_t iTimeStamp, char *pTime)
{
    struct tm *pTmp = gmtime(&iTimeStamp);
    if (pTmp == NULL) {
        return;
    }
    
    sprintf(pTime, "%04d-%02d-%02d %02d:%02d", pTmp->tm_year + 1900, pTmp->tm_mon + 1, pTmp->tm_mday, pTmp->tm_hour, pTmp->tm_min);
}

int myClass::largest_rectangle(std::vector<int> &height)
{
    int res = 0;
    for (int i = 0; i < height.size(); ++i) {
        if (i + 1 < height.size() && height[i] <= height[i + 1]) {
            continue;
        }
    
        int minH = height[i];
        for (int j = i; j >= 0; --j) {
            minH = (minH < height[j] ? minH : height[j]);
            int area = minH * (i - j + 1);
            res = (res >= area ? res : area);
        }
    }
    
    return res;
}

int myClass::largest_rectangle_with_stack(std::vector<int> &height)
{
    int res = 0;
    std::stack<int> sk;
    
    for (int i = 0; i < height.size(); ++i) {
        if (sk.empty() || (!sk.empty() && height[sk.top()] <= height[i])) {
            sk.push(i);
        }
        else {
            while (!sk.empty() && height[sk.top()] > height[i]) {
                int idx = sk.top();
                sk.pop();
                int width = sk.empty() ? i : (i - sk.top() - 1);
                res = (res >= height[idx] * width) ? res : (height[idx] * width);
            }
        }
        sk.push(i);
    }
    
    return res;
}

LinkNode *reverse_link_1(LinkNode *head)
{
    LinkNode *prv = head;
    LinkNode *cur = head->next;
    LinkNode *nxt = cur->next;
    
    while (cur != NULL) {
        nxt = nxt->next;
        prv = cur;
        cur = cur->next;
    }
    
    head->next = NULL;
    return prv;
}

LinkNode *reverse_link_2(LinkNode *head)
{
    if (head == NULL || head->next == NULL) {
        return head;
    }
    else
    {
        LinkNode *newNode = reverse_link_2(head->next);
        head->next = NULL;
        return newNode;
    }
}

void f1()
{
    std::cout << "This is f1." << std::endl;
}

void first_appear_once(std::string str)
{
    int hash_table[256] = {0};
    for (size_t i = 0; i < str.size(); ++i) {
        hash_table[str[i]]++;
    }
    
    for (size_t i = 0; i < str.size(); ++i) {
        if (hash_table[str[i]] == 1) {
            std::cout << "First character appear once is " << str[i] << std::endl;
            return;
        }
    }
    return;
}

int more_than_half_num(std::vector<int> &nums)
{
    int result = nums[0];
    int times = 1;
    for (size_t i = 1; i < nums.size(); ++i) {
        if (times == 0)
        {
            result = nums[i];
            times = 1;
        }
        else if (result == nums[i])
        {
            times++;
        }
        else
        {
            times--;
        }
    }
    return result;
}

long adddd(int a, int b)
{
    char *c = (char *)a;
    return (long)&c[b];
}

int convert_num(int a, int b)
{
    return count_one(a ^ b);
}

int count_one(int x)
{
    x = (x & (0x55555555)) + ((x >> 1) & (0x55555555));
    x = (x & (0x33333333)) + ((x >> 2) & (0x33333333));
    x = (x & (0x0f0f0f0f)) + ((x >> 4) & (0x0f0f0f0f));
    x = (x & (0x00ff00ff)) + ((x >> 8) & (0x00ff00ff));
    x = (x & (0x0000ffff)) + ((x >> 16) & (0x0000ffff));
    
    return x;
}

int replace_bits(int m, int n, int i, int j)
{
    int tmp = (1 << i) - 1;
    tmp &= m;
    
    return ((m >> (j + 1)) << (j + 1)) | (n << i) | tmp;
}

bool is_unique_1(std::string s)
{
    bool a[256];
    memset(a, 0, sizeof(a));
    size_t len = s.size();
    
    for (size_t i = 0; i < len; ++i) {
        if (a[s[i]]) {
            return false;
        }
        else {
            a[s[i]] = true;
        }
    }
    
    return true;
}

bool is_unique_2(std::string s)
{
    int a[8];
    memset(a, 0, sizeof(a));
    
    size_t len = s.size();
    for (size_t i = 0; i < len; ++i) {
        int idx = s[i] / 32;
        int shift = s[i] % 32;
        
        if (a[idx] & (1 << shift)) {
            return false;
        }
        
        a[idx] |= (1 << shift);
    }
    
    return true;
}

// count i from 1 to n
int count_i_s(int n, int i)
{
    // 1 <= i <= 9
    if (i < 1 || i > 9) {
        return -1;
    }
    
    int count = 0;
    int factor = 1;
    int higher, current, lower;
    
    while (n / factor > 0) {
        higher = n / (factor * 10);
        current = (n / factor) % 10;
        lower = n - (n / factor) * factor;
        
        if (current < i) {
            count += higher * factor;
        } else if (current == i) {
            count += higher * factor + lower + 1;
        } else {
            count += (higher + 1) * factor;
        }
        
        factor *= 10;
    }
    
    return count;
}


void reverse_ch(char *pBegin, char *pEnd)
{
    if (pBegin == NULL || pEnd == NULL) {
        return;
    }
    
    while (pBegin < pEnd) {
        char tmp = *pBegin;
        *pBegin = *pEnd;
        *pEnd = tmp;
        
        pBegin++;
        pEnd--;
    }
}
char *reverse_sentence(char *pData)
{
    if (pData == NULL) {
        return NULL;
    }
    
    char *pB = pData;
    char *pE = pData;
    while (*pE != '\0') {
        pE++;
    }
    pE--;
    
    // reverse the whole sentence
    reverse_ch(pB, pE);
    
    pB = pE = pData;
    while (*pB != '\0') {
        if (*pB == ' ') {
            pB++;
            pE++;
        }
        else if (*pE == ' ' || *pE == '\0') {
            reverse_ch(pB, --pE);
            pB = ++pE;
        }
        else {
            pE++;
        }
    }
    
    return pData;
}

// redis SDS (simple dynamic string)
// sds.h/sdshdr
struct sdshdr
{
    int free;
    int len;
    char buf[];
};

int add2(int a, int b)
{
    if (b == 0) {
        return a;
    }
    
    int sum = a ^ b;
    int carry = (a & b) << 1;
    return add2(sum, carry);
}

int add3(int a, int b)
{
    while (b != 0) {
        int sum = a ^ b;
        int carry = (a & b) << 1;
        a = sum;
        b = carry;
    }
    return a;
}
