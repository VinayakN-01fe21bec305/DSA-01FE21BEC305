#include <stdio.h>

#define MAX 100

int stack[MAX];
int top = -1;

void push(int val)
{


    if (top == MAX - 1)
    {
        printf("Error: Stack overflow\n");
    }
     else
        top++;
        stack[top] = val;

}

int pop()
 {
    if (top == -1)
{
        printf("Error: Stack underflow\n");
        return -1;
    }
    else
 {
        int val = stack[top];
        top--;
        return val;
     }
}

int main()
 {
    int numbers[] = {2, 5, 7, 10, 3};

    for (int i = 0; i < sizeof(numbers)/sizeof(int); i++)
 {
        push(numbers[i]);
    }

    int total = 0;

    while (top != -1)
 {
        total += pop();
    }

       printf("The sum is: %d\n", total);

    return 0;
}
