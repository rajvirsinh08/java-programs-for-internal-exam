// for performing binary searching array must be sorted or else it will not work properly
#include<stdio.h>
main()
{
	int arr[50],sa,key,high,low,mid,i,value=-1;;
	
	printf("Binary Search\n");
		
		printf("Enter Size Of Array : ");
		scanf("%d",&sa);
		
		/*Get Array*/
		for(int i=0; i<sa; i++)
		{
			printf("Enter Element On [%d] : ",i+1);
			scanf("%d",&arr[i]);
		}
		
		/*Print Array*/
		printf("\nArray : ");
		for(int i=0; i<sa; i++)
		{
			printf(" %d ",arr[i]);
		}
		printf("\n");
		
		printf("Enter Key For Searching : ");
		scanf("%d",&key);
		
		high=sa-1;
		low=0;
		
		
		while(low<=high)
		{
			mid=(high+low)/2;
			if(arr[mid]==key)
			{
				printf("\n%d Is present at %d Index\n",key,mid);
				value=1;
				break;
			}
			else if(key>arr[mid])
			{
				low=mid+1;
			}
			else
			{
				high=mid-1;
			}
		}
		
		if(value==-1)
		{
			printf("\n%d Element Not Found In Array\n",key);
		}
}
