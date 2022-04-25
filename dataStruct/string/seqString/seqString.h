//**************************
// Author:  yh
// Time:    2022/2/20
//**************************

#ifndef CESSENCE_SEQSTRING_H
#define CESSENCE_SEQSTRING_H

#include "../../common/dataType.h"

typedef struct HString{
    char *ch;
    int length;
    HString() {
        ch = nullptr;
        length = 0;
    }
} HString;

Status assign(HString &string, char * chars);
int getLength(HString string);
Status compare(HString string, HString targerString);
Status clear(HString &string);
Status concat(HString &string, HString S1, HString S2);
Status subString(HString subString, HString string, int pos, int len);
Status Index(HString S, HString T, int pos);

#endif //CESSENCE_SEQSTRING_H
