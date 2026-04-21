#include<stdio.h>
#include <stdlib.h>
#define SIZE 10
struct stack
{
    int top;
    int st[SIZE];
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
    if(s.top>=SIZE-1)
        return 1;
    else
        return 0;
}
void push(int ele)
{
    if(isfull())
    {
        printf("Stack is Full..");
        return;
    }
    else
    {
        s.top++;
        s.st[s.top]=ele;

    }
}
int pop()
{
    if(isempty())
    {
        printf("Stack is empty..");
        return -1;
    }
    else
    {

        int val = s.st[s.top];
        s.top--;
        return val;
    }
}
void display()
{
    if(isempty())
    {
        printf("Stack is Empty..\n");
        return;
    }
    int i;
    for(i=s.top;i>-1;i--)
    {
        printf("%d->",s.st[i]);
    }
}
int peep()
{
    if(isempty())
    {
        printf("Stack is Empty..");
        return -1;
    }
    else
    {
        return s.st[s.top];
    }
}
void main()
{
    int ch,val=0,item=0,pos=0;
    s.top = -1;

    while(1)
    {
        printf("\n1. Display");
        printf("\n2. Push");
        printf("\n3. Pop");
        printf("\n4. Peep");
        printf("\n5. Exit");

        printf("\nEnter your choice : ");
        scanf("%d",&ch);

        switch(ch)
        {
            case 1:
                display();
                break;
            case 2:
                printf("\nEnter Element to add : ");
                scanf("%d",&val);
                push(val);
                break;
            case 3:
                item = pop();
                printf("\nDeleted item %d",item);
                break;
            case 4:
                pos = peep();
                printf("\nTop possition : %d",pos);
                break;
            case 5:
                printf("\nByeeeeee");
                exit(0);
            default:
                printf("\nInvalid choice");
                break;

        }
    }
}
