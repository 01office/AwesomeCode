//
//  main.cpp
//  awesomecode
//
//  Created by heyong on 16/8/11.
//  Copyright © 2016年 heyong. All rights reserved.
//

#include <iostream>
using namespace std;

void myswap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
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

int main(int argc, const char * argv[]) {
    int a[] = {5, 7, 2, 4, 10, 88, 22, 13, 66, 11};
    
    insert_sort_1(a, 10);
    
    myprint(a, 10);
    
    return 0;
}
