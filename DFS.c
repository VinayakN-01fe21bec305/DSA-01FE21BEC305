#include <stdio.h>
#include <stdlib.h>
#define SIZE 40

struct Stack
{
    int items[SIZE];
    int top;
};

struct Stack* createStack();
void push(struct Stack* stack, int value);
int pop(struct Stack* stack);
int isEmpty(struct Stack* stack);

void dfs(int graph[][SIZE], int numVertices, int startVertex);


struct Stack* createStack()
{
    struct Stack* stack = malloc(sizeof(struct Stack));
    stack->top = -1;
    return stack;
}


void push(struct Stack* stack, int value)
{
    if (stack->top == SIZE - 1)
        printf("\nStack is full!");
    else
        stack->items[++stack->top] = value;
}


int pop(struct Stack* stack)
{
    if (isEmpty(stack))
        {
        printf("Stack is empty!");
        return -1;
    }

    return stack->items[stack->top--];
}


int isEmpty(struct Stack* stack)
{
    return stack->top == -1;
}

// DFS traversal
void dfs(int graph[][SIZE], int numVertices, int startVertex)
{
    struct Stack* stack = createStack();
    int visited[SIZE] = { 0 };

    visited[startVertex] = 1;
    push(stack, startVertex);

    printf("DFS Traversal: ");

    while (!isEmpty(stack))
        {
        int currentVertex = pop(stack);
        printf("%d ", currentVertex);

        for (int i = 0; i < numVertices; i++)
            {
            if (graph[currentVertex][i] == 1 && visited[i] == 0)
            {
                visited[i] = 1;
                push(stack, i);
            }
        }
    }
    printf("\n");
}

int main()
{
    int numVertices = 6;
    int graph[SIZE][SIZE] = {
        { 0, 1, 0, 0, 0, 1 },
        { 1, 0, 1, 0, 0, 0 },
        { 1, 0, 0, 1, 0, 0 },
        { 0, 0, 1, 0, 1, 0 },
        { 0, 0, 0, 1, 0, 1 },
        { 1, 0, 0, 0, 1, 0 }
    };

    int startVertex;
    printf("Enter the starting vertex: ");
    scanf("%d", &startVertex);

    dfs(graph, numVertices, startVertex);

    return 0;
}
