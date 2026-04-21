#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#define SIZE 10
struct stack
{
	int st[SIZE];
	int top;
}s;
int isfull()
{
	if(s.top >= SIZE-1)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
int isempty()
{
	if(s.top == -1)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
void push(char ele)
{
	if(isfull())
	{
		printf("Stack is full.");
		exit(0);
	}
	else
	{
		s.top++;
		s.st[s.top]=ele;
	}
}
int pop()
{
	int item;
	if(isempty())
	{
		printf("Stack is empty.");
		exit(0);
	}
	else
	{
		item=s.st[s.top];
		s.top--;
	}
	return item;
}

void main()
{
	char postfix[50];
	s.top = -1;
	printf("Enter Postfix Exprestion:");
	scanf("%s",postfix);
	int i,a,b,c,num;
	for(i=0;postfix[i]!='\0';i++)
	{
		if(isdigit(postfix[i]))
		{
			num = postfix[i]-'0'; //here convert string to interger
			push(num);
		}
		else
		{
			a=pop();
			b=pop();
			switch(postfix[i])
			{
				case '+':
					c=b+a;
				break;
				case '-':
					c=b-a;
				break;
				case '*':
					c=b*a;
				break;
				case '/':
					c=b/a;
				break;
				default:
					printf("Invalid operator");
			}
			push(c);
		}
	}
	printf("%d",pop());
}

