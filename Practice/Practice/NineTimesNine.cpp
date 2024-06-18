//==========================================================
//	‹ã‹ã•\‚ð•\Ž¦‚·‚é
//==========================================================
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> // printf()

int main()
{
  
    printf("    |");
    for (int i = 1; i <= 9; i++) {
        printf(" %3d", i);
    }
    printf("\n----+");
    for (int i = 1; i <= 9; i++) {
        printf("----");
    }
    printf("\n");

   
    for (int i = 1; i <= 9; i++) {
        printf(" %2d |", i);
        for (int j = 1; j <= 9; j++) {
            printf(" %3d", i * j);
        }
        printf("\n");
    }
	return 0;
}