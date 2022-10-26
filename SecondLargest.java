import java.util.*;
public class SecondLargest {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter Size Of Array");
        int n = sc.nextInt();
        int arr[] = new int[n];
        for (int i = 0; i < n; i++) {
            arr[i] = sc.nextInt();
        }
        int l=arr[0];
        int m=-1;
    for(int i=1;i<n;i++){
        if(l<arr[i]){
            m=l;
            l=arr[i];
        }
        else if(l!=arr[i]){
            if(m==-1 || arr[i]>m)
                m=arr[i];
        }
    }
        System.out.println(" Largest "+l);
        System.out.println("Second Largest "+m);
    }
}
