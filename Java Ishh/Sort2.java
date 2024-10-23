import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;

public class Sort2 {
    int[] arr;

    Sort2(int[] arr) {
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

    void quicksort() {
        quicksortPriv(arr, 0, arr.length - 1);
        System.out.print("Quick Sort: Sorted Array: ");
        printArr(arr);
    }

    private void quicksortPriv(int[] arr, int left, int right) {
        if (left < right) {
            int pivot = partition(arr, left, right);
            quicksortPriv(arr, left, pivot - 1);
            quicksortPriv(arr, pivot + 1, right);
        }
    }

    private int partition(int[] arr, int left, int right) {
        int pivot = arr[right], i = left - 1;
        for (int j = left; j < right; j++) {
            if (arr[j] <= pivot) swap(++i, j, arr);
        }
        swap(i + 1, right, arr);
        return i + 1;
    }

    void heapsort() {
        heapsortPriv(arr);
        System.out.print("Heap Sort: Sorted Array: ");
        printArr(arr);
    }

    private void heapsortPriv(int[] array) {
        int n = array.length;
        for (int i = n / 2 - 1; i >= 0; i--) heapify(array, n, i);
        for (int i = n - 1; i > 0; i--) {
            swap(0, i, array);
            heapify(array, i, 0);
        }
    }

    private static void heapify(int[] array, int n, int i) {
        int largest = i, left = 2 * i + 1, right = 2 * i + 2;
        if (left < n && array[left] > array[largest]) largest = left;
        if (right < n && array[right] > array[largest]) largest = right;
        if (largest != i) {
            swap(i, largest, array);
            heapify(array, n, largest);
        }
    }

    void bucketsort() {
        if (arr.length == 0) return;
        int minValue = arr[0], maxValue = arr[0];
        for (int num : arr) {
            if (num < minValue) minValue = num;
            if (num > maxValue) maxValue = num;
        }

        int bucketCount = 10;
        ArrayList<ArrayList<Integer>> buckets = new ArrayList<>();
        for (int i = 0; i < bucketCount; i++) buckets.add(new ArrayList<>());

        for (int num : arr) {
            int index = (num - minValue) * (bucketCount - 1) / (maxValue - minValue);
            buckets.get(index).add(num);
        }

        ArrayList<Integer> sortedList = new ArrayList<>();
        for (ArrayList<Integer> bucket : buckets) {
            Collections.sort(bucket);
            sortedList.addAll(bucket);
        }

        for (int i = 0; i < arr.length; i++) arr[i] = sortedList.get(i);
        System.out.print("Bucket Sort: Sorted Array: ");
        printArr(arr);
    }

    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        System.out.print("Unsorted Array: ");
        int[] array = Arrays.stream(in.readLine().trim().split(" ")).mapToInt(Integer::parseInt).toArray();
        Sort2 sortArr = new Sort2(array);
        sortArr.quicksort();
        sortArr.heapsort();
        sortArr.bucketsort();
    }
}
