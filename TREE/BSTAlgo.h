#ifndef BSTALGO_H
#define BSTALGO_H

#include"BSTNode.h"
#include<queue>

void Add(BSTNode*& root, int data);
bool IsContain(BSTNode* root, int data);
int Min(BSTNode* root);
BSTNode* NodeMin(BSTNode* root);
BSTNode* NodeMax(BSTNode* root);
int Max(BSTNode* root);
int Height(BSTNode* root);
BSTNode* DeleteNode(BSTNode* root, int value);
void LevelOrder(BSTNode* root);
void PreOrder(BSTNode* root);
void InOrder(BSTNode* root);
void PostOrder(BSTNode* root);
BSTNode* InOrderSuccessor(BSTNode* root, int data);
BSTNode* InOrderSuccessor2(BSTNode* root, int data);

#endif // !BSTALGO_H
