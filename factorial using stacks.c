#include <stdio.h>
#include <stdlib.h>

#define SIZE 100

typedef struct
 {
    int data[SIZE];
    int top;
} Stack;

void push(Stack *stack, int val)
 {
    if (stack->top == SIZE)
        {
        fprintf(stderr, "Stack overflow\n");
        exit(1);
    }
    stack->data[stack->top] = val;
    stack->top++;
}

int pop(Stack *stack)
 {
    if (stack->top == 0)
        {
        fprintf(stderr, "Stack underflow\n");
        exit(1);
    }
    stack->top--;
    return stack->data[stack->top];
}

int factorial(int n)
{
    Stack stack;
    stack.top = 0;
    push(&stack, n);

    int res = 1;
    while (stack.top > 0)
        {
        int a = pop(&stack);
        if (a == 0)
         {
            res *= 1;
        } else
        {
            res *= a;
            push(&stack, a - 1);
        }
    }

    return res;
}

int main()
 {
    int n = 5;
    int result = factorial(n);
    printf("%d! = %d\n", n, result);
    return 0;
}
