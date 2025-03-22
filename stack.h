#ifndef STACK_H
#define STACK_H

#include "boolean.h"

typedef struct {
    char nama_makanan[30];
    int harga;
} Makanan;

typedef struct tElmtStack *addressS;
typedef struct tElmtStack {
    Makanan info;
    addressS next;
} ElmtStack;

typedef struct {
    addressS Top;
} Stack;

void CreateStack(Stack *S);
void Push(Stack *S, Makanan X);
void PrintStack(Stack S);

#endif

