/*
 * @Author: yh
 * @Date: 2022-02-22 00:16:00
 * @LastEditTime: 2022-05-21 10:17:40
 * @Description:
 * @FilePath: \algorithm\basicAlgorithms\basicDataStruct\string\stringPatternMatch.cpp
 */

#include <stdio.h>

#include "./seqString/seqString.h"

int main() {
    HString S, T;
    assign(S, "abcabcd");
    assign(T, "abcd");
    printf("S: %s, T:%s\n", S.ch, T.ch);
    int index = Index(S, T, 0);
    printf("index: %d", index);

    return 0;
}