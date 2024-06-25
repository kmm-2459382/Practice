//==========================================================
//  ピラミッドを表示する 倒置
//==========================================================
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> // printf()

// 関数プロトタイプ
void PrintPyramid_UpsideDown(int n);

int main()
{
    while (true) {
        int n;
        do {
            printf("何段のピラミッドですか? ");
            scanf("%d", &n);
        } while (n <= 0);
        PrintPyramid_UpsideDown(n);

        char choice;
        printf("もう一度表示しますか？ (y/n): ");
        scanf(" %c", &choice);
        if (choice != 'y' && choice != 'Y') {
            break;
        }
    }
    return 0;
}

void PrintPyramid_UpsideDown(int n)
{
    for (int i = n; i >= 1; i--) {
        // Print leading spaces
        for (int j = 0; j < n - i; j++) {
            printf(" ");
        }
        // Print asterisks
        for (int k = 0; k < 2 * i - 1; k++) {
            printf("*");
        }
        // Move to the next line
        printf("\n");
    }
}
