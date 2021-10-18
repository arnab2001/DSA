public class RecursiveLinearSearch {
    public static void main(String[] args) {
        int[] arr = {3,2,1,18,19};
        int target= 19;
        int index = Search(arr, 0, target);
        System.out.println(index);
    }

    static int Search(int[] arr, int index, int target) {
        if (arr[index] == target) {
            return index;
        }
        if (index == arr.length) {
            return -1;
        }
        return Search(arr, index+1, target);
    }
}

