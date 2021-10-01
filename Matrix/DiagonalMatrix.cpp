#include<stdio.h>
#include<iostream>

using namespace std;
 
 
void set(int A[],int i,int j,int x)
{
	if(i==j)
	{
		A[i-1]=x;
	}
}

int get(int A[],int i,int j)
{
	if(i==j)
	{
		return A[i-1];
	}
	else
	return 0;
}
void display(int A[],int n)
{
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(i==j)
			{
				cout<<A[i]<<" ";
			}
			else
			cout<<"0 ";
		}
		cout<<endl;
	}
	
}



int main(){
	int arr[10];
	int n=4; //4*4 matrix
	set(arr,1,1,12);set(arr,2,2,12);set(arr,3,3,12);set(arr,4,4,12);
	int c=get(arr,1,3);
	cout<<c<<endl;
	display(arr,4);
}
