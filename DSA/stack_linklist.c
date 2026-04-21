#include<stdlib.h>
#include<stdio.h>

struct node {
    int data;
    struct node *next;
};

struct node *top = NULL;

struct node *createNode(int ele)
{
    struct node *newnode;
    newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data=ele;
    newnode->next=NULL;
    return newnode;
}

void push(int ele)
{
    struct node *newnode,*temp;
    newnode=createNode(ele);
    if(top==NULL)
    {
        top=newnode;
    }
    else
    {
        temp=top;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=newnode;
    }
}

void pop()
{
    struct node *temp,*prev;
    if(top==NULL)
    {
        printf("\n Stack is empty.");
        return;
    }
    else
    {
        temp=top;
        while(temp->next!=NULL)
        {
            prev = temp;
            temp=temp->next;
        }
        prev->next=NULL;
        free(temp);

    }
}

void isempty()
{
    if(top==NULL)
    {
        printf("\n Stack is empty.");
        return;
    }
    else
    {
        printf("\n Stack is not empty.");
        return;
    }
}

void display()
{
    struct node *temp;
    if(top==NULL)
    {
        printf("\n Stack is empty.");
        return;
    }
    else
    {
        int i;
        temp=top;
        while(temp!=NULL)
        {
            printf("%d <- \t ",temp->data);
            temp=temp->next;
        }
    }
}
void main()
{
    int ch,val,pos,c;
    while(1)
    {
        printf("\n1. Display");
        printf("\n2. pop");
        printf("\n3. push");
        printf("\n4. isempty");
        printf("\n5. Exit");

        printf("\n Enter your choice : ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
                display();
                break;
            case 2:
                pop();
                break;
            case 3:
                printf("\nEnter Value : ");
                scanf("%d",&val);
                push(val);
                break;
           case 4:
                isempty();
                break;
            case 5:
                printf("\nByeee");
                exit(0);
                break;
            default:
                printf("\n Invalid choice");
        }
    }
}
