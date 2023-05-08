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
struct node *search(struct node *ptr, int val)
    {
        while(ptr!=NULL)
            {
                if(val < ptr->data)
                    {
                        ptr = ptr->left;
                    }
                else if (val > ptr->data)
                    {
                        ptr = ptr->right;
                    }
                else
                    {
                        return ptr;
                    }
            }
        return NULL;
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
                root = insert_node(root,val);
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