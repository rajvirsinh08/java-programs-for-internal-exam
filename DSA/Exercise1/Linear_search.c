//Linear Search
#include<stdio.h>
void main()
{
    int arr[50],n,key,i;
    printf("Enter Length of array [max-50] : ");
    scanf("%d",&n);
    printf("\n Enter Elements in Array ");
    for(i=0;i<n;i++)
    {
        printf("\n Enter %d Element : ", i+1);
        scanf("%d",&arr[i]);
    }

    printf("\n Array is :");
    for(i=0;i<n;i++)
    {
        printf("\t%d",arr[i]);
    }

    printf("\n Enter Element For Searching : ");
    scanf("%d",&key);
    for(i=0;i<n;i++)
    {
        if(arr[i]==key)
        {
            printf("\n Key Found at possition %d",i+1);
            break;
        }
    }
    if(i==n)
    {
        printf("\n Key not Found in Array.");
    }
}
