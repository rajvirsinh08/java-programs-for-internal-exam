#include<stdio.h>
#include<stdlib.h>

#define SIZE 100

struct queue{
    int data[SIZE];
    int priority[SIZE];
    int front, rear;
} q;

int isempty()
{
    if(q.front == -1)
        return 1;
    else
        return 0;
}

int isfull()
{
    if(q.rear == SIZE - 1)
        return 1;
    else
        return 0;
}

void enqueue(int val, int pri){
    if(isfull())
    {
        printf("\nQueue is Full");
        return;
    }
    else if(q.front == -1 && q.rear == -1){
        q.front = q.rear = 0;
    }
    else{
        q.rear++;
    }

    q.data[q.rear] = val;
    q.priority[q.rear] = pri;
}

void dequeue(){
    if(isempty()){
        printf("\nQueue is empty");
        return;
    }

    int max = q.front, i;

    for(i = q.front; i <= q.rear; i++){
        if(q.priority[i] < q.priority[max]){
            max = i;
        }
    }

    printf("\nDeleted element is %d[%d]", q.data[max], q.priority[max]);

    for(i = max; i < q.rear; i++){
        q.data[i] = q.data[i+1];
        q.priority[i] = q.priority[i+1];
    }

    if(q.front == q.rear){
        q.front = q.rear = -1;
    }
    else{
        q.rear--;
    }
}

void display()
{
    if(isempty())
    {
        printf("\nQueue is Empty");
        return;
    }

    int i;
    for(i = q.front; i <= q.rear; i++)
    {
        printf("\t%d[%d] <- ", q.data[i], q.priority[i]);
    }
}

int main()
{
    q.front = q.rear = -1;
    int ch, val, pri;

    while(1)
    {
        printf("\n1. Display");
        printf("\n2. Add");
        printf("\n3. Delete");
        printf("\n4. Exit");

        printf("\nEnter your choice: ");
        scanf("%d", &ch);

        switch(ch)
        {
            case 1:
                display();
                break;

            case 2:
                printf("\nEnter Data and Priority: ");
                scanf("%d %d", &val, &pri);
                enqueue(val, pri);
                break;

            case 3:
                dequeue();
                break;

            case 4:
                exit(0);

            default:
                printf("\nInvalid Choice");
        }
    }
}
