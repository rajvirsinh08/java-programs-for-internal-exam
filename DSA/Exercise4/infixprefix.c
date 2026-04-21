#include<stdio.h>
#include<string.h>
#include <ctype.h>
#include<conio.h>
#define MAX 50

struct stack {
    int top;
    char st[MAX];
}s;

int isempty()
{
    if(s.top==-1)
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
        return;
    else
    {
        s.top++;
        s.st[s.top] = ch;
    }
}

char pop()
{
    if(isempty())
        return '\0';
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
        return '\0';
    else
        return s.st[s.top];
}

int presedance(char op)
{
    if(op=='+' || op=='-')
        return 1;
    else if(op=='*' || op=='/')
        return 2;
    else if(op=='^')
        return 3;
    else
        return 0;

}

void infixtopostfix(char infix[], char postfix[])
{
    int i,k=0;
    for(i=0; infix[i]!='\0'; i++)
    {
        char n = infix[i];
        if(isalnum(n))
        {
            postfix[k++]=n;
        }
        else if(n=='(')
        {
            push(n);
        }
        else if(n==')')
        {
            while(!isempty()&&peep()!='(')
            {
                postfix[k++]=pop();
            }
            pop();

        }
        else
        {
            while(!isempty()&&presedance(peep())>=presedance(n))
            {
                postfix[k++]=pop();
            }
            push(n);
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
    char infix[MAX], postfix[MAX],rev[MAX];

    printf("Enter Infix Expression : ");
    scanf("%s", infix);

    // Step 1: Reverse infix
    strcpy(rev,strrev(infix));

    // Step 2: Change brackets
    for(int i=0; infix[i]!='\0'; i++)
    {
        if(infix[i]=='(')
            infix[i]=')';
        else if(infix[i]==')')
            infix[i]='(';
    }

    // Step 3: Convert to postfix
    infixtopostfix(infix, postfix);

    // Step 4: Reverse postfix
    strcpy(rev, strrev(infix));

    printf("Prefix Expression : %s", postfix);
}
