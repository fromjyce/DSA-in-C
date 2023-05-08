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
struct node *search (struct node *ptr, int val)
    {
        if (ptr==NULL)
            {
                return NULL;
            }
        else if (val < ptr->key)
            {
                return search(ptr->left,val);
            }
        else if (val > ptr->key)
            {
                return search(ptr->right,val);
            }
        else
            {
                return ptr;
            }
    }
int main() 
    {
        int n,i,sch;
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
       printf("Enter the element that you want to search: ");
       scanf("%d", &sch);
       ptr = search(root,sch);
       if(ptr==NULL)
        {
            printf("Key not present");
        }
        else
            {
                printf("Key present");
            }
       return 0;
    }