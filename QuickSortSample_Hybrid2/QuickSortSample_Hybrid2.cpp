//=========================================================
//	�N�C�b�N�\�[�g�@�n�C�u���b�g2
//==========================================================
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>   // printf(),scanf()
#include <stdlib.h>  // srand(),rand()
#include <time.h>    // time()

// �֐��v���g�^�C�v
void qsort(int array[], int arraySize);
void QuickSort(int array[], int left, int right);
int Sort3Element(int array[], int a, int b, int c);
void dumpArray(const int array[], int arraySize);
int getRandRange(int min, int max);
// �����}�N��
#define swap(type,a,b)   do{ type tmp=a; a=b; b=tmp; }while(false)

int main()
{
	srand(time(nullptr));
	int arraySize;
	int* array;

	while (true) {
		do {
			printf("�v�f��:");
			scanf("%d", &arraySize);
		} while (arraySize <= 2);

		array = (int*)calloc(arraySize, sizeof(int));
		if (array == nullptr) {
			printf("calloc()���s\n");
			exit(1);
		}
		for (int i = 0; i < arraySize; i++) {
			array[i] = getRandRange(1, 100);
		}
		dumpArray(array, arraySize);
		qsort(array, arraySize);
		printf("�����Ƀ\�[�g���܂���\n");
		dumpArray(array, arraySize);

		free(array);
	}
	return 0;
}

void qsort(int array[], int arraySize)
{
	QuickSort(array, 0, arraySize - 1);
}

//
// �O��̏C���R�[�f�B���O�����̊֐��Ɏ{���Ă��������B
//
void QuickSort(int array[], int left, int right)
{
	int pl = left;
	int pr = right;
	int m = Sort3Element(array, pl, (pl + pr) / 2, pr);
	int x = array[m];

	do {
		while (array[pl] < x) pl++;
		while (array[pr] > x) pr--;
		if (pl <= pr) {
			swap(int, array[pl], array[pr]);
			pl++;
			pr--;
		}
	} while (pl <= pr);

	// �v�f����10�ȉ��̏ꍇ�͑}���\�[�g
	if (right - left <= 9) {
		for (int i = left + 1; i <= right; i++) {
			int j = i;
			while (j > left && array[j] < array[j - 1]) {
				swap(int, array[j], array[j - 1]);
				j--;
			}
		}
	}
	else {
		if (left < pr) QuickSort(array, left, pr);
		if (pl < right) QuickSort(array, pl, right);
	}
}

int Sort3Element(int array[], int a, int b, int c)
{
	// array[a],array[b],array[c]���o�u���\�[�g���Ă���
	if (array[a] > array[b]) swap(int, array[a], array[b]);
	if (array[b] > array[c]) swap(int, array[b], array[c]);
	if (array[a] > array[b]) swap(int, array[a], array[b]);
	return b;
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
