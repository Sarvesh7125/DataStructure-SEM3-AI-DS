#include <stdio.h>
#include <stdlib.h>

#define MAX 10
int queue[MAX], front = -1, rear = -1;

void insert(int queue[], int val) {
    if (rear == MAX - 1) {
        printf("\nOVERFLOW\n");
        return;
    }
    if (front == -1) front = 0;
    queue[++rear] = val;
}

int delete_element(int queue[]) {
    if (front == -1 || front > rear) {
        printf("\nUNDERFLOW\n");
        return -1;
    }
    int val = queue[front++];
    if (front > rear) front = rear = -1;
    return val;
}

void display(int queue[]) {
    if (front == -1 || front > rear) {
        printf("\nQUEUE IS EMPTY\n");
        return;
    }
    printf("\nQueue Elements: ");
    for (int i = front; i <= rear; i++) {
        printf("%d ", queue[i]);
    }
    printf("\n");
}

int main() {
    int val, option;
    do {
        printf("\nQueue Menu: 1. Enqueue \t 2. Dequeue \t 3. Display \t 4. Exit\n");
        printf("Enter your option: ");
        scanf("%d", &option);
        switch (option) {
            case 1:
                printf("\nEnter the number to be pushed in queue: ");
                scanf("%d", &val);
                insert(queue, val);
                display(queue);
                break;
            case 2:
                val = delete_element(queue);
                if (val != -1) printf("\nDeleted element is %d\n", val);
                display(queue);
                break;
            case 3:
                display(queue);
                break;
            case 4:
                printf("\nEND OF PROGRAM !!");
        }
    } while (option != 4);
    return 0;
}
