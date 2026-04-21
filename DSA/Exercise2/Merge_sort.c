#include<stdio.h>

void Merge(int arr[], int start, int mid, int end)
{
    int temp[50];
    int i = start, j = mid + 1, k = start;

    while(i <= mid && j <= end)
    {
        if(arr[i] < arr[j])
        {
            temp[k++] = arr[i++];
        }
        else
        {
            temp[k++] = arr[j++];
        }
    }

    while(i <= mid)
    {
        temp[k++] = arr[i++];
    }

    while(j <= end)
    {
        temp[k++] = arr[j++];
    }

    // copy temp into original array
    for(i = start; i <= end; i++)
    {
        arr[i] = temp[i];
    }
}

void MS(int arr[],int start,int end)
{
    int mid = start + ((end - start) / 2);

    if(start < end)
    {
        MS(arr,start,mid);     // Left
        MS(arr,mid+1,end);     // Right
        Merge(arr,start,mid,end);
    }
}

int main()
{
    int arr[50], sa, i, k;

    printf("Enter Size Of Array : ");
    scanf("%d",&sa);

    /* Get Array */
    for(k = 0; k < sa; k++)
    {
        printf("Enter Element On [%d] : ",k+1);
        scanf("%d",&arr[k]);
    }

    /* Print Array */
    printf("\nArray : ");
    for(k = 0; k < sa; k++)
    {
        printf(" %d ",arr[k]);
    }

    MS(arr,0,sa-1);

    printf("\nSorted Array:\n");
    for(k = 0; k < sa; k++)
    {
        printf(" %d ", arr[k]);
    }

    return 0;
}