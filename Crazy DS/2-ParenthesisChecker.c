#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 50
char stk[MAX];
int top = -1;

void push(char c) {
    if (top < MAX - 1) stk[++top] = c;
}

char pop() {
    return (top == -1) ? '\0' : stk[top--];
}

int main() {
    char exp[MAX], temp;
    int flag = 1;
    printf("\nEnter an expression: ");
    gets(exp);
    for (int i = 0; exp[i] != '\0'; i++) {
        if (exp[i] == '(' || exp[i] == '{' || exp[i] == '[') push(exp[i]);
        if (exp[i] == ')' || exp[i] == '}' || exp[i] == ']') {
            if (top == -1) flag = 0;
            else {
                temp = pop();
                if ((exp[i] == ')' && (temp == '{' || temp == '[')) ||
                    (exp[i] == '}' && (temp == '(' || temp == '[')) ||
                    (exp[i] == ']' && (temp == '(' || temp == '{'))) {
                    flag = 0;
                }
            }
        }
    }
    if (top >= 0) flag = 0;
    printf("\n%s Expression.", flag ? "Valid" : "Invalid");
    return 0;
}
