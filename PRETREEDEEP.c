#include <stdio.h>
#include <stdlib.h>
#include <time.h>


struct TreeNode
{
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
};


struct TreeNode* createNode(int data)
{
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}


struct TreeNode* deepCopy(struct TreeNode* root)
{
    if (root == NULL) return NULL;
    struct TreeNode* newNode = createNode(root->data);
    newNode->left = deepCopy(root->left);
    newNode->right = deepCopy(root->right);

    return newNode;
}


void inOrderTraversal(struct TreeNode* root)
{
    if (root == NULL) return;
    inOrderTraversal(root->left);
    printf("%d ", root->data);
    inOrderTraversal(root->right);
}

int main()
{

    srand(time(NULL));


    struct TreeNode* root = createNode(rand() % 100);
    root->left = createNode(rand() % 100);
    root->right = createNode(rand() % 100);
    root->left->left = createNode(rand() % 100);
    root->left->right = createNode(rand() % 100);


    struct TreeNode* deepCopyRoot = deepCopy(root);


    printf("Original tree (In-order traversal): ");
    inOrderTraversal(root);
    printf("\n");


    printf("Deep copy of the tree (In-order traversal): ");
    inOrderTraversal(deepCopyRoot);
    printf("\n");

    return 0;
}
