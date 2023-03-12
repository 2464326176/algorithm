/*
 * @Author: yh
 * @Date: 2022/9/27 0:20
 * @Description: 
 * @FilePath: \algorithm\basicAlgo\dictionaryAndRetrieval\hash\hash.cpp
 */

#include <stdio.h>
#include "hash.h"


KeyType hashFunciotn(KeyType key) {
    return key % REGION_LEN;
}

/**
 * @brief 开放定址法
 */
bool linearSearch(const HashDictionary &phash, KeyType key, int *position) {
    int hashPos = hashFunciotn(key);  // hash表返回的地址 除留取余法

    for (int inc = 0; inc < phash.regionLength; inc++) {
        if (phash.element[hashPos].key == key) {
            *position = hashPos;
            return true;
        } else if (phash.element[hashPos].key == -1) {
            *position = hashPos;
            return false;
        }
        hashPos = (hashPos + 1) % phash.regionLength;
    }

    *position = -1;
    return false;
}

bool linearInsert(HashDictionary *phash, KeyType key) {
    int position;
    if (linearSearch(*phash, key, &position)) {
        printf("element found \n");
        return true;
    } else if (position != -1) {
        phash->element[position].key = key;
        return true;
    }

    return false;
}

void printHd(const HashDictionary &hd) {
    for (int i = 0; i < hd.regionLength; ++i) {
        printf("i: %d, key: %d\n", i, hd.element[i].key);
    }
}

void searchLinkAddrHashDictionary(const LinkAddrHashDictionary &hd, KeyType key) {
    int hashPos = hashFunciotn(key);  // hash表返回的地址 除留取余法
    if (hd.element[hashPos] == nullptr) {
        printf("not found!!!");
    } else {
        LinkListNode *pLinkList = hd.element[hashPos];
        while (pLinkList) {
            if (pLinkList->key == key) {
                printf("found!!!");
            }
            pLinkList = pLinkList->next;
        }
    }
}

void insertLinkAddrHashDictionary(LinkAddrHashDictionary *hd, KeyType key) {
    int hashPos = hashFunciotn(key);  // hash表返回的地址 除留取余法

    if (hashPos > hd->regionLength) {
        return;
    }

    if (hd->element[hashPos] == nullptr) {
        LinkListNode *linkList = new LinkListNode(key);
        hd->element[hashPos] = linkList;
    } else {
        LinkListNode *pLinkList = hd->element[hashPos];
        while (pLinkList->next) {
            pLinkList = pLinkList->next;
        }

        LinkListNode *linkList = new LinkListNode(key);
        pLinkList->next = linkList;
    }
}

void printHd(const LinkAddrHashDictionary &hd) {
    for (int i = 0; i < hd.regionLength; ++i) {
        if (hd.element[i]) {
            printf("LinkAddrHashDictionary i: %d\n", i);
            LinkListNode *pLinkList = hd.element[i];
            while (pLinkList) {
                if (pLinkList->key != -1) {
                    printf("%d ", pLinkList->key);
                }
                pLinkList = pLinkList->next;
            }
            printf("\n");
        }
    }
}
int main() {
    HashDictionary hd;
    linearInsert(&hd, 4);
    linearInsert(&hd, 7);
    linearInsert(&hd, 3);
    linearInsert(&hd, 3);
    linearInsert(&hd, 2);
    linearInsert(&hd, 14);
    linearInsert(&hd, 9);
    linearInsert(&hd, 8);
    printf("---------------------------");
    LinkAddrHashDictionary linkAddrHashDictionary;
    insertLinkAddrHashDictionary(&linkAddrHashDictionary, 4);
    insertLinkAddrHashDictionary(&linkAddrHashDictionary, 17);
    insertLinkAddrHashDictionary(&linkAddrHashDictionary, 30);
    insertLinkAddrHashDictionary(&linkAddrHashDictionary, 5);
    insertLinkAddrHashDictionary(&linkAddrHashDictionary, 18);
    insertLinkAddrHashDictionary(&linkAddrHashDictionary, 31);
    printHd(linkAddrHashDictionary);
    return 0;
}