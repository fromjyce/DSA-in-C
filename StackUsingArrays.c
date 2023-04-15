// Implementation of Stacks using Arrays 
#include <stdio.h>
#define MAX_SIZE 100
int stack[MAX_SIZE];
int i,j,n;
int choice = 0, top = -1;
void push();
void pop();
void show();
void peek();
void main()
    {
        printf ("Enter the number of elements in the stack: ");
        scanf ("%d", &n);
        while(choice!=5)
            {
                printf("\n1. Push \n2. Pop \n3. Show \n4. Peek \n5. Exit");
                printf("\nEnter your choice: ");
                scanf("%d", &choice);
                switch(choice)
                    {
                        case 1: 
                            {
                                push();
                                break;
                            }
                        case 2:
                            {
                                pop();
                                break;
                            }
                        case 3:
                            {
                                show();
                                break;
                            }
                        case 4:
                            {
                                peek();
                                break;
                            }
                        case 5:
                            {
                                printf("EXITED");
                                break;
                            }
                        default:
                            {
                                printf("ENTER A VALID CHOICE!!!");
                            }

                    };
            }
    }
void push()
    {
        int val;
        if (top == n)
            {
                printf ("OVERFLOW");
            }
        else
            {
                printf ("VALUE: ");
                scanf("%d", &val);
                top = top+1;
                stack[top] = val;
            }
    }
void pop()
    {
        if (top==-1)
            {
                printf("UNDERFLOW");
            }
        else
            {
                top = top-1;
            }
    }
void show()
    {
        for (i=top;i>=0; i--)
            {
                printf("%d\n", stack[i]);
            }
        if (top==-1)
            {
                printf("STACK IS EMPTY");
            }
    }
void peek()
    {
        if(top==-1)
            {
                printf("STACK IS EMPTY");
            }
        else
            {
                printf("TOP ELEMENT OF THE STACK is %d", stack[top]);
            }
    }


