// Write a C program to remove characters (from a string) located at odd positions.

#include<stdio.h>
#include<string.h>

int main(){
	int i,j=0,k;
	char str[100],ans[100];
	printf("Enter the string: ");
	scanf("%s",str);
	
	for(i=0;i<strlen(str);i++){
		if(i%2!=0){
			ans[j]=str[i];
			j++;
		}
	}
	printf("The string after remove odd index will be: ");
	for(k=0;k<j;k++){
		printf("%c",ans[k]);
	}
}
