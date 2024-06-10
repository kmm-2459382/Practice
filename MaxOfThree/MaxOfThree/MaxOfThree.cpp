//=====================================================
//  3値の最大値
//=====================================================
#include <stdio.h>
#include <stdlib.h>  // srand(),rand()
#include <time.h>    // time()
//  関数プロトタイプ
int MaxOfThree(int a, int b, int c);

int main()
{
    srand(time(NULL));
    int a = rand() % 100;
    int b = rand() % 100;
    int c = rand() % 100;
    int ans = MaxOfThree(a, b, c);
    printf("MaxOfThree(%d, %d, %d): %d\n", a, b, c, ans);
    return 0;
}

int MaxOfThree(int a, int b, int c)
{
    // ここに3値の最大値を算定するコードを書いてください。

    printf("三つの整数の最大値を求めます。\n");
    printf("aの値 : ");   scanf_s("%d", &a);
    printf("bの値 : ");   scanf_s("%d", &b);
    printf("cの値 : ");   scanf_s("%d", &c);

    int max = a;
    if (b > max) max = b;
    if (c > max) max = c;

    printf("最大値は%dです。\n", max);

    return 0;
}