#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Linked_list {
    struct Node* head;
};

void insert_begin(struct Linked_list*, int);
void insert_end(struct Linked_list*, int);
void insert_specific(struct Linked_list*, int, int);
void insert_before(struct Linked_list*, int, int);
void insert_after(struct Linked_list*, int, int);
int delete_begin(struct Linked_list*);
int delete_end(struct Linked_list*);
int delete_specific(struct Linked_list*, int);
int delete_before(struct Linked_list*, int);
int delete_after(struct Linked_list*, int);
int search(struct Linked_list*, int);
void display(struct Linked_list*);

int main() {
    int val, pos, option, option2;
    struct Linked_list* ll = (struct Linked_list*)malloc(sizeof(struct Linked_list));
    ll->head = NULL;

    do {
        printf("Linked List Menu : 1. Insert    2. Delete    3. Search    4. Display    5. Exit\n");
        printf("Enter your choice : ");
        scanf("%d", &option);
        switch(option) {
            case 1:
                printf("\nInsert : 1. At Beginning    2. At End    3. At Specific position    4. Before Node    5. After Node\n");
                printf("Enter your choice : ");
                scanf("%d", &option2);
                switch (option2) {
                    case 1: scanf("%d", &val); insert_begin(ll, val); break;
                    case 2: scanf("%d", &val); insert_end(ll, val); break;
                    case 3: scanf("%d", &val); scanf("%d", &pos); insert_specific(ll, val, pos); break;
                    case 4: scanf("%d", &val); scanf("%d", &pos); insert_before(ll, val, pos); break;
                    case 5: scanf("%d", &val); scanf("%d", &pos); insert_after(ll, val, pos); break;
                }
                display(ll);
                break;
            case 2:
                printf("\nDelete : 1. At Beginning    2. At End    3. A Specific Node    4. Before Node    5. After Node\n");
                printf("Enter your choice : ");
                scanf("%d", &option2);
                switch (option2) {
                    case 1: val = delete_begin(ll); if (val != -1) printf("\nDeleted element is %d\n", val); break;
                    case 2: val = delete_end(ll); if (val != -1) printf("\nDeleted element is %d\n", val); break;
                    case 3: scanf("%d", &pos); val = delete_specific(ll, pos); if (val != -1) printf("\nDeleted element is %d\n", val); break;
                    case 4: scanf("%d", &pos); val = delete_before(ll, pos); if (val != -1) printf("\nDeleted element is %d\n", val); break;
                    case 5: scanf("%d", &pos); val = delete_after(ll, pos); if (val != -1) printf("\nDeleted element is %d\n", val); break;
                }
                display(ll);
                break;
            case 3: scanf("%d", &val); int res = search(ll, val); if (res != -1) printf("\nElement found at %d position.\n", res); break;
            case 4: display(ll); break;
            case 5: printf("\nEND OF PROGRAM!!"); break;
        }
    } while(option != 5);
    free(ll);
    return 0;
}

void insert_begin(struct Linked_list* ll, int val) {
    struct Node* new = (struct Node*)malloc(sizeof(struct Node));
    new->data = val; new->next = ll->head; ll->head = new;
}

void insert_end(struct Linked_list* ll, int val) {
    struct Node* curr = ll->head;
    while (curr && curr->next) curr = curr->next;
    struct Node* new = (struct Node*)malloc(sizeof(struct Node));
    new->data = val; new->next = NULL;
    if (curr) curr->next = new; else ll->head = new;
}

void insert_specific(struct Linked_list* ll, int val, int pos) {
    if (pos == 1) { insert_begin(ll, val); return; }
    struct Node* curr = ll->head;
    for (int i = 1; i < pos - 1 && curr; i++) curr = curr->next;
    if (!curr) { printf("\nPosition does not exist.\n"); return; }
    struct Node* new = (struct Node*)malloc(sizeof(struct Node));
    new->data = val; new->next = curr->next; curr->next = new;
}

void insert_before(struct Linked_list* ll, int val, int node) {
    if (ll->head->data == node) { insert_begin(ll, val); return; }
    struct Node* curr = ll->head;
    while (curr->next && curr->next->data != node) curr = curr->next;
    if (!curr->next) { printf("\nNode not present in Linked List.\n"); return; }
    struct Node* new = (struct Node*)malloc(sizeof(struct Node));
    new->data = val; new->next = curr->next; curr->next = new;
}

void insert_after(struct Linked_list* ll, int val, int node) {
    struct Node* curr = ll->head;
    while (curr && curr->data != node) curr = curr->next;
    if (!curr) { printf("\nNode not present in Linked List.\n"); return; }
    struct Node* new = (struct Node*)malloc(sizeof(struct Node));
    new->data = val; new->next = curr->next; curr->next = new;
}

int delete_begin(struct Linked_list* ll) {
    if (!ll->head) { printf("\nUNDERFLOW\n"); return -1; }
    struct Node* node = ll->head; int val = node->data;
    ll->head = ll->head->next; free(node); return val;
}

int delete_end(struct Linked_list* ll) {
    if (!ll->head) { printf("\nUNDERFLOW\n"); return -1; }
    if (!ll->head->next) { int val = ll->head->data; free(ll->head); ll->head = NULL; return val; }
    struct Node* curr = ll->head; while (curr->next->next) curr = curr->next;
    int val = curr->next->data; free(curr->next); curr->next = NULL; return val;
}

int delete_specific(struct Linked_list* ll, int pos) {
    if (!ll->head) { printf("\nUNDERFLOW\n"); return -1; }
    if (pos == 1) return delete_begin(ll);
    struct Node* curr = ll->head;
    for (int i = 1; i < pos - 1 && curr; i++) curr = curr->next;
    if (!curr || !curr->next) { printf("\nNode not present in Linked List\n"); return -1; }
    struct Node* node = curr->next; int val = node->data; curr->next = node->next; free(node); return val;
}

int delete_before(struct Linked_list* ll, int node) {
    if (!ll->head) { printf("\nUNDERFLOW\n"); return -1; }
    if (ll->head->data == node) { printf("\nNo element before this.\n"); return -1; }
    if (ll->head->next && ll->head->next->data == node) return delete_begin(ll);
    struct Node* curr = ll->head;
    while (curr->next && curr->next->next && curr->next->next->data != node) curr = curr->next;
    if (!curr->next || !curr->next->next) { printf("\nNode not present in Linked List.\n"); return -1; }
    struct Node* del = curr->next; int val = del->data; curr->next = del->next; free(del); return val;
}

int delete_after(struct Linked_list* ll, int node) {
    if (!ll->head) { printf("\nUNDERFLOW\n"); return -1; }
    struct Node* curr = ll->head;
    while (curr && curr->data != node) curr = curr->next;
    if (!curr || !curr->next) { printf("\nNode not present in Linked List.\n"); return -1; }
    struct Node* del = curr->next; int val = del->data; curr->next = del->next; free(del); return val;
}

int search(struct Linked_list* ll, int val) {
    if (!ll->head) { printf("\nLinked List is Empty.\n"); return -1; }
    struct Node* curr = ll->head; int count = 1;
    while (curr) {
        if (curr->data == val) return count;
        count++; curr = curr->next;
    }
    printf("\nElement not found.\n"); return -1;
}

void display(struct Linked_list* ll) {
    if (!ll->head) { printf("\nLinked List is Empty.\n"); return; }
    struct Node* curr = ll->head; printf("\nLinked List Elements : ");
    while (curr) { printf("%d ", curr->data); curr = curr->next; }
    printf("\n");
}
