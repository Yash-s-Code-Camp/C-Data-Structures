#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

struct Node
{
    int data;
    struct Node *next;
};

void createHeadNode(struct Node *head, int data)
{
    head->data = data;
    head->next = NULL;
}

void createNodeAt(int position, struct Node *head, int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));

   
    if (position == 0)
    {
        createHeadNode(head, data);
    }

    struct Node *current = head;
    newNode->data = data;
    newNode->next = NULL;
    while (position - 1 > 0)
    {
        current = current->next;
        position--;
    }
    newNode->next = current->next;
    current->next = newNode;
}

void deleteNodeAt(int position, struct Node **head)
{
    // if (*head == NULL)
    // {
    //     return;
    // }
    struct Node *current = *head;
    struct Node *temp;
    if (position == 0)
    {
        *head = current->next;
        free(current);
        return;
    }
    for (int i = 0; i < position; i++)
    {
        temp = current;
        current = current->next;
    }
    if (current == NULL || current->next == NULL)
    {
        return;
    }
    //struct Node *next = current->next->next;
    temp->next = current->next;
    free(current);
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
    current->next->next = NULL;
}
void deleteLastNode(struct Node *head)
{
    struct Node *current = head;
    struct Node *temp = head;

    while (current->next != NULL)
    {
        temp = current;
        current = current->next;
    }
    printf("\t(%d, %d %d) deleted...\n", current->data, current, current->next);
    temp->next = NULL;
    free(current);
}
void printList(struct Node *head)
{
    struct Node *current = head;

    printf("\t");
    while (current != NULL)
    {
        printf("(%d, %d %d)->", current->data, current, current->next);
        current = current->next;
    }
    printf("x\n");
}

int getListSize(struct Node *head)
{
    int size = 0;
    struct Node *current = head;

    while (current->next != NULL)
    {

        current = current->next;
        size++;
    }

    return size + 1;
}

int main()
{
    int ch;
    int data, pos;
    struct Node *head = (struct Node *)malloc(sizeof(struct Node));

    do
    {
        printf("\n\n\n1. Create Head Node\n2. Create New Node at Last\n3. Create new Node at position\n4. Delete last Node\n5. Delete node from position\n6. Show as LinkedList\n7. Get List size\n8. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            printf("\tData: ");
            scanf("%d", &data);
            createHeadNode(head, data);
            break;
        case 2:
            printf("\tData: ");
            scanf("%d", &data);
            createNewNode(head, data);
            break;
        case 3:
            printf("\tPosition: ");
            scanf("%d", &pos);
            printf("\tData: ");
            scanf("%d", &data);
            createNodeAt(pos, head, data);
            break;
        case 4:
            deleteLastNode(head);
            break;
        case 5:
            printf("\tPosition: ");
            scanf("%d", &pos);
            deleteNodeAt(pos, &head);
            break;
        case 6:
            printList(head);
            break;
        case 7:
            printf("\tTotal %d nodes in List\n", getListSize(head));
            break;
        case 8:
            exit(0);
            break;

        default:
            printf("Invalid choice!\n");
            break;
        }
    } while (1);

    return 0;
}