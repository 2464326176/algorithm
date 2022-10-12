/*
 * @Author: yh
 * @Date: 2022/9/30 1:14
 * @Description: 
 * @FilePath: huffmanTree.h
 */

#ifndef ALGORITHM_BASICALGORITHMS_TREE_HUFFMANTREE_HUFFMANTREE_H
#define ALGORITHM_BASICALGORITHMS_TREE_HUFFMANTREE_HUFFMANTREE_H
#include <cstdlib>
#include <cstdios>

typedef struct {
    unsigned int weight;
    unsigned int parent, lchild, rchild;
}HTNode, *HuffmanTree;

typedef char **HuffmanCode;

void huffmanCoding(HuffmanTree &ht, HuffmanCode &hc, int *w, int n) {
    if(n <= 1) {
        return ;
    }

    int m = n * 2 -1;
    ht = (HuffmanTree) malloc((m + 1) * sizeof(HTNode));
    HuffmanTree *pHead = ht;
    int i = 1
    for(; i < n; ++i, ++pHead, ++w) {
        *pHead = {*w, 0, 0, 0}
    }

    for(; i <= m; ++i) {
        
    }
}

#endif //ALGORITHM_BASICALGORITHMS_TREE_HUFFMANTREE_HUFFMANTREE_H
