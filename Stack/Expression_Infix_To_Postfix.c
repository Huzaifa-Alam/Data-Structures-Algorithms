#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define Max 100

// Global variables
int stack[Max]; // Stack to hold operators
// char stack[Max]; // Stack to hold operators
char infix[Max], postfix[Max]; // Arrays to hold the infix and postfix expressions
int top = -1; // Initialize top of the stack to -1, indicating an empty stack

// Function prototypes
void print();
int precedence(char c);
void push(char c);
char pop();
int space(char c);
int isempty();
void inToPostfix();

int main()
{
    printf("Enter infix Expression: ");
    gets(infix);

    inToPostfix(); // Convert the infix expression to postfix
    print(); // Print the resulting postfix expression

    return 0;
}

// Function to convert infix expression to postfix
void inToPostfix() {
    int i, j = 0;
    char symbol, next;

    for (i = 0; i < strlen(infix); i++) {
        symbol = infix[i];

        if (!space(symbol)) { // Skip spaces and tabs
            switch (symbol) {
                case '(':
                    push(symbol); // Push '(' onto the stack
                    break;

                case ')':
                    while ((next = pop()) != '(') { // Pop and add to postfix until '(' is found
                        postfix[j++] = next;
                    }
                    break;

                // If symbol is an operator
                case '+':
                case '-':
                case '*':
                case '/':
                case '^':
                    while (!isempty() && precedence(stack[top]) >= precedence(symbol)) {
                        postfix[j++] = pop(); // Pop higher precedence operators and add to postfix
                    }
                    push(symbol); // Push the current operator onto the stack
                    break;

                default:
                    postfix[j++] = symbol; // If symbol is an operand, add it to postfix
                    break;
            }
        }
    }

    while (!isempty()) { // Pop remaining operators from the stack
        postfix[j++] = pop();
    }

    postfix[j] = '\0'; // Null-terminate the postfix expression
}



// Function to determine the precedence of operators
int precedence(char c)
{
    switch (c)
    {
        case '^':
            return 3; // Highest precedence

        case '*':
        case '/':
            return 2;

        case '+':
        case '-':
            return 1;

        default:
            return 0; // Lowest precedence (non-operators)
    }
}

// Function to print the postfix expression
void print(){
    int i = 0;
    printf("The Equivalent Expression in PostFix is: ");
    while (postfix[i])
    {
        printf("%c", postfix[i++]);
    }
    printf("\n");
}

// Function to push an operator onto the stack
void push(char c){
    if (top == Max-1){
        printf("OverFlow");
        return ;
    }
    top++;
    stack[top] = c;
}

// Function to pop an operator from the stack
char pop(){
    char poppedval;
    if(top == -1){
        printf("Stack UnderFLow");
        exit(1);
    }
    poppedval = stack[top];
    top--;
    return poppedval;
}
