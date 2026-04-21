//binary Search
//perform on sorted array
#include<stdio.h>
void main()
{
    int arr[50],n,key,i,start,end,mid;
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

    start = 0;
    end = n-1;


    while(start <= end)
    {
        mid = (start + end )/2;

        if(arr[mid]==key)
        {
            printf("Element Found.");
            break;
        }
        if(key<=arr[mid])
        {
            end=mid-1;
        }
        if(key>=arr[mid])
        {
            start =mid+1;
        }
    }
    if(start>end)
    {
        printf("Value not found.");
    }
}
