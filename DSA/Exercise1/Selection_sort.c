//Selection Sort
#include<stdio.h>
void main()
{
    int arr[50],i,j,n,min;
    printf("Enter Length of Array : ");
    scanf("%d",&n);
    printf("\n Enter Elements ");
    for(i=0; i<n; i++)
    {
        printf("\n Enter %d elememt : ",i+1);
        scanf("%d",&arr[i]);
    }
    printf("\n Array : ");
    for(i=0 ; i<n; i++)
    {
        printf("\t%d",arr[i]);
    }
    for(i=0; i<n-1; i++)
    {
        min = i;
        for(j=i+1; j<n; j++)
        {
            if(arr[j] < arr[min])
            {
                min = j;
            }
        }
        if(min!=i)
        {
            int tmp = arr[i];
            arr[i]=arr[min];
            arr[min]=tmp;
        }
    }
    printf("\n Sorted Array : ");
    for(i=0 ; i<n; i++)
    {
        printf("\t%d",arr[i]);
    }
}
