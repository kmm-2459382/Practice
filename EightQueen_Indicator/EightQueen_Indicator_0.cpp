//==========================================================
//	8���ܖ��@�\������
//==========================================================
#include <stdio.h> // printf(),scanf()

// �֐��v���g�^�C�v
void set(int column);
void print();

const int FIELD_SIZE = 8;
const int DIAGONAL_SIZE = FIELD_SIZE * 2 - 1; // �ΐ��̃T�C�Y

int pos[FIELD_SIZE];    // �e��̉��܂̈ʒu
bool flag[FIELD_SIZE];  // �e�s�ɉ��܂��z�u�ς�?
bool flag2[DIAGONAL_SIZE];  // �e��΂߂ɉ��܂��z�u�ς�?
bool flag3[DIAGONAL_SIZE];  // �e���΂߂ɉ��܂��z�u�ς�?

int main()
{
    for (int line = 0; line < FIELD_SIZE; line++) {
        flag[line] = false;
    }
    for (int i = 0; i < DIAGONAL_SIZE; i++) {
        flag2[i] = flag3[i] = false;
    }

    set(0);
    return 0;
}

void set(int column)
{
    for (int line = 0; line < FIELD_SIZE; line++) {
        if (!flag[line] && !flag2[column + line] && !flag3[(FIELD_SIZE - 1) - column + line]) {
            pos[column] = line;
            if (column == FIELD_SIZE - 1) {
                print();
            }
            else {
                flag[line] = true;
                flag2[column + line] = true;
                flag3[(FIELD_SIZE - 1) - column + line] = true;
                set(column + 1);
                flag[line] = false;
                flag2[column + line] = false;
                flag3[(FIELD_SIZE - 1) - column + line] = false;
            }
        }
    }
}

void print()
{
    static int solution_count = 0;  // �𓚂̐����J�E���g����ÓI�ϐ�

    printf("�� %d:\n", ++solution_count);
    printf("+---+---+---+---+---+---+---+---+\n");

    for (int row = 0; row < FIELD_SIZE; row++) {
        printf("|");
        for (int col = 0; col < FIELD_SIZE; col++) {
            if (pos[col] == row) {
                printf(" Q |");
            }
            else {
                printf("   |");
            }
        }
        printf("\n+---+---+---+---+---+---+---+---+\n");
    }
    printf("\n");
}