/*Problem: Convert an infix expression to postfix notation using stack.

Input:
- Single line: infix expression (operands are single characters)

Output:
- Print the postfix expression

Example:
Input:
A+B*C 

Output:
ABC*+

Explanation:
Operator precedence: * > +
Use stack to handle operator precedence and associativity*/
#include <stdio.h>
#include <ctype.h>

#define MAX 100

char stack[MAX];
int top = -1;

void push(char x) {
    stack[++top] = x;
}

char pop() {
    return stack[top--];
}

int precedence(char x) {
    if (x == '+' || x == '-') return 1;
    if (x == '*' || x == '/') return 2;
    if (x == '^') return 3;
    return 0;
}

int main() {
    char exp[MAX];
    int i = 0;
    
    scanf("%s", exp);

    while (exp[i] != '\0') {
        
        if (isalnum(exp[i])) {
            printf("%c", exp[i]);
        }
        
        else if (exp[i] == '(') {
            push(exp[i]);
        }
        
        else if (exp[i] == ')') {
            while (stack[top] != '(') {
                printf("%c", pop());
            }
            pop(); 
        }
        
        else {
            while (top != -1 && precedence(stack[top]) >= precedence(exp[i])) {
                printf("%c", pop());
            }
            push(exp[i]);
        }

        i++;
    }

    while (top != -1) {
        printf("%c", pop());
    }

    return 0;
}
