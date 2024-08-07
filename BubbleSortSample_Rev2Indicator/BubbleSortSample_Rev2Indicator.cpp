//=========================================================
//	単純交換ソート 第２版 経過表示
//==========================================================
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>   // printf(),scanf()
#include <stdlib.h>  // srand(),rand()
#include <time.h>    // time()
// 関数プロトタイプ
void BubbleSort(int array[], int arraySize);
int getRandRange(int min, int max);
void dumpArray(const int array[], int arraySize);
// 交換マクロ
#define swap(type,a,b)	do{type tmp=a; a=b; b=tmp;}while(false)

int main()
{
	srand(time(nullptr));
	int arraySize;
	int* array;

	while (true) {
		do {
			printf("要素数:");
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
		BubbleSort(array, arraySize);
		printf("昇順にソートしました\n");
		dumpArray(array, arraySize);

		free(array);
	}
	return 0;
}

void BubbleSort(int array[], int arraySize)
{
	int compareCount = 0;
	int swapCount = 0;

	for (int i = 0; i < arraySize - 1; i++) {
		for (int j = arraySize - 1; j > i; j--) {
			compareCount++;
			if (array[j - 1] > array[j]) {
				swap(int, array[j - 1], array[j]);
				swapCount++;
			}
		}
		dumpArray(array, arraySize);  // 配列の経過表示
		printf("比較回数: %d, 交換回数: %d\n", compareCount, swapCount);
	}

	printf("最終結果: 比較回数: %d, 交換回数: %d\n", compareCount, swapCount);
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
