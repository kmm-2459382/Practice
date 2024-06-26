//==========================================================
//	三角形を表示する
//==========================================================
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> // printf()
// 関数プロトタイプ
void PrintTriangle(int n);

int main()
{
	while (true) {
		int n;
		do {
			printf("何段の三角形ですか? ");
			scanf("%d", &n);
		} while (n <= 0);
		PrintTriangle(n);
	}
	return 0;
}

void PrintTriangle(int n)
{
	// ここをコーディングしましょう。
	// 教科書のList1-11 を参考にしてください。
	// for文を２重に使います。
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			putchar('*');
		}
		putchar('\n');
	}

}
