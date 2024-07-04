#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>   // printf(), scanf()
#include <stdlib.h>  // srand(), rand()
#include <time.h>    // time()
#include <memory.h>  // memcpy() 
#include "IntStack.h" // IntStackヘッダーをインクルード

// 関数プロトタイプ
void QuickSort_Recursive(int array[], int left, int right);
void QuickSort_NotRecursive(int array[], int left, int right);
void dumpArray(const int array[], int arraySize);
int getRandRange(int min, int max);

// 交換マクロ
#define swap(type, a, b)   do{ type tmp=a; a=b; b=tmp; }while(false)

int main()
{
    srand(time(nullptr));
    int arraySize;
    int* array;
    int* array2;

    while (true) {
        do {
            printf("要素数:");
            scanf("%d", &arraySize);
        } while (arraySize <= 2);

        array = (int*)calloc(arraySize, sizeof(int));
        array2 = (int*)calloc(arraySize, sizeof(int));
        if (array == nullptr || array2 == nullptr) {
            printf("calloc()失敗\n");
            exit(1);
        }
        for (int i = 0; i < arraySize; i++) {
            array[i] = array2[i] = getRandRange(1, 100);
        }

        dumpArray(array, arraySize);
        QuickSort_Recursive(array, 0, arraySize - 1);
        QuickSort_NotRecursive(array2, 0, arraySize - 1);
        printf("昇順にソートしました\n");
        dumpArray(array2, arraySize);

        free(array2);
        free(array);
    }
    return 0;
}

// 再帰的クイックソート
// 要素数が小さいグループを優先的に分割するようにする
void QuickSort_Recursive(int array[], int left, int right)
{
    int pl = left;
    int pr = right;
    int x = array[(left + right) / 2];

    do {
        while (array[pl] < x) pl++;
        while (array[pr] > x) pr--;
        if (pl <= pr) {
            swap(int, array[pl], array[pr]);
            pl++;
            pr--;
        }
    } while (pl <= pr);
    if (left < pr) QuickSort_Recursive(array, left, pr);
    if (pl < right) QuickSort_Recursive(array, pl, right);
}

// 非再帰的クイックソート
// 要素数が小さいグループを優先的に分割するようにする
void QuickSort_NotRecursive(int array[], int left, int right)
{
    IntStack stk;
    Initialize(&stk, right - left + 1);

    Push(&stk, left);
    Push(&stk, right);
    while (IsEmpty(&stk) == false) {
        Pop(&stk, &right);
        Pop(&stk, &left);
        int pl = left;
        int pr = right;
        int x = array[(left + right) / 2];
        do {
            while (array[pl] < x) pl++;
            while (array[pr] > x) pr--;
            if (pl <= pr) {
                swap(int, array[pl], array[pr]);
                pl++;
                pr--;
            }
        } while (pl <= pr);
        if ((pr - left) > (right - pl)) {
            if (left < pr) {
                Push(&stk, left);
                Push(&stk, pr);
            }
            if (pl < right) {
                Push(&stk, pl);
                Push(&stk, right);
            }
        }
        else {
            if (pl < right) {
                Push(&stk, pl);
                Push(&stk, right);
            }
            if (left < pr) {
                Push(&stk, left);
                Push(&stk, pr);
            }
        }
    }
    Terminate(&stk);
}

void dumpArray(const int array[], int arraySize)
{
    for (int i = 0; i < arraySize; i++) {
        printf("array[%d] = %d\n", i, array[i]);
    }
}

int getRandRange(int min, int max)
{
    int wid = max - min + 1;
    return min + rand() % wid;
}
