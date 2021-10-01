#include<stdio.h>

void swap(int *x, int *y){
    int temp = *x;
    *x = *y;
    *y = temp;
}


int main (){
	int n,a[100],i,j,k,flag;
	printf("Enter the size: ");
	scanf("%d",&n);
	printf("Enter the array elements\n");
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
		
	for(i=0;i<n;i++){
		flag=0;
		for(j=0;j<n-i;j++){
		    if(a[j]>a[j+1]){
		        flag=1;
		        swap(&a[j],&a[j+1]);
		    }
		}
		printf("Array elements are after %d pass ",i+1);
		for(k=0;k<n;k++){
			printf("%d ",a[k]);
		} 
		printf("\n");
		if(flag==0)
		    break;
	}
	printf("Sorted elements are\n");
	for(i=0;i<n;i++)
	printf("%d ",a[i]);
	return 0;
}
