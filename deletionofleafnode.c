#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *left;
    struct node *right;
};
struct node *createnode(int value)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = value;
    newnode->left = NULL;
    newnode->right = NULL;
    return newnode;
}
struct node *insertBST(struct node *root, int value)
{
    if (root == NULL)
    {
        return createnode(value);
    }
    if (value < root->data)
    {
        root->left = insertBST(root->left, value);
    }
    else if (value > root->data)
    {
        root->right = insertBST(root->right, value);
    }

    return root;
}
struct node *inorderpre(struct node *root)
{
    root = root->left;
    while (root->right != NULL)
    {
        root = root->right;
    }
    return root;
}
struct node *deletion(struct node *root, int element)
{
    struct node *inpre = NULL;
    if (root == NULL)
    {
        return NULL;
    }
    if (root->left == NULL && root->right == NULL)
    {
        free(root);
        return NULL;
    }
    if (element < root->data)
    {
        root->left = deletion(root->left, element);
    }
    else if (element > root->data)
    {
        root->right = deletion(root->right, element);
    }
    else
    {
        inpre = inorderpre(root);
        root->data = inpre->data;
        root->left = deletion(root->left, inpre->data);
    }
    return root;
}
void inorder(struct node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d ", root->data);

        inorder(root->right);
    }
}
int main()
{
    struct node *root = NULL;
    int value;
    printf("Create Binary Search Tree\n");
    printf("Enter -1 to stop\n");
    printf("-------------------------\n");
    while (1)
    {
        printf("Enter the data = ");
        scanf("%d", &value);
        if (value == -1)
            break;
        root = insertBST(root, value);
    }
    inorder(root);
    int element;
    printf("\nEnter the element you want Delete = ");
    scanf("%d", &element);

    root = deletion(root, element);
    inorder(root);

    return 0;
}