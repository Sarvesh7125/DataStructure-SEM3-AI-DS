#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Queue {
    struct Node* front;
    struct Node* rear;
};

struct Node* create_Node(int val) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = val; node->next = NULL;
    return node;
}

void Enqueue(struct Queue* que, int val) {
    struct Node* new_Node = create_Node(val);
    if (que->front == NULL) {
        que->front = que->rear = new_Node;
        return;
    }
    que->rear->next = new_Node; que->rear = new_Node;
}

int Dequeue(struct Queue* que) {
    if (que->front == NULL) { printf("\nUNDERFLOW\n"); return -1; }
    int val = que->front->data; struct Node* node = que->front;
    if (que->front == que->rear) { que->front = que->rear = NULL; free(node); return val; }
    que->front = que->front->next; free(node); return val;
}

void display(struct Queue* que) {
    if (que->front == NULL) { printf("\nQueue is Empty\n"); return; }
    struct Node* curr = que->front;
    printf("\nQueue Elements are: ");
    while (curr) { printf("%d ", curr->data); curr = curr->next; }
    printf("\n");
}

int main() {
    int val, opt;
    struct Queue* que = (struct Queue*)malloc(sizeof(struct Queue));
    que->front = que->rear = NULL;
    
    do {
        printf("\nQueue Menu: 1. Enqueue \t 2. Dequeue \t 3. Display \t 4. Exit\n");
        printf("Enter your option: ");
        scanf("%d", &opt);
        switch (opt) {
            case 1: printf("\nEnter the number to be inserted in queue: "); scanf("%d", &val); Enqueue(que, val); display(que); break;
            case 2: val = Dequeue(que); if (val != -1) printf("\nThe number deleted is %d\n", val); display(que); break;
            case 3: display(que); break;
            case 4: printf("\nEND OF PROGRAM !!"); break;
        }
    } while (opt != 4);
    return 0;
}

