#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node* next;
};
typedef struct Node Node;


Node* GetNewNode(int data)
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void Traversal(Node* head)
{
    while (head != NULL)
    {
        printf("%d ", head->data);
        head = head->next;
    }
}

int ValueAt(Node* head, int pos)
{
    if (head == NULL)
    {
        printf("List is null");
        return 0;
    }
    int index = 0;
    for (; index < pos && head != NULL; ++index)
    {
        head = head->next;
    }

    if (head == NULL)
    {
        printf("The position does not exist");
        return 0;
    }

    return head->data;
}

Node* InsertToHead(Node* head, int data)
{
    Node* newNode = GetNewNode(data);
    newNode->next = head;
    head = newNode;
    return head;
}

Node* InsertToMiddle(Node* prev, int data)
{
    Node* newNode = GetNewNode(data);
    if (prev != NULL)
    {
        newNode->next = prev->next;
    }
    prev->next = newNode;
    return prev;
}

Node* InsertToPosition(Node* head, int data, int pos)
{
    if (pos == 0)
        return InsertToHead(head, data);
    
    Node* travelsal = head;
    int i;
    for (i = 1; i < pos && head != NULL; ++i)
    {
        travelsal = travelsal->next;
    }

    if (travelsal == NULL)
    {
        printf("Index out of range! FAILED");
        return head;
    }

    Node* newNode = GetNewNode(data);
    newNode->next = travelsal->next;
    travelsal->next = newNode;
    return head;
}

Node* InsertToLast(Node* head, int data)
{
    Node* newNode = GetNewNode(data);
    if (head == NULL)
    {
        head = newNode;
        return head;
    }

    Node* tail = head;
    while (tail->next)
    {
        tail = tail->next;
    }
    tail->next = newNode;

    return head;
}

Node* DeleteAtHead(Node* head)
{
    if (head == NULL)
        return head;
    Node* deleteNode = head;
    head = head->next;
    free(deleteNode);
    return head;
}

Node* DeleteAtPosition(Node* head, int pos)
{
    if (pos == 0)
        return DeleteAtHead(head);
    int i;
    Node* travelsal = head;
    for (i = 1; i < pos && travelsal->next != NULL; ++i)
    {
        travelsal = travelsal->next;
    }

    if (travelsal->next == NULL)
        return head;
    
    Node* deleteNode = travelsal->next;
    travelsal->next = deleteNode->next;
    free (deleteNode);
    return head;
}

Node* DeleteAtLast(Node* head)
{
    if (head == NULL)
        return head;
    Node* travel1 = head, *travel2 = head;
    while (travel1->next)
    {
        travel2 = travel1;
        travel1 = travel1->next;
    }
    travel2->next = NULL;
    free(travel1);
    if (travel2 == head)
        return NULL;
    else
        return head;
}


int main()
{
    Node* head = NULL;
    /*Node* node1 = GetNewNode(1);
    Node* node2 = GetNewNode(2);
    Node* node3 = GetNewNode(3);

    head = node1;
    head->next = node2;
    node2->next = node3;
    head = InsertToHead(head, 4);*/

    int i;
    for (i = 0; i < 6; ++i)
    {
        head = InsertToHead(head, i);
    }
    //head = DeleteAtLast(head);
    head = DeleteAtLast(head);
    head = DeleteAtLast(head);
    if (head != NULL)
    {
        Traversal(head);
    }
    else
    {
        printf("NOTHING");
    }

    //printf("\n%d", ValueAt(head, 5));

    return 0;
}