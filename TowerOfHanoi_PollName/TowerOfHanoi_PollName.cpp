//=========================================================
//	ハノイの塔　解法
//==========================================================
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>   // printf(),scanf()

typedef enum {
    A = 1,
    B = 2,
    C = 3,
} POS;

// 軸名を表示する関数
const char* pos_to_string(POS pos) {
    switch (pos) {
    case A:
        return "A軸";
    case B:
        return "B軸";
    case C:
        return "C軸";
    default:
        return "Unknown";
    }
}

// 関数プロトタイプ
void move(int no, POS from, POS to);

int main()
{
    while (true) {
        int n;
        do {
            printf("ハノイの塔\a円盤の数:");
            scanf("%d", &n);
        } while (n < 1);

        move(n, A, C);
    }
    return 0;
}

void move(int no, POS from, POS to)
{
    POS tmp = (POS)((A + B + C) - from - to);
    if (no > 1) {
        move(no - 1, from, tmp);
    }
    printf("円盤[%d]を %s から %s へ移動\n", no, pos_to_string(from), pos_to_string(to));
    if (no > 1) {
        move(no - 1, tmp, to);
    }
}