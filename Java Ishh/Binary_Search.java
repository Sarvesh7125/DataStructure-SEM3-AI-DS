import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

public class Binary_Search {
    static int BinarySearch (int key, int[] arr) {
        Arrays.sort(arr);
        int left = 0;
        int right = arr.length - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (arr[mid] == key) {
                return mid;
            }
            if (arr[mid] < key) {
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }
        return -1;
    }

    public static void main (String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        System.out.print("Enter values of array : ");
        int num[] = Arrays.stream(in.readLine().replaceAll("\\s+", " ").split(" ")).mapToInt(Integer::parseInt).toArray();
        System.out.print("\nEnter the number to search : ");
        int key = Integer.parseInt(in.readLine());
        if (Binary_Search.BinarySearch(key, num) == -1) {
            System.out.println("\nElement not found !!");
        }
        else {
            System.out.println("\nElement found at index " + Binary_Search.BinarySearch(key, num) + ".\n");
        }
    }
}