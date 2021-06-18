#include <iostream>
#include <stdlib.h>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

void createHeadNode(int data, struct Node *head)
{
    head->data = data;
    head->next = NULL;
}

void createNewNode(int data, struct Node *head)
{
    struct Node *current = head;

    while (current->next != NULL)
    {
        current = current->next;
    }
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));

    newNode->data = data;
    current->next = newNode;
    newNode->next = NULL;
}

void printList(struct Node *head)
{
    struct Node *current = head;
    while (current != NULL)
    {
        cout << "(" << current->data << ", " << current << ", " << current->next << ")"
             << "->";
        current = current->next;
    }
    cout << "x";
}

int main()
{
    struct Node *head = (struct Node *)malloc(sizeof(struct Node));

    createHeadNode(3, head);
    createNewNode(7, head);
    createNewNode(5, head);

    printList(head);

    return 0;
}
