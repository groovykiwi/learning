/****************************************************/
/* Stack’s Push/Pop operations – */
/* 1D-array implementation of stack structure */
/****************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
typedef struct
{
    char home[35];
    int top;
} My_stack;
void push(My_stack *, char); /* prototypes (declarations) of functions in use */
void pop(My_stack *);        /* they implement standard operations on stack */
int is_empty(My_stack *);
int is_vowel(char);
void main(void)
{
    My_stack st;
    char input[50]; /* input sequence for processing */
    int i = 0;
    st.top = -1;
    /* previous assignment indicates that stack is empty from the beginning */
    printf("Enter the sequence (length is limited!): ");
    gets(input);
    printf("RESULT (after performing pop operation): ");
    while (input[i] != '\0') /* while end of line is not reached */
    {
        if (isalpha(input[i]))
        {
            push(&st, input[i]); /* push character onto the stack */
        }
        else if (input[i] == '*')
        {
            pop(&st);
        }
        else
        {
            printf("ERROR: Wrong input symbol – program terminates !\n");
            exit(1);
        }
        i++;
    }
}
void push(My_stack *s, char c) // push (insert) operation
{                              // assume there is enough space for pushing next element!
    if (is_vowel(c))
    {
        // printf("pushed %c\n", c);
        s->top++;
        s->home[s->top] = c;
    }
}
void pop(My_stack *s) // pop (remove) operation
{

    if (is_empty(s))
    {
        printf("ERROR: Nothing to pop - program terminates\n");
        exit(1);
    }

    printf("%c", s->home[s->top--]);
}

int is_vowel(char c)
{
    char vowels[10] = {'A', 'E', 'I', 'O', 'U', 'a', 'e', 'i', 'o', 'u'};
    for (int i = 0; i < 10; i++)
    {
        if (c == vowels[i])
            return 1;
    }
    return 0;
}

int is_empty(My_stack *s) // checking whether stack is empty or not
{
    return (s->top < 0 ? 1 : 0);
}

/*
ANSWER
a) EAEE <-- FE*NERBA*HCE**
b) EEAE <-- FE*NER*BA*HCE*
*/