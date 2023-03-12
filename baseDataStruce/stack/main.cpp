//**************************
// Author:  yh
// Time:    2022/2/17
//**************************

#include <iostream>
#include "linkedStack/stack.h"

int main() {
    SqStack st;
    int value = 0;

    initStack(st);

    pushStack(st, 5);
    pushStack(st, 8);
    pushStack(st, 3);
    pushStack(st, 2);
    traverseStack(st);

    popStack(st, value);
    traverseStack(st);

    clearStack(st);
    traverseStack(st);

    destroyStack(st);
    traverseStack(st);

    return 0;
}

