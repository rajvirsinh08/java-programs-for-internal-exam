#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

#define MAX 10

struct stack{
	int top;
	char data[MAX];
}s;

int isempty(){
	if(s.top==-1){
		return 1;
	}
	else{
		return 0;
	}
}

int isfull(){
	if(s.top>MAX-1){
		return 1;
	}
	else{
		return 0;
	}
}

void push(int val){
	if(isfull()){
		printf("Stack is full...");
		return;
	}
	else{
		s.top++;
		s.data[s.top]=val;
	}
}

int pop(){
	if(isempty()){
		printf("Stack is empty...");
		return -1;
	}
	else{
		char val=s.data[s.top];
		s.top--;
		return val;
	}
}
int peep(){
	if(isempty()){
		printf("Stack is empty...");
		return -1;
	}
	else{
		return s.data[s.top];
	}
}

void display(){
	if(isempty()){
		printf("Stack is underflow..");
		return;
	}
	int i;
	for(i=s.top;i>=0;i--){
		printf("\t%d->",s.data[i]);
	}
}

void main(){
	char postfix[MAX],ch;
	s.top=-1;
	
	printf("Enter postfix evaluation:");
	scanf("%s",postfix);
	
	int i,a,b,c,num;
	
	for(i=0;i<postfix[i]!='\0';i++){
		ch=postfix[i];
		
		if(isdigit(ch)){
			num=ch-'0';
			push(num);
		}
		else{
			a=pop();
			b=pop();
			
			switch(ch){
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
					printf("Invalid choice");
			}
			push(c);
		}
	}
	printf("%d",pop());
}
