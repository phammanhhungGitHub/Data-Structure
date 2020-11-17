#include "Stack.h"

template <class T>
Node<T>::Node(T data)
{
	this->data = data;
	next = nullptr;
}

template <class T>
Node<T>::~Node()
{
	delete next;
}

template <class T>
Stack<T>::Stack()
{
	head = nullptr;
}

template <class T>
void Stack<T>::Push(T data)
{
	Node<T>* newNode = new Node<T>(data);
	newNode->next = head;
	head = newNode;
}

template <class T>
void Stack<T>::Pop()
{
	if (head == nullptr)
	{
		return;
	}
	Node<T>* deleteNode = head;
	head = head->next;
	deleteNode->next = nullptr;
	delete deleteNode;
}

template <class T>
T Stack<T>::Top()
{
	assert(head != nullptr &&  "Stack is empty");
	if (head != nullptr)
		return head->data;
}

template <class T>
bool Stack<T>::IsEmpty()
{
	return (head == nullptr);
}

template <class T>
Stack<T>::~Stack()
{
	delete head;
}

template class Node<char>;
template class Stack<char>;
template class Node<int>;
template class Stack<int>;
