//==========================================================
//  �����`��\������
//==========================================================
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> // printf()

// �֐��v���g�^�C�v
void PrintRectangle(int w, int h);

int main()
{
    while (true) {
        int h, w;
        char choice;

        puts("�����`��\�����܂�");
        do {
            printf("������: ");
            scanf("%d", &h);
        } while (h <= 0);

        do {
            printf("������: ");
            scanf("%d", &w);
        } while (w <= 0);

        PrintRectangle(w, h);

        printf("������x�\�����܂����H (y/n): ");
        scanf(" %c", &choice);
        if (choice != 'y' && choice != 'Y') {
            break;
        }
    }
    return 0;
}

void PrintRectangle(int w, int h)
{
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            printf("* ");
        }
        printf("\n");
    }
}
