#include <stdio.h>
#include <ctype.h>

#define MAX 100
float st[MAX];
int top = -1;

void push(float st[], float val) {
    if (top < MAX - 1) st[++top] = val;
}

float pop(float st[]) {
    return (top == -1) ? -1 : st[top--];
}

float evaluatePostfixExp(char exp[]) {
    int i = 0;
    float op1, op2, value;
    while (exp[i] != '\0') {
        if (isdigit(exp[i])) {
            push(st, (float)(exp[i] - '0'));
        } else {
            op2 = pop(st);
            op1 = pop(st);
            switch (exp[i]) {
                case '+': value = op1 + op2; break;
                case '-': value = op1 - op2; break;
                case '*': value = op1 * op2; break;
                case '/': value = op1 / op2; break;
                case '%': value = (int)op1 % (int)op2; break;
            }
            push(st, value);
        }
        i++;
    }
    return pop(st);
}

int main() {
    char exp[100];
    printf("\nEnter any postfix expression: ");
    gets(exp);
    printf("\nValue of Postfix expression = %.2f", evaluatePostfixExp(exp));
    return 0;
}
