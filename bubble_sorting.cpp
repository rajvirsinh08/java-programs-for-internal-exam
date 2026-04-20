#include<stdio.h>
main()
{
	int arr[50],sa,i;
	
	printf("Bubble Sorting \n");
		
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
		
		int j,temp;
		
		for(i=0; i<sa; i++)
		{
			for(j=0; j<sa-1-i; j++)
			{
				if(arr[j]>arr[j+1])
				{
					temp=arr[j];
					arr[j]=arr[j+1];
					arr[j+1]=temp;
				}
			}
		}
		
		printf("\nSorted Array : ");
		for(int i=0; i<sa; i++)
		{
			printf(" %d ",arr[i]);
		}
}
