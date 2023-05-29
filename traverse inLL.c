#include <stdio.h>
#include <stdlib.h>


struct node {
    int data;
    struct node* next;
};


void printll(struct node* head) {
    struct node* curr = head;

    while (curr != NULL) {
        printf("%d ", curr->data);
        curr = curr->next;
    }
}

int main() {
    int n, i, res;
    struct node* head = NULL;
    struct node* curr = NULL;


    printf("Enter the number of nodes: ");
    scanf("%d", &n);


    for (i = 0; i < n; i++) {
        printf("Enter the value for node %d: ", i+1);
        scanf("%d", &res);

        if (head == NULL) {
            head = malloc(sizeof(struct node));
            head->data = res;
            head->next = NULL;
            curr = head;
        }
        else {
            curr->next = malloc(sizeof(struct node));
            curr->next->data = res;
            curr->next->next = NULL;
            curr = curr->next;
        }
    }


    printll(head);

    return 0;
}
