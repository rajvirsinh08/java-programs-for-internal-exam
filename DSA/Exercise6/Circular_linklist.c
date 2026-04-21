#include<stdio.h>
#include<stdlib.h>
struct node {
    int data;
     struct node *next;
};

struct node *head = NULL;
struct node *tail = NULL;

struct node *createNode(int ele)
{
    struct node *newnode;
    newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=ele;
    newnode->next=NULL;
    return newnode;
}

//create nodes using only Head Pointer
/*void CrateList()
{
    int choice=1,ele;
    while(choice)
    {
        struct node *newnode;
        printf("\n Enter data : ");
        scanf("%d",&ele);
        newnode=createNode(ele);
        if(head==NULL)
        {
            head=newnode;
            newnode->next=head;
        }
        else
        {
            struct node *temp;
            temp=head;
            while(temp->next!=head)
            {
                temp=temp->next;
            }
            temp->next=newnode;
            newnode->next=head;
        }
        printf("\n Do you want to Continue ? [ EXIT = 0 ] : ");
        scanf("%d",&choice);
    }
}*/

// create nodes using head and tail both pointer
/*void CrateList()
{
    int choice=1,ele;
    while(choice)
    {
        struct node *newnode;
        printf("\n Enter data : ");
        scanf("%d",&ele);
        newnode=createNode(ele);
        if(head == NULL)
        {
            head=newnode;
            tail=newnode;
            tail->next=head;
        }
        else
        {
            tail->next=newnode;
            newnode->next=head;
            tail=newnode;
        }
        printf("\n Do you want to Continue ? [ EXIT = 0 ] : ");
        scanf("%d",&choice);
    }
}*/

//create nodes using only tail pointer
void CrateList()
{
    int choice=1,ele;
    while(choice)
    {
        struct node *newnode;
        printf("\n Enter data : ");
        scanf("%d",&ele);
        newnode=createNode(ele);
        if(tail == NULL)
        {
            tail=newnode;
            newnode->next=tail;
        }
        else
        {
            newnode->next=tail->next;
            tail->next=newnode;
            tail=newnode;
        }
        printf("\n Do you want to Continue ? [ EXIT = 0 ] : ");
        scanf("%d",&choice);
    }
}

void display()
{
    struct node *temp;
    if(tail==NULL)
    {
        printf("\n List is Empty..");
        return;
    }
    else
    {
        temp=tail->next;
        while(temp->next!=tail->next)
        {
            printf("%d -> \t",temp->data);
            temp=temp->next;
        }
        printf("%d",temp->data);

    }
}


//display function is used when head and head + tail pointer managed
/*void display()
{
    if(head==NULL)
    {
        printf("\n List is Empty..");
        return;
    }
    else
    {
        struct node *temp;
        temp=head;
        while(temp->next!=head)
        {
            printf("%d -> \t",temp->data);
            temp=temp->next;
        }
        printf("%d",temp->data);
    }
}*/

void count()
{
    int c=1;
    if(head==NULL)
    {
        printf("\n List is Empty");
        return;
    }
    else
    {
        struct node *temp;
        temp=head;
        while(temp->next!=head)
        {
            c++;
            temp=temp->next;
        }
    }
    printf("\n Total Number of Nodes %d .",c);
}

void main()
{
    int ch;
    while(1)
    {
        printf("\n1. Display");
        printf("\n2. Create List");
        printf("\n3. Count");
        printf("\n4. Exit");

        printf("\n Enter Your Choice : ");
        scanf("%d",&ch);
        switch(ch)
        {
        case 1:
            display();
            break;
        case 2:
            CrateList();
            break;
        case 3:
            count();
            break;
        case 4:
            printf("\nByee....");
            exit(1);
        default:
            printf("\nInvalid Choice");
            break;
        }
    }
}
