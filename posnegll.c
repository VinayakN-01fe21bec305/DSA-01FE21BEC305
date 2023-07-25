#include <stdio.h>
#include <stdlib.h>

// Structure for a linked list node
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->next = NULL;
    return node;
}

// Function to insert a node at the end of the linked list
void insertEnd(struct Node** head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
        return;
    }

    struct Node* curr = *head;
    while (curr->next != NULL)
        curr = curr->next;
    curr->next = newNode;
}

// Function to display the linked list along with memory locations
void displayLinkedList(struct Node* head) {
    struct Node* curr = head;
    while (curr != NULL) {
        printf("%d (Memory Location: %p) -> ", curr->data, curr);
        curr = curr->next;
    }
    printf("NULL\n");
}

// Function to separate positive and negative numbers into separate linked lists
void separateNumbers(struct Node* head, struct Node** positiveList, struct Node** negativeList) {
    struct Node* curr = head;
    while (curr != NULL) {
        if (curr->data >= 0)
            insertEnd(positiveList, curr->data);
        else
            insertEnd(negativeList, curr->data);
        curr = curr->next;
    }
}

int main() {
    FILE* file = fopen("input.txt", "r");
    if (file == NULL) {
        printf("Failed to open the file.\n");
        return 1;
    }

    struct Node* head = NULL;
    int num;

    // Read 10 numbers from the file and store them in the linked list
    for (int i = 0; i < 10; i++) {
        if (fscanf(file, "%d", &num) == 1)
            insertEnd(&head, num);
    }

    fclose(file);

    printf("Numbers in the linked list:\n");
    displayLinkedList(head);

    struct Node* positiveList = NULL;
    struct Node* negativeList = NULL;

    separateNumbers(head, &positiveList, &negativeList);

    printf("\nPositive numbers:\n");
    displayLinkedList(positiveList);

    printf("\nNegative numbers:\n");
    displayLinkedList(negativeList);

    return 0;
}
