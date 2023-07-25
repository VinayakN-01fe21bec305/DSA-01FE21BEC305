#include <stdio.h>
#include <stdlib.h>

#define BUCKET_SIZE 10

typedef struct Node
{
    int data;
    struct Node* next;
} Node;

int kmod10_hash(int num)
 {
    return num % 10;
}

void insert(Node* buckets[], int num)
 {
    int hash = kmod10_hash(num);
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = num;
    newNode->next = NULL;

    if (buckets[hash] == NULL)
    {
        buckets[hash] = newNode;
    } else
     {
        Node* curr = buckets[hash];
        while (curr->next != NULL)
         {
            curr = curr->next;
        }
        curr->next = newNode;
    }
}

void printBuckets(Node* buckets[])
 {
    for (int i = 0; i < BUCKET_SIZE; i++)
        {
        printf("Bucket %d: ", i);
        Node* curr = buckets[i];
        while (curr != NULL)
         {
            printf("%d ", curr->data);
            curr = curr->next;
        }
        printf("\n");
    }
}

int main()
 {
    Node* buckets[BUCKET_SIZE] = { NULL };

    int count;
    printf("Enter the number of input numbers: ");
    scanf("%d", &count);

    printf("Enter the numbers:\n");
    for (int i = 0; i < count; i++)
    {
        int num;
        printf("Number %d: ", i + 1);
        scanf("%d", &num);
        insert(buckets, num);
    }

    printf("\nHash Buckets:\n");
    printBuckets(buckets);

    return 0;
}

