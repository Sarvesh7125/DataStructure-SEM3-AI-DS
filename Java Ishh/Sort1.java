import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

public class Sort1 {
    int[] arr;

    Sort1(int[] arr) {
        this.arr = arr;
    }

    static void printArr(int[] arr) {
        for (int i : arr) System.out.print(i + " ");
        System.out.println();
    }

    static void swap(int a, int b, int[] arr) {
        int temp = arr[a];
        arr[a] = arr[b];
        arr[b] = temp;
    }

    void selectionSort() {
        for (int i = 0; i < arr.length; i++) {
            int min = i;
            for (int j = i + 1; j < arr.length; j++) {
                if (arr[j] < arr[min]) min = j;
            }
            swap(min, i, arr);
        }
        System.out.print("Selection Sort: Sorted Array: ");
        printArr(arr);
    }

    void insertionSort() {
        for (int i = 1; i < arr.length; i++) {
            int key = arr[i];
            int j = i - 1;
            while (j >= 0 && arr[j] > key) {
                arr[j + 1] = arr[j];
                j--;
            }
            arr[j + 1] = key;
        }
        System.out.print("Insertion Sort: Sorted Array: ");
        printArr(arr);
    }

    void mergeSort() {
        mergeSortPriv(arr);
        System.out.print("Merge Sort: Sorted Array: ");
        printArr(arr);
    }

    private void mergeSortPriv(int[] temp) {
        if (temp.length < 2) return;
        int mid = temp.length / 2;
        int[] left = Arrays.copyOfRange(temp, 0, mid);
        int[] right = Arrays.copyOfRange(temp, mid, temp.length);
        mergeSortPriv(left);
        mergeSortPriv(right);
        merge(temp, left, right);
    }

    private void merge(int[] array, int[] left, int[] right) {
        int i = 0, j = 0, k = 0;
        while (i < left.length && j < right.length) {
            array[k++] = (left[i] <= right[j]) ? left[i++] : right[j++];
        }
        while (i < left.length) array[k++] = left[i++];
        while (j < right.length) array[k++] = right[j++];
    }

    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        System.out.print("Enter unsorted array (space-separated): ");
        int[] array = Arrays.stream(in.readLine().trim().split(" ")).mapToInt(Integer::parseInt).toArray();
        Sort1 sortArr = new Sort1(array);
        sortArr.selectionSort();
        sortArr.insertionSort();
        sortArr.mergeSort();
    }
}
