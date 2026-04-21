#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
void main()
{
	int b,e,result;
	printf("Enter Base:");
	scanf("%d",&b);
	printf("Enter Exponent:");
	scanf("%d",&e);
	result=power(b,e);
	printf("Factorial is: %d",result);
}
int power(int b,int e)
{
	if(e==0)
	{
		return 1;
	}
	return b*power(b,e-1);
}

