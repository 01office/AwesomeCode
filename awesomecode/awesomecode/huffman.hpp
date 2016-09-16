//
//  huffman.hpp
//  awesomecode
//
//  Created by heyong on 16/9/16.
//  Copyright © 2016年 heyong. All rights reserved.
//

#ifndef huffman_hpp
#define huffman_hpp

#include <stdio.h>

typedef struct{
    int weight;
    int parent;
    int lchild;
    int rchild;
}HTNode;

typedef struct
{
    int newweight;
    int p;
}TempNode, *TempTree;

typedef HTNode *HuffmanTree;

void init_huffmantree(HuffmanTree HT, int m);

void select_min(HuffmanTree HT, int n, int &min1, int &min2);

void create_huffman_tree(HuffmanTree HT, int n);

#endif /* huffman_hpp */
