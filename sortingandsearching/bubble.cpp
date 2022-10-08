#include<iostream>
using namespace std;

void bubbleSort(int* arr, int n)
{   
    for(int i = 1; i<n; i++) {
        bool swapped = false;
        
        for(int j =0; j<n-i; j++) {
            
            if(arr[j] > arr[j+1]) {
                swap(arr[j], arr[j+1]);
                swapped = true;
            }
            
        }
        
        if(swapped == false) {
            break;
        }
           
    }
}
void inputArray(int*arr,int n){
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    
}
void printArray(int*arr,int n){
    for (int i = 0; i < n; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    
}

int main(){

 int n;
    cout<<"enter size of array :"<<endl;
    cin>>n;
int arr[100];
cout<<"enter elements in array:";
inputArray(arr,n);
cout<<"Array before sorting : ";
printArray(arr,n);
cout<<"array afer sorting:";
bubbleSort(arr,n);
printArray(arr,n);

return 0;
}