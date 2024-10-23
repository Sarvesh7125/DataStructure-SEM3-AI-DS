#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 100
char st[MAX];
int top = -1;

void push(char st[], char val) {
    if (top < MAX - 1) st[++top] = val;
}

char pop(char st[]) {
    return (top == -1) ? ' ' : st[top--];
}

int getPriority(char op) {
    return (op == '/' || op == '*' || op == '%') ? 1 : (op == '+' || op == '-') ? 0 : -1;
}

void InfixtoPostfix(char source[], char target[]) {
    int i = 0, j = 0;
    while (source[i] != '\0') {
        if (source[i] == '(') push(st, source[i]);
        else if (source[i] == ')') {
            while (top != -1 && st[top] != '(') target[j++] = pop(st);
            if (top == -1) { printf("\nINCORRECT EXPRESSION"); exit(1); }
            pop(st);
        } else if (isdigit(source[i]) || isalpha(source[i])) {
            target[j++] = source[i];
        } else if (strchr("+-*/%", source[i])) {
            while (top != -1 && st[top] != '(' && getPriority(st[top]) >= getPriority(source[i]))
                target[j++] = pop(st);
            push(st, source[i]);
        } else {
            printf("\nINCORRECT ELEMENT IN EXPRESSION"); exit(1);
        }
        i++;
    }
    while (top != -1 && st[top] != '(') target[j++] = pop(st);
    target[j] = '\0';
}

int main() {
    char infix[MAX], postfix[MAX];
    printf("\nEnter any infix expression: ");
    gets(infix);
    InfixtoPostfix(infix, postfix);
    printf("\nThe corresponding postfix expression is: %s\n", postfix);
    return 0;
}
