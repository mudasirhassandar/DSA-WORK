#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

// Create a new node
struct Node *createNode(int value)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to check height and balance
int checkHeight(struct Node *root)
{
    if (root == NULL)
        return 0;

    int lh = checkHeight(root->left);
    if (lh == -1)
        return -1;

    int rh = checkHeight(root->right);
    if (rh == -1)
        return -1;

    if (abs(lh - rh) > 1)
        return -1;

    return 1 + (lh > rh ? lh : rh);
}

// Wrapper function
int isBalanced(struct Node *root)
{
    return checkHeight(root) != -1;
}

int main()
{
    struct Node *root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);

    if (isBalanced(root))
        printf("Binary Tree is Balanced\n");
    else
        printf("Binary Tree is NOT Balanced\n");

    return 0;
}
