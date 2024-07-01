//=========================================================
//	単純交換ソート 経過表示
//==========================================================
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>   // printf(), scanf()
#include <stdlib.h>  // srand(), rand()
#include <time.h>    // time()

// 関数プロトタイプ
void BubbleSort(int array[], int arraySize);
int getRandRange(int min, int max);
void dumpArray(const int array[], int arraySize);
void dumpArrayWithMarks(const int array[], int arraySize, int idx1, int idx2, char mark1, char mark2);

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

// 比較回数と交換回数を表示するように修正
void BubbleSort(int array[], int arraySize)
{
	int comparisons = 0;
	int swaps = 0;
	for (int i = 0; i < arraySize - 1; i++) {
		printf("パス %d:\n", i + 1);
		for (int j = arraySize - 1; j > i; j--) {
			comparisons++;
			if (array[j - 1] > array[j]) {
				swap(int, array[j - 1], array[j]);
				swaps++;
				dumpArrayWithMarks(array, arraySize, j - 1, j, '+', ' '); // 交換を表示
			}
			else {
				dumpArrayWithMarks(array, arraySize, j - 1, j, '-', ' '); // 比較を表示
			}
		}
	}
	printf("比較は %d 回でした\n", comparisons);
	printf("交換は %d 回でした\n", swaps);
}

void dumpArray(const int array[], int arraySize)
{
	for (int i = 0; i < arraySize; i++) {
		printf("array[%d] = %d\n", i, array[i]);
	}
}

void dumpArrayWithMarks(const int array[], int arraySize, int idx1, int idx2, char mark1, char mark2)
{
	for (int i = 0; i < arraySize; i++) {
		if (i == idx1) {
			printf("%3d%c", array[i], mark1);
		}
		else if (i == idx2) {
			printf("%3d%c", array[i], mark2);
		}
		else {
			printf("%3d   ", array[i]);
		}
	}
	printf("\n");
}

int getRandRange(int min, int max)
{
	int wid = max - min + 1;
	return min + rand() % wid;
}
