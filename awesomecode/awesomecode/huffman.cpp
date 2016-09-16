//
//  huffman.cpp
//  awesomecode
//
//  Created by heyong on 16/9/16.
//  Copyright © 2016年 heyong. All rights reserved.
//

#include "huffman.hpp"

void init_huffmantree(HuffmanTree HT, int m)
{
    HT = new HTNode[m];
    for (int i = 0; i < m; ++i) {
        HT[i].weight = 0;
        HT[i].parent = -1;
        HT[i].lchild = -1;
        HT[i].rchild = -1;
    }
}

void select_min(HuffmanTree HT, int n, int &min1, int &min2)
{
    TempTree TT = new TempNode[n];
    int i, j = 0;
    for (i = 0; i < n; ++i) {
        if (HT[i].parent != -1 && HT[i].weight != 0) {
            TT[j].newweight = HT[i].weight;
            TT[j].p = i;
            ++j;
        }
    }
    
    int m1 = 0, m2 = 0;
    for (i = 0; i < j; ++i) {
        if (TT[i].newweight < TT[m1].newweight) {
            m1 = i;
        }
    }
    for (i = 0; i < j; ++i) {
        if (m1 == m2) {
            ++m2;
        }
        if (TT[i].newweight <= TT[m2].newweight && i != m1) {
            m2 = i;
        }
    }
    
    min1 = TT[m2].p;
    min2 = TT[m2].p;
}
