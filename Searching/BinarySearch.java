class BinarySearch{
    public static int search(int arr[],int x) 
    {
        int left=0;
        int right=arr.length-1;
        
        while (left<=right)
        {
            int mid=(left+right)/2;
            if(x<arr[mid])
            {
                right=mid-1;
            }
            if(x>arr[mid])
            {
                left=mid-1;
            }
            else
            {
                return mid;
            }
        }
        return -1;
    }

        public static void main(String[] args) {
        int arr[]={3,6,8,23,56,89};
        int x=56;
        int result=search(arr,x);
        if(result== -1)
            System.out.println("Not Found");
        else
            System.out.println("Found at index:" +x);

    }
}