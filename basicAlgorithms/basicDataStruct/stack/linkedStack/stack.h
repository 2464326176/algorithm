//**************************
// Author:  yh
// Time:    2022/1/31
//**************************

#ifndef CESSENCE_STACK_H
#define CESSENCE_STACK_H
#include "../common/dataType.h"
#define STACK_INIT_SIZE 100;
#define STACK_INCREMENT 10

typedef int ElemType;

typedef struct {
  ElemType *base;
  ElemType *top;
  int size;
} SqStack;

Status initStack(SqStack &stack);
Status destroyStack(SqStack &stack);
Status clearStack(SqStack &stack);
bool isStackEmpty(SqStack &stack);
Status getStackLenth(SqStack &stack);
Status getTop(SqStack &stack, ElemType &elem);
Status pushStack(SqStack &stack, ElemType elem);
Status popStack(SqStack &stack, ElemType &elem);
Status traverseStack(SqStack &stack);

#endif //CESSENCE_STACK_H
