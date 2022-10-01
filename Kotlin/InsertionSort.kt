fun insertionSort(arr: IntArray) {
    val lastIndex: Int = arr.size - 1

    for (i in 1..lastIndex) {
        val temp: Int = arr[i]
        var holePosition: Int = i
        while(holePosition > 0 && arr[holePosition - 1] > temp) {
            arr[holePosition] = arr[holePosition - 1]
            holePosition--
        }
        arr[holePosition] = temp
    }
}

fun printArray(arr: IntArray) {
    val lastIndex: Int = arr.size - 1;
    for (i in 0..lastIndex) {
        val num = arr[i]
            print("$num ")
    }
    println("")
}

fun main(args: Array<String>) {
    val arr: IntArray = intArrayOf(15, 3, 12, 6, -9, 9, 0);
    print("Before Sorting: ")
    printArray(arr)

    insertionSort(arr)
    print("After Sorting: ")
    printArray(arr)
}
