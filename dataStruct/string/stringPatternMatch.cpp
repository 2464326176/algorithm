//**************************
// Author:  yh
// Time:    2022/2/22
//**************************

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