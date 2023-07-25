#include<stdio.h>
#include<time.h>
#include<stdlib.h>

typedef struct node {
    int data;
    struct node *left, *right;
} N;

FILE *fp, *pre, *in, *post, *deleted;

void preorder(N *root) {
    if (root == NULL)
        return;
    printf("%d ", root->data);
    fprintf(pre, "%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

void inorder(N *root) {
    if (root == NULL)
        return;

    inorder(root->left);
    printf("%d ", root->data);
    fprintf(in, "%d ", root->data);
    inorder(root->right);
}

void postorder(N *root) {
    if (root == NULL)
        return;
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
    fprintf(post, "%d ", root->data);
}

N* insert(N *root, int a) {
    if (root == NULL) {
        root = (N*)malloc(sizeof(N));
        root->data = a;
        root->right = root->left = NULL;
        return root;
    } else if (a > root->data) {
        root->right = insert(root->right, a);
        return root;
    } else if (a < root->data) {
        root->left = insert(root->left, a);
        return root;
    }
}

N* minValueNode(N* node) {
    N* current = node;
    while (current && current->left != NULL)
        current = current->left;
    return current;
}

N* deleteNode(N* root, int key) {
    if (root == NULL)
        return root;

    if (key < root->data)
        root->left = deleteNode(root->left, key);
    else if (key > root->data)
        root->right = deleteNode(root->right, key);
    else {
        if (root->left == NULL) {
            N* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            N* temp = root->left;
            free(root);
            return temp;
        }
        N* temp = minValueNode(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

int main() {
    int n, i, a;
    in = fopen("in.txt", "w+");
    pre = fopen("pre.txt", "w+");
    post = fopen("post.txt", "w+");

    srand(time(NULL));
    fp = fopen("TREE.txt", "w+");
    N *root = NULL;

    printf("Enter the number of random numbers: ");
    scanf("%d", &n);

    printf("Generated random numbers: ");
    for (i = 0; i < n; i++) {
        a = (rand() % 100) + 1;
        fprintf(fp, "%d\n", a);
        printf("%d ", a);
    }

    rewind(fp);

    for (i = 0; i < n; i++) {
        fscanf(fp, "%d", &a);
        root = insert(root, a);
    }

    int num_deleted;
    printf("\nEnter the number of nodes to delete: ");
    scanf("%d", &num_deleted);

    int* deleted_numbers = malloc(num_deleted * sizeof(int));

    for (i = 0; i < num_deleted; i++) {
        printf("Enter the number to delete: ");
        scanf("%d", &deleted_numbers[i]);
    }

    for (i = 0; i < num_deleted; i++) {
        root = deleteNode(root, deleted_numbers[i]);
    }

    // Open the file to store the deleted numbers

    deleted = fopen("deleted.txt", "w+");
    if (deleted == NULL) {
        printf("Failed to open deleted.txt\n");
        exit(1);
    }

    for (i = 0; i < num_deleted; i++) {
        fprintf(deleted, "%d\n", deleted_numbers[i]);
    }

    fclose(deleted);

    printf("\nPreorder: ");
    preorder(root);
    printf("\nInorder: ");
    inorder(root);
    printf("\nPostorder: ");
    postorder(root);
    printf("\n");

    fclose(fp);
    fclose(pre);
    fclose(in);
    fclose(post);

    return 0;
}
