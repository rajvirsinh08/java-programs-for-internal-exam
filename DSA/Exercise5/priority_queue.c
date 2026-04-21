#include<stdio.h>
#include<stdlib.h>
#define SIZE 100

struct queue{
    int data[SIZE];
    int priority[SIZE];
    int front,rear;
}q;

int isempty()
{
    if(q.rear == -1 && q.front == -1)
        return 1;
    else
        return 0;
}

int isfull()
{
    if(q.rear == SIZE -1 )
        return 1;
    else
        return 0;
}

void enqueue(int val, int pri)
{
    if(isfull())
    {
        printf("\n Queue is Full");
        return;
    }
    else if(q.front==-1 && q.rear==-1)
    {
        q.front=q.rear=0;
    }
    else
    {
        q.rear++;
    }
    q.data[q.rear]=val;
    q.priority[q.rear]=pri;
}
void dequeue()
{
    if(isempty())
    {
         printf("\n Queue is Empty");
        return;
    }
    int max=0,i;
    for(i=1;i<=q.rear;i++)
    {
        if(q.priority[i]<q.priority[max])
        {
            max=i;
        }

    }
    printf("\n Deleted Element is %d[%d]",q.data[max],q.priority[max]);
    for(i=max;i<q.rear;i++)
    {
        q.data[i]=q.data[i+1];
        q.priority[i]=q.priority[i+1];
    }
    //q.rear--;
    //if last element in queue then we need to reset queue
    if(q.front == q.rear)
    {
        q.front = q.rear = -1;   // 🔥 reset queue
    }
    else
    {
        q.rear--;
    }
}
void display()
{
    if(isempty())
    {
         printf("\n Queue is Empty");
        return;
    }
    int i;
    for(i=q.front;i<=q.rear;i++)
    {
        printf("\t %d[%d] <- ",q.data[i],q.priority[i]);
    }
}
void main()
{
    q.front = q.rear = -1;
    int ch,val,pri;
    while(1)
    {
        printf("\n1. Display");
        printf("\n2. Add");
        printf("\n3. Delete");
        printf("\n4. Exit");

        printf("\n Enter your choice : ");
        scanf("%d",&ch);
        switch(ch)
        {
        case 1:
            display();
            break;
        case 2:
            printf("\nEnter Data and priority : ");
            scanf("%d %d",&val,&pri);
            enqueue(val,pri);
            break;
        case 3:
            dequeue();
            break;
        case 4:
            exit(0);

        default:
            printf("\n Invalid choice");
            break;

        }
    }
}
