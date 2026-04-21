//Bubble sort
#include<stdio.h>
void main()
{
    int arr[50],i,j,temp,n;
    printf("Enter Length of Ele : ");
    scanf("%d",&n);

    for(i=0;i<n;i++)
    {
        printf("\nEnter %d Element : ",i+1);
        scanf("%d",&arr[i]);
    }
    printf("\nArray : ");
    for(i=0; i<n; i++)
    {
        printf("\t%d",arr[i]);
    }
    for(i=0;i<n-1;i++)
    {
        for(j=0;j<n-1-i;j++)
        {
            if(arr[j] > arr[j+1])
            {
                temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
    printf("\nArray After Sorting: ");
    for(i=0; i<n; i++)
    {
        printf("\t%d",arr[i]);
    }
}
