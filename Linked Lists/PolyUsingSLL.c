// Implementation of polynomial equation using singly linked list
#include <stdio.h>
#include <malloc.h>
struct node
    {
        int num;
        int coeff;
        struct node *next;
    };
    struct node *start1 = NULL;
    struct node *start2 = NULL;
    struct node *start3 = NULL;
    struct node *start4 = NULL;
    struct node *last3 = NULL;
    struct node *create_poly(struct node *);
    struct node *display_poly(struct node *);
    struct node *add_poly(struct node *, struct node *, struct node *);
    struct node *add_node(struct node *, int, int);
    int main ()
        {
            int option;
            do
            {
                printf("\n1. Enter the first polynomial");
                printf("\n2. Display the first polynomial");
                printf("\n3. Enter the second polynomial");
                printf("\n4. Display the second polynomial");
                printf("\n5. Add the polynomials");
                printf("\n6. Display the results");
                printf("\n7. EXIT");
                printf ("\nEnter your option: ");
                scanf ("%d", &option);
                switch(option)
                    {
                        case 1: start1 = create_poly(start1);
                        break;
                        case 2: start1 = display_poly(start1);
                        break;
                        case 3: start2 = create_poly(start2);
                        break;
                        case 4: start2 = display_poly(start2);
                        break;
                        case 5: start3 = add_poly(start1, start2, start3);
                        break;
                        case 6: start3 = display_poly(start3);
                        break;
                    };
            } while (option!=7);
            getchar();
            return 0;
        }
    struct node *create_poly(struct node *start)
        {
            struct node *new_node, *ptr;
            int n, c;
            printf ("\n ENter the number: ");
            scanf ("%d", &n);
            printf ("\t Enter its coefficient: ");
            scanf ("%d", &c);
            while (n!=-1)
                {
                    if (start==NULL)
                        {
                            new_node = (struct node *)malloc(sizeof(struct node));
                            new_node->num = n;
                            new_node->coeff = c;
                            new_node->next = NULL;
                            start = new_node;
                        }
                    else
                        {
                            ptr = start;
                            while (ptr->next != NULL)
                                {
                                    ptr = ptr->next;
                                }
                            new_node = (struct node *)malloc(sizeof(struct node));
                            new_node->num = n;
                            new_node->coeff = c;
                            new_node->next = NULL;
                            ptr->next = new_node;
                        }
                    printf("\n Enter the number: ");
                    scanf("%d", &n);
                    if (n==-1)
                        {
                            break;
                        }
                    printf ("\t Enter its coefficient: ");
                    scanf("%d", &c);
                }
            return start;
        }
    struct node *display_poly(struct node *start)
        {
            struct node *ptr;
            ptr = start;
            while (ptr != NULL)
                {
                    printf("\n%d x %d\t", ptr->num, ptr->coeff);
                    ptr = ptr->next;
                }
            return start;
        }
    struct node *add_poly(struct node *start1, struct node *start2, struct node *start3)
        {
            struct node *ptr1, *ptr2;
            int sum_num, c;
            ptr1 = start1, ptr2 = start2;
            while (ptr1 != NULL && ptr2 != NULL)
                {
                    if (ptr1->coeff == ptr2->coeff)
                        {
                            sum_num = ptr1->num + ptr2->num;
                            start3 = add_node(start3, sum_num, ptr1->coeff);
                            ptr1 = ptr1->next;
                            ptr2 = ptr2->next;
                        }
                    else if (ptr1->coeff > ptr2->coeff)
                        {
                            start3 = add_node(start3, ptr1->num, ptr1->coeff);
                            ptr1 = ptr1->next;
                        }
                    else if (ptr1->coeff < ptr2->coeff)
                        {
                            start3 = add_node(start3, ptr2 -> num, ptr2 -> coeff);
                            ptr2 = ptr2 -> next;
                        }
                }
            if (ptr1 == NULL)
                {
                    while(ptr2 != NULL)
                        {
                            start3 = add_node(start3, ptr2 -> num, ptr2 -> coeff);
                            ptr2 = ptr2 -> next;
                        }
                }
            if (ptr2 == NULL)
                {
                    while(ptr1 != NULL)
                        {
                            start3 = add_node(start3, ptr1 -> num, ptr1 -> coeff);
                            ptr1 = ptr1 -> next;
                        }
                }
            return start3;
        }
    struct node *add_node(struct node *start, int n, int c)
        {
            struct node *ptr, * new_node;
            if (start == NULL)
                {
                    new_node = (struct node *)malloc(sizeof(struct node));
                    new_node->num = n;
                    new_node->coeff = c;
                    new_node->next = NULL;
                    start = new_node;
                }
            else
                {
                    ptr = start;
                    while (ptr->next != NULL)
                        {
                            ptr = ptr->next;
                        }
                    new_node = (struct node *)malloc(sizeof(struct node));
                    new_node->num = n;
                    new_node->coeff = c;
                    new_node->next = NULL;
                    ptr->next = new_node;
                }
            return start;
        }
