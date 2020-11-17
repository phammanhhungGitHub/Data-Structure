#ifndef BSTNODE_H
#define BSTNODE_H

#include<iostream>

class BSTNode
{
public:
	int data;
	BSTNode* left;
	BSTNode* right;
	BSTNode(int data = 0);
	~BSTNode();
};
#endif // !BSTNODE_H
