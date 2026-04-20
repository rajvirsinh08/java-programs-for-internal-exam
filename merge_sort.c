#include<stdio.h>

void merge(int arr[],int start,int mid,int end){
	int temp[50];
	int i=start,j=mid+1,k=start;
	
	while(i<=mid&&j<=end){
		if(arr[i]<arr[j]){
			temp[k++]=arr[i++];
		}
		else{
			temp[k++]=arr[j++];
		}
	}
	
	while(i<=mid){
		temp[k++]=arr[i++];
	}
	
	while(j<=end){
		temp[k++]=arr[j++];
	}
	for(i=start;i<=end;i++){
		arr[i]=temp[i];	
	}
	
}
void ms(int arr[],int start,int end){
	int mid=start+((end-start)/2);
	
	if(start<end){
		ms(arr,start,mid);
		ms(arr,mid+1,end);
		merge(arr,start,mid,end);
	}
}

int main(){
	int arr[50],sa,i,k;
	
	printf("Enter the size of array: ");
	scanf("%d",&sa);
	
	for(k=0;k<sa;k++){
		printf("Enter element on [%d]: ",k+1);
		scanf("%d",&arr[k]);
	}
	
    printf("\nArray : ");
    for(k = 0; k < sa; k++)
    {
        printf(" %d ",arr[k]);
    }
    
    ms(arr,0,sa-1);
    
    printf("\n Sorted Array : ");
    for(k = 0; k < sa; k++)
    {
        printf(" %d ",arr[k]);
    }
	return 0;
}
