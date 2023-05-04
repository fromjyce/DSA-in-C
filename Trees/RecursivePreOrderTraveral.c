//RecursivePreOrderTraversal
#include <stdio.h>
#include <stdlib.h>
struct node 
    {
        int key;
        struct node *left;
        struct node *right;
    };
struct node *insert(struct node *root, int val)
    {
        if (root==NULL)
            {
                root = (struct node *)malloc(sizeof(struct node));
                root->key = val;
                root->left = NULL;
                root->right = NULL;
            }
        else if (root->key < val)
            {
                root->right = insert(root->right,val);
            }
        else if (val < root->key)
        {
           root->left = insert(root->left, val);
        }
        else
            {
                printf("Entered Value is a Duplicate Value");
            }
        return root;
    }
void preorder(struct node *root)
    {
        if(root==NULL)
            {
                return;
            }
        printf("%d ", root->key);
        preorder(root->left);
        preorder(root->right);
    }
int main() 
    {
        int n,i;
        struct node *root = NULL;
        printf ("\nEnter the number of nodes that you want to insert: ");
        scanf ("%d", &n);
        root = NULL;
        for (i=0; i<n; i++)
            {
                int val;
                printf("Add Node: ");
                scanf("%d", &val);
                root = insert(root,val);
            }
        printf("Nodes in - Pre Order Traversal: ");
        preorder(root);
        return 0;
    }
