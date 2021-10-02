import java.util.Arrays;
import java.util.Scanner;

public class QuickSort {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter array size: ");


        //taking input from the user
        int n=sc.nextInt();
        int[] array=new int[n];
        System.out.println("Enter array elements space separated");
        for(int i=0;i<n;i++){
            array[i]=sc.nextInt();

        }

        //call to the quicksort function
        quickSort(array,0,array.length);

        System.out.println(Arrays.toString(array));


    }


    public static int Partition(int[] A,int l,int h){
        int pivot=A[l];
        int i=l;
        int j=h;
        while(i<j){
            do {
                i++;
            }while(i<j && A[i]<=pivot);

            do{
                j--;
            }while(A[j]>pivot);
            if(i<j)
                swap(A,i,j);

        }
        swap(A,l,j);

        return j;
    }

    public static void swap(int[] A,int a,int b){

        // function to swap to numbers a and b in array.
        int temp=A[a];
        A[a]=A[b];
        A[b]=temp;

    }

    public static void quickSort(int[] array,int l, int h){
        if(l<h){
            int j=Partition(array,l,h);

            quickSort(array,l,j);
            quickSort(array,j+1,h);
        }

    }
}
