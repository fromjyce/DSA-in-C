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
struct node *min(struct node *ptr)
    {
        if (ptr!=NULL)
            {
                while(ptr->left != NULL)
                    {
                        ptr = ptr->left;
                    }
            }
        return ptr;
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
int main ()
    {
        struct node *root=NULL, *ptr;
        int choice,k;
        while(1)
            {
                printf("\n1. Insert \n2. Delete \n3. Search \n4. Find Minimum \n5. Find Maximum \n6. Retrieve \n7. Quit \nEnter your Choice: ");
                scanf("%d", &choice);
                switch(choice)
                    {
                        case 1:
                            printf("\nEnter the key to be inserted: ");
                            scanf("%d", &k);
                            ptr = insert_node(root,k);
                            break;
                        case 2:
                            printf("Enter the key to be deleted: ");
                            scanf("%d", &k);
                            root = del(root,k);
                            break;
                        case 3:
                            printf("Enter the key to be searched: ");
                            scanf("%d", &k);
                            ptr = search(root,k);
                            if (ptr==NULL)
                                {
                                    printf("Key not present");
                                }
                            else
                                {
                                    printf("Key present");
                                }
                            break;
                        case 4:
                            ptr = min(root);
                            if (ptr!=NULL)
                                {
                                    printf("Minimum Key: %d", ptr->data);
                                }
                            break;
                        case 5:
                            ptr = max(root);
                            if (ptr!=NULL)
                                {
                                    printf("Maximum Key: %d", ptr->data);
                                }
                            break;
                        case 6:
                            printf("\nNodes in - Pre Order Traversal: ");
                            preorder(root);
                            printf("\nNodes in - In Order Traversal: ");
                            inorder(root);
                            printf("\nNodes in - Post Order Traversal: ");
                            postorder(root);
                            break;
                        default:
                            printf("INVALID CHOICE");
                    }
            }
        return 0;
    }