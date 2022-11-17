#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//#include <conio.h>
#define STACKSIZE 6

struct person
{
    int empnr;
    char name[12];
    int age;
};

struct stack
{
    struct person items[STACKSIZE];
    int top;
};

void push(struct stack *, int, char[], int);
struct person pop(struct stack *);
void main(void)
{
    struct stack s;
    struct person deleted;
    int empnr, age;
    char name[12];
    char optype;
    s.top = -1;

    do
    {
        printf("Enter Operation type \n");
        scanf("\n%c", &optype);
        switch (optype)
        {
        case 'I':
        {
            printf("Enter employee: \n");
            scanf("%d %s %d", &empnr, name, &age);
            push(&s, empnr, name, age);
            break;
        }
        case 'D':
        {
            deleted = pop(&s);
            printf("%d %s %d is deleted\n", deleted.empnr, deleted.name, deleted.age);
            break;
        }
        default:
            printf("%s", "Illegal Oparation code \n");
        }
    } while (optype != 'E');
}

// Returns person popped
struct person pop(struct stack *ps)
{
    struct person x;
    if (ps->top == -1)
    {
        printf("%s", "Error: Stack Underflow");
        exit(1);
    }
    else
    {
        x = ps->items[ps->top];
        ps->top--;
    }
    return x;
}

void push(struct stack *ps, int empnr, char name[], int age)
{
    if (ps->top == STACKSIZE - 1)
    {
        printf("%s", "Error: Stack Overflow");
        exit(1);
    }
    else
    {
        ps->top++;
        ps->items[ps->top].empnr = empnr;
        strcpy(ps->items[ps->top].name, name);
        ps->items[ps->top].age = age;
    }
}