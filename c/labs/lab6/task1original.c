#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define NULL 0
struct node
{
    char info[10];
    struct node *n;
};
void main(void)
{
    typedef struct node *NODEPTR;
    char a[10];
    int cnt = 0;
    NODEPTR x, y, save, head, p, q;
    x = (NODEPTR)malloc(sizeof(struct node));
    y = (NODEPTR)malloc(sizeof(struct node));
    head = x;
    x->n = y;
    y->n = NULL;
    strcpy(x->info, "cemal");
    strcpy(y->info, "mert");
    do
    {
        puts("Enter Name information");
        gets(a);
        cnt++;
        q = NULL;
        for (p = head; p != NULL && strcmp(a, p->info) > 0; p = p->n)
            q = p;
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
    for (save = head; save != NULL; save = save->n)
        printf("Traverse Node =%s\n", save->info);
    getchar();
}