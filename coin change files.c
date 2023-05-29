#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int top = -1;
int stack[MAX];

void push(int item)
{
    if (top >= MAX - 1)
        {
        printf("Stack Overflow\n");
        return;
    }

    stack[++top] = item;
}

int pop()
{
    if (top < 0)
        {
        printf("Stack Underflow\n");
        return -1;
    }

    return stack[top--];
}

void sort(int arr[], int n)
{
    int i, j, temp;

    for (i = 0; i < n; i++)
        {
        for (j = i + 1; j < n; j++)
        {
            if (arr[i] < arr[j])
             {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

int min(int a, int b)
 {
    return a < b ? a : b;
}

void coin_change(int coins[], int n, int amount)
 {
    int i, count = 0;

    sort(coins, n);

    for (i = 0; i < n; i++)
        {
        while (amount >= coins[i])
            {
            amount -= coins[i];
            push(coins[i]);
            count++;
        }
    }

    printf("Minimum coins required: %d\n", count);
    printf("Coins used: ");
    for (i = 0; i < count; i++)
        {
        printf("%d ", pop());
    }
    printf("\n");
}

int main()
 {
    int coins[] = {1, 5, 10, 25};
    int n = sizeof(coins) / sizeof(coins[0]);
    int amount = 67;

    coin_change(coins, n, amount);

    return 0;
}
