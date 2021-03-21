#ifndef __BINARY_TREE3_H__
#define __BINARY_TREE3_H__

typedef int BTData;

typedef struct _bTreeNode
{
	BTData data;
	struct _bTreeNode* left;
	struct _bTreeNode* right;
} BTreeNode;

BTreeNode* MakeBTreeNode(void);
BTData GetData(BTreeNode* bt);
void SetData(BTreeNode* bt, BTData data);

BTreeNode* GetLeftSubTree(BTreeNode* bt); // return left (sub tree) address
BTreeNode* GetRightSubTree(BTreeNode* bt); // return right address 

void MakeLeftSubTree(BTreeNode* main,BTreeNode* sub);
void MakeRightSubTree(BTreeNode* main,BTreeNode* sub);

// not using memory free
void ChangeLeftSubTree(BTreeNode* main,BTreeNode* sub);
void ChangeRightSubTree(BTreeNode* main, BTreeNode* sub);

//delete child node and return child pointer (not memory free)
BTreeNode* RemoveLeftSubTree(BTreeNode* bt);
BTreeNode* RemoveRightSubTree(BTreeNode* bt);

typedef void (*VisitFuncPtr)(BTData data);

void PreorderTraverse(BTreeNode* bt,VisitFuncPtr action);
void InorderTraverse(BTreeNode* bt,VisitFuncPtr action);
void PostorderTraverse(BTreeNode* bt,VisitFuncPtr action);

void DeleteTree(BTreeNode* bt);

#endif