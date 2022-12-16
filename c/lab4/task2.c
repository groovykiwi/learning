#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#define MAXCOLS 80
struct stack
{
    int top;
    double items[MAXCOLS];
};
double eval(char[]);
double pop(struct stack *);
void push(struct stack *, double);
int empty(struct stack *);
int isdigit(char);
double oper(int, double, double);
void main(void)
{
    char expr[MAXCOLS];
    int pos = 0;
    while ((expr[pos++] = getchar()) != '\n')
        ;
    expr[--pos] = '\0';
    printf("%s%s", " The original postfix expression is \n", expr);

    printf("\nAnswer is: %.2f ", eval(expr));
}
double pop(struct stack *ps)
{
    double x;
    if (ps->top == -1)
    {
        printf("%s", "stack underflow");
        exit(1);
    }
    else
    {
        x = ps->items[ps->top];
        ps->top = ps->top - 1;
    }
    return x;
}
void push(struct stack *ps, double x)
{
    if (ps->top == MAXCOLS - 1)
    {
        printf("%s", "stack overflow ");
        exit(1);
    }
    else
    {
        ps->top = ps->top + 1;
        ps->items[ps->top] = x;
    }
}
double eval(char expr[])
{
    int c, pos;
    double opnd1, opnd2, value;
    struct stack s;
    s.top = -1;
    for (pos = 0; (c = expr[pos]) != '\0'; pos++)
    {
        if (isdigit(c))
            push(&s, (double)(c - '0'));
        else if (c == ' ')
        {
        }
        else
        {
            opnd2 = pop(&s);
            opnd1 = pop(&s);
            value = oper(c, opnd1, opnd2);
            push(&s, value);
        }
    }
    return (pop(&s));
}
int isdigit(char symb) { return (symb >= '0' && symb <= '9'); }
double oper(int symb, double op1, double op2)
{
    switch (symb)
    {
    case '+':
        return (op1 + op2);
    case '-':
        return (op1 - op2);
    case '*':
        return (op1 * op2);
    case '/':
        return (op1 / op2);
    case '$':
        return (pow(op1, op2));
    default:
        printf("%s", "illegal operation ");
        exit(1);
    }
}

// 9 1 4 2 / + - 2 3 * /
// 3 9 2 3 $ - * 6 +