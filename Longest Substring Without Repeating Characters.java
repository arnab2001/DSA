public class Solution {
    public static int lengthOfLongestSubstring(String s) {
        HashSet<Character> hs = new HashSet<>();
        int i = 0, j = 0, max = 0;
        while(j<s.length()){
            if(!hs.contains(s.charAt(j))){
                hs.add(s.charAt(j++));
                max = Math.max(max, hs.size());
            }else{
                hs.remove(s.charAt(i++));
            }
        }
        return max;
    }
    
    public static void main(String agrs[]){
      String str = "abcabcbb";
      int len = lengthOfLongestSubstring(str);
      System.out.println(len);
   }
}
