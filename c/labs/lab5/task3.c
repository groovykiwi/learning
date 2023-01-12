#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#define MAXELEMENTS 5
#define TRUE 1
#define FALSE 0
// circular Queue insertion and deletion functions
struct queue
{
    int items[MAXELEMENTS];
    int front, rear;
};
void cqinsert(struct queue *, int);
int cqdelete(struct queue *);
int empty(struct queue *);
int main(void)
{
    char operation;
    int x;
    struct queue q;
    q.front = q.rear = MAXELEMENTS - 1;
    do
    {
        printf("%s\n", "\nInsert Operation type I, D or E ");
        scanf("\n%c", &operation);
        switch (operation)
        {
        case 'I':
            printf("%s\n", "Insert an element");
            scanf("\n%d", &x);
            cqinsert(&q, x);
            break;
        case 'D':
            x = cqdelete(&q);
            break;
        }
    } while (operation != 'E');
    return 0;
}
int empty(struct queue *pq)
{
    return ((pq->front == pq->rear) ? TRUE : FALSE);
}
int cqdelete(struct queue *pq)
{
    if (empty(pq))
    {
        printf("Queue underflow ");
        exit(1);
    }
    if (pq->front == MAXELEMENTS - 1)
        pq->front = 0;
    else
        (pq->front)++;
    printf("\n%d at location %d is deleted \n", pq->items[pq->front], pq->front);
    return (pq->items[pq->front]);
}
void cqinsert(struct queue *pq, int x)
{
    /* make room for new element */
    if (pq->rear == MAXELEMENTS - 1)
        pq->rear = 0;
    else
        (pq->rear)++;
    if (pq->rear == pq->front)
    {
        printf("Queue overflow");
        getchar();
        getchar();
        exit(1);
    }
    printf("\n%d is inserted at location %d \n", x, pq->rear);
    pq->items[pq->rear] = x;
}
