//==========================================================
//  �O�p�`��\������ �o���G�e�B
//==========================================================
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> // printf()

// �֐��v���g�^�C�v
void PrintTriangleLB(int n);
void PrintTriangleLU(int n);
void PrintTriangleRU(int n);
void PrintTriangleRB(int n);

int main()
{
    while (true) {
        int n;
        do {
            printf("���i�̎O�p�`�ł���? ");
            scanf("%d", &n);
        } while (n <= 0);
        PrintTriangleLB(n); printf("\n");
        PrintTriangleLU(n); printf("\n");
        PrintTriangleRU(n); printf("\n");
        PrintTriangleRB(n); printf("\n");

        char choice;
        printf("������x�\�����܂����H (y/n): ");
        scanf(" %c", &choice);
        if (choice != 'y' && choice != 'Y') {
            break;
        }
    }
    return 0;
}

void PrintTriangleLB(int n)
{
    // �����������p�̂Q���ӎO�p�`
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            printf("*");
        }
        printf("\n");
    }
}

void PrintTriangleLU(int n)
{
    // ���㑤�����p�̂Q���ӎO�p�`
    for (int i = n; i >= 1; i--) {
        for (int j = 1; j <= i; j++) {
            printf("*");
        }
        printf("\n");
    }
}

void PrintTriangleRU(int n)
{
    // �E�㑤�����p�̂Q���ӎO�p�`
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
    // �E���������p�̂Q���ӎO�p�`
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
