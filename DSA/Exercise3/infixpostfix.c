#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#define MAX 10
struct stack{
    int top;
    char st[MAX];
}s;
int isempty()
{
    if(s.top == -1)
        return 1;
    else
        return 0;
}

int isfull()
{
    if(s.top>=MAX-1)
        return 1;
    else
        return 0;
}
void push(char ch)
{
    if(isfull())
    {
        printf("Stack is Full...");
        return '\0';
    }
    else
    {
        s.top++;
        s.st[s.top]=ch;
    }
}
char pop()
{
    if(isempty())
    {
        printf("Stack is Empty...");
        return '\0';
    }
    else
    {
        char val = s.st[s.top];
        s.top--;
        return val;
    }
}
char peep()
{
    if(isempty())
    {
        printf("Stack is Empty.");
        return '\0';
    }
    else
        return s.st[s.top];
}
int precedence(char op)
{
    if(op == '-' || op=='+')
        return 1;
    else if(op=='*' || op=='/')
        return 2;
    else if(op=='^')
        return 3;
    else
        return 0;
}
void infixtopostfix(char infix[],char postfix[])
{
    int i,k=0;
    char ch;
    for(i=0 ; infix[i]!='\0'; i++)
    {
        ch = infix[i];
        if(isalnum(ch))
        {
            postfix[k++]=ch;
        }
        else if(ch=='(')
        {
            push(ch);
        }
        else if(ch==')')
        {
            while(!isempty()&&peep()!='(')
            {
                postfix[k++]=pop();
            }
            pop(); // remove ( from stack
        }
        else
        {

            while(!isempty()&&precedence(peep())>=precedence(ch))
            {
                postfix[k++]=pop();
            }
            push(ch);
        }
    }
    while(!isempty())
    {
        postfix[k++]=pop();
    }
    postfix[k]='\0';
}
void main()
{
    char infix[MAX], postfix[MAX];
    printf("Enter Infix Expression : ");
    scanf("%s",&infix);
    infixtopostfix(infix,postfix);
    printf("Postfix Expression : %s",postfix);
}
