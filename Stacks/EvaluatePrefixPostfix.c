// Conversion of Infix to Prefix and Postfix
#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#define MAX 100
char st[MAX];
int top=-1;
void reverse(char str[]);
void push(char st[], char);
char pop(char st[]);
void PostfixtoPrefix(char source[], char target[]);
void InfixtoPostfix(char source[], char target[]);
int getPriority(char);
char infix[100], postfix[100], temp[100];
int stk[10];
int topep =-1;
int popep();
void pushep(int);
int get_type(char c);
int main() 
    {
        int len, val ,i, opr1, opr2, res;
        printf("ENTER THE INFIX EXPRESSION: ");
        gets(infix);
        strcpy(postfix, "");
        InfixtoPostfix(infix, postfix);
        printf("POSTFIX EXPRESSION: ");
        puts(postfix);
        reverse(infix);
        strcpy(postfix, "");
        PostfixtoPrefix(temp, postfix);
        strcpy(temp, "");
        reverse(postfix);
        printf("PREFIX EXPRESSION: ");
        puts(temp);
        len = strlen(temp);
        for (i=len-1; i>=0; i--)
            {
                switch(get_type(temp[i]))
                    {
                        case 0:
                            val = temp[i] - '0';
                            pushep(val);
                            break;
                        case 1:
                            opr1 = popep();
                            opr2 = popep();
                            switch(temp[i])
                                {
                                    case '+':
                                        res = opr1+opr2;
                                        break;
                                    case '-':
                                        res = opr1 - opr2;
                                        break;
                                    case '*':
                                        res = opr1*opr2;
                                        break;
                                    case '/':
                                        res = opr1/opr2;
                                        break;
                                }
                            pushep(res);
                    }
            }
        printf("RESULT: %d", stk[0]);
        getch();
        return 0;
    }
void pushep(int val)
    {
        stk[++topep] = val;
    }
int popep()
    {
        return (stk[topep--]);
    }
int get_type(char c)
    {
        if(c=='+' || c== '-' || c=='*' || c == '/')
            {
                return 1;
            }
        else
            {
                return 0;
            }
    }
void InfixtoPostfix(char source[], char target[])
    {
        int i=0, j=0;
        char temp;
        strcpy(target, "");
        while(source[i]!='\0')
            {
                if (source[i]=='(')
                    {
                        push(st, source[i]);
                        i++;
                    }
                else if (source[i]==')')
                    {
                        while((top!=-1) && (st[top]!='('))
                            {
                                target[j] = pop(st);
                                j++;
                            }
                        if (top==-1)
                            {
                                printf("INCORRECT EXPRESSION");
                                exit(1);
                            }
                        temp = pop(st);
                        i++;
                    }
                else if (isdigit(source[i]) || isalpha(source[i]))
                    {
                        target[j] = source[i];
                        j++;
                        i++;
                    }
                else if (source[i] == '+' || source[i] == '-' || source[i] == '*' || source[i] == '/' || source[i] == '%')
                    {
                        while((top!=-1) && (st[top]!= '(') && (getPriority(st[top])) >= getPriority(source[i]))
                            {
                                target[j] = pop(st);
                                j++;
                            }
                        push(st, source[i]);
                        i++;
                    }
                else
                    {
                        printf("INCORRECT ELEMENT IN EXPRESSION");
                        exit(1);
                    }
            }
        while ((top!=-1) && (st[top]!='('))
            {
                target[j] = pop(st);
                j++;
            }
        target[j] = '\0';
    }

void reverse(char str[])
    {
        int len, i=0, j=0;
        len = strlen(str);
        j = len-1;
        while(j>=0)
            {
                if (str[j] == '(')
                    {
                        temp[i] = ')';
                    }
                else if (str[j] == ')')
                    {
                        temp[i] = '(';
                    }
                else
                    {
                        temp[i] = str[j];
                    }
                i++ , j--;
            }
        temp[i] = '\0';
    }
void PostfixtoPrefix(char source[], char target[])
    {
        int i=0, j=0;
        char temp;
        strcpy(target, "");
        while(source[i]!='\0')
            {
                if (source[i]=='(')
                    {
                        push(st, source[i]);
                        i++;
                    }
                else if (source[i] == ')')
                    {
                        while((top!=-1) && (st[top]!='('))
                            {
                                target[j] = pop(st);
                                j++;
                            }
                        if(top==-1)
                            {
                                printf("INCORRECT EXPRESSION");
                                exit(1);
                            }
                        temp = pop(st);
                        i++;
                    }
                else if (isdigit(source[i]) || isalpha(source[i]))
                    {
                        target[j] = source[i];
                        j++;
                        i++;
                    }
                else if (source[i] == '+' || source[i] == '-' || source[i] == '*' || source[i] == '/' || source[i] == '%')
                    {
                        while((top!=-1) && (st[top]!='(') && (getPriority(st[top])) > getPriority(source[i]))
                            {
                                target[j] = pop(st);
                                j++;
                            }
                        push(st, source[i]);
                        i++;
                    }
                else
                    {
                        printf("INCORRECT ELEMENT IN EXPRESSION");
                        exit(1);
                    }
            }
        while((top!=-1) && (st[top]!='('))
            {
                target[j] = pop(st);
                j++;
            }
        target[j]='\0';
    }
int getPriority(char op)
    {
        if(op=='/' || op == '*' || op == '%')
            {
                return 2;
            }
        else if (op == '+' || op == '-')
            {
                return 1;
            }
        else
            {
                return 0;
            }
    }
void push(char st[], char val)
    {
        if (top == MAX-1)
            {
                printf("STACK OVERFLOW");
            }
        else
            {
                top++;
                st[top] = val;
            }
    }
char pop (char st[])
    {
        char val = ' ';
        if (top==-1)
            {
                printf("STACK UNDERFLOW");
            }
        else
            {
                val = st[top];
                top--;
            }
        return val;
    }
