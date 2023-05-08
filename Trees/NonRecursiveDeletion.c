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
struct node *del(struct node *root, int dval)
    {
        struct node *par, *ptr, *child, *succ, *parsucc;
        ptr = root;
        par = NULL;
        while(ptr!=NULL)
            {
                if(dval==ptr->data)
                    {
                        break;
                    }
                par = ptr;
                if(dval < ptr->data)
                    {
                        ptr = ptr->left;
                    }
                else
                    {
                        ptr = ptr->right;
                    }
            }
        if (ptr==NULL)
            {
                printf("\nKEY NOT FOUND");
                return root;
            }
        if (ptr->left!=NULL && ptr->right!=NULL)
            {
                parsucc = ptr;
                succ = ptr->right;
                while (succ->left!=NULL)
                    {
                        parsucc = succ;
                        succ = succ->left;
                    }
                ptr->data = succ->data;
                ptr = succ;
                par = parsucc; 
            }
        if (ptr->left!=NULL)
            {
                child = ptr->left;
            }
        else
            {
                child = ptr->right;
            }
        if(par==NULL)
            {
                root = child;
            }
        else if (ptr==par->left)
            {
                par->left = child;
            }
        else
            {
                par->right = child;
            }
        free(ptr);
        printf("Key Deleted Successfully");
        return root;
    }
int main()
    {
        int n,i,k;
        struct node *root = NULL, *ptr1, *ptr2;
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
        printf("Enter the key that you want to delete: ");
        scanf("%d", &k);
        root = del(root,k);
        return 0;
    }