//Array Update Element, Delete Element Add Element
#include<stdio.h>
void main()
{
    int i, arr[50], n, delind, addval, search, newval;
    printf("\n Enter Element to Add on Array : ");
    scanf("%d",&n);

    for(i=0;i<n;i++)
    {
        printf("\n Enter %d Element : ",i+1);
        scanf("%d",&arr[i]);
    }

    printf("\nArray : ");
    for(i=0;i<n;i++)
    {
        printf("\t%d",arr[i]);
    }

    printf("\n Enter Possition For Delete : ");
    scanf("%d",&delind);

    for(i=0; i<n; i++)
    {
        if(arr[i] == delind)
        {
            for(arr[i]=delind; i<n; i++)
            {
                arr[i]=arr[i+1];
            }
            n--;
        }
    }

    printf("\nArray : ");
    for(i=0;i<n;i++)
    {
        printf("\t%d",arr[i]);
    }

    printf("\n Enter Element to add : ");
    scanf("%d",&addval);
    for(i=0;i<n;i++)
    {
        if (i+1 == n)
        {
            arr[++i]=addval;
        }
    }
    n++;
    printf("\nArray : ");
    for(i=0;i<n;i++)
    {
        printf("\t%d",arr[i]);
    }

    printf("\n Enter Element to Update : ");
    scanf("%d",&search);
    for(i=0;i<n;i++)
    {
        if(arr[i]==search)
        {
            printf("\n Enter New Value : ");
            scanf("%d",&newval);
            arr[i]=newval;
        }
    }
    printf("\nArray : ");
    for(i=0;i<n;i++)
    {
        printf("\t%d",arr[i]);
    }
}
