#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

// A print function to view results
void printList(struct Node *head)
{
    struct Node *temp = head;
    while (temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

void deleteLastNode(struct Node *head)
{
    struct Node *temp = head;
    struct Node *prev = head;
    int i = 0;

    if (head == NULL)
    {
        return;
    }

    // loop to the end of the list
    while (temp != NULL)
    {
        if (i == 0)
        {
            temp = temp->next;
        }

        else
        {
            temp = temp->next;
            prev = prev->next;
        }

        i++;
    }

    prev->next = NULL;
    free(temp);
}

int main()
{
    struct Node *head;
    struct Node *temp;
    struct Node *successor;
    struct Node *newList;
    struct Node *newNode;
    int i = 0;

    // create the linked list 1->2->3->4(head is 1).
    head = malloc(sizeof(struct Node));
    head->data = 1;
    temp = head;

    for (i = 1; i < 4; i++)
    {
        newList = malloc(sizeof(struct Node));
        newList->data = i + 1;
        temp->next = newList;
        temp = temp->next;
    }

    temp->next = NULL;

    printList(head);

    // add node 5 after node 3 into the linked list
    temp = head;
    newNode = malloc(sizeof(struct Node));
    newNode->data = 5;

    // loop to node 3
    while (temp->data != 3)
    {
        temp = temp->next;
    }

    successor = temp->next;
    temp->next = newNode;
    newNode->next = successor;

    printList(head);

    // delete the last node in the linked list
    deleteLastNode(head);
}
