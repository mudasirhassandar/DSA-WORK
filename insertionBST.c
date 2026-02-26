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
struct node *insertion(struct node *root, int element)
{
    struct node *prev = NULL;
    struct node *temproot = root;
    if (root == NULL)
    {
        return createnode(element);
    }
    while (temproot != NULL)
    {
        prev = temproot;
        if (element == temproot->data)
        {
            printf("Duplicate Element is Not Allowed...\n");
            return root;
        }
        else if (element < temproot->data)
        {
            temproot = temproot->left;
        }
        else
        {
            temproot = temproot->right;
        }
    }
    struct node *newnode = createnode(element);
    if (element < prev->data)
        prev->left = newnode;
    else
    {
        prev->right = newnode;
    }
    return root;
}
void preorder(struct node *root)
{
    if (root != NULL)
    {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
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
    preorder(root);
    int element;
    printf("\nEnter the element you want insert = ");
    scanf("%d", &element);

    root = insertion(root, element);
    preorder(root);

    return 0;
}