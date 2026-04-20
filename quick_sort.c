#include<stdio.h>
void main(){
	int arr[50],i,j,n,lb=0,ub=0;
	
	int partition(int a[],int lb,int ub);
	void quicksort(int a[],int lb,int ub);
	
	printf("Howmany elements you want to add:?");
	scanf("%d",&n);
	
	for(i=0;i<n;i++){
		printf("Enter %d elements:",i+1);
		scanf("%d",&arr[i]);
	}
	printf("Array: ");
	for(i=0;i<n;i++){
		printf("%d\t",arr[i]);
	}
	
	lb=0;
	ub=n-1;
	quicksort(arr,lb,ub);
	
	printf("Sorted Array : ");
	for(i=0;i<n;i++){
		printf("%d\t",arr[i]);
	}
}

void quicksort(int a[],int lb,int ub){
	if(lb<ub){
		int pivot=partition(a,lb,ub);
		quicksort(a,lb,pivot-1);
		quicksort(a,pivot+1,ub);
	}
}

int partition(int a[],int lb,int ub){
	int j=ub;
	int i=lb;
	int pivot=a[lb];
	
	while(i<j){
		while(a[i]<=pivot){
			i++;
		}
		while(a[j]>pivot){
			j--;
		}
		if(i<j){
			int temp=a[j];
			a[j]=a[i];
			a[i]=temp;
		}
	}
	if(i>j){
		int temp=a[j];
		a[j]=a[lb];
		a[lb]=temp;
		return j;
	}
}
