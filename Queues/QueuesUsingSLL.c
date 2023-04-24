#include <stdio.h>
#include <stdlib.h>
struct node
    {
        int data;
        struct node *next;
    }*front = NULL, *rear = NULL;
void insert(int item);
int del();
int peek();
int isEmpty();
void display();
main()
    {
        int choice, item;
        while(1)
            {
                printf("\n1. Insert\n2. Delete \n3. Display the element at the front \n4. Display all the elements of the queue \n5. Quit \nEnter your choice: ");
                scanf("%d", &choice);
                switch(choice)
                        {
                            case 1: 
                                    printf("Input the element for adding in queue: ");
                                    scanf("%d", &item);
                                    insert(item);
                                    break;
                            case 2:
                                    printf("Deleted element is %d", del());
                                    break;
                            case 3:
                                    printf("Element at the front of the queue is %d", peek());
                                    break;
                            case 4:
                                    display();
                                    break;
                            case 5:
                                    exit(1);
                            default:
                                    printf("Wrong Choice");    
                        }
            }
    }
void insert(int item)
    {
        struct node *tmp;
        tmp = (struct node *)malloc(sizeof(struct node));
        if(tmp==NULL)
            {
                printf("Memory not available");
                return;
            }
        tmp->data = item;
        tmp->next = NULL;
        if(front==NULL)
            {
                front = tmp;
            }
        else
            {
                rear->next = tmp;
            }
        rear = tmp;
    }
int del()
    {
        struct node *tmp;
        int item;
        if(isEmpty())
            {
                printf("Queue Underflow");
                exit(1);
            }
        tmp = front;
        item = tmp->data;
        front = front->next;
        free(tmp);
        return item;
    }
int peek()
    {
        if(isEmpty())
            {
                printf("Queue Underflow");
                exit(1);
            }
        return front->data;
    }
int isEmpty()
    {
        if(front==NULL)
            {
                return 1;
            }
        else
            {
                return 0;
            }
    }
void display()
    {
        struct node *ptr;
        ptr = front;
        if(isEmpty())
            {
                printf("Queue is empty");
                return;
            }
        printf("Queue Elements: ");
        while(ptr!=NULL)
            {
                printf("%d ", ptr->data);
                ptr = ptr->next;
            }
        printf("\n\n");
    }
