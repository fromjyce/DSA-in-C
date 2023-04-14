// Implementation of Stacks using Singly Linked List
#include <stdio.h>
#include <malloc.h>
struct stack 
    {
        int data;
        struct stack *next;
    };
    struct stack *top = NULL;
    struct stack *push(struct stack *, int);
    struct stack *display(struct stack *);
    struct stack *pop (struct stack *);
    int peek (struct stack *);

    int main (int argc, char *arg[])
        {
            int val, option;
            do 
                {
                    printf ("\n1. PUSH \n2. POP \n3. PEEK \n4. DISPLAY \n5. EXIT \nEnter your option: ");
                    scanf("%d", &option);
                    switch(option)
                        {
                            case 1:
                                {
                                    printf("\nNUMBER TO BE PUSHED ON STACK: ");
                                    scanf("%d", &val);
                                    top = push(top, val);
                                    break;
                                }
                            case 2:
                                {
                                    top = pop(top);
                                    break;
                                }
                            case 3:
                                {
                                    val = peek(top);
                                    if (val != -1)
                                        {
                                            printf("VALUE AT THE TOP OF THE STACK IS %d", val);
                                        }
                                    else
                                        {
                                            printf("STACK IS EMPTY");
                                            break;
                                        }
                                }
                            case 4:
                                {
                                    top = display(top);
                                    break;
                                }
                        }
                } while(option!=5);
            return 0;
        }
    struct stack *push(struct stack *top, int val)
        {
            struct stack *ptr;
            ptr = (struct stack*)malloc(sizeof(struct stack));
            ptr->data = val;
            if (top == NULL)
                {
                    ptr->next = NULL;
                    top = ptr;
                }
            else
                {
                    ptr->next=top;
                    top = ptr;
                }
            return top;
        }
    struct stack *display(struct stack *top)
        {
            struct stack *ptr;
            ptr = top;
            if (top == NULL)
                {
                    printf("STACK IS EMPTY");
                }
            else
                {
                    while(ptr != NULL)
                        {
                            printf(" \n %d", ptr->data);
                            ptr = ptr->next;
                        }
                }
            return top;
        }
    struct stack *pop(struct stack *top)
        {
            struct stack *ptr;
            ptr = top;
            if (top == NULL)
                {
                    printf("STACK UNDERFLOW");
                }
            else
                {
                    top = top->next;
                    printf("VALUE BEING DELETED IS %d", ptr->data);
                }
            return top;
        }
    int peek(struct stack *top)
        {
            if (top == NULL)
                {
                    return -1;
                }
            else
                {
                    return top->data;
                }
        }