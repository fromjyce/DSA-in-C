//RecursiveTraversal
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
void inorder(struct node *root)
    {
        if(root==NULL)
            {
                return;
            }
        inorder(root->left);
        printf("%d ", root->key);
        inorder(root->right);
    }
void postorder(struct node *root)
    {
        if(root==NULL)
            {
                return;
            }
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->key);
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
        printf("\nNodes in - Pre Order Traversal: ");
        preorder(root);
        printf("\nNodes in - In Order Traversal: ");
        inorder(root);
        printf("\nNodes in - Post Order Traversal: ");
        postorder(root);
        return 0;
    }
