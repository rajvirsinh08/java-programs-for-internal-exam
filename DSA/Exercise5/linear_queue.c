#include<stdio.h>
#include<stdlib.h>
#define SIZE 10
struct queue{
    int rear,front;
    int data[SIZE];
}q;

int isqempty()
{
    if(q.rear == -1 && q.front == -1)
        return 1;
    else
        return 0;
}

int isqfull()
{
    if(q.rear == SIZE -1)
        return 1;
    else
        return 0;
}

void enqueue(int val)
{
    if(isqfull())
    {
        printf("\n Overflow..");
        return;
    }
    else if(q.rear == -1 && q.front == -1)
    {
        q.rear=q.front=0;
        q.data[q.rear]=val;
    }
    else
    {
        q.rear++;
        q.data[q.rear]=val;
    }
}

void dequeue()
{
    if(isqempty())
    {
        printf("\nQueue is Empty");
        return;
    }
    else if(q.front==q.rear)
    {
        printf("\n Last element %d",q.data[q.front]);
        q.front=q.rear=-1;
    }
    else
    {
        printf("\n Deleted element %d",q.data[q.front]);
        q.front++;
    }
}

int peek()
{
    if(isqempty())
    {
        printf("\nQueue is Empty");
        return -1;
    }
    else
    {
        return q.data[q.front];
    }
}

void display()
{
    if(isqempty())
    {
        printf("\nQueue is Empty");
        return;
    }
    int i;
    for(i = q.front; i <= q.rear; i++)
    {
        printf("\t%d -> ",q.data[i]);
    }
}

void main()
{
    q.rear=q.front=-1;
    int ch,val;
    while(1)
    {
        printf("\n1. Display");
        printf("\n2. Add");
        printf("\n3. Delete");
        printf("\n4. Peek");
        printf("\n5. exit");

        printf("\nEnter Your Choice : ");
        scanf("%d",&ch);

        switch(ch)
        {
        case 1:
            display();
            break;
        case 2:
            printf("\nEnter element : ");
            scanf("%d",&val);
            enqueue(val);
            break;
        case 3:
            dequeue();
            break;
        case 4:
            printf("\nCurrent Pointer %d",peek());
            break;
        case 5:
            printf("\nByeee..");
            exit(1);
            break;
        default:
            printf("\nInvalid Choice");
            break;
        }
    }
}
