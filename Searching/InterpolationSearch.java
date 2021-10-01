class InterpolationSearsch{
    public static void Search(int arr[],int x){
        int low=0;
        int high=arr.length-1;

        //while(low<=high && x>=arr[low] x<=arr[high])
        while (low <= high && x >= arr[low] && x <= arr[high])//check if element is present
        {
            if(low==high)
            {
                if(arr[low]==x)
                    return low;
                return -1;//else part
            }
            int pos=low + (((high-low) / (arr[high]-arr[low]))*(x - arr[low]));
            if(arr[pos]==x)
            {
                return pos;
            }
            if(arr[pos]<x)
            low=pos+1;
            else
            high=pos-1;    
        }
        return -1;
    }
    public static void main(String[] args) {
        
        int arr[]={1,2,4,6,8,11,32,45,66,67,94,234,675,776,789,890};
        int x=234;
        int position = Search(arr,x);
        System.out.println(" found at: " + position);
    }
    public static void main(String[] args) {
        
        int arr[]={1,2,4,6,8,11,32,45,66,67,94,234,675,776,789,890};
        int x=234;
        int pos =Search(arr,x);
        System.out.println(" found at: " + pos);
    }
}