//==========================================================
//	ÇQï™íTçıñÿ
//==========================================================
#include "BinaryTree.h"
#include <stdio.h>   // printf(),puts()
#include <stdlib.h>  // calloc(),free()

// ä÷êîÉvÉçÉgÉ^ÉCÉv
static BinNode* allocBinNode(void);
static void setBinNode(BinNode* node, const Member* x, const BinNode* left, const BinNode* right);

// íTçı
BinNode* Search(BinNode* p, const Member* x)
{
	if (p == nullptr) {
		return nullptr;
	}
	int cond = MemberNoCmp(x, &p->data);
	if (cond == 0) {
		return p;
	}
	else if (cond < 0) {
		return Search(p->left, x);
	}
	else { // cond>0
		return Search(p->right, x);
	}
}
// ÉmÅ[ÉhÇÃë}ì¸
BinNode* Add(BinNode* p, const Member* x)
{
	if (p == nullptr) {
		p = allocBinNode();
		setBinNode(p, x, nullptr, nullptr);
		return p;
	}
	int cond = MemberNoCmp(x, &p->data);
	if (cond == 0) {
		printf("ÅyÉGÉâÅ[Åz%dÇÕä˘Ç…ìoò^Ç≥ÇÍÇƒÇ¢Ç‹Ç∑\n", x->no);
	}
	else if (cond < 0) {
		p->left = Add(p->left, x);
	}
	else {
		p->right = Add(p->right, x);
	}
	return p;
}
// ÉmÅ[ÉhÇÃçÌèú
bool Remove(BinNode** root, const Member* x)
{
	BinNode* next, * temp;
	BinNode** left;
	BinNode** p = root;

	while (true) {
		int cond;
		if (*p == nullptr) {
			printf("ÅyÉGÉâÅ[Åz%dÇÕìoò^Ç≥ÇÍÇƒÇ¢Ç‹ÇπÇÒ\n", x->no);
			return false;
		}
		cond = MemberNoCmp(x, &(*p)->data);
		if (cond == 0) {
			break;
		}
		else if (cond < 0) {
			p = &(*p)->left;
		}
		else {
			p = &(*p)->right;
		}
	}
	if ((*p)->left == nullptr) {
		next = (*p)->right;
	}
	else {
		left = &(*p)->left;
		while ((*left)->right != nullptr) {
			left = &(*left)->right;
		}
		next = *left;
		*left = (*left)->left;
		next->left = (*p)->left;
		next->right = (*p)->right;
	}
	temp = *p;
	*p = next;
	free(temp);

	return true;
}
// ëSÉmÅ[ÉhÇÃï\é¶
void PrintTree(const BinNode* p)
{
	if (p != nullptr) {
		PrintTree(p->left);
		PrintLnMember(&p->data);
		PrintTree(p->right);
	}
}
// ëSÉmÅ[ÉhÇÃçÌèú
void FreeTree(BinNode* p)
{
	if (p != nullptr) {
		FreeTree(p->left);
		FreeTree(p->right);
		free(p);
	}
}
// ç≈è¨ílÉmÅ[ÉhÇéÊìæ
BinNode* GetMinNode(const BinNode* p)
{
	if (p == nullptr) {
		return nullptr;
	}
	while (p->left != nullptr) {
		p = p->left;
	}
	return (BinNode*)p;
}

// ç≈ëÂílÉmÅ[ÉhÇéÊìæ
BinNode* GetMaxNode(const BinNode* p)
{
	if (p == nullptr) {
		return nullptr;
	}
	while (p->right != nullptr) {
		p = p->right;
	}
	return (BinNode*)p;
}

// ÉmÅ[ÉhÇìÆìIÇ…ämï€
static BinNode* allocBinNode(void)
{
	BinNode* node = (BinNode*)calloc(1, sizeof(BinNode));
	if (node == nullptr) {
		printf("callocé∏îs");
		exit(1);
	}
	return node;
}
// ÉmÅ[ÉhÇÃÉÅÉìÉoÅ[ê›íË
static void setBinNode(BinNode* node, const Member* x, const BinNode* left, const BinNode* right)
{
	node->data = *x;
	node->left = (BinNode*)left;
	node->right = (BinNode*)right;
}
