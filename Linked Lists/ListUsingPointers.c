// Pointer Based Implementation of Linked List ADT
#include <stdio.h>
#include <stdlib.h>
struct node {
    		int data;
    		struct node* next;
};
struct node *new, *head = NULL, *tail = NULL, *temp, *current, *prev, *next;
void create() {
    		int value;
    		new = (struct node*)malloc(sizeof(struct node));
    		printf("Enter the value: ");
    		scanf("%d", &value);
    		new->data = value;
    		new->next = NULL;
}
void insert() {
    		create();
    		if (head == NULL) {
        			head = new;
        			tail = new;
    		}
 else {
        			tail->next = new;
        			tail = new;
   		 }
}
void insertBegin() {
         if (head == NULL) {
        			printf("No Linked List found");
    		} 
else {
        			create();
        			new->next = head;
        			head = new;
    		}
}
void insertMiddle() {
    		if (head == NULL) {
        			printf("No Linked List found");
    		}
else {
        			create();
        			temp = head;
        			int pos, i;
        			printf("Enter the position where new node is to be inserted: ");
        			scanf("%d", &pos);
        			for (i = 0; i < pos - 1; i++) {
         		 	temp = temp->next;
       			}
        			new->next = temp->next;
        			temp->next = new;
    		}
}
void insertEnd() {
    		if (head == NULL) {
        			printf("No Linked List found");
    		}
else {
        			create();
        			tail->next = new;
        			tail = new;
    		}
}
void delBeg() {
    		if (head == NULL) {
              printf("No Linked List found");
   	 	}
else {
        			temp = head;
        			head = head->next;
        			free(temp);
    		}
}
void delMid() {
    		if (head == NULL) {
        			printf("No Linked List found");
    		} 
else {
        			temp = head;
        			int pos = 0, i;
        			printf("Enter the position which you want to delete: ");
        			scanf("%d", &pos);
        			for (i = 0; i < pos - 1; i++) {
            			temp = temp->next;
        			}
        			current = temp->next;
        			temp->next = current->next;
        			free(current);
    		}
}
void delEnd() {
    		if (head == NULL) {
        			printf("No Linked List found");
    		}
else {
        			temp = head;
        			while (temp->next != tail) {
            			temp = temp->next;
        			}
        			tail = temp;
        			temp = tail->next;
        			tail->next = NULL;
        			free(temp);
}
}
void traverse() {
    		printf("Updated Linked List:\n");
    		temp = head;
    		while (temp != NULL) {
        			printf("%d\n", temp->data);
        			temp = temp->next;
    		}
}
int main() {
options:
    	int c;
    	printf("Do you want to \n1. Insert a new value \n2. Delete a value \n3. Traverse the list \n4. Exit \nEnter your choice: ");
    	scanf("%d", &c);
    	if (c == 1) {
        		int c1;
        		printf("Do you want to \n1. Create a Node \n2. Insert at Beginning \n3. Insert in the Middle \n4. Insert at the End \nEnter your choice: ");
        		scanf("%d", &c1);
        		if (c1 == 1) {
            		insert();
            		goto options;
        		}
		else if (c1==2)
			{
				insertBegin();
				goto options;
			}
		else if (c1==3)
			{
				insertMiddle();
				goto options;
			}
		else if (c1==4)
			{
				insertEnd();
                                goto options;
    }
		else
			{
				printf ("ERROR");
				goto options;
			}
	}
else if (c==2)
		{
			int c2;
			printf ("Do you want to delete the value \n1. At Beginning \n2. In Middle \n3. At End \nEnter your choice: ");
			scanf ("%d", &c2);
			if (c2==1)
				{
					delBeg();
					goto options;
				}
			else if (c2==2)
				{
					delMid();
					goto options;
				}
			else if (c2==3)
				{
					delEnd();
					goto options;
				}
			else
				{
					printf ("ERROR");
					goto options;
				}
		}
else if (c==3)
		{
			traverse();
}
else
    		{
     			exit(0);
    		}
return 0;
}
