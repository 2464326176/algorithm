/*
 * @Author: yh
 * @Date: 2022-02-20 23:08:13
 * @LastEditTime: 2022-05-21 02:38:16
 * @Description:
 * @FilePath:
 * \algorithm\basicAlgorithms\basicDataStruct\string\linkString\string.h
 */

//**************************
// Author:  yh
// Time:    2022/2/20
//**************************

#ifndef CESSENCE_SEQSTRING_H
#define CESSENCE_STRING_H
#include "../../common/dataType.h"

#define CHUNKSIZE 80

typedef struct Chunk {
  char ch[CHUNKSIZE];
  struct Chunk *next;
} Chunk;

typedef struct {
  Chunk *head, *tail;
  int currentLength;
} LString;

Status initString(LString &string);
int getLength(LString string);
Status compare(LString String, LString targetString);
Status clear(LString &string);
Status concat(LString &string, LString firstString, LString secondString);
Status subString(LString subString, LString string, int pos, int len);

#endif // CESSENCE_SEQSTRING_H
