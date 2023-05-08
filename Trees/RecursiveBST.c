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
struct node *min(struct node *ptr)
    {
        if (ptr==NULL)
            {
                return NULL;
            }
        else if (ptr->left==NULL)
            {
                return ptr;
            }
        else
            {
                return min(ptr->left);
            }
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
                            ptr = insert(root,k);
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
                                    printf("Minimum Key: %d", ptr->key);
                                }
                            break;
                        case 5:
                            ptr = max(root);
                            if (ptr!=NULL)
                                {
                                    printf("Maximum Key: %d", ptr->key);
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