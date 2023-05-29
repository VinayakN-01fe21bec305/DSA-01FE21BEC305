#include <stdio.h>
#include <stdlib.h>

// Linked List Node
struct node
 {
    int data;
    struct node* next;
};

// Insert a new node at the end of the linked list
void insert_node(struct node** head_ref, int data)
 {
    // Allocate memory for new node
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = NULL;

    // If linked list is empty, make new node as head
    if (*head_ref == NULL)
        {
        *head_ref = new_node;
        return;
    }

    // Traverse to last node and insert new node
    struct node* last_node = *head_ref;
    while (last_node->next != NULL)
        {
        last_node = last_node->next;
    }
    last_node->next = new_node;
}

// Perform binary search on the linked list
struct node* binary_search(struct node* head, int key)
 {
    // Base case: if head is NULL or key is found in head node
    if (head == NULL || head->data == key)
        {
        return head;
    }

    // Find the middle node of the linked list
    struct node* middle = head;
    struct node* end = head->next;
    while (end != NULL && end->data < key)
        {
        middle = middle->next;
        end = end->next;
    }

    // If middle node is the key, return it
    if (middle->data == key)
        {
        return middle;
    }

    // If key is greater than the middle node, search in the right half of the linked list
    if (middle->data < key)
        {
        return binary_search(middle->next, key);
    }

    // If key is smaller than the middle node, search in the left half of the linked list
    return binary_search(head, key);
}

// Display the linked list
void display_list(struct node* node)
 {
    while (node != NULL)
        {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

int main() {
    // Create a linked list
    struct node* head = NULL;
    insert_node(&head, 10);
    insert_node(&head, 20);
    insert_node(&head, 30);
    insert_node(&head, 40);
    insert_node(&head, 50);

    // Display the linked list
    printf("Linked list:\n");
    display_list(head);

    // Search for key in the linked list
    int key = 30;
    struct node* result = binary_search(head, key);
    if (result != NULL)
        {
        printf("Key %d found at node %d\n", key, result->data);
    } else
     {
        printf("Key %d not found in the linked list\n", key);
    }

    return 0;
}

