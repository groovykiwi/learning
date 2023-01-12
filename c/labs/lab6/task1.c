#include <stdlib.h>

#include <stdio.h>

#include <string.h>

#define NULL 0

typedef struct node *NODEPTR;

struct node
{
    char info[10];
    struct node *n;
};

void deleteNode(NODEPTR *head, char *info)
{
    NODEPTR temp = *head, prev;

    // If head holds the info to be deleted
    if (temp != NULL && temp->info == info)
    {
        *head = temp->n;
        free(temp);
        return;
    }

    // While current node is not equal to the deleted one go up the list
    while (temp != NULL && strcmp(temp->info, info) != 0)
    {
        prev = temp; // Keep previous node to change its n after deletion
        temp = temp->n;
    }

    // If info not found
    if (temp == NULL)
    {
        printf("Name was not found in linked list\n");
        return;
    }

    // Unlink the node from linked list
    prev->n = temp->n;

    free(temp);
}

void main(void)
{
    char a[10];
    int cnt = 0;
    NODEPTR x, y, save, head, p, q;

    x = (NODEPTR)malloc(sizeof(struct node));
    y = (NODEPTR)malloc(sizeof(struct node));
    head = x;
    x->n = y;
    y->n = NULL;

    strcpy(x->info, "Cemal");
    strcpy(y->info, "Mert");

    // Organize first 2 node in descending order
    if (strcmp(x->info, y->info) < 0)
    {
        char temp[10];
        strcpy(temp, x->info);
        strcpy(x->info, y->info);
        strcpy(y->info, temp);
    }

    do
    {
        printf("Enter name information: ");
        gets(a);
        cnt++;
        q = NULL;
        for (p = head; p != NULL && strcmp(a, p->info) < 0; p = p->n) //  < Descending Order
        {
            q = p;
        }
        if (q == NULL)
        {
            p = (NODEPTR)malloc(sizeof(struct node));
            strcpy(p->info, a);
            p->n = head;
            head = p;
        }
        else
        {
            save = p;
            p = (NODEPTR)malloc(sizeof(struct node));
            strcpy(p->info, a);
            p->n = save;
            q->n = p;
        }
    } while (cnt != 3);

    // Print List
    for (save = head; save != NULL; save = save->n)
        printf("Traverse Node: %s\n", save->info);

    // Delete 2 entries
    for (int i = 0; i < 2; i++)
    {
        char name[10];
        printf("Enter name to delete: ");
        gets(name);
        deleteNode(&head, name);
    }

    // Print List
    for (save = head; save != NULL; save = save->n)
        printf("Traverse Node: %s\n", save->info);
}
