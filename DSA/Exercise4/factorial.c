#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
void main()
{
	int num,result;
	printf("Enter number:");
	scanf("%d",&num);
	result=fact_num(num);
	printf("Factorial is: %d",result);
}
int fact_num(int num)
{
	if(num==1)
	{
		return 1;
	}
	return num*fact_num(num-1);
}
