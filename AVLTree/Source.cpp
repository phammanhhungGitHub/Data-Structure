#include<iostream>
#include<algorithm>
#include<cmath>
struct AVLTNode
{
	int data;
	AVLTNode* left;
	AVLTNode* right;
	int height;
};

AVLTNode* GetNewNode(int data)
{
	AVLTNode* newNode = new AVLTNode();
	newNode->data = data;
	newNode->left = nullptr;
	newNode->right = nullptr;
	newNode->height = 0;
	return newNode;
}

#pragma region Height
int Height(AVLTNode* node)
{
	if (node == nullptr)
		return -1;
	return node->height;
}

void UpdateHeight(AVLTNode* root)
{
	root->height = std::max(Height(root->left), Height(root->right)) + 1;
}
#pragma endregion

#pragma region MinMax

AVLTNode* FindMinNode(AVLTNode* root)
{
	if (root == nullptr)
		return root;
	if (root->left)
		return FindMinNode(root->left);
	else
		return root;
}
#pragma endregion

#pragma region Rotate

AVLTNode* RotateLeft(AVLTNode* root)
{
	AVLTNode* newRoot = root->right;
	AVLTNode* leftNewRoot = newRoot->left;

	root->right = leftNewRoot;
	newRoot->left = root;

	UpdateHeight(root);
	UpdateHeight(newRoot);
	return newRoot;
}

AVLTNode* RotateRight(AVLTNode* root)
{
	AVLTNode* newRoot = root->left;
	AVLTNode* rightNewRoot = newRoot->right;

	root->left = rightNewRoot;
	newRoot->right = root;

	UpdateHeight(root);
	UpdateHeight(newRoot);

	return newRoot;
}

#pragma endregion

#pragma region Insert
AVLTNode* BSTInsert(AVLTNode* root, int data)
{
	if (root == nullptr)
	{
		AVLTNode* newNode = GetNewNode(data);
		root = newNode;
		return root;
	}

	if (data < root->data)
	{
		root->left = BSTInsert(root->left, data);
	}
	else if (data > root->data)
	{
		root->right = BSTInsert(root->right, data);
	}
	UpdateHeight(root);
	return root;
}

AVLTNode* AVLTInsert(AVLTNode* root, int data)
{
	if (root == nullptr)
	{
		AVLTNode* newNode = GetNewNode(data);
		root = newNode;
		return root;
	}

	if (data < root->data)
	{
		root->left = AVLTInsert(root->left, data);
	}
	else if (data > root->data)
	{
		root->right = AVLTInsert(root->right, data);
	}
	UpdateHeight(root);

	int balance = Height(root->left) - Height(root->right);
	if (balance > 1)
	{
		if (data < root->left->data)
		{
			root = RotateRight(root);
		}
		else
		{
			root->left = RotateLeft(root->left);
			root = RotateRight(root);
		}
	}
	else if (balance < -1)
	{
		if (data > root->right->data)
		{
			root = RotateLeft(root);
		}
		else
		{
			root->right = RotateRight(root->right);
			root = RotateLeft(root);
		}
	}
	return root;
}
#pragma endregion

#pragma region Traversal

void PreOrderTraversal(AVLTNode* root)
{
	if (root == nullptr)
		return;
	std::cout << root->data << '-' << root->height << ' ';
	PreOrderTraversal(root->left);
	PreOrderTraversal(root->right);
}

void InOrderTraversal(AVLTNode* root)
{
	if (root == nullptr)
		return;
	InOrderTraversal(root->left);
	std::cout << root->data << '-' << root->height << ' ';
	InOrderTraversal(root->right);
}

void PostOrderTraversal(AVLTNode* root)
{
	if (root == nullptr)
		return;
	PostOrderTraversal(root->left);
	PostOrderTraversal(root->right);
	std::cout << root->data << '-' << root->height << ' ';
}
#pragma endregion

#pragma region Delete

AVLTNode* DeleteTree(AVLTNode* root)
{
	if (root->left == nullptr && root->right == nullptr)
	{
		delete root;
		root = nullptr;
		return root;
	}
	if (root->left != nullptr)
	{
		root->left = DeleteTree(root->left);
	}
	if (root->right != nullptr)
	{
		root->right = DeleteTree(root->right);
	}
	return root;

}

AVLTNode* BSTDelete(AVLTNode* root, int key)
{
	if (root == nullptr)
		return root;
	if (key < root->data)
	{
		root->left = BSTDelete(root->left, key);
	}
	else if (key > root->data)
	{
		root->right = BSTDelete(root->right, key);
	}
	else
	{
		if (root->left == nullptr && root->right == nullptr)
		{
			delete root;
			root = nullptr;
		}
		else if (root->left == nullptr)
		{
			AVLTNode* temp = root->right;
			delete root;
			root = temp;
		}
		else if (root->right == nullptr)
		{
			AVLTNode* temp = root->left;
			delete root;
			root = temp;
		}
		else
		{
			AVLTNode* minNode = FindMinNode(root->right);
			root->data = minNode->data;
			root->right = BSTDelete(root->right, root->data);
		}
	}
	
	return root;
}

AVLTNode* AVLTDelete(AVLTNode* root, int key)
{
	if (root == nullptr)
		return root;
	if (key < root->data)
	{
		root->left = AVLTDelete(root->left, key);
	}
	else if (key > root->data)
	{
		root->right = AVLTDelete(root->right, key);
	}
	else
	{
		if (root->left == nullptr && root->right == nullptr)
		{
			delete root;
			root = nullptr;
		}
		else if (root->left == nullptr)
		{
			AVLTNode* temp = root->right;
			delete root;
			root = temp;
		}
		else if (root->right == nullptr)
		{
			AVLTNode* temp = root->left;
			delete root;
			root = temp;
		}
		else
		{
			AVLTNode* minNode = FindMinNode(root->right);
			root->data = minNode->data;
			root->right = AVLTDelete(root->right, root->data);
		}
	}

	if (root == nullptr)
		return root;
	UpdateHeight(root);
	int balance = Height(root->left) - Height(root->right);
	if (balance > 1)
	{
		if (Height(root->left->left) >= Height(root->left->right))
		{
			root = RotateRight(root);
		}
		else
		{
			root->left = RotateLeft(root->left);
			root = RotateRight(root);
		}
	}
	else if (balance < -1)
	{
		if (Height(root->right->right) >= Height(root->right->left))
		{
			root = RotateLeft(root);
		}
		else
		{
			root->right = RotateRight(root->right);
			root = RotateLeft(root);
		}
	}
	return root;
}
#pragma endregion



int main()
{
	AVLTNode* root = nullptr;
	root = AVLTInsert(root, 30);
	root = AVLTInsert(root, 15);
	root = AVLTInsert(root, 40);
	root = AVLTInsert(root, 11);
	root = AVLTInsert(root, 35);
	root = AVLTInsert(root, 20);
	root = AVLTInsert(root, 23);
	std::cout << "Before : ";
	PreOrderTraversal(root);
	root = AVLTDelete(root, 35);
	std::cout << "\nAfter : ";
	PreOrderTraversal(root);
	root = DeleteTree(root);

	return 0;
}