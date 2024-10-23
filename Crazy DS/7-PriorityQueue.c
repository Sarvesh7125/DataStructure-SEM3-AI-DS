#include <stdio.h>
#define MAX 5

int queue[MAX][2];
int size = 0;

void Enqueue(int queue[][2], int val, int prio) {
    if (size == MAX) {
        printf("\nOVERFLOW\n");
        return;
    }
    int i = size - 1;
    while (i >= 0 && queue[i][1] > prio) {
        queue[i + 1][0] = queue[i][0];
        queue[i + 1][1] = queue[i][1];
        i--;
    }
    queue[i + 1][0] = val;
    queue[i + 1][1] = prio;
    size++;
}

int Dequeue(int queue[][2]) {
    if (size == 0) {
        printf("\nUNDERFLOW\n");
        return -1;
    }
    int val = queue[0][0];
    for (int i = 0; i < size - 1; i++) {
        queue[i][0] = queue[i + 1][0];
        queue[i][1] = queue[i + 1][1];
    }
    size--;
    return val;
}

void display(int queue[][2]) {
    if (size == 0) {
        printf("\nQueue is Empty.\n");
        return;
    }
    printf("\nQueue Elements: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", queue[i][0]);
    }
    printf("\n          Priority: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", queue[i][1]);
    }
    printf("\n");
}

int main() {
    int val, option, prio;
    do {
        printf("\nPriority Queue Menu: 1. Enqueue \t 2. Dequeue \t 3. Display \t 4. Exit\n");
        printf("Enter your option: ");
        scanf("%d", &option);
        switch (option) {
            case 1:
                printf("\nEnter the number: ");
                scanf("%d", &val);
                printf("Enter the priority: ");
                scanf("%d", &prio);
                Enqueue(queue, val, prio);
                display(queue);
                break;
            case 2:
                val = Dequeue(queue);
                if (val != -1) printf("\nThe number with highest priority is %d\n", val);
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
