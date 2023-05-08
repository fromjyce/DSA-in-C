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
struct node *max(struct node *ptr)
    {
        if (ptr==NULL)
            {
                return NULL;
            }
        else if (ptr->right==NULL)
            {
                return ptr;
            }
        else
            {
                return max(ptr->right);
            }
    }
int main() 
    {
        int n,i;
        struct node *root = NULL, *ptr;
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
       ptr = max(root);
       if(ptr!=NULL)
            {
                printf("Maximum Key: %d\n", ptr->key);
            }
        return 0;
    }