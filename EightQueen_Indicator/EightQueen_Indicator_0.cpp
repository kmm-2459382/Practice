//==========================================================
//	8王妃問題　表示改良
//==========================================================
#include <stdio.h> // printf(),scanf()

// 関数プロトタイプ
void set(int column);
void print();

const int FIELD_SIZE = 8;
const int DIAGONAL_SIZE = FIELD_SIZE * 2 - 1; // 斜線のサイズ

int pos[FIELD_SIZE];    // 各列の王妃の位置
bool flag[FIELD_SIZE];  // 各行に王妃が配置済か?
bool flag2[DIAGONAL_SIZE];  // 各上斜めに王妃が配置済か?
bool flag3[DIAGONAL_SIZE];  // 各下斜めに王妃が配置済か?

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
    static int solution_count = 0;  // 解答の数をカウントする静的変数

    printf("解答 %d:\n", ++solution_count);
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