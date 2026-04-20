#include<stdio.h>
main()
{
		int arr[50],sa,key,value=-1;
		
		printf("Liner Search\n");
		
		printf("Enter Size Of Array : ");
		scanf("%d",&sa);
		
		/*Get Array*/
		for(int i=0; i<sa; i++)
		{
			printf("Enter Element On [%d] : ",i+1);
			scanf("%d",&arr[i]);
		}
		
		/*Print Array*/
		printf("\nArray\n");
		for(int i=0; i<sa; i++)
		{
			printf(" %d ",arr[i]);
		}
		printf("\n");
		
		printf("Enter Key For Searching : ");
		scanf("%d",&key);
		
		for(int i=0; i<sa; i++)
		{
			if(arr[i]==key)
			{
				printf("\n%d Is present at %d Index\n",key,i+1);
				value=1;
				break;
			}
		}
		
		if(value==-1)
		{
			printf("\n%d Element Not Found In Array\n",key);
		}
}
