#include "IntStack.h"
#include <stdio.h>
#include <stdlib.h>  // calloc(), free()

// スタックの初期化
IntStackResult Initialize(IntStack* s, int max)
{
    s->ptr = 0;
    s->stk = (int*)calloc(max, sizeof(int));
    if (s->stk == nullptr) {
        s->max = 0;
        return INITIALIZE_FAIL;
    }
    s->max = max;
    return SUCCESS;
}

// スタックへデータをプッシュ
IntStackResult Push(IntStack* s, int x)
{
    if (s->ptr >= s->max) {
        return PUSH_NO_SPACE;
    }
    s->stk[s->ptr++] = x;
    return SUCCESS;
}

// スタックからデータをポップ
IntStackResult Pop(IntStack* s, int* x)
{
    if (s->ptr <= 0) {
        return POP_NO_DATA;
    }
    *x = s->stk[--s->ptr];
    return SUCCESS;
}

// スタックのトップのデータをピーク
IntStackResult Peek(IntStack* s, int* x)
{
    if (s->ptr <= 0) {
        return PEEK_NO_DATA;
    }
    *x = s->stk[s->ptr - 1];
    return SUCCESS;
}

// スタックをクリア
void Clear(IntStack* s)
{
    s->ptr = 0;
}

// スタックの容量を取得
int Capacity(const IntStack* s)
{
    return s->max;
}

// スタックのサイズを取得
int Size(const IntStack* s)
{
    return s->ptr;
}

// スタックが空かどうかを確認
bool IsEmpty(const IntStack* s)
{
    return s->ptr <= 0;
}

// スタックが満杯かどうかを確認
bool IsFull(const IntStack* s)
{
    return s->ptr == s->max;
}

// スタックから検索
int Search(const IntStack* s, int x)
{
    for (int i = s->ptr - 1; i >= 0; i--) {
        if (s->stk[i] == x) {
            return i;
        }
    }
    return SEARCH_NOT_FOUND; // -1
}

// スタックの内容を表示
void Print(const IntStack* s)
{
    for (int i = 0; i < s->ptr; i++) {
        printf("%d ", s->stk[i]);
    }
    putchar('\n');
}

// スタックの後始末
void Terminate(IntStack* s)
{
    if (s->stk != nullptr) {
        free(s->stk);
        s->stk = nullptr;
    }
    s->max = s->ptr = 0;
}
