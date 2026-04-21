//evaluate a postfix expression takes as input using stack

#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#define SIZE 10

struct stack{
    int top;
    int data[SIZE];
}s;

int isfull()
{
    if(s.top >= SIZE-1)
        return 1;
    else
        return 0;
}

int isempty()
{
    if(s.top == -1)
        return 1;
    else
        return 0;
}

void push(int val)
{
    if(isfull())
    {
        printf("Stack is overflow..");
        return;
    }
    else
    {
        s.top++;
        s.data[s.top]=val;
    }
}

int pop()
{
    if(isempty())
    {
        printf("\n Stack is Underflow..");
        return -1;
    }
    else
    {
        int val = s.data[s.top];
        s.top--;
        return val;
    }
}

int peep()
{
    if(isempty())
    {
        printf("\n Stack is Underflow..");
        return -1;
    }
    else
        return s.data[s.top];
}

void display()
{
    if(isempty())
    {
        printf("\n Stack is Underflow..");
        return;
    }
    int i;
    for(i=s.top; i >= 0 ; i--)
    {
        printf("\t%d -> ",s.data[i]);
    }
}


void main()
{
    char postfix[SIZE],ch;
    s.top=-1;
    printf("\n enter postfix evaluation : ");
    scanf("%s",postfix);
    int i,a,b,c,num;
    for(i=0;postfix[i]!='\0';i++)
    {
        ch=postfix[i];
        if(isdigit(ch))
        {
            num=ch-'0';
            push(num);
        }
        else
        {
            a=pop();
            b=pop();
            switch(ch)
            {
                case '+':
                    c = b+a;
                    break;
                case '-':
                    c = b-a;
                    break;
                case '*':
                    c = b*a;
                    break;
                case '/':
                    c = b/a;
                    break;
                default:
                    printf("\n Invalid choice");
            }
            push(c);
        }
    }
    printf("%d",pop());
}
