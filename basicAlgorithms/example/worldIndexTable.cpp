//**************************
// Author:  yh
// Time:    2022/2/25
//**************************
#include <stdio.h>
#include <stdlib.h>


#define MaxBookNum  1000
#define MaxKeyNum   2500
#define MaxLineLen  500
#define MaxWordNum  10


typedef struct {
    char *item[];
    int last;
}WordListType;

typedef int ElemType;

typedef struct {
    HString key;
    LinkList bnolist;
}IdxTermType;

typedef struct {
    IdxTermType item[MaxKeyNum + 1];
    int last;
};


char *buf;              //
WordListType wdList;

void initIdxList();

void getLine();

void extractKeyWord();

int insIdxList();

void putText();

