#pragma once

// スタック操作結果の列挙型
typedef enum {
    SUCCESS,
    INITIALIZE_FAIL,
    PUSH_NO_SPACE,
    POP_NO_DATA,
    PEEK_NO_DATA,
    SEARCH_NOT_FOUND = -1 // 通常は-1
} IntStackResult;

// スタック構造体
typedef struct {
    int max;
    int ptr;
    int* stk;
} IntStack;

IntStackResult Initialize(IntStack* s, int max);
IntStackResult Push(IntStack* s, int x);
IntStackResult Pop(IntStack* s, int* x);
IntStackResult Peek(IntStack* s, int* x);
void Clear(IntStack* s);
int Capacity(const IntStack* s);
int Size(const IntStack* s);
bool IsEmpty(const IntStack* s);
bool IsFull(const IntStack* s);
int Search(const IntStack* s, int x);
void Print(const IntStack* s);
void Terminate(IntStack* s);
