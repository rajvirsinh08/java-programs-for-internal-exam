#include<stdio.h>
void main()
{
    int arr[100],i,n,j,val;
    printf("\n Enter length of array : ");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        printf("\n enter val %d : ",i+1);
        scanf("%d",&arr[i]);
    }

    printf("\n Array : ");
    for(i=0;i<n;i++)
    {
        printf("\t%d",arr[i]);
    }
    for(i=0;i<n-1;i++)
    {
        int min=i;
        for( j=i+1;j<n;j++)
        {
            if(arr[j]<arr[min])
            {
                min=j;
            }

        }
        if(min!=j)
        {
            int tmp = arr[i];
            arr[i]=arr[min];
            arr[min]=tmp;
        }
    }
     printf("\n Sorted Array : ");
    for(i=0;i<n;i++)
    {
        printf("\t%d",arr[i]);
    }
}
