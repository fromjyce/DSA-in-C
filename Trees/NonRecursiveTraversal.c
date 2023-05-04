#include <stdio.h>
#include <stdlib.h>
#define MAX 100
struct node 
    {
        int data;
        struct node *left;
        struct node *right;
    };
struct node *stack[MAX];
int top=-1;
void push_stack(struct node *item)
    {
        if (top==(MAX-1))
            {
                printf("\nStack Overflow \n");
                return;
            }
        top = top+1;
        stack[top] = item;
    }
struct node *pop_stack()
    {
        struct node *item;
        if (top==-1)
            {
                printf("Stack Underflow..\n");
                exit(1);
            }
        item = stack[top];
        top = top-1;
        return item;
    }
int stack_empty()
    {
        if (top==-1)
            {
                return 1;
            }
        else
            {
                return 0;
            }
    }
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
void preorder(struct node *root)
    {
        struct node *ptr = root;
        if (ptr==NULL)
            {
                printf("Tree is empty\n");
                return;
            }
        push_stack(ptr);
        while(!stack_empty())
            {
                ptr = pop_stack();
                printf("%d ", ptr->data);
                if(ptr->right!=NULL)
                    {
                        push_stack(ptr->right);
                    }
                if (ptr->left!=NULL)
                    {
                        push_stack(ptr->left);
                    }
            }
    }
void postorder(struct node *root)
{
    struct node *q = NULL, *ptr = root;
    if (ptr == NULL) {
        printf("Tree is empty\n");
        return;
    }
    while (1) {
        while (ptr != NULL) {
            push_stack(ptr);
            ptr = ptr->left;
        }
        if (stack_empty()) {
            return;
        }
        ptr = pop_stack();
        if (ptr->right == NULL || ptr->right == q) {
            printf("%d ", ptr->data);
            q = ptr;
            ptr = NULL;
        } else {
            push_stack(ptr);
            ptr = ptr->right;
        }
    }
    printf("\n");
}
void inorder(struct node *root)
    {
        struct node *ptr = root;
        if (ptr==NULL)
            {
                printf("Tree is empty\n");
                return;
            }
        while(1)
            {
                while(ptr->left!=NULL)
                    {
                        push_stack(ptr);
                        ptr = ptr->left;
                    }
                while (ptr->right==NULL)
                    {
                        printf("%d ", ptr->data);
                        if(stack_empty())
                            {
                                return;
                            }
                        ptr = pop_stack();
                    }
                printf("%d ", ptr->data);
                ptr = ptr->right;
            }
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
                root = insert_node(root,val);
            }
        printf("\nNodes in - Pre Order Traversal: ");
        preorder(root);
        printf("\nNodes in - In Order Traversal: ");
        inorder(root);
        printf("\nNodes in - Post Order Traversal: ");
        postorder(root);
        return 0;
    }
