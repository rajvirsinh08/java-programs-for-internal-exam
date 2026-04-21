#include<stdio.h>

void toh(int n, char a, char b, char c)
{
    if(n==1)
    {
        printf("Move disk 1 from %c to %c\n",a,c);
        return;
    }
    toh(n-1,a,c,b);
    printf("Move disk %d from %c to %c\n",n,a,c);
    toh(n-1,b,a,c);
}

void main()
{
    int n;
    printf("Enter number of dish : ");
    scanf("%d",&n);
    toh(n,'A','B','C');
}
