#ifndef QUEUE_H
#define QUEUE_H

#include<cassert>
class Node
{
public:
	int data;
	Node* next;
	Node(int data = 0);
	~Node();
};

class Queue
{
private:
	Node* head;
	Node* tail;
public:
	Queue();
	void Enqueue(int data);
	void Dequeue();
	int Front();
	int Back();
	bool IsEmpty();
	~Queue();
};

#endif // !QUEUE_H
