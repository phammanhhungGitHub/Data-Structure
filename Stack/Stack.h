#ifndef STACK_H
#define STACK_H

#include<cassert>

template <class T>
class Node
{
public:
	T data;
	Node* next;
	Node(T data);
	~Node();
};



template <class T>
class Stack
{
private:
	Node<T>* head;
public:
	Stack();
	void Push(T data);
	void Pop();
	T Top();
	bool IsEmpty();
	~Stack();
};


#endif // !STACK_H
