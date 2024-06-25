//==========================================================
//  ピラミッドを表示する
//==========================================================
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> // printf()

// 関数プロトタイプ
void PrintPyramid(int n);

int main()
{
    while (true) {
        int n;
        char choice;

        do {
            printf("何段のピラミッドですか? ");
            scanf("%d", &n);
        } while (n <= 0);

        PrintPyramid(n);

        printf("もう一度表示しますか？ (y/n): ");
        scanf(" %c", &choice);
        if (choice != 'y' && choice != 'Y') {
            break;
        }
    }
    return 0;
}

void PrintPyramid(int n)
{
    for (int i = 1; i <= n; i++) {
        // Print leading spaces
        for (int j = 1; j <= n - i; j++) {
            printf(" ");
        }
        // Print asterisks
        for (int k = 1; k <= 2 * i - 1; k++) {
            printf("*");
        }
        // Move to the next line
        printf("\n");
    }
}
