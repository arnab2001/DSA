class JumpSearch{
    public static void Search(int arr[],int x){
        int n=arr.length;
        int block=(int)Math.floor(Math.sqrt(n));
        int low=0;
        while(arr[Math.min(block,n)-1]<x)
        {
            low=block;
            block=block+block;
            if(low>=n)
                return -1;
        }
        while(arr[low]<x)
        {
            low++;
            if(arr[low]==Math.min(block,n))
                return -1;
        }
        if (arr[prev] == x) 
            return prev; 
  
        return -1; 
    } 
        

    public static void main(String[] args) {
        
        int arr[]={1,2,4,6,8,11,32,45,66,67,94,234,675,776,789,890};
        int x=234;
        int pos =Search(arr,x);
        System.out.println(" found at: " + pos);
    }
}

