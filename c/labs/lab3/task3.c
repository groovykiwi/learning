#include <stdio.h>
#include <stdlib.h>
#define STACKSIZE 64

typedef struct
{
    char home[STACKSIZE];
    int top;
} stack;

// Functions prototypes
int isAB(char);
void push(stack *, char);
char pop(stack *);

int main()
{
    // Stack init
    stack st;
    st.top = -1;

    char input[STACKSIZE];
    printf("Enter the string: \n");
    scanf("%s", input);

    // Push left side of string
    int i = 0;
    while (input[i] != '*')
    {
        // If valid input (a or b) push to stack
        if (isAB(input[i]))
        {
            push(&st, input[i]);
            i++;
        }
        else
        {
            printf("Wrong character!\n");
            exit(1);
        }
    }

    // Check if right side is reverse of left
    int valid = 1;
    for (int j = i + 1; j < 2 * i + 1; j++)
    {
        if (pop(&st) != input[j])
            valid = 0;
    }

    if (valid)
        printf("\nThe string is valid\n");
    else
        printf("\nThe string is invalid\n");
}

int isAB(char c)
{
    if (c == 'A' || c == 'a' || c == 'B' || c == 'b')
        return 1;
    return 0;
}

void push(stack *s, char c)
{
    s->top++;
    s->home[s->top] = c;
    printf("Pushed: %c\n", c);
}

char pop(stack *s)
{
    printf("Popped: %c\n", s->home[s->top]);
    return s->home[s->top--];
}