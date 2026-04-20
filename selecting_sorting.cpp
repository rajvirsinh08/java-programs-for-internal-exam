#include<stdio.h>
main()
{
	int arr[50],sa,i;
	
	printf("Selection Sorting \n");
		
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
		
		int j,temp,min=0;
		
		for(i=0; i<sa; i++)
		{
			min=i;
			for(j=i+1; j<sa; j++)
			{
				if(arr[min]>arr[j])
				{
					min=j;
				}
			}
			if(min !=i)
			{
				temp=arr[i];
				arr[i]=arr[min];
				arr[min]=temp;
			}
		}
		
		printf("Sorted Array: ");
		for(int i=0; i<sa; i++)
		{
			printf(" %d ",arr[i]);
		}
}
