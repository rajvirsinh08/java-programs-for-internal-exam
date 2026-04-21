//Quick Sort
#include<stdio.h>
void main()
{
    int arr[50],i,j,n,lb=0,ub=0;
    int partition(int a[],int lb, int ub);
    void quicksort(int a[],int lb, int ub);
    printf("\n How many Elements you want to add ? ");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        printf("\n Enter %d Elements : ");
        scanf("%d",&arr[i]);
    }
    printf("\n Array : ");
    for(i=0;i<n;i++)
    {
        printf("%d\t",arr[i]);
    }
    lb=0;
    ub=n-1;
    quicksort(arr,lb,ub);
    printf("\n Sorted Array : ");
    for(i=0;i<n;i++)
    {
        printf("%d\t",arr[i]);
    }
}
void quicksort(int a[],int lb, int ub)
{
    if(lb<ub)
    {
        int pivot = partition(a,lb,ub);
        quicksort(a,lb,pivot-1);
        quicksort(a,pivot+1,ub);
    }
}
int partition(int a[],int lb, int ub)
{
    int j=ub;
    int i=lb;
    int pivot = a[lb];
    while(i<j)
    {
        while(a[i]<=pivot)
        {
            i++;
        }
        while(a[j]>pivot)
        {
            j--;
        }
        if(i<j)
        {
            int tmp = a[j];
            a[j] = a[i];
            a[i] = tmp;
        }
    }
    if(i>j)
    {
        int tmp = a[j];
        a[j] = a[lb];
        a[lb] = tmp;
        return j;
    }

}
