#include "IntStack.h"
#include <stdio.h>
#include <stdlib.h>  // calloc(), free()

// �X�^�b�N�̏�����
IntStackResult Initialize(IntStack* s, int max)
{
    s->ptr = 0;
    s->stk = (int*)calloc(max, sizeof(int));
    if (s->stk == nullptr) {
        s->max = 0;
        return INITIALIZE_FAIL;
    }
    s->max = max;
    return SUCCESS;
}

// �X�^�b�N�փf�[�^���v�b�V��
IntStackResult Push(IntStack* s, int x)
{
    if (s->ptr >= s->max) {
        return PUSH_NO_SPACE;
    }
    s->stk[s->ptr++] = x;
    return SUCCESS;
}

// �X�^�b�N����f�[�^���|�b�v
IntStackResult Pop(IntStack* s, int* x)
{
    if (s->ptr <= 0) {
        return POP_NO_DATA;
    }
    *x = s->stk[--s->ptr];
    return SUCCESS;
}

// �X�^�b�N�̃g�b�v�̃f�[�^���s�[�N
IntStackResult Peek(IntStack* s, int* x)
{
    if (s->ptr <= 0) {
        return PEEK_NO_DATA;
    }
    *x = s->stk[s->ptr - 1];
    return SUCCESS;
}

// �X�^�b�N���N���A
void Clear(IntStack* s)
{
    s->ptr = 0;
}

// �X�^�b�N�̗e�ʂ��擾
int Capacity(const IntStack* s)
{
    return s->max;
}

// �X�^�b�N�̃T�C�Y���擾
int Size(const IntStack* s)
{
    return s->ptr;
}

// �X�^�b�N���󂩂ǂ������m�F
bool IsEmpty(const IntStack* s)
{
    return s->ptr <= 0;
}

// �X�^�b�N�����t���ǂ������m�F
bool IsFull(const IntStack* s)
{
    return s->ptr == s->max;
}

// �X�^�b�N���猟��
int Search(const IntStack* s, int x)
{
    for (int i = s->ptr - 1; i >= 0; i--) {
        if (s->stk[i] == x) {
            return i;
        }
    }
    return SEARCH_NOT_FOUND; // -1
}

// �X�^�b�N�̓��e��\��
void Print(const IntStack* s)
{
    for (int i = 0; i < s->ptr; i++) {
        printf("%d ", s->stk[i]);
    }
    putchar('\n');
}

// �X�^�b�N�̌�n��
void Terminate(IntStack* s)
{
    if (s->stk != nullptr) {
        free(s->stk);
        s->stk = nullptr;
    }
    s->max = s->ptr = 0;
}
