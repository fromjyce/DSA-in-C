#include <stdio.h>
#include <stdlib.h>
#define MAX 100
struct node 
    {
        int data;
        struct node *left;
        struct node *right;
    };
struct node *insert_node(struct node *root, int key)
    {
        struct node *tmp, *par, *ptr;
        ptr = root;
        par = NULL;
        while (ptr!=NULL)
            {
                par = ptr;
                if (key < ptr->data)
                    {
                        ptr = ptr->left;
                    }
                else if (key > ptr->data)
                    {
                        ptr = ptr->right;
                    }
                else
                    {
                        printf("Duplicate Key");
                        return root;
                    }
            }
        tmp = (struct node *)malloc(sizeof(struct node));
        tmp->data = key;
        tmp->left = NULL;
        tmp->right = NULL;
        if (par==NULL)
            {
                root = tmp;
            }
        else if (key < par->data)
            {
                par->left = tmp;
            }
        else
            {
                par->right = tmp;
            }
        return root;
    }
struct node *max(struct node *ptr)
    {
        if (ptr!=NULL)
            {
                while(ptr->right != NULL)
                    {
                        ptr = ptr->right;
                    }
            }
        return ptr;
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
                root = insert_node(root,val);
            }
        ptr = max(root);
        if(ptr!=NULL)
            {
                printf("Maximum Key: %d\n", ptr->data);
            }
        return 0;
    }