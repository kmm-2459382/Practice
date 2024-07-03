//=========================================================
//	�P�������\�[�g Shaker Sort
//==========================================================
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>   // printf(),scanf()
#include <stdlib.h>  // srand(),rand()
#include <time.h>    // time()
// �֐��v���g�^�C�v
void ShakerSort(int array[], int arraySize);
void SortTest(int array[], int arraySize);
int getRandRange(int min, int max);
void dumpArray(const int array[], int arraySize);
// �����}�N��
#define swap(type,a,b)	do{type tmp=a; a=b; b=tmp;}while(false)

int main()
{
	srand(time(nullptr));
	char yesno;
	do {
		printf("�T���v��(y/n)?");
		scanf(" %c", &yesno);
	} while (yesno != 'y' && yesno != 'n');
	if (yesno == 'y') {
		int sample[] = { 9,1,3,4,6,7,8 };
		int sampleSize = sizeof(sample) / sizeof(sample[0]);
		SortTest(sample, sampleSize);
	}
	else {
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
			SortTest(array, arraySize);
			free(array);
		}
	}
	return 0;
}

void SortTest(int array[], int arraySize)
{
	dumpArray(array, arraySize);
	ShakerSort(array, arraySize);
	printf("�����Ƀ\�[�g���܂���\n");
	dumpArray(array, arraySize);
}

void ShakerSort(int array[], int arraySize)
{
	int compareCount = 0;
	int swapCount = 0;
	int left = 0;
	int right = arraySize - 1;
	int pass = 1;

	while (left < right) {
		printf("�p�X %d:\n", pass);
		printf("  L                             R\n");

		for (int i = left; i < right; i++) {
			compareCount++;
			if (array[i] > array[i + 1]) {
				swap(int, array[i], array[i + 1]);
				swapCount++;
			}
			for (int j = left; j <= right; j++) {
				if (j == i) {
					printf("%3d + ", array[j]);
				}
				else {
					printf("%3d   ", array[j]);
				}
			}
			printf("\n");
		}
		right--;

		printf("��r��: %d, ������: %d\n", compareCount, swapCount);
		pass++;

		if (left >= right) {
			break;
		}

		printf("�p�X %d:\n", pass);
		printf("       L                        R\n");

		for (int i = right; i > left; i--) {
			compareCount++;
			if (array[i - 1] > array[i]) {
				swap(int, array[i - 1], array[i]);
				swapCount++;
			}
			for (int j = left; j <= right; j++) {
				if (j == i - 1 || j == i) {
					printf("%3d + ", array[j]);
				}
				else {
					printf("%3d   ", array[j]);
				}
			}
			printf("\n");
		}
		left++;

		printf("��r��: %d, ������: %d\n", compareCount, swapCount);
		pass++;
	}

	printf("�ŏI����: ��r��: %d, ������: %d\n", compareCount, swapCount);
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
