import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

public class HashTable {
    final int size = 10;
    int[] table;
    int collision;
    int swaps;

    HashTable() {
        table = new int[size];
        collision = 0;
        swaps = 0;
    }

    void insert(int key, int index) {
        while (table[index] != 0) {
            collision++;
            swaps++;
            index = (index + 1) % size;
        }
        table[index] = key;
    }

    void division(int key) {
        insert(key, key % size);
    }

    void multiplication(int key) {
        insert(key, (int) (size * ((key * 0.618) % 1)));
    }

    void midsquare(int key) {
        insert(key, (key * key % 10000) % size);
    }

    void folding(int key) {
        String keyString = String.valueOf(key);
        int sum = 0;
        for (int i = 0; i < keyString.length(); i += 2) {
            sum += Integer.parseInt(keyString.substring(i, Math.min(i + 2, keyString.length())));
        }
        insert(key, sum % size);
    }

    void display() {
        System.out.println("HashTable:");
        for (int i = 0; i < table.length; i++) {
            System.out.println("Index " + i + " : " + table[i]);
        }
        System.out.println("Collisions: " + collision);
        System.out.println("Swaps: " + swaps);
    }

    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        System.out.print("Enter values (space-separated): ");
        int[] arr = Arrays.stream(in.readLine().trim().split(" "))
                          .mapToInt(Integer::parseInt)
                          .toArray();
        
        HashTable table = new HashTable();
        System.out.println("Division Hashing:");
        for (int i : arr) table.division(i);
        table.display();

        HashTable table1 = new HashTable();
        System.out.println("Multiplication Hashing:");
        for (int j : arr) table1.multiplication(j);
        table1.display();

        HashTable table2 = new HashTable();
        System.out.println("Mid-Square Hashing:");
        for (int j : arr) table2.midsquare(j);
        table2.display();

        HashTable table3 = new HashTable();
        System.out.println("Folding Hashing:");
        for (int j : arr) table3.folding(j);
        table3.display();
    }
}
