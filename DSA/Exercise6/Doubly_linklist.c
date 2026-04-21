#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *prev;
    struct node *next;
};

struct node *head = NULL;

struct node* createNode(int ele)
{
    struct node *newnode;
    newnode = (struct node*) malloc(sizeof(struct node));
    newnode->data=ele;
    newnode->prev=NULL;
    newnode->next=NULL;
    return newnode;
}

void insert()
{
    struct node *newnode,*temp;
    int choice=1,val;
    while(choice)
    {

        printf("\n Enter value to add : ");
        scanf("%d",&val);
        newnode=createNode(val);
        if(head==NULL)
        {
            head=newnode;
        }
        else
        {
            temp=head;
            while(temp->next != NULL)
            {
                temp=temp->next;
            }
            temp->next=newnode;
            newnode->prev=temp;
        }


        printf("\n Continue insert ?? [EXIT==0] : ");
        scanf("%d",&choice);
    }
}

void insertatend(int ele)
{
    struct node *newnode,*temp;
    newnode=createNode(ele);
    if(head == NULL)
    {
        head=newnode;
    }
    else
    {
        temp=head;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=newnode;
        newnode->prev=temp;
    }
}

void insertatbegin(int ele)
{
    struct node *newnode;
    newnode = createNode(ele);
    if(head == NULL)
    {
        head=newnode;
    }
    else
    {
        newnode->next=head;
        head->prev=newnode;
        head=newnode;
    }
}

void insertatpos(int ele, int pos)
{
    struct node *newnode, *temp;
    newnode=createNode(ele);
    int i=0;
    int c = count();
    if(pos < 0 || pos > c+1)
    {
        printf("\n Invalid position..");
        return;
    }
    else
    {
        temp=head;
        while(i<pos-1)
        {
            temp=temp->next;
            i++;
        }
        newnode->prev=temp;
        newnode->next=temp->next;
        temp->next=newnode;


        if(newnode->next!=NULL)
        {
            newnode->next->prev=newnode;
        }
    }
}

int count()
{
    struct node *temp;
    temp=head;
    int c=0;
    while(temp!=NULL)
    {
        temp=temp->next;
        c++;
    }
    return c;
}

void display()
{
    struct node *temp;
    temp=head;
    while(temp!=NULL)
    {
        printf("%d < - > \t", temp->data);
        temp=temp->next;
    }
    printf("NULL");
}

void deleteatend()
{
    struct node *temp;
    if(head==NULL)
    {
        printf("\n link list is empty");
        return;
    }
    else
    {
        temp=head;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->prev->next=NULL;
        free(temp);
    }
}
void deleteatbeg()
{
    struct node *temp;
    if(head==NULL)
    {
        printf("\n link list is empty");
        return;
    }
    else if(head->next==NULL) // we can check if only one value then reset head to NULL
    {
        head=NULL;
        free(head);
    }
    else
    {
        temp=head;
        head = temp->next;
        head->prev=NULL;
        free(temp);
    }
}
void deleteatpos(int pos)
{
    struct node *temp;
    int c = count();
    int i=0;
    if(pos<=0 || pos > c+1)
    {
        printf("\n Invalid Position.");
        return;
    }
    if(head==NULL)
    {
        printf("\n link list is empty");
        return;
    }
    else if(pos==1)
    {
        deleteatbeg();
    }
    else if(c==pos)
    {
        deleteatend();
    }
    else
    {
        temp=head;
        while(i<pos)
        {
            temp=temp->next;
            i++;
        }
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
        free(temp);
    }

}
void main()
{
    int ch,val,pos,c;
    while(1)
    {
        printf("\n1. Display");
        printf("\n2. Insert");
        printf("\n3. Insert  at end");
        printf("\n4. Insert at after specific position");
        printf("\n5. Insert at start");
        printf("\n6. Delete at End");
        printf("\n7. Delete at Beging");
        printf("\n8. Delete at Position");
        printf("\n9. Count");
        printf("\n10. Exit");

        printf("\n Enter your choice : ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
                display();
                break;
            case 2:
                insert();
                break;
            case 3:
                printf("\nEnter Value : ");
                scanf("%d",&val);
                insertatend(val);
                break;
           case 4:
                printf("\nEnter Value and position : ");
                scanf("%d %d",&val,&pos);
                insertatpos(val,pos);
                break;
            case 5:
                printf("\nEnter Value : ");
                scanf("%d",&val);
                insertatbegin(val);
                break;
            case 6:
                deleteatend();
                break;
           case 7:
                deleteatbeg();
                break;
            case 8:
                printf("\nEnter position to Delete : ");
                scanf("%d",&pos);
                deleteatpos(pos);
                break;
            case 9:
                printf("\n Total Nodes are %d.",count());
                break;
            case 10:
                printf("\nByeee");
                exit(0);
                break;
            default:
                printf("\n Invalid choice");
        }
    }
}
