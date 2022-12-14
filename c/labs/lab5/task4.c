#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#define MAXELEMENTS 15
#define TRUE 1
#define FALSE 0
// circular Queue insertion and deletion functions

struct person
{
    int empNo;
    char name[12];
    int age;
    char gender[2]; /* M=male, F=Female */
};

struct queue
{
    struct person allperson[MAXELEMENTS];
    int front, rear;
};

void cqinsert(struct queue *, struct person);
struct person cqdelete(struct queue *);
int empty(struct queue *);
int main(void)
{

    char operation;
    struct person x;

    int empNo;
    char name[12];
    int age;
    char gender[2];

    struct queue q;
    struct queue m;
    struct queue f;
    q.front = q.rear = MAXELEMENTS - 1;
    m.front = m.rear = MAXELEMENTS - 1;
    f.front = f.rear = MAXELEMENTS - 1;

    // Initialize Queue with tenPerson
    struct person tenPerson[10] = {123, "Ahmet", 21, "M",
                                   234, "Sevgi", 26, "F", 128, "Osman", 18, "M", 432, "Mert", 27, "M",
                                   287, "Ayse", 34, "F", 423, "Kemal", 21, "M", 634, "Lale", 16, "F",
                                   828, "Sefer", 15, "M", 252, "Meral", 27, "F", 887, "Demet", 34, "F"};
    for (int i = 0; i <= 10; i++)
    {
        cqinsert(&q, tenPerson[i]);
    }

    do
    {
        printf("%s\n", "\nInsert Operation type I, D, A or E ");
        scanf("\n%c", &operation);
        switch (operation)
        {
        case 'I':
            printf("%s\n", "Insert an element");
            scanf("\n%d %s %d %s", &empNo, name, &age, gender);

            x.empNo = empNo;
            strcpy(x.name, name);
            x.age = age;
            strcpy(x.gender, gender);

            cqinsert(&q, x);
            break;
        case 'D':
            x = cqdelete(&q);
            if (strcmp(x.gender, "M") == 0)
            {
                printf("\nMale added");
                cqinsert(&m, x);
            }
            if (strcmp(x.gender, "F") == 0)
            {
                printf("\nFemale added");
                cqinsert(&f, x);
            }
            break;
        case 'A':
            while (empty(&q) == 0)
            {
                x = cqdelete(&q);
                if (strcmp(x.gender, "M") == 0)
                {
                    printf("\nMale added");
                    cqinsert(&m, x);
                }
                if (strcmp(x.gender, "F") == 0)
                {
                    printf("\nFemale added");
                    cqinsert(&f, x);
                }
            }

            break;
        }
    } while (operation != 'E');
    return 0;
}
int empty(struct queue *pq)
{
    return ((pq->front == pq->rear) ? TRUE : FALSE);
}
struct person cqdelete(struct queue *pq)
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

    struct person p = pq->allperson[pq->front];
    printf("\n%d %s %d %s at location %d is deleted \n", p.empNo, p.name, p.age, p.gender, pq->front);

    return (pq->allperson[pq->front]);
}
void cqinsert(struct queue *pq, struct person x)
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
    printf("\n%d %s %d %s is inserted at location %d \n", x.empNo, x.name, x.age, x.gender, pq->rear);
    pq->allperson[pq->rear] = x;
}
