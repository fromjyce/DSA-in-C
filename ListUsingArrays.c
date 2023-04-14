# Array Implementation of List ADT
#include <stdio.h>
#include <stdlib.h>
#define SIZE 100
int main () {
int n;
printf ("Enter the size of the array: ");
scanf ("%d", &n);
int a[n];
int i;
if (n<=SIZE)
		{
			printf ("Enter the elements of the array: \n");
			for (i=0; i<n; i++)
				{
					printf ("Element %d: ",i+1);
					scanf ("%d", &a[i]);
				}
		}
else
  {
    printf ("Enter the size of the array smaller than or equal to 100.\n");
  }
options: 
int c;
printf ("Do you want to \n1. Insert \n2. Delete \n3. Search \n4. Display \n5. Exit \nEnter your choice: ");
scanf ("%d", &c);
if  (c==1)
		{
			int x,pos;
			printf ("Enter the element: ");
			scanf ("%d", &x);
			printf ("Enter the position: ");
			scanf ("%d", &pos);
			n++;
			for (i=n-1; i>=pos;i--)
				{
					a[i]=a[i-1];
}
			a[pos-1]=x;
			goto options;
		}
else if (c==2)
		{
			int p;
			printf ("Enter the position: ");
			scanf ("%d", &p);
			if (p<0 || p>n)
				{
					printf ("Deletion is not possible.");
				}
			else
				{
					for (i=p-1; i<n-1; i++)
						{
							a[i]=a[i+1];
						}
					n--;
				}
			goto options;
		}
else if (c==3)
		{
			int search,s;
			printf ("Enter the element: ");
			scanf ("%d", &search);
			for (i=0; i<n; i++)
				{
					if(search==a[i])
						{
							s=1;
							break;
						}
				}
			if (s==1)
				{
printf ("Searched element is present in the array.\n");
				}
			else 
				{
printf ("Searched element is not present in the array\n");
				}
			goto options;
		}
else if (c==4)
		{
			printf ("Displaying the elements of the array: \n");
			for (i=0; i<n; i++)
				{
					printf ("%d ", a[i]);
				}
			printf ("\n");
			goto options;
		}
else
		{
			exit(0);
		}
return 0;
}
