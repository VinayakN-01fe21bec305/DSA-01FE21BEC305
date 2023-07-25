#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct Node* insert(struct Node* root, int data) {
    if (root == NULL) {
        return createNode(data);
    }

    if (data < root->data) {
        root->left = insert(root->left, data);
    } else if (data > root->data) {
        root->right = insert(root->right, data);
    }

    return root;
}

struct Node* findMinValueNode(struct Node* node) {
    struct Node* current = node;
    while (current && current->left != NULL) {
        current = current->left;
    }
    return current;
}

struct Node* deleteNode(struct Node* root, int data) {
    if (root == NULL) {
        return root;
    }

    if (data < root->data) {
        root->left = deleteNode(root->left, data);
    } else if (data > root->data) {
        root->right = deleteNode(root->right, data);
    } else {
        if (root->left == NULL) {
            struct Node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct Node* temp = root->left;
            free(root);
            return temp;
        }

        struct Node* temp = findMinValueNode(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }

    return root;
}

int countLevels(struct Node* root) {
    if (root == NULL) {
        return 0;
    } else {
        int leftHeight = countLevels(root->left);
        int rightHeight = countLevels(root->right);

        if (leftHeight > rightHeight) {
            return leftHeight + 1;
        } else {
            return rightHeight + 1;
        }
    }
}

void levelOrderTraversal(struct Node* root) {
    if (root == NULL) {
        return;
    }

    struct Node* queue[100];
    int front = 0, rear = 0;

    queue[rear] = root;
    rear++;

    while (front < rear) {
        struct Node* current = queue[front];
        printf("%d ", current->data);
        front++;

        if (current->left != NULL) {
            queue[rear] = current->left;
            rear++;
        }

        if (current->right != NULL) {
            queue[rear] = current->right;
            rear++;
        }
    }
}

void inorderTraversal(struct Node* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}

int main() {
    srand(time(0));  // Initialize random seed

    struct Node* root = NULL;
    int numRandomNumbers, i, data;

    printf("Enter the number of random numbers to generate: ");
    scanf("%d", &numRandomNumbers);

    FILE* file = fopen("rand.txt", "w");
    if (file == NULL) {
        printf("Failed to open the file.\n");
        return 1;
    }

    for (i = 0; i < numRandomNumbers; i++) {
        data = rand() % 100;  // Generate random numbers between 0 and 99
        fprintf(file, "%d\n", data);
        root = insert(root, data);
    }

    fclose(file);

    printf("Level Order Traversal: ");
    levelOrderTraversal(root);
    printf("\n");

    int levels = countLevels(root);
    printf("Number of Levels: %d\n", levels);

    int deleteValue;
    printf("Enter the value to delete from the BST: ");
    scanf("%d", &deleteValue);

    root = deleteNode(root, deleteValue);

    printf("BST after deleting %d: ", deleteValue);
    inorderTraversal(root);
    printf("\n");

    return 0;
}
