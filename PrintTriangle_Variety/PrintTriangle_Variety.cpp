//==========================================================
//  三角形を表示する バラエティ
//==========================================================
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> // printf()

// 関数プロトタイプ
void PrintTriangleLB(int n);
void PrintTriangleLU(int n);
void PrintTriangleRU(int n);
void PrintTriangleRB(int n);

int main()
{
    while (true) {
        int n;
        do {
            printf("何段の三角形ですか? ");
            scanf("%d", &n);
        } while (n <= 0);
        PrintTriangleLB(n); printf("\n");
        PrintTriangleLU(n); printf("\n");
        PrintTriangleRU(n); printf("\n");
        PrintTriangleRB(n); printf("\n");

        char choice;
        printf("もう一度表示しますか？ (y/n): ");
        scanf(" %c", &choice);
        if (choice != 'y' && choice != 'Y') {
            break;
        }
    }
    return 0;
}

void PrintTriangleLB(int n)
{
    // 左下側が直角の２等辺三角形
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            printf("*");
        }
        printf("\n");
    }
}

void PrintTriangleLU(int n)
{
    // 左上側が直角の２等辺三角形
    for (int i = n; i >= 1; i--) {
        for (int j = 1; j <= i; j++) {
            printf("*");
        }
        printf("\n");
    }
}

void PrintTriangleRU(int n)
{
    // 右上側が直角の２等辺三角形
    for (int i = n; i >= 1; i--) {
        for (int j = 1; j <= n - i; j++) {
            printf(" ");
        }
        for (int k = 1; k <= i; k++) {
            printf("*");
        }
        printf("\n");
    }
}

void PrintTriangleRB(int n)
{
    // 右下側が直角の２等辺三角形
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n - i; j++) {
            printf(" ");
        }
        for (int k = 1; k <= i; k++) {
            printf("*");
        }
        printf("\n");
    }
}
