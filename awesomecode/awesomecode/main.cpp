//
//  main.cpp
//  awesomecode
//
//  Created by heyong on 16/8/11.
//  Copyright © 2016年 heyong. All rights reserved.
//

#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>

#include "my_algor.hpp"

using namespace std;

void myswap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

inline void myswap1(int &a, int &b)
{
    if (a != b) {
        a ^= b;
        b ^= a;
        a ^= b;
    }
}

void myprint(int arr[], int n)
{
    for (int index = 0; index < n; ++index) {
        cout << arr[index] << " ";
    }
    cout << endl;
}

/**
 * 冒泡排序
 * 1. 比较两个相邻的数据，如果前面的大于后面的，则交换
 * 2. 对数组第 0 到 n-1 遍历一遍后，最大的数据将会到达数组第 n-1 的位置
 * 3. n=n-1，如果 n 不为 0，则重复第二步
 */
void bubble_sort_1(int arrry[], int n)
{
    for (int i = 0; i < n; ++i) {
        for (int j = 1; j < n - i; ++j) {
            if (arrry[j - 1] > arrry[j]) {
                myswap(arrry[j - 1], arrry[j]);
            }
        }
    }
}

/**
 * 改进的冒泡排序
 * 设置标志，如果一趟发生了交换，则置标志为 true，否则为 false。
 * 如果有一趟没有发生交换，则排序已经完成
 */
void bubble_sort_2(int array[], int n)
{
    int k = n, j;
    bool flag = true;
    
    while (flag) {
        flag = false;
        for (j = 1; j < k; ++j) {
            if (array[j - 1] > array[j]) {
                myswap(array[j - 1], array[j]);
                flag = true;
            }
        }
        k--;
    }
}

/**
 * 改进的冒泡排序
 * 如果待排序数组恰好后半部分已经有序，且都大于前面部分的数据，
 * 那么一趟遍历后，最后交换的位置一定小于临界点，且后面已经有序，
 * 记录下这个位置，后面只需要从头部遍历到这个位置就可以
 */
void bubble_sort_3(int array[], int n)
{
    int k = n, j;
    int flag = n;
    
    while (flag > 0) {
        k = flag;
        flag = 0;
        for (j = 1; j < k; ++j) {
            if (array[j - 1] > array[j]) {
                myswap(array[j - 1], array[j]);
                flag = j;
            }
        }
    }
}

/**
 * 插入排序
 */
void insert_sort_1(int arr[], int n)
{
    int i, j;
    for (i = 1; i < n; ++i) {
        if (arr[i - 1] > arr[i]) {
            int tmp = arr[i];
            for (j = i - 1; j >= 0 && arr[j] > tmp; --j) {
                arr[j + 1] = arr[j];
            }
            arr[j + 1] = tmp;
        }
    }
}

/**
 * 改进的插入排序
 * arr[i] 插入到前面的有序序列中时，采用交换替代移动
 */
void insert_sort_2(int arr[], int n)
{
    int i, j;
    for (i = 1; i < n; ++i) {
        for (j = i - 1; j >= 0 && arr[j] > arr[j + 1]; --j) {
            myswap(arr[j], arr[j + 1]);
        }
    }
}

/**
 * 直接选择排序
 * 选取无序部分中最小的放在有序的后面一个位置
 */
void select_sort_1(int arr[], int n)
{
    int i, j, minIndex;
    for (i = 0; i < n; ++i) {
        minIndex = i;
        
        for (j = i + 1; j < n; ++j) {
            if (arr[j] < arr[i]) {
                minIndex = j;
            }
        }
        
        myswap(arr[i], arr[minIndex]);
    }
}

/**
 * 字符串逆序
 */
char *str_r_1(const char *str)
{
    size_t len = strlen(str);
    char *tmp = new char[len + 1];
    strcpy(tmp, str);
    
    for (int i = 0; i < len / 2; ++i) {
        char c = tmp[i];
        tmp[i] = tmp[len - i - 1];
        tmp[len - i - 1] = c;
    }
    
    return tmp;
}

char *str_r_2(const char *str)  // 用指针代替下标访问
{
    char *tmp = new char[strlen(str) + 1];
    strcpy(tmp, str);
    char *ret = tmp;
    
    char *p = tmp + strlen(str) - 1;
    while (p > tmp) {
        char c = *tmp;
        *tmp = *p;
        *p = c;
        
        --p;
        ++tmp;
    }
    
    return ret;
}

char *str_r_3(const char *str)  // 不使用额外变量
{
    char *tmp = new char[strlen(str) + 1];
    strcpy(tmp, str);
    char *ret = tmp;
    
    char *p = tmp + strlen(str) - 1;
    while (p > tmp) {
//        *tmp ^= *p;
//        *p ^= *tmp;
//        *tmp ^= *p;
        *tmp = *tmp + *p;
        *p = *tmp - *p;
        *tmp = *tmp - *p;
        
        --p;
        ++tmp;
    }
    
    return ret;
}

/**
 * 编辑距离
 */
class Solution_EditDis
{
public:
    int minDistance(string str1, string str2)
    {
        int len1 = str1.size(), len2 = str2.size();
        int i, j;
        vector<vector<int> > dp(len1 + 1);
        
        for (i = 0; i <= len1; ++i) {
            vector<int> tmp(len2 + 1, 0);
            dp[i] = tmp;
        }
        
        for (i = 1; i <= len1; ++i) {
            dp[i][0] = i;
        }
        
        for (j = 1; j <= len2; ++j) {
            dp[0][j] = j;
        }
        
        for (i = 1; i <= len1; ++i) {
            for (j = 1; j <= len2; ++j) {
                if (str1[i - 1] == str2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1];
                }
                else
                {
                    dp[i][j] = min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1])) + 1;
                }
            }
        }
        
        return dp[len1][len2];
    }
    
    // recursive
    int string_distance(string str1, int p1begin, int p1end, string str2, int p2begin, int p2end)
    {
        if (p1begin > p1end) {
            if (p2begin > p2end) {
                return 0;
            }
            else
            {
                return p2end - p2begin + 1;
            }
        }
        if (p2begin > p2end) {
            if (p1begin > p1end) {
                return 0;
            }
            else
            {
                return p1end - p1begin + 1;
            }
        }
        
        if (str1[p1begin] == str2[p2begin]) {
            return string_distance(str1, p1begin + 1, p1end, str2, p2begin + 1, p2end);
        }
        else
        {
            int d1 = string_distance(str1, p1begin + 1, p1end, str2, p2begin + 2, p2end);
            int d2 = string_distance(str1, p1begin + 2, p1end, str2, p2begin + 1, p2end);
            int d3 = string_distance(str1, p1begin + 2, p1end, str2, p2begin + 2, p2end);
            return minValue(d1, d2, d3) + 1;
        }
    }
    
private:
    /**
     * 求三个数中的最小值
     */
    int minValue(int a, int b, int c)
    {
        return (a < b ? a : b) < c ? (a < b ? a : b) : c;
    }
};

/**
 * 给定一个十进制整数N，统计1到N所有书中出现的“1”的个数
 * N＝2，1、2中“1”的个数为1
 * N＝12，1、2、3、4、5、6、7、8、9、10、11、12中“1”的个数为5
 */
int count_one_1(int N)
{
    int i, j;
    int count = 0;
    for (i = 0; i <= N; ++i) {
        j = i;
        while (j != 0) {
            if (j % 10 == 1) {
                ++count;
            }
            j /= 10;
        }
    }
    return count;
}

int count_one_2(int N)  // 利用统计的方法
{
    int count = 0;
    int i = 1;
    int current = 0, before = 0, after = 0;
    
    while ((N / i) != 0) {
        current = (N / i) % 10;
        before = N / (i * 10);
        after = N - (N / i) * i;
        
        if (current > 1)
        {
            count = count + (before + 1) * i;
        }
        else if (current == 0)
        {
            count = count + before * i;
        }
        else if (current == 1)
        {
            count = count + before * i + after + 1;
        }
        
        i *= 10;
    }
    
    return count;
}

/**
  * 快速排序
  */
void quick_sort(int arr[], int l, int r)
{
    if (l < r) {
        int i = l, j = r, tmp = arr[l];
        while (i < j) {
            while (i < j && arr[j] >= tmp) {
                --j;
            }
            if (i < j) {
                arr[i++] = arr[j];
            }
            
            while (i < j && arr[i] < tmp) {
                ++i;
            }
            if (i < j) {
                arr[j--] = arr[i];
            }
        }
        arr[i] = tmp;
        
        quick_sort(arr, l, i - 1);
        quick_sort(arr, i + 1, r);
    }
}

/**
 * 回文字符串判断
 */
bool is_huiwen(string &str)
{
    size_t l = str.size();
    for (size_t i = 0; i < l / 2; ++i) {
        if (str[i] != str[l - i - 1]) {
            return false;
        }
    }
    return true;
}

/**
 * 不用循环、递归打印1到100
 */
class Get1To100
{
    static int i;
    
public:
    Get1To100() {
        cout << i++ << " ";
    }
};
int Get1To100::i = 1;

template <int N>
class X: X<N - 1> {
public:
    X(){cout << N << " ";}
};
template <>
class X<0> {};

void (*fp)();

int main(int argc, const char * argv[]) {
    int a[] = {5, 7, 2, 4, 10, 88, 22, 13, 66, 11};
    
    select_sort_1(a, 10);
    
    myprint(a, 10);
    
    char *str = "I am the one!";
    cout << str_r_3(str) << endl;
    
    int myint = 123;
    stringstream ss;
    ss << myint;
    cout << ss.str() << endl;
    
    int myint1;
    string mystr = "456";
    stringstream ss1(mystr);
    ss1 >> myint1;
    cout << myint1 << endl;
    
    string s1 = "abc", s2 = "def";
    Solution_EditDis sed;
    cout << sed.minDistance(s1, s2) << endl;
    cout << sed.string_distance(s1, 0, 2, s2, 0, 2) << endl;
    
    cout << count_one_1(123) << endl;
    
    quick_sort(a, 0, 9);
    myprint(a, 10);
    
    cout << my_sqrt(15.0) << endl;
    
    string huiwen = "12212332145";
    string huiwen0 = "$#";
    for (int i = 0; i < huiwen.size(); ++i) {
        huiwen0 += huiwen[i];
        huiwen0 += '#';
    }
    manacher(huiwen0);
    
    int aa[] = {3, -5, 4, 6, 8, -2, 3};
    cout << maxSubSum(aa, 7) << endl;
    
    char *p = "123()[4]{56}7";
    cout << my_match(p, 13) << endl;
    
//    Get1To100 my_c[100];
//    X<100> x;
    
    cout << is_prime(17) << endl;
    
    shaixuanfa(100);
    
    cout << my_atoi("  -2147483657") << endl;
    
    Solution sol;
    cout << sol.simplify_path("/aa/bb/../cc/") << endl;
    cout << sol.is_valid("(0[]{})") << endl;
    
    // time_t -> string
    time_t itime = 178345656;
    string istr;
    get_str_from_timestamp(itime, const_cast<char *>(istr.c_str()));
    cout << istr.c_str() << endl;
    
    std::vector<int> vlr = {2, 1, 5, 6, 2, 4};
    myClass mc;
    std::cout << mc.largest_rectangle_with_stack(vlr) << std::endl;
    
    std::string str_to_split("Somewhere down the road");
    istringstream iss(str_to_split);
    do {
        std::string sub;
        iss >> sub;
        std::cout << sub << std::endl;
    } while (iss);
    
    std::vector<int> data = {1, 2, 3, 3, 6, 6, 7, 7, 10};
    // iterator pointing to the first element that not less than value, or last if no sucn element is found
    auto lower = std::lower_bound(data.begin(), data.end(), 5);
    // returns an iterator to the first element greater than a certain value
    auto upper = std::upper_bound(data.begin(), data.end(), 4);
    std::cout << *lower << " " << *upper << std::endl;
    
    stringstream myss;
    std::string s;
    myss << "wuhan university of technology";
    while (myss >> s)
    {
        cout << s << endl;
    }

    fp = f1;
    (*fp)();
   
    return 0;
}
