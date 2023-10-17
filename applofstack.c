#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>

#define MAX_SIZE 100

// Structure for the stack
typedef struct {
    char data[MAX_SIZE];
    int top;
} Stack;

void initialize(Stack* stack) {
    stack->top = -1;
}

void push(Stack* stack, char value) {
    stack->data[++stack->top] = value;
}

char pop(Stack* stack) {
    return stack->data[stack->top--];
}

bool isEmpty(Stack* stack) {
    return stack->top == -1;
}

// Evaluate a postfix expression
int evaluatePostfixExpression(const char* expression) {
    Stack stack;
    initialize(&stack);

    for (int i = 0; expression[i] != '\0'; i++) {
        if (isdigit(expression[i])) {
            push(&stack, expression[i]);
        } else if (expression[i] == ' ') {
            continue;  // Ignore spaces
        } else {
            int operand2 = pop(&stack) - '0';
            int operand1 = pop(&stack) - '0';
            int result;

            switch (expression[i]) {
                case '+':
                    result = operand1 + operand2;
                    break;
                case '-':
                    result = operand1 - operand2;
                    break;
                case '*':
                    result = operand1 * operand2;
                    break;
                case '/':
                    result = operand1 / operand2;
                    break;
            }

            push(&stack, result + '0');
        }
    }

    return pop(&stack) - '0';
}

// Check bracket matching
bool isBracketMatch(const char* expression) {
    Stack stack;
    initialize(&stack);

    for (int i = 0; expression[i] != '\0'; i++) {
        if (expression[i] == '(') {
            push(&stack, '(');
        } else if (expression[i] == ')') {
            if (isEmpty(&stack)) {
                return false;
            }
            pop(&stack);
        }
    }

    return isEmpty(&stack);
}

int main() {
    char postfixExpression[MAX_SIZE];
    printf("Enter a postfix expression: ");
    scanf("%[^\n]", postfixExpression);
    getchar(); // Consume the newline character

    int result = evaluatePostfixExpression(postfixExpression);
    printf("Postfix expression result: %d\n", result);

    char bracketExpression[MAX_SIZE];
    printf("Enter an expression with brackets: ");
    scanf("%[^\n]", bracketExpression);
    getchar(); // Consume the newline character

    if (isBracketMatch(bracketExpression)) {
        printf("Brackets are matched.\n");
    } else {
        printf("Brackets are not matched.\n");
    }

    return 0;
}
