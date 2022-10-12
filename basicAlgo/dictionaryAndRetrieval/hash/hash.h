/*
 * @Author: yh
 * @Date: 2022/9/27 0:20
 * @Description:
 * @FilePath: \algorithm\basicAlgo\dictionaryAndRetrieval\hash\hash.h
 */

#ifndef BASICALGO_DICTIONARYANDRETRIEVAL_HASH_HASH_H_
#define BASICALGO_DICTIONARYANDRETRIEVAL_HASH_HASH_H_
#include<stdio.h>

#define null -1

#define REGION_LEN 13

typedef int KeyType;
typedef int DataType;
// 开放定址法
struct DicElement {
    KeyType key;
    DataType value;
    DicElement() : key(-1), value(0) {}
};

typedef struct {
    int regionLength = REGION_LEN;
    DicElement element[REGION_LEN];
} HashDictionary;

KeyType hashFunciotn(KeyType key);

bool linearSearch(const HashDictionary &phash, KeyType key, int *position);

bool linearInsert(HashDictionary *phash, KeyType key);


// 链地址法

struct LinkListNode {
    int key = -1;
    LinkListNode *next = nullptr;
    LinkListNode() :key(-1), next(nullptr) {}

    LinkListNode(int key) :key(key), next(nullptr) {}
};

typedef struct {
    int regionLength = REGION_LEN;
    LinkListNode* element[REGION_LEN] {nullptr};
} LinkAddrHashDictionary;

void searchLinkAddrHashDictionary(const LinkAddrHashDictionary &hd, KeyType key);

void insertLinkAddrHashDictionary(LinkAddrHashDictionary *hd, KeyType key);

void printHd(const LinkAddrHashDictionary &hd);

#endif  // BASICALGO_DICTIONARYANDRETRIEVAL_HASH_HASH_H_
