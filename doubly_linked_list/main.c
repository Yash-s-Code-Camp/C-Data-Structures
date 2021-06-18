#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

struct Node
{
    int data;
    struct Node *prev;
    struct Node *next;
};

void createHeadNode(struct Node *head, int data)
{
    head->data = data;
    head->prev = NULL;
    head->next = NULL;
}

void createNewNode(struct Node *head, int data)
{
    struct Node *current = head;

    while (current->next != NULL)
    {
        current = current->next;
    }

    current->next = (struct Node *)malloc(sizeof(struct Node));
    current->next->data = data;
    current->next->prev = current;
    current->next->next = NULL;
}
void pop(struct Node *head)
{
    struct Node *current = head;

    while (current->next != NULL)
    {
        current = current->next;
    }

    current->prev->next = NULL;
    free(current);
}

void printList(struct Node *head)
{
    struct Node *current = head;

    // printf("\t");
    printf("(D   C    P    N\n)");
    while (current != NULL)
    {
        printf("(%d, %d, %d, %d)->", current->data, current, current->prev, current->next);
        current = current->next;
    }
    printf("x\n");
}

int main()
{
    struct Node *head = (struct Node *)malloc(sizeof(struct Node));

    head->data = 5;
    head->prev = NULL;
    head->next = NULL;

    createNewNode(head, 7);
    createNewNode(head, 11);

    printList(head);
    pop(head);
    printList(head);
    return 0;
}