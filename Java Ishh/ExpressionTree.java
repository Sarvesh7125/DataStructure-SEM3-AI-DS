import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

class Stack {
    Node[] stk;
    int top;

    Stack() {
        this.stk = new Node[100];
        top = -1;
    }

    void push(Node pushNode) {
        if (top < 99) stk[++top] = pushNode;
    }

    Node pop() {
        return (top == -1) ? null : stk[top--];
    }

    Node peek() {
        return (top == -1) ? null : stk[top];
    }
}

class Node {
    String data;
    Node left, right;

    Node(String data) {
        this.data = data;
        this.left = this.right = null;
    }
}

class BinarySearchTree {
    Node root;

    BinarySearchTree() {
        this.root = null;
    }

    void inorder() { inorderPriv(this.root); }
    private void inorderPriv(Node root) {
        if (root != null) {
            inorderPriv(root.left);
            System.out.print(root.data);
            inorderPriv(root.right);
        }
    }

    void preorder() { preorderPriv(this.root); }
    private void preorderPriv(Node root) {
        if (root != null) {
            System.out.print(root.data);
            preorderPriv(root.left);
            preorderPriv(root.right);
        }
    }
}

public class ExpressionTree {
    static BinarySearchTree expressionTree(String[] expressionArray) {
        String operators = "+-*/^";
        BinarySearchTree bst = new BinarySearchTree();
        Stack expStack = new Stack();

        for (String i : expressionArray) {
            Node temp = new Node(i);
            if (!operators.contains(temp.data)) expStack.push(temp);
            else {
                temp.right = expStack.pop();
                temp.left = expStack.pop();
                expStack.push(temp);
            }
        }

        bst.root = expStack.peek();
        return bst;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        System.out.print("Enter an expression: ");
        String[] expressionArray = in.readLine().trim().split("");
        BinarySearchTree bst = expressionTree(expressionArray);
        System.out.print("Infix Expression: "); bst.inorder();
        System.out.print("\nPrefix Expression: "); bst.preorder();
    }
}
