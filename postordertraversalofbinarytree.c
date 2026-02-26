#include <stdio.h>
#include <stdlib.h>

// Structure of a node
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};
void postordertraversal(struct Node *root)
{

    if (root != NULL)
    {

        postordertraversal(root->left);
        postordertraversal(root->right);
        printf("%d ", root->data);
    }
}

// Function to create tree from user input
struct Node *createTree()
{

    int value;

    // Ask user for data
    printf("Enter data (-1 for no node) = ");
    scanf("%d", &value);

    // If user enters -1, no node is created
    if (value == -1)
    {
        return NULL;
    }

    // Create new node
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));

    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;

    // Create left subtree
    printf("Enter left child of %d\n", value);
    newNode->left = createTree();

    // Create right subtree
    printf("Enter right child of %d\n", value);
    newNode->right = createTree();

    return newNode;
}

int main()
{

    struct Node *root = NULL;

    printf("Create Binary Tree\n");
    printf("------------------\n");

    // Start creating tree
    root = createTree();

    printf("\nBinary Tree Created Successfully!\n");
    postordertraversal(root);

    return 0;
}