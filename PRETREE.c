#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Definition for a binary tree node
struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
};

// Function to create a new binary tree node
struct TreeNode* createNode(int data) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function for pre-order traversal to create a deep copy of the binary tree
struct TreeNode* deepCopy(struct TreeNode* root) {
    if (root == NULL) return NULL;

    // Create a new node with the same data as the current node
    struct TreeNode* newNode = createNode(root->data);

    // Recursively copy the left and right subtrees
    newNode->left = deepCopy(root->left);
    newNode->right = deepCopy(root->right);

    return newNode;
}

// Function to perform in-order traversal of the binary tree and print its elements
void inOrderTraversal(struct TreeNode* root) {
    if (root == NULL) return;

    // Recursively traverse the left subtree
    inOrderTraversal(root->left);

    // Process the current node
    printf("%d ", root->data);

    // Recursively traverse the right subtree
    inOrderTraversal(root->right);
}

int main() {
    // Seed the random number generator with the current time
    srand(time(NULL));

    // Create a sample binary tree with random integer values
    struct TreeNode* root = createNode(rand() % 100); // Generate random number between 0 and 99
    root->left = createNode(rand() % 100);
    root->right = createNode(rand() % 100);
    root->left->left = createNode(rand() % 100);
    root->left->right = createNode(rand() % 100);

    // Perform pre-order traversal to create a deep copy of the tree
    struct TreeNode* deepCopyRoot = deepCopy(root);

    // Print the original tree
    printf("Original tree (In-order traversal): ");
    inOrderTraversal(root);
    printf("\n");

    // Print the deep copy of the tree
    printf("Deep copy of the tree (In-order traversal): ");
    inOrderTraversal(deepCopyRoot);
    printf("\n");

    return 0;
}
