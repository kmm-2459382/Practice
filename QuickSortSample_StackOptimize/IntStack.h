#pragma once
#ifndef __IntStack
#define __IntStack

typedef struct {
    int max;  // スタックの容量
    int ptr;  // スタックのポインター
    int* stk; // スタック本体
} IntStack;

typedef enum {
    SUCCESS = 0,
    INITIALIZE_FAIL = 1,
    PUSH_NO_SPACE = 2,
    POP_NO_DATA = 3,
    PEEK_NO_DATA = 4,
} IntStackResult;

#define SEARCH_NOT_FOUND (-1)

// スタックの初期化
IntStackResult Initialize(IntStack* s, int max);
// スタックへデータをプッシュ
IntStackResult Push(IntStack* s, int x);
// スタックからデータをポップ
IntStackResult Pop(IntStack* s, int* x);
// スタックのトップのデータをピーク
IntStackResult Peek(IntStack* s, int* x);
// スタックをクリア
void Clear(IntStack* s);
// スタックの容量を取得
int Capacity(const IntStack* s);
// スタックのサイズを取得
int Size(const IntStack* s);
// スタックが空かどうかを確認
bool IsEmpty(const IntStack* s);
// スタックが満杯かどうかを確認
bool IsFull(const IntStack* s);
// スタックから検索
int Search(const IntStack* s, int x);
// スタックの内容を表示
void Print(const IntStack* s);
// スタックの後始末
void Terminate(IntStack* s);

#endif // __IntStack
