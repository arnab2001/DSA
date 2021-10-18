import java.util.ArrayList;

/*
This program print all permutation of given string
*/

public class Permutation {
  public static void main(String[] args) {
    ArrayList<String> str = permutate("abc");
    System.out.println(str.toString());
  }

  static ArrayList<String> permutate(String str) {
    if (str.length() == 0) {
      ArrayList<String> result = new ArrayList<String>();
      result.add("");
      return result;
    }
    if (str.length() == 1) {
      ArrayList<String> result = new ArrayList<String>();
      result.add(str);
      return result;
    }
    char cc = str.charAt(0);
    String nextstr = str.substring(1);
    ArrayList<String> next = permutate(nextstr);
    ArrayList<String> result = new ArrayList<String>();
    for (int i = 0; i < next.size(); i++) {
      String elem = next.get(i);
      for (int j = 0; j <= elem.length(); j++) {
        String temp = elem.substring(0, j) + cc + elem.substring(j);
        result.add(temp);
      }
    }
    return result;
  }
}
