import java.util.ArrayList;

/*
This program find all the path in a maze
For explainaton- https://youtu.be/7i41gZLXe5k
*/

public class MazePath {
  public static void main(String[] args) {
    ArrayList<String> maze = mazePath(0, 0, 3-1); // Maze of 3 size
    System.out.println(maze.toString());

  }

  public static ArrayList<String> mazePath(int i, int j, int n) {
    if (i == n && j == n) {
      ArrayList<String> result = new ArrayList<String>();
      result.add("");
      return result;
    }
    if (i > n || j > n) {
      ArrayList<String> result = new ArrayList<String>();
      return result;
    }
    ArrayList<String> result = new ArrayList<String>();
    ArrayList<String> nextV = mazePath(i + 1, j, n);
    for (int k = 0; k < nextV.size(); k++) {
      String temp = 'V' + nextV.get(k);
      result.add(temp);
    }
    ArrayList<String> nextH = mazePath(i, j + 1, n);
    for (int k = 0; k < nextH.size(); k++) {
      String temp = 'H' + nextH.get(k);
      result.add(temp);
    }
    return result;
  }
}
