#include <stdio.h>
#include <stdlib.h>
#define STACKSIZE 5

struct stack
{
    int top;
    int items[STACKSIZE];
};

int empty(struct stack *ps);
void push(struct stack *ps, int x);
int pop(struct stack *ps);

int main()
{
    int x, w, i;
    struct stack s;
    s.top = -1;

    /*push items into the stack*/
    printf("Input 5 Items for stack: \n");
    for (i = 0; i < STACKSIZE; i++)
    {
        scanf("%d", &x);
        push(&s, x);
    } // end for
    /*print the items of the stack*/
    printf("\nPopping & Printing 5 Items of stack: \n");
    for (i = 0; i < STACKSIZE; i++)
    {
        w = pop(&s);
        printf("%d \t", w);
    } // end for
    /*checkifstackisempty*/
    if (empty(&s))
        printf("\n stack is empty \n");
    else
        printf("\n stack is not empty \n");
    return 0;
} // end main

int empty(struct stack *ps)
{
    return (ps->top == -1);
}

void push(struct stack *ps, int x)
{
    // Complete the function
    // increment the top to the next index
    ps->top++;
    // printf("top count: %d", ps->top);

    ps->items[ps->top] = x;
    printf("items: %d\n", ps->items[ps->top]);
}

int pop(struct stack *ps)
{
    // Complete the function
}