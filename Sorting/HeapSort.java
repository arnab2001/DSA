class HeapSort{
    void sort(int arr[]){
        int n=arr.length;
        for (int i = n / 2 - 1; i >= 0; i--) 
            heapify(arr, n, i);
        for (int i=n-1; i>0; i--) 
            { 
                // Move current root to end 
                int temp = arr[0]; 
                arr[0] = arr[i]; 
                arr[i] = temp; 
      
                // /call max heapify on the reduced heap 
                heapify(arr, i, 0); 
            } 
        

    }



    void heapify(int arr[],int n, int i){
         int largest=i;
        int left=2*i;
        int right=2*i+1;
        while(left<n && arr[left]>arr[largest])
        {
            largest=left;
        }
        while(right<n && arr[right]>arr[largest])
        {
            largest=right;
        }
        if(largest!=i)
        {
        int temp=arr[i];
        arr[i]=arr[largest];
        arr[largest]=arr[temp];
        
        heapify(arr,n,largest);
    }
    }


    static void printarray(int arr[]){
        int n=arr.length;
    for(int i=0;i<n;i++)
    System.out.println(arr[i]+" ");
    }

    public static void main(String args[]){ 
        int arr[] = {22, 14, 19, 54, 65, 127}; 
        int n = arr.length; 
  
        HeapSort obj = new HeapSort(); 
        obj.sort(arr); 
  
        System.out.println("Sorted array is"); 
        printarray(arr); 
    } 


}