
#include <stdio.h>
#include <stdlib.h>

struct AVLNode
{
    int key;
    struct AVLNode* left;
    struct AVLNode* right;
    int height;
};


int max(int a, int b)
 {
    int result;
    if (a > b)
        {
        result = a;
    } else
    {
        result = b;
    }
    return result;
}



int height(struct AVLNode* node)
 {
    if (node == NULL)
        return 0;
    return node->height;
}


struct AVLNode* newNode(int key)
 {
    struct AVLNode* node = (struct AVLNode*)malloc(sizeof(struct AVLNode));
    node->key = key;
    node->left = NULL;
    node->right = NULL;
    node->height = 1;
    return node;
}

// Function to right rotate
struct AVLNode* rightRotate(struct AVLNode* y)
 {
    struct AVLNode* x = y->left;
    struct AVLNode* T2 = x->right;
    x->right = y;
    y->left = T2;
    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;
    return x;
}

// Function to left rotate
struct AVLNode* leftRotate(struct AVLNode* x)
 {
    struct AVLNode* y = x->right;
    struct AVLNode* T2 = y->left;
    y->left = x;
    x->right = T2;
    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;
    return y;
}

int getBalance(struct AVLNode* node)
 {
    if (node == NULL)
        return 0;
    return height(node->left) - height(node->right);
}

struct AVLNode* insert(struct AVLNode* node, int key)
{
    if (node == NULL)
        return newNode(key);

    if (key < node->key)
        node->left = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);
    else
        return node;

    node->height = 1 + max(height(node->left), height(node->right));

    int balance = getBalance(node);

    //ll
    if (balance > 1 && key < node->left->key)
        return rightRotate(node);

    // rr
    if (balance < -1 && key > node->right->key)
        return leftRotate(node);

    //lr
    if (balance > 1 && key > node->left->key)
        {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    // rl
    if (balance < -1 && key < node->right->key)
        {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}


struct AVLNode* minValueNode(struct AVLNode* node)
 {
    struct AVLNode* current = node;
    while (current->left != NULL)
        current = current->left;
    return current;
}


struct AVLNode* deleteNode(struct AVLNode* root, int key)
{

    if (root == NULL)
        {
        return root;
    }

    if (key < root->key)
        {
        root->left = deleteNode(root->left, key);
    } else if (key > root->key)
     {
        root->right = deleteNode(root->right, key);
    } else
    {

        struct AVLNode* temp = root->left;
        if (root->right != NULL)
            {
            temp = root->right;
            root->right = NULL;
        }

        if (temp == NULL)
            {
            temp = root;
            root = NULL;
        } else
        {
            *root = *temp;
        }

        free(temp);
    }

    if (root == NULL)
        {
        return root;
    }

    root->height = 1 + max(height(root->left), height(root->right));

    int balance = getBalance(root);

    // ll
    int balanceLeft = getBalance(root->left);
    if (balance > 1 && balanceLeft >= 0)
        {
        root = rightRotate(root);
    }

    // lr
    if (balance > 1 && balanceLeft < 0)
        {
        root->left = leftRotate(root->left);
        root = rightRotate(root);
    }

    // rr
    int balanceRight = getBalance(root->right);
    if (balance < -1 && balanceRight <= 0)
        {
        root = leftRotate(root);
    }

    // rl
    if (balance < -1 && balanceRight > 0)
        {
        root->right = rightRotate(root->right);
        root = leftRotate(root);
    }
    return root;
}

void printInOrder(struct AVLNode* root)
 {
    if (root != NULL)
        {
        printInOrder(root->left);
        printf("%d ", root->key);
        printInOrder(root->right);
    }
}


void printPreOrder(struct AVLNode* root)
{
    if (root != NULL)
    {
        printf("%d ", root->key);
        printPreOrder(root->left);
        printPreOrder(root->right);
    }
}


void printPostOrder(struct AVLNode* root)
 {
    if (root != NULL)
    {
        printPostOrder(root->left);
        printPostOrder(root->right);
        printf("%d ", root->key);
    }
}


void printTree(struct AVLNode* root, int space)
 {
    if (root == NULL)
        return;

    space += 10;

    printTree(root->right, space);

    printf("\n");
    for (int i = 10; i < space; i++)
        printf(" ");
    printf("%d\n", root->key);

    printTree(root->left, space);
}

int main()
 {
    struct AVLNode* root = NULL;
    FILE* file = fopen("numbers.txt", "w");
    int numCount;
    printf("Enter the number of random numbers to generate: ");
    scanf("%d", &numCount);

    printf("the number which r generated are ");
    for (int i = 0; i < numCount; i++)
        {
        int num = rand() % 100;
        printf("%d ", num);
        fprintf(file, "%d\n", num);
    }
    fclose(file);

    file = fopen("numbers.txt", "r");

    int num;
    while (fscanf(file, "%d", &num) != EOF) {
        root = insert(root, num);
    }
    fclose(file);

    printf("\nInitial AVL tree structure:\n");
    printTree(root, 0);

    int choice, value;

    do {
        printf("\n\n enter your choice \n");
        printf("1. insert the number\n");
        printf("2. Delete the number\n");
        printf("3. In-order traversal\n");
        printf("4. Pre-order traversal\n");
        printf("5. Post-order traversal\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
         {
            case 1:
                printf("Enter the number to insert: ");
                scanf("%d", &value);
                root = insert(root, value);
                printf("Number %d inserted successfully!\n", value);
                printf("Updated AVL tree structure:\n");
                printTree(root, 0);
                break;
            case 2:
                printf("Enter the number to delete: ");
                scanf("%d", &value);
                root = deleteNode(root, value);
                printf("Number %d deleted successfully!\n", value);
                printf("Updated AVL tree structure:\n");
                printTree(root, 0);
                break;
            case 3:
                printf("In-order traversal: ");
                printInOrder(root);
                printf("\n");
                break;
            case 4:
                printf("Pre-order traversal: ");
                printPreOrder(root);
                printf("\n");
                break;
            case 5:
                printf("Post-order traversal: ");
                printPostOrder(root);
                printf("\n");
                break;
            case 6:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
                break;
        }
    }
    while (choice != 6);

    return 0;
}
