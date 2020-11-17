#include "Queue.h"

Node::Node(int data)
{
	this->data = data;
	next = nullptr;
}

Node::~Node()
{
	delete next;
}

Queue::Queue()
{
	head = nullptr;
	tail = nullptr;
}

void Queue::Enqueue(int data)
{
	Node* newNode = new Node(data);
	if (tail == nullptr) // also, head == nullptr
	{
		head = newNode;
		tail = newNode;
		return;
	}
	tail->next = newNode;
	tail = newNode;
}

void Queue::Dequeue()
{
	if (head == nullptr) // also, tail == nullptr
		return;
	Node* deleteNode = head;
	if (head == tail)
		tail = nullptr;
	head = head->next;
	deleteNode->next = nullptr;
	delete deleteNode;
}

int Queue::Front()
{
	if (head == nullptr)
		assert(head != nullptr && "Queue is empty");
	else
		return head->data;
}

int Queue::Back()
{
	if (tail == nullptr)
		assert(tail != nullptr && "Queue is empty");
	else
		return tail->data;
}

Queue::~Queue()
{
	delete head;
}
