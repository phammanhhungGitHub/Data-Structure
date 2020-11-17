#include "BSTNode.h"

BSTNode::BSTNode(int data)
{
	this->data = data;
	left = nullptr;
	right = nullptr;
}

BSTNode::~BSTNode()
{
	delete left;
	delete right;
	std::cout << "Delete Node " << data << '\n';
}
