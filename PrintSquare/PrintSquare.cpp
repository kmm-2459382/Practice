//==========================================================
//  正方形を表示する
//==========================================================
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> // printf()

// 関数プロトタイプ
void PrintSquare(int n);

int main()
{
    while (true) {
        int n;
        char choice;

        puts("正方形を表示します");
        printf("段数は: ");
        scanf("%d", &n);

        if (n > 0) {
            PrintSquare(n);
        }
        else {
            printf("段数は正の整数でなければなりません。\n");
            continue;
        }

        printf("もう一度表示しますか？ (y/n): ");
        scanf(" %c", &choice);
        if (choice != 'y' && choice != 'Y') {
            break;
        }
    }
    return 0;
}

void PrintSquare(int n)
{
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("* ");
        }
        printf("\n");
    }
}
