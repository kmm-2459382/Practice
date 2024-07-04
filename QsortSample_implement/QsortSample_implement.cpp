#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>   // printf(), scanf()
#include <stdlib.h>  // srand(), rand(), calloc(), free()
#include <time.h>    // time()
#include <stdint.h>  // intptr_t

// 関数プロトタイプ
void q_sort(void* base, size_t nmemb, size_t size, int (*compar)(const void*, const void*));
void* getAdrs(void* base, size_t size, int idx);
void swapMem(void* base, size_t size, int idx1, int idx2);
int CompareInt(const int* a, const int* b);
void dumpArray(const int array[], int arraySize);
int getRandRange(int min, int max);

typedef struct {
    int left;
    int right;
} StackFrame;

int main()
{
    srand((unsigned)time(nullptr));  // srandの引数を明示的にキャスト
    int arraySize;
    int* array;

    while (true) {
        do {
            printf("要素数: ");
            scanf("%d", &arraySize);
        } while (arraySize <= 2);

        array = (int*)calloc(arraySize, sizeof(int));
        if (array == nullptr) {
            printf("calloc()失敗\n");
            exit(1);
        }
        for (int i = 0; i < arraySize; i++) {
            array[i] = getRandRange(1, 100);
        }
        dumpArray(array, arraySize);

        q_sort(array, arraySize, sizeof(array[0]), (int(*)(const void*, const void*))CompareInt);

        printf("昇順にソートしました\n");
        dumpArray(array, arraySize);

        free(array);
    }
    return 0;
}

// 非再帰的なクイックソートの実装
void q_sort(void* base, size_t nmemb, size_t size, int (*compare)(const void*, const void*))
{
    if (nmemb <= 1) return;

    StackFrame stack[128];  // 適切なサイズのスタックを用意
    int stackIndex = 0;

    stack[stackIndex].left = 0;
    stack[stackIndex].right = (int)(nmemb - 1);
    stackIndex++;

    while (stackIndex > 0) {
        stackIndex--;
        int left = stack[stackIndex].left;
        int right = stack[stackIndex].right;

        if (left >= right) continue;

        int pivotIdx = (left + right) / 2;
        void* pivot = getAdrs(base, size, pivotIdx);

        int i = left;
        int j = right;

        while (i <= j) {
            while (compare(getAdrs(base, size, i), pivot) < 0) i++;
            while (compare(getAdrs(base, size, j), pivot) > 0) j--;

            if (i <= j) {
                swapMem(base, size, i, j);
                i++;
                j--;
            }
        }

        // 小さいサイズの部分配列をスタックにプッシュ
        if (j - left > right - i) {
            stack[stackIndex].left = left;
            stack[stackIndex].right = j;
            stackIndex++;
            stack[stackIndex].left = i;
            stack[stackIndex].right = right;
            stackIndex++;
        }
        else {
            stack[stackIndex].left = i;
            stack[stackIndex].right = right;
            stackIndex++;
            stack[stackIndex].left = left;
            stack[stackIndex].right = j;
            stackIndex++;
        }
    }
}

// メモリブロックを交換する関数
void swapMem(void* base, size_t size, int idx1, int idx2)
{
    char temp;
    char* adr1 = (char*)getAdrs(base, size, idx1);
    char* adr2 = (char*)getAdrs(base, size, idx2);
    for (size_t i = 0; i < size; i++) {
        temp = *adr1;
        *adr1 = *adr2;
        *adr2 = temp;
        adr1++, adr2++;
    }
}

// 配列のインデックスのアドレスを取得する関数
void* getAdrs(void* base, size_t size, int idx)
{
    intptr_t adrs = (intptr_t)base + idx * size;
    return (void*)adrs;
}

// int型の比較関数
int CompareInt(const int* a, const int* b)
{
    return *a - *b;
}

// 配列を表示する関数
void dumpArray(const int array[], int arraySize)
{
    for (int i = 0; i < arraySize; i++) {
        printf("array[%d] = %d\n", i, array[i]);
    }
}

// ランダムな整数を取得する関数
int getRandRange(int min, int max)
{
    int wid = max - min + 1;
    return min + rand() % wid;
}
