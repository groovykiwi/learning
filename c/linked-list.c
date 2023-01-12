#include <stdio.h>

struct node
{
    int info;
    struct node *next;
};

typedef struct node *NODEPTR;
NODEPTR p;

NODEPTR getnode()
{
    NODEPTR q;
    q = (NODEPTR)malloc(sizeof(struct node));
    return q;
}

void freenode(NODEPTR p)
{
    free(p);
}

int empty(NODEPTR *plist) // plist is a pointer to the list
{
    return *plist == NULL ? 1 : 0;
}

void push(NODEPTR *plist, int x) // Add to front of the list
{
    NODEPTR p = getnode();
    p->info = x;

    if (empty(plist))
    {
        *plist = p;
        p->next = NULL;
    }
    else
    {
        p->next = *plist;
        *plist = p;
    }
}

void insafter(NODEPTR p, int x)
{
    if (p == NULL)
    {
        printf("Error: void insertion");
        exit(1);
    }

    NODEPTR q = getnode();
    q->info = x;
    q->next = p->next;
    p->next = q;
}

void delafter(NODEPTR p, int *px)
{
    if (p == NULL || p->next == NULL)
    {
        printf("Error: void deletion");
        exit(1);
    }

    NODEPTR q = p->next;
    *px = q->info;
    p->next = q->next;
    freenode(q);
}

// Place in a sorted order
void place(NODEPTR *plist, int x)
{
    NODEPTR p, q;
    q = NULL; // q here is the previous node
    for (p = *plist; p != NULL && x > p->info; p = p->next)
        q = p;

    if (q == NULL) // Empty list or smallest number
        push(plist, x);
    else
        insafter(q, x);
}

void insend(NODEPTR *plist, int x)
{
    NODEPTR p, q;
    p = getnode();
    p->info = x;
    p->next = NULL;

    if (*plist == NULL)
        *plist = p;
    else
        for (q = *plist; q->next != NULL; q = q->next)
            ;

    q->next = p;
}

void display(NODEPTR *plist)
{
    NODEPTR p;
    for (p = *plist; p != NULL; p = p->next)
        printf("%d -> ", p->info);
    printf("NULL\n");
}
NODEPTR search(NODEPTR list, int x)
{
    NODEPTR p;
    for (p = list; p != NULL; p = p->next)
        if (p->info == x)
            return p;
    return NULL;
}

// Remove all nodes with info x
void rmvx(NODEPTR *plist, int x)
{
}

int main()
{
    NODEPTR list = NULL;

    NODEPTR *plist = &list;

    push(plist, 7);
    push(plist, 3);
    push(plist, 1);
    place(plist, 4);

    NODEPTR q = list->next->next;
    insafter(q, 9);

    display(plist);
    int x = 0;
    int *px = &x;
    delafter(q, px);

    insend(plist, 4);
    display(plist);

    if (search(list, 3) != NULL)
        printf("found");
}