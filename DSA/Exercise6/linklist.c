#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *head = NULL;

struct node* createNode(int ele)
{
    struct node *newnode;
    newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data=ele;
    newnode->next=NULL;
    return newnode;
}

void insertatbeg(int ele)
{
    struct node *newnode;
    newnode = createNode(ele);
    newnode->next=head;
    head=newnode;
}

void insertatend(int ele)
{
    struct node *newnode, *temp;
    newnode = createNode(ele);
    temp=head;
    if(head==NULL)
    {
        head=newnode;
    }
    else
    {
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=newnode;
    }
}

void insertatpos(int ele,int pos)
{
    struct node *newnode, *temp;
    newnode=createNode(ele);
    int i=1;
    temp=head;
    while(i<pos)
    {
        temp=temp->next;
        i++;
    }
    newnode->next=temp->next;
    temp->next=newnode;
}

void display()
{
    struct node *temp;
    temp=head;
    while(temp!=NULL)
    {
        printf("\t%d -> ",temp->data);
        temp=temp->next;

    }
    printf("\tNULL");
}

void deleteatstart()
{
    if(head==NULL)
    {
        printf("\n Linklist is empty");
        return;
    }
    struct node *temp;
    temp=head;
    head = temp->next;
    free(temp);
}

void deleteatend()
{
    if(head==NULL)
    {
        printf("\n Linklist is empty");
        return;
    }
    struct node *temp,*prev;
    temp=head;
    while(temp->next!=NULL)
    {
        prev=temp;
        temp=temp->next;
    }
    if(temp==head)
    {
        head==NULL;
    }
    else
    {
        prev->next=NULL;
        free(temp);
    }
}

void deleteatpos(int pos)
{
    struct node *temp,*nextnode;
    temp=head;
    int i=1;
    while(i<pos-1)
    {
        temp=temp->next;
        i++;
    }
    nextnode = temp->next;
    temp->next=nextnode->next;
    free(nextnode);
}

int count()
{
    if(head==NULL)
    {
        return 0;
    }
    int c=0;
    struct node *temp;
    temp=head;
    while(temp!=NULL)
    {
        temp=temp->next;
        c++;
    }
    return c;
}
void main()
{
    int ch,val,pos,c;
    while(1)
    {
        printf("\n1. Display");
        printf("\n2. Insert at end");
        printf("\n3. Insert at Begining");
        printf("\n4. Insert at after specific position");
        printf("\n5. Delete at start");
        printf("\n6. Delete at End");
        printf("\n7. Delete at specific position");
        printf("\n8. Count");
        printf("\n9. Exit");

        printf("\n Enter your choice : ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
                display();
                break;
            case 2:
                printf("\nEnter Value : ");
                scanf("%d",&val);
                insertatend(val);
                break;
            case 3:
                printf("\nEnter Value : ");
                scanf("%d",&val);
                insertatbeg(val);
                break;
            case 4:
                printf("\nEnter Value and position : ");
                scanf("%d %d",&val,&pos);
                insertatpos(val,pos);
                break;
            case 5:
                deleteatstart();
                break;
            case 6:
                deleteatend();
                break;
            case 7:
                printf("\nEnter position : ");
                scanf("%d",&pos);
                deleteatpos(pos);
                break;
            case 8:
                printf("\n Total Nodes are %d.",count());
                break;
            case 9:
                printf("\nByeee");
                exit(1);
                break;
            default:
                printf("\n Invalid choice");
        }
    }
}
