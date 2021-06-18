#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node()
    {
        data = 0;
        next = NULL;
    }
};

class LinkedList
{
public:
    Node *head = new Node();
    void createHeadNode(int data)
    {
        head->data = data;
        head->next = NULL;

        cout << "Head Node (" << head->data << ", " << head->next << ") created" << endl;
    }

    void createNewNode(int data)
    {
        Node *current = head;

        while (current->next != NULL)
        {
            current = current->next;
        }

        Node *newNode = new Node();
        current->next = newNode;
        newNode->data = data;
        newNode->next = NULL;

        cout << "New Node (" << newNode->data << ", " << newNode->next << ") created." << endl;
    }

    void print()
    {
        Node *current = head;

        while (current != NULL)
        {
            cout << "(" << current->data << ", " << current->next << ")"
                 << "->";
            current = current->next;
        }
        cout << "x";
    }
};

int main()
{
    LinkedList list;

    list.createHeadNode(7);
    list.createNewNode(3);
    list.createNewNode(-4);
    list.createNewNode(9);
    list.createNewNode(5);

    list.print();

    return 0;
}