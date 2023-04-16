// Conversion of Infix to Prefix and Evaluation of Prefix
#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#define MAX 100
int stkep[10];
int topep =-1;
int popep();
void pushep(int);
int get_type(char c);
char stitop[MAX];
int topitop=-1;
void reverse(char str[]);
void pushitop(char stitop[], char);
char popitop(char stitop[]);
void InfixtoPostfix(char source[], char target[]);
int getPriority(char);
char infix[100], postfix[100], temp[100]; 
int main()
    {
        int len, val ,i, opr1, opr2, res;
        printf("ENTER THE INFIX EXPRESSION: ");
        gets(infix);
        reverse(infix);
        strcpy(postfix, "");
        InfixtoPostfix(temp, postfix);
        strcpy(temp, "");
        reverse(postfix);
        printf("CORRESPONDING PREFIX EXPRESSION: ");
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
        printf("RESULT: %d", stkep[0]);
        getch();
        return 0;
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
                i++;
                j--;
            }
        temp[i] = '\0';
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
                        pushitop(stitop, source[i]);
                        i++;
                    }
                else if (source[i] == ')')
                    {
                        while((topitop!=-1) && (stitop[topitop]!='('))
                            {
                                target[j] = popitop(stitop);
                                j++;
                            }
                        if(topitop==-1)
                            {
                                printf("INCORRECT EXPRESSION");
                                exit(1);
                            }
                        temp = popitop(stitop);
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
                        while((topitop!=-1) && (stitop[topitop]!='(') && (getPriority(stitop[topitop])) > getPriority(source[i]))
                            {
                                target[j] = popitop(stitop);
                                j++;
                            }
                        pushitop(stitop, source[i]);
                        i++;
                    }
                else
                    {
                        printf("INCORRECT ELEMENT IN EXPRESSION");
                        exit(1);
                    }
            }
        while((topitop!=-1) && (stitop[topitop]!='('))
            {
                target[j] = popitop(stitop);
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
void pushitop(char stitop[], char val)
    {
        if (topitop == MAX-1)
            {
                printf("STACK OVERFLOW");
            }
        else
            {
                topitop++;
                stitop[topitop] = val;
            }
    }
char popitop(char stitop[])
    {
        char val = ' ';
        if (topitop==-1)
            {
                printf("STACK UNDERFLOW");
            }
        else
            {
                val = stitop[topitop];
                topitop--;
            }
        return val;
    }
void pushep(int val)
    {
        stkep[++topep] = val;
    }
int popep()
    {
        return (stkep[topep--]);
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