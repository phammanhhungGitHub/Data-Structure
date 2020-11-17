#include "BSTAlgo.h"

void Add(BSTNode*& root, int data)
{
	if (root == nullptr)
	{
		BSTNode* newNode = new BSTNode(data);
		root = newNode;
		return;
	}
	else if (data <= root->data)
	{
		Add(root->left, data);
	}
	else
	{
		Add(root->right, data);
	}
}

bool IsContain(BSTNode* root, int data)
{
	if (root == nullptr)
	{
		return false;
	}
	else if (root->data == data)
	{
		return true;
	}
	else if (data <= root->data)
	{
		return IsContain(root->left, data);
	}
	else
	{
		return IsContain(root->right, data);
	}
}

int Min(BSTNode* root)
{
	if (root == nullptr)
	{
		return 0;
	}
	else if (root->left == nullptr)
	{
		return root->data;
	}
	
	return Min(root->left);
}

BSTNode* NodeMin(BSTNode* root)
{
	if (root == nullptr || root->left == nullptr)
		return root;
	else
		return NodeMin(root->left);
}

BSTNode* NodeMax(BSTNode* root)
{
	if (root == nullptr || root->right == nullptr)
		return root;
	else
		return NodeMax(root->right);
}

int Max(BSTNode* root)
{
	if (root == nullptr)
	{
		return 0;
	}
	else if (root->right == nullptr)
	{
		return root->data;
	}
	
	return Max(root->right);
}

int Height(BSTNode* root)
{
	if (root == nullptr)
	{
		return -1;
	}

	int leftHeight = Height(root->left) + 1;
	int rightHeight = Height(root->right) + 1;
	return (leftHeight > rightHeight) ? leftHeight : rightHeight;
}

BSTNode* DeleteNode(BSTNode* root, int data)
{
	if (root == nullptr)
	{
		return root;
	}
	else if (data < root->data)
	{
		root->left = DeleteNode(root->left, data);
	}
	else if (data > root->data)
	{
		root->right = DeleteNode(root->right, data);
	}
	else
	{
		if (root->left == nullptr && root->right == nullptr)
		{
			delete root;
			root = nullptr;
			return root;
		}
		else if (root->left == nullptr)
		{
			BSTNode* temp = root;
			root = root->right;
			temp->right = nullptr;
			delete temp;
			return root;
		}
		else if (root->right == nullptr)
		{
			BSTNode* temp = root;
			root = root->left;
			temp->left = nullptr;
			delete temp;
			return root;
		}
		else
		{
			BSTNode* temp = NodeMin(root->right);
			root->data = temp->data;
			root->right = DeleteNode(root->right, temp->data);
		}
	}
	return root;
}

void LevelOrder(BSTNode* root)
{
	if (root == nullptr)
		return;
	std::queue<BSTNode*> q;
	q.push(root);
	while (!q.empty())
	{
		std::cout << q.front()->data << " ";
		if (q.front()->left != nullptr)
			q.push(q.front()->left);
		if (q.front()->right != nullptr)
			q.push(q.front()->right);
		q.pop();
	}
}

void PreOrder(BSTNode* root)
{
	if (root == nullptr)
		return;

	std::cout << root->data << ' ';
	PreOrder(root->left);
	PreOrder(root->right);
}

void InOrder(BSTNode* root)
{
	if (root == nullptr)
		return;

	InOrder(root->left);
	std::cout << root->data << ' ';
	InOrder(root->right);
}

void PostOrder(BSTNode* root)
{
	if (root == nullptr)
		return;

	PostOrder(root->left);
	PostOrder(root->right);
	std::cout << root->data << ' ';
}

BSTNode* InOrderSuccessor(BSTNode* root, int data)
{
	if (root == nullptr)
		return root;

	BSTNode* node = InOrderSuccessor(root->left, data);
	if (node != nullptr)
		return node;

	if (root->data > data)
		return root;

	node = InOrderSuccessor(root->right, data);
	if (node != nullptr)
		return node;

	return nullptr;
}

BSTNode* InOrderSuccessor2(BSTNode* root, int data)
{
	BSTNode* node = root;
	while (node->data != data && node != nullptr)
	{
		if (data < node->data)
		{
			node = node->left;
		}
		else
		{
			node = node->right;
		}
	}

	if (node == nullptr)
		return node;

	if (node->right != nullptr)
	{
		return NodeMin(node->right);
	}

	BSTNode* ancestor = root;
	BSTNode* successor = nullptr;
	while (ancestor->data != node->data)
	{
		if (node->data < ancestor->data)
		{
			successor = ancestor;
			ancestor = ancestor->left;
		}
		else
		{
			ancestor = ancestor->right;
		}
	}

	return successor;
}