//==========================================================
//  �����`��\������
//==========================================================
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> // printf()

// �֐��v���g�^�C�v
void PrintSquare(int n);

int main()
{
    while (true) {
        int n;
        char choice;

        puts("�����`��\�����܂�");
        printf("�i����: ");
        scanf("%d", &n);

        if (n > 0) {
            PrintSquare(n);
        }
        else {
            printf("�i���͐��̐����łȂ���΂Ȃ�܂���B\n");
            continue;
        }

        printf("������x�\�����܂����H (y/n): ");
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
