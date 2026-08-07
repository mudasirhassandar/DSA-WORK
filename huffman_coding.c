#include <stdio.h>
#include <stdlib.h>
struct node
{
    char data;
    int freq;
    struct node *left, *right;
};
struct node *createnode(char data, int freq)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->freq = freq;
    newnode->left = NULL;
    newnode->right = NULL;
    return newnode;
}
void printcodes(struct node *root, int arr[], int top)
{
    if (root->left)
    {
        arr[top] = 0;
        printcodes(root->left, arr, top + 1);
    }
    if (root->right)
    {
        arr[top] = 1;
        printcodes(root->right, arr, top + 1);
    }
    if (!root->left && !root->right)
    {
        printf("%c-> ", root->data);
        for (int i = 0; i < top; i++)
        {
            printf("%d", arr[i]);
        }
        printf("\n");
    }
}
int main()
{
    char ch[] = {'A', 'B', 'C', 'D', 'E', 'F'};
    int freq[] = {5, 9, 12, 13, 16, 45};
    int n = 6;

    // creation of nodes
    struct node *A = createnode(ch[0], freq[0]);
    struct node *B = createnode(ch[1], freq[1]);
    struct node *C = createnode(ch[2], freq[2]);
    struct node *D = createnode(ch[3], freq[3]);
    struct node *E = createnode(ch[4], freq[4]);
    struct node *F = createnode(ch[5], freq[5]);
    // creation of tree
    struct node *N1 = createnode('$', 14);
    N1->left = A;
    N1->right = B;
    struct node *N2 = createnode('$', 25);
    N2->left = C;
    N2->right = D;
    struct node *N3 = createnode('$', 30);
    N3->left = N1;
    N3->right = E;
    struct node *N4 = createnode('$', 55);
    N4->left = N3;
    N4->right = N2;
    struct node *ROOT = createnode('$', 14);
    ROOT->left = N4;
    ROOT->right = F;
    int arr[100];
    printf("\nHuffman Codes\n");
    printcodes(ROOT, arr, 0);
    return 0;
}