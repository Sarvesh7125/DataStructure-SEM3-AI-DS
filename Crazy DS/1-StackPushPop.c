#include <stdio.h>
#include <stdlib.h>
#define MAX 10

int st[MAX], top = -1;

void push(int st[], int val) {
    if (top == MAX - 1) {
        printf("\nSTACK OVERFLOW\n");
    } else {
        st[++top] = val;
    }
}

int pop(int st[]) {
    if (top == -1) {
        printf("\nSTACK UNDERFLOW\n");
        return -1;
    }
    return st[top--];
}

void display(int st[]) {
    if (top == -1) {
        printf("\nSTACK IS EMPTY\n");
        return;
    }
    printf("\nStack Elements : ");
    for (int i = top; i >= 0; i--) {
        printf(" %d", st[i]);
    }
    printf("\n");
}

int peek(int st[]) {
    if (top == -1) {
        printf("\nSTACK IS EMPTY\n");
        return -1;
    }
    return st[top];
}

int main() {
    int val, option;
    do {
        printf("\nStack Menu : 1. Push \t 2. Pop \t 3. Peek \t 4. Display \t 5. Exit\n");
        printf("Enter your option: ");
        scanf("%d", &option);
        switch (option) {
            case 1:
                printf("\nEnter the number to be pushed: ");
                scanf("%d", &val);
                push(st, val);
                display(st);
                break;
            case 2:
                val = pop(st);
                if (val != -1)
                    printf("\nPopped: %d\n", val);
                display(st);
                break;
            case 3:
                val = peek(st);
                if (val != -1)
                    printf("\nTop: %d\n", val);
                break;
            case 4:
                display(st);
                break;
            case 5:
                printf("\nEND OF PROGRAM !!");
        }
    } while (option != 5);
    return 0;
}
