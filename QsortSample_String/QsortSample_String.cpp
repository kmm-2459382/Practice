//=========================================================
//	qsort�T���v�� ������
//==========================================================
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>   // printf(),scanf()
#include <stdlib.h>  // srand(),rand(),qsort()
#include <string.h>  // strcmp()

// �֐��v���g�^�C�v
int CompareString(const char a[], const char b[]);
int CompareStringPointer(const char** a, const char** b);

int main()
{
	//  
	//  a[]�̃������[�@�@�@�@�@�@p[]�̃������[
	//  +--+--+--+--+--+--+--+   +------------+
	//  |L |I |S |P |\0|. |. |   |�|�C���^�[a |   => "LISP"
	//  |C |\0|. |. |. |. |. |   |�|�C���^�[b |   => "C"
	//  |A |d |a |\0|. |. |. |   |�|�C���^�[c |   => "Ada"
	//  |P |a |s |c |a |l |\0|   |�|�C���^�[d |   => "Pascal"
	//  <----- 7 byte ------->   <--4or8byte-->
	//
	char a[][7] = { "LISP","C","Ada","Pascal" };
	const char* p[] = { "LISP","C","Ada","Pascal" };

	int aSize = sizeof(a) / sizeof(a[0]);
	int pSize = sizeof(p) / sizeof(p[0]);
	//
	// �ȉ���xxxxx�̕����𖄂߂Ă��������B
	//
	qsort(
		a,               // �z��
		aSize,               // �z��̗v�f��
		sizeof(a[0]),       // �v�f�̃T�C�Y
		(int(*)(const void*, const void*))CompareString // ��r�֐�
	);
	qsort(
		(void*)p,                // �z��
		pSize,                // �z��̗v�f��
		sizeof(p[0]),       // �v�f�̃T�C�Y
		(int(*)(const void*, const void*))CompareStringPointer // ��r�֐�
	);
	printf("�����Ƀ\�[�g���܂���\n");

	printf("a[]:");
	for (int i = 0; i < aSize; i++) {
		printf("%s ", a[i]);
	}
	putchar('\n');

	printf("p[]:");
	for (int i = 0; i < pSize; i++) {
		printf("%s ", p[i]);
	}
	putchar('\n');
	return 0;
}

int CompareString(const char a[], const char b[])
{
	// ���̕������R�[�f�B���O���Ă�������
	// strcmp()���g���܂�
	return strcmp(a, b);
}

int CompareStringPointer(const char** a, const char** b)
{
	// ���̕������R�[�f�B���O���Ă�������
	// strcmp()���g���܂�
	return strcmp(*a, *b);
}
