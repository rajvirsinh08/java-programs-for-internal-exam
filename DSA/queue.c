//queue
#include<stdio.h>
#define SIZE 10
struct queue{
    int rear,front;
    int data[SIZE];
}q;

int isqfull()
{
    if(q.rear>=SIZE-1)
        return 1;
    else
        return 0;
}

int isqempty()
{
    if(q.front==SIZE-1)
        return 1;
    else
        return 0;
}

void endque(int val)
{
    if(isqfull())
    {
        printf("Queue overflow");
        return;
    }
    else if(q.front==-1 && q.rear==-1)
    {
        q.front=q.rear=0;
        q.data[q.rear]=val;
    }
    else
    {
        q.rear++;
        q.data[q.rear]=val;
    }
}

void deque()
{
    if(isqempty())
    {
        printf("Queue overflow");
        return;
    }
    else if(q.front==q.rear)
    {
        printf("\n Last element %d",q.data[q.front]);
        q.front=q.rear=-1;
    }
    else
    {
        printf("\n Poped Element %d",q.data[q.front]);
        q.front++;
    }

}


void display()
{
    if(isqempty())
    {
        printf("Queue overflow");
        return;
    }
    int i;
}
