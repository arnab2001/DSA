
import java.util.*;
class HelloWorld {
    public static void main(String[] args) {
        Scanner sc= new Scanner(System.in);
        System.out.print("Enter the string: ");
        String str = sc.nextLine();
        
        int[] frq = new int[256];
        Arrays.fill(frq,0);
        
        for(int i=0;i<str.length();i++){
            frq[str.charAt(i)]++;
        }
        System.out.println("Repeating Charecters: ");
        for(int i=0;i<256;i++){
            if(frq[i]>0){
                System.out.println("Freq of "+(char)i+" is "+frq[i]);
            }
            
        }
        int ctr_first = 0, ctr_second = 0;
        for(int i=0;i<256;i++){
            if(frq[i]>frq[ctr_first]){
                ctr_second=ctr_first;
                ctr_first=i;
            }
            else if(frq[i]>frq[ctr_second] && frq[i]!=frq[ctr_first]){
                ctr_second=i;
            }
            
        }
        System.out.println();
        System.out.println("2nd highest Freq is = "+(char)ctr_second);
        
        
        
    }
}

