import java.util.Scanner;

class Node {
    int data;
    Node left, right;
    public Node(int data) {
        this.data = data;
        this.left = this.right = null;
    }
}

public class BinarySearchTree {
    Node root;

    public BinarySearchTree() {
        root = null;
    }
    
    void insert(int val) {
        if (root == null) {
            root = new Node(val);
            return;
        }
        insertPriv(val, root);
    }

    private void insertPriv(int val, Node root) {
        if (val < root.data) {
            if (root.left == null) root.left = new Node(val);
            else insertPriv(val, root.left);
        } else if (val > root.data) {
            if (root.right == null) root.right = new Node(val);
            else insertPriv(val, root.right);
        }
    }

    boolean search(int val) {
        return searchPriv(val, root) != null;
    }

    Node searchPriv(int val, Node root) {
        if (root == null) return root;
        if (root.data == val) return root;
        return val < root.data ? searchPriv(val, root.left) : searchPriv(val, root.right);
    }

    void inOrder() { inOrderPriv(root); }
    private void inOrderPriv(Node root) {
        if (root == null) return;
        inOrderPriv(root.left);
        System.out.print(root.data + " ");
        inOrderPriv(root.right);
    }
    
    void preOrder() { preOrderPriv(root); }
    private void preOrderPriv(Node root) {
        if (root == null) return;
        System.out.print(root.data + " ");
        preOrderPriv(root.left);
        preOrderPriv(root.right);
    }

    void postOrder() { postOrderPriv(root); }
    private void postOrderPriv(Node root) {
        if (root == null) return;
        postOrderPriv(root.left);
        postOrderPriv(root.right);
        System.out.print(root.data + " ");
    }
    
    boolean delete(int val) {
        if (root == null) return false;
        return deletePriv(val, root) != null;
    }

    private Node deletePriv(int val, Node root) {
        if (root == null) return root;
        if (val < root.data) root.left = deletePriv(val, root.left);
        else if (val > root.data) root.right = deletePriv(val, root.right);
        else {
            if (root.left == null) return root.right;
            if (root.right == null) return root.left;
            Node curr = root.right;
            while (curr.left != null) curr = curr.left;
            root.data = curr.data;
            root.right = deletePriv(curr.data, root.right);
        }
        return root;
    }

    public static void main(String[] args) {
        int opt;
        BinarySearchTree bst = new BinarySearchTree();
        try (Scanner sc = new Scanner(System.in)) {
            do {
                System.out.println("\nMenu: 1. Insert 2. Delete 3. Search 4. Display 5. Exit");
                opt = sc.nextInt();
                switch (opt) {
                    case 1:
                        System.out.print("Enter number: ");
                        bst.insert(sc.nextInt());
                        break;
                    case 2:
                        System.out.print("Enter delete element: ");
                        if (bst.delete(sc.nextInt())) System.out.println("Element deleted!");
                        else System.out.println("Element not found");
                        break;
                    case 3:
                        System.out.print("Enter Search element: ");
                        System.out.println(bst.search(sc.nextInt()) ? "Element found" : "Element not found!");
                        break;
                    case 4:
                        System.out.print("Display: 1. Inorder 2. PostOrder 3. PreOrder\nEnter choice: ");
                        int c = sc.nextInt();
                        switch (c) {
                            case 1: bst.inOrder(); break;
                            case 2: bst.postOrder(); break;
                            case 3: bst.preOrder(); break;
                        }
                        break;
                    case 5: System.out.println("End of Program !!"); break;
                }
            } while (opt != 5);
        }
    }
}
