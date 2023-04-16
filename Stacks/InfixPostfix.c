// Conversion of Infix to Postfix and Evaluation of Postfix
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
# define MAX 100
char stitop[MAX];
float step[MAX];
int topitop=-1;
int topep=-1;
void pushitop(char stitop[], char);
char popitop(char stitop[]);
void InfixtoPostfix(char source[], char target[]);
int getPriority(char);
void pushep(float step[], float val);
float popep(float step[]);
float evaluatePostfixExp(char exp[]);
int main ()
    {
        char infix[100], postfix[100];
        float val;
        printf("ENTER THE INFIX EXPRESSION: ");
        gets(infix);
        strcpy (postfix, "");
        InfixtoPostfix(infix, postfix);
        printf("CORRESPONDING POSTFIX EXPRESSION: ");
        puts(postfix);
        val = evaluatePostfixExp(postfix);
        printf("VALUE OF THE POSTFIX EXPRESSION: %.2f", val);
        getch();
        return 0;
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
                else if (source[i]==')')
                    {
                        while((topitop!=-1) && (stitop[topitop]!='('))
                            {
                                target[j] = popitop(stitop);
                                j++;
                            }
                        if (topitop==-1)
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
                        while((topitop!=-1) && (stitop[topitop]!= '(') && (getPriority(stitop[topitop])) >= getPriority(source[i]))
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
        while ((topitop!=-1) && (stitop[topitop]!='('))
            {
                target[j] = popitop(stitop);
                j++;
            }
        target[j] = '\0';
    }
int getPriority(char op)
    {
        if (op == '/' || op == '*' || op == '%')
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
        if (topitop==MAX-1)
            {
                printf("STACK OVERFLOW");
            }
        else
            {
                topitop++;
                stitop[topitop]=val;
            }
    }
char popitop(char stitop[])
    {
        char val = ' ';
        if (topitop==-1)
            {
                printf("\nSTACK UNDERFLOW");
            }
        else
            {
                val = stitop[topitop];
                topitop--;
            }
        return val;
    }
float evaluatePostfixExp(char exp[])
    {
        int i = 0;
        float op1, op2, value;
        while (exp[i] != '\0')
            {
                if (isdigit(exp[i]))
                    {
                        pushep(step, (float)(exp[i]-'0'));
                    }
                else
                    {
                        op2 = popep(step);
                        op1 = popep(step);
                        switch(exp[i])
                            {
                                case '+':
                                    value = op1 + op2;
                                    break;
                                case '-':
                                    value = op1 - op2;
                                    break;
                                case '*':
                                    value = op1 * op2;
                                    break;
                                case '/':
                                    value = op1 / op2 ;
                                    break;
                                case '%':
                                    value = (int)op1 % (int)op2;
                                    break;
                            }
                        pushep(step, value);
                    }
                i++;
            }
        return (popep(step));
    }
void pushep(float step[], float val)
    {
        if (topep==MAX-1)
            {
                printf("STACK OVERFLOW");
            }
        else
            {
                topep++;
                step[topep] = val;
            }
    }
float popep(float step[])
    {
        float val=-1;
        if(topep==-1)
            {
                printf("STACK UNDERFLOW");
            }
        else
            {
                val = step[topep];
                topep--;
            }
        return val;
    }