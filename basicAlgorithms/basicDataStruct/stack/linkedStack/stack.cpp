//**************************
// Author:  yh
// Time:    2022/1/30
//**************************
#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

Status initStack(SqStack &stack) {
    stack.base = (ElemType *) malloc(sizeof(ElemType));
    if (!stack.base) {
        exit(OVERFLOW);
    }

    stack.top = stack.base;
    stack.size = STACK_INIT_SIZE;
    return EXIT_SUCCESS;
}

Status destroyStack(SqStack &stack) {
    ElemType *p = stack.base;

    while (p != stack.top) {
        ElemType *tmpStackNode = p;
        ++p;
        free(tmpStackNode);
        tmpStackNode = nullptr;
    }

    if (p) {
        free(p);
    }

    stack.base = nullptr;
    stack.top = nullptr;
    stack.size = 0;
    return EXIT_SUCCESS;
}

Status clearStack(SqStack &stack) {
    ElemType *p = ++stack.base;

    while (p != stack.top) {
        ElemType *tmpStackNode = p;
        ++p;
        free(tmpStackNode);
        tmpStackNode = nullptr;
    }

    stack.top = stack.base;
    stack.size = 0;
    return EXIT_SUCCESS;
}

bool isStackEmpty(SqStack &stack) {
    if (stack.base == stack.top) {
        return true;
    }

    return false;
}

Status getStackLength(SqStack &stack) {
    ElemType *p = stack.base;
    int length = 0;
    while (p != stack.top) {
        ++p;
        ++length;
    }

    return length;
}

Status getTop(SqStack &stack, ElemType &elem) {
    if (stack.top == stack.base) {
        return EXIT_FAILURE;
    }

    elem = *(stack.top - 1);
    return EXIT_SUCCESS;

}

Status pushStack(SqStack &stack, ElemType elem) {
    if (stack.top - stack.base >= stack.size) {
        stack.base = (ElemType *) realloc(stack.base, (stack.size + STACK_INCREMENT) * sizeof(ElemType));
        if (!stack.base) {
            exit(ERROR);
        }

        stack.top = stack.base + stack.size;
        stack.size = stack.size + STACK_INCREMENT;
    }

    *stack.top++ = elem;
    return EXIT_SUCCESS;
}

Status popStack(SqStack &stack, ElemType &elem) {
    if (stack.top == stack.base) {
        exit(ERROR);
    }

    elem = *--stack.top;
    return EXIT_SUCCESS;
}

Status traverseStack(SqStack &stack) {
    if (!stack.base) {
        exit(ERROR);
    }

    ElemType *p = stack.base;

    while (p != stack.top) {
        printf("%d ", *p);
        ++p;
    }

    printf("\n");
    return EXIT_SUCCESS;
}