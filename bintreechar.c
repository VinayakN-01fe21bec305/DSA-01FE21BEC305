#include<stdio.h>
#include<time.h>
#include<stdlib.h>

typedef struct node
{
    int data;
    struct node *left, *right;
} N;

FILE *fp, *pre, *in, *post;

void preorder(N *root)
{
    if (root == NULL)
        return;
    printf("%c ", root->data);
    fprintf(pre, "%c\n", root->data);
    preorder(root->left);
    preorder(root->right);
}

void inorder(N *root)
{
    if (root == NULL)
        return;

    inorder(root->left);
    printf("%c ", root->data);
    fprintf(in, "%c\n", root->data);
    inorder(root->right);
}

void postorder(N *root)
{
    if (root == NULL)
        return;
    postorder(root->left);
    postorder(root->right);
    printf("%c ", root->data);
    fprintf(post, "%c\n", root->data);
}

N *insert_NODE(N *root, int a)
{
    if (root == NULL)
    {
        root = (N *)malloc(sizeof(N));
        root->data = a;
        root->right = root->left = NULL;
        return root;
    }
    else if (a > root->data)
    {
        root->right = insert_NODE(root->right, a);
        return root;
    }
    else if (a < root->data)
    {
        root->left = insert_NODE(root->left, a);
        return root;
    }
}

int main()
{
    int n, i;
    int a;
    in = fopen("Inorder_Traversal.txt", "w");
    pre = fopen("Preorder_Traversal.txt", "w");
    post = fopen("Postorder_traversal.txt", "w");
    srand(time(NULL));
    fp = fopen("TREE.txt", "w+");
    N *root = NULL;
    printf("Enter the number of random numbers:\n");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        a = (rand() % 26) + 'A';
        fprintf(fp, "%c\n", a);
    }
    rewind(fp);
    for (i = 0; i < n; i++)
    {
        fscanf(fp, "%c\n", &a);
        root = insert_NODE(root, a);
    }
    printf("Preorder:\n");
    preorder(root);
    printf("\n");
    printf("Inorder:\n");
    inorder(root);
    printf("\n");
    printf("Postorder:\n");
    postorder(root);
    printf("\n");
}
