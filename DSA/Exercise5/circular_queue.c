#include<stdio.h>
#include<stdlib.h>
#define SIZE 6

struct queue{
    int front,rear;
    int data[SIZE];
}q;

int isqempty()
{
    if(q.rear == -1 && q.rear == -1)
        return 1;
    else
        return 0;
}

int isqfull()
{
    if(q.front == ((q.rear+1)%SIZE) )    // if(q.rear == SIZE -1 )
        return 1;
    else
        return 0;
}

void enqueue(int val)
{
    if(isqfull())
    {
        printf("\n Overflow");
        return;
    }
    else if(q.front == -1 && q.rear == -1)
    {
        q.front=q.rear=0;
        q.data[q.rear]=val;
    }
    else
    {
        q.rear = (q.rear+1)%SIZE;     //q.rear++
        q.data[q.rear]=val;
    }
}

void dequeue()
{
    if(isqempty())
    {
        printf("\n Underflow.");
        return;
    }
    else if(q.front==q.rear)
    {
        printf("\n Last Element %d",q.data[q.front]);
        q.front=q.rear=-1;
    }
    else
    {
        printf("\n Deleted Element %d",q.data[q.front]);
        q.front=(q.front+1)%SIZE;      //q.front++
    }
}

int peek()
{
    if(isqempty())
    {
        printf("\n Underflow.");
        return;
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
        printf("\n Underflow.");
        return;
    }
    int i;
    i=q.front;
    while(i != q.rear)
    {
        printf("%d ->\t",q.data[i]);
        i=(i+1)%SIZE;
    }
    printf("%d -> \t ",q.data[q.rear]);
}

void main()
{
    q.rear=q.front=-1;
    int ch,val,pek;
    while(1)
    {
        printf("\n 1. Display");
        printf("\n 2. Add");
        printf("\n 3. Delete");
        printf("\n 4. Peek");
        printf("\n 5. exit");

        printf("\n Enter your choice : ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
                display();
                break;
            case 2:
                printf("\n Enter value : ");
                scanf("%d",&val);
                enqueue(val);
                break;
            case 3:
                dequeue();
                break;
            case 4:
                pek=peek();
                printf("\n Peeked Element %d",pek);
                break;
            case 5:
                exit(1);
            default:
                printf("\n Invalid Choice");
                break;
        }
    }
}
