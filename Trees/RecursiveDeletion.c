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
struct node *del (struct node *ptr, int dval)
    {
        struct node *tmp, *succ;
        if (ptr==NULL)
            {
                pritnf("\nKEY NOT FOUND");
                return ptr;
            }
        if (dval < ptr->key)
            {
                ptr->left = del(ptr->left,dval);
            }
        else if (dval > ptr->key)
            {
                ptr->right = del(ptr->right,dval);
            }
        else
            {
                if (ptr->left!=NULL && ptr->right!=NULL)
                    {
                        succ = ptr->right;
                        while(succ->left)
                            {
                                succ = succ->left;
                            }
                        ptr->key = succ->key;
                        ptr->right = del(ptr->right, succ->key);
                    }
                else
                    {
                        tmp = ptr;
                        if (ptr->left!=NULL)
                            {
                                ptr = ptr->left;
                            }
                        else if (ptr->right!=NULL)
                            {
                                ptr=ptr->right;
                            }
                        else
                            {
                                ptr = NULL;
                            }
                        free(tmp);
                        printf("Deleted Successfully");
                    }
            }
        return ptr;
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
                root = insert(root,val);
            }
        printf("Enter the key that you want to delete: ");
        scanf("%d", &k);
        root = del(root,k);
        return 0;
    }