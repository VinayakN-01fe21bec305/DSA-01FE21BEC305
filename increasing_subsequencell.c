#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int value;
    int length;
    struct node *prev;
    struct node *next;
} Node;

int longest_increasing_subsequence(int *arr, int n)
 {
    Node *head = NULL, *tail = NULL;
    int i, j;

    for (i = 0; i < n; i++)
        {
        Node *new_node = (Node*) malloc(sizeof(Node));
        new_node->value = arr[i];
        new_node->length = 1;
        new_node->prev = NULL;
        new_node->next = NULL;

        if (head == NULL)
        {
            head = tail = new_node;
        } else
        {
            Node *cur = head;
            while (cur != NULL) {
                if (cur->value < arr[i])
                 {
                    new_node->length = cur->length + 1;
                    new_node->prev = cur;
                    cur = cur->next;
                } else
                {
                    if (cur == head)
                    {
                        head = new_node;
                    } else
                    {
                        new_node->prev = cur->prev;
                        cur->prev->next = new_node;
                    }
                    new_node->next = cur;
                    cur->prev = new_node;
                    break;
                }
            }
            if (cur == NULL)
             {
                tail->next = new_node;
                new_node->prev = tail;
                tail = new_node;
            }
        }
    }

    int max_length = 0;
    Node *cur = head;
    while (cur != NULL)
     {
        if (cur->length > max_length)
         {
            max_length = cur->length;
        }
        cur = cur->next;
    }

    // free memory used by linked list
    cur = head;
    while (cur != NULL)
     {
        Node *temp = cur;
        cur = cur->next;
        free(temp);
    }

    return max_length;
}

int main()
 {
    int arr[] = {10, 9, 2, 5, 3, 7, 101, 18};
    int n = sizeof(arr) / sizeof(int);
    int result = longest_increasing_subsequence(arr, n);
    printf("Longest increasing subsequence: %d\n", result);
    return 0;
}

