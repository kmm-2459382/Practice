#pragma once
#ifndef __IntStack
#define __IntStack

typedef struct {
    int max;  // �X�^�b�N�̗e��
    int ptr;  // �X�^�b�N�̃|�C���^�[
    int* stk; // �X�^�b�N�{��
} IntStack;

typedef enum {
    SUCCESS = 0,
    INITIALIZE_FAIL = 1,
    PUSH_NO_SPACE = 2,
    POP_NO_DATA = 3,
    PEEK_NO_DATA = 4,
} IntStackResult;

#define SEARCH_NOT_FOUND (-1)

// �X�^�b�N�̏�����
IntStackResult Initialize(IntStack* s, int max);
// �X�^�b�N�փf�[�^���v�b�V��
IntStackResult Push(IntStack* s, int x);
// �X�^�b�N����f�[�^���|�b�v
IntStackResult Pop(IntStack* s, int* x);
// �X�^�b�N�̃g�b�v�̃f�[�^���s�[�N
IntStackResult Peek(IntStack* s, int* x);
// �X�^�b�N���N���A
void Clear(IntStack* s);
// �X�^�b�N�̗e�ʂ��擾
int Capacity(const IntStack* s);
// �X�^�b�N�̃T�C�Y���擾
int Size(const IntStack* s);
// �X�^�b�N���󂩂ǂ������m�F
bool IsEmpty(const IntStack* s);
// �X�^�b�N�����t���ǂ������m�F
bool IsFull(const IntStack* s);
// �X�^�b�N���猟��
int Search(const IntStack* s, int x);
// �X�^�b�N�̓��e��\��
void Print(const IntStack* s);
// �X�^�b�N�̌�n��
void Terminate(IntStack* s);

#endif // __IntStack
