public class Count {
    public static void main(String[] args) {
        String str = "0111100010";
        int count = 0, zero=0,ones=0;
        for(int i=0;i<str.length();i++){
            int ch = str.charAt(i);
            if(ch == '0')
                zero++;
            else
                ones++;
            if(zero == ones){
                count++;
                zero=0;
                ones = 0;
            }    
        }
        System.out.println(count);
    }    
}
