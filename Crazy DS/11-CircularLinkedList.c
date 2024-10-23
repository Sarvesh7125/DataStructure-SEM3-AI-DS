#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} node;

typedef struct Linked_list {
    node* head;
} Linked_list;

node* create_node(int val) {
    node* new_node = (node*)malloc(sizeof(node));
    new_node->data = val; new_node->next = NULL;
    return new_node;
}

void insert_begin(Linked_list* ll, int val) {
    node* new_node = create_node(val);
    if (ll->head == NULL) {
        ll->head = new_node; new_node->next = ll->head; return;
    }
    node* curr = ll->head;
    while (curr->next != ll->head) curr = curr->next;
    new_node->next = ll->head; ll->head = new_node; curr->next = ll->head;
}

void insert_end(Linked_list* ll, int val) {
    node* new_node = create_node(val);
    if (ll->head == NULL) {
        ll->head = new_node; new_node->next = ll->head; return;
    }
    node* curr = ll->head;
    while (curr->next != ll->head) curr = curr->next;
    new_node->next = curr->next; curr->next = new_node;
}

void insert_after(Linked_list* ll, int val, int pos) {
    node* new_node = create_node(val);
    if (ll->head == NULL) {
        ll->head = new_node; new_node->next = ll->head; return;
    }
    node* curr = ll->head;
    while (curr->data != pos) {
        if (curr->next == ll->head) { printf("\nElement not found\n"); return; }
        curr = curr->next;
    }
    new_node->next = curr->next; curr->next = new_node;
}

int delete_begin(Linked_list* ll) {
    if (ll->head == NULL) { printf("\nUNDERFLOW\n"); return -1; }
    if (ll->head->next == ll->head) {
        int val = ll->head->data; ll->head = NULL; free(ll->head); return val;
    }
    int val = ll->head->data; node* del_node = ll->head; node* curr = ll->head;
    while (curr->next != ll->head) curr = curr->next;
    ll->head = ll->head->next; curr->next = ll->head; free(del_node); return val;
}

int delete_end(Linked_list* ll) {
    if (ll->head == NULL) { printf("\nUNDERFLOW\n"); return -1; }
    if (ll->head->next == ll->head) {
        node* del_node = ll->head; int val = del_node->data; ll->head = NULL; free(del_node); return val;
    }
    node* curr = ll->head;
    while (curr->next->next != ll->head) curr = curr->next;
    node* del_node = curr->next; int val = del_node->data; curr->next = curr->next->next; free(del_node); return val;
}

int delete_specific(Linked_list* ll, int pos) {
    if (ll->head == NULL) { printf("\nUNDERFLOW\n"); return -1; }
    if (ll->head->data == pos) return delete_begin(ll);
    node* curr = ll->head;
    while (curr->next->data != pos) {
        if (curr->next->next == ll->head) { printf("\nElement not found\n"); return -1; }
        curr = curr->next;
    }
    node* del_node = curr->next; int val = del_node->data; curr->next = curr->next->next; free(del_node); return val;
}

int search(Linked_list* ll, int val) {
    if (ll->head == NULL) { printf("\nUNDERFLOW\n"); return -1; }
    int pos = 1; node* curr = ll->head;
    while (curr->data != val) {
        if (curr->next == ll->head) { printf("\nElement not found\n"); return -1; }
        curr = curr->next; pos++;
    }
    return pos;
}

void display(Linked_list* ll) {
    if (ll->head == NULL) { printf("\nList is Empty\n\n"); return; }
    node* curr = ll->head; printf("\nList Elements: ");
    do { printf("%d ", curr->data); curr = curr->next; } while (curr != ll->head);
    printf("\n\n");
}

int main() {
    int val, opt, opt2, pos;
    Linked_list* ll = (Linked_list*)malloc(sizeof(Linked_list));
    ll->head = NULL;
    do {
        printf("Linked List Menu: 1. Insert    2. Delete    3. Search    4. Display    5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &opt);
        switch (opt) {
            case 1:
                printf("\nInsert: 1. At Beginning    2. At End    3. After Node\n");
                printf("Enter your choice: ");
                scanf("%d", &opt2);
                switch (opt2) {
                    case 1: printf("\nEnter number: "); scanf("%d", &val); insert_begin(ll, val); break;
                    case 2: printf("\nEnter number: "); scanf("%d", &val); insert_end(ll, val); break;
                    case 3: printf("\nEnter number: "); scanf("%d", &val); printf("\nEnter after number: "); scanf("%d", &pos); insert_after(ll, val, pos); break;
                }
                display(ll); break;
            case 2:
                printf("\nDelete: 1. At Beginning    2. At End    3. Specific Node\n");
                printf("Enter your choice: ");
                scanf("%d", &opt2);
                switch (opt2) {
                    case 1: val = delete_begin(ll); if (val != -1) printf("\nDeleted: %d\n", val); break;
                    case 2: val = delete_end(ll); if (val != -1) printf("\nDeleted: %d\n", val); break;
                    case 3: printf("\nEnter number to delete: "); scanf("%d", &pos); val = delete_specific(ll, pos); if (val != -1) printf("\nDeleted: %d\n", val); break;
                }
                display(ll); break;
            case 3: printf("\nEnter number to search: "); scanf("%d", &val); int res = search(ll, val); if (res != -1) printf("\nFound at position: %d\n", res); break;
            case 4: display(ll); break;
            case 5: printf("\nEND OF PROGRAM!!\n"); break;
        }
    } while (opt != 5);
    free(ll);
    return 0;
}
