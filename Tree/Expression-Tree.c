#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure for the Expression Tree Node
struct ExpressionTreeNode
{
    char c;
    struct ExpressionTreeNode *leftChild;
    struct ExpressionTreeNode *rightChild;
};

// Function to check if a character is an operator
int isOperator(char c)
{
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

// Function to perform inorder traversal of the tree
void inorderTraversal(struct ExpressionTreeNode *root){
    if (root == NULL){
        return; // Exit if the tree is empty
    }
    inorderTraversal(root->leftChild); // Traverse the left subtree
    printf("%c ", root->c); // Print the character in the node
    inorderTraversal(root->rightChild); // Traverse the right subtree
}

int main()
{
    struct ExpressionTreeNode *root = NULL; // Initialize the root as NULL
    char infix[] = "ab+cd-*"; // Postfix expression
    struct ExpressionTreeNode *stack[10]; // Stack to store tree nodes
    int top = -1; // Initialize the stack top

    // Creating the expression tree
    for (int i = 0; i < strlen(infix); i++)
    {
        struct ExpressionTreeNode *temp = (struct ExpressionTreeNode *)malloc(sizeof(struct ExpressionTreeNode));
        temp->c = infix[i];
        temp->leftChild = NULL;
        temp->rightChild = NULL;

        if (!isOperator(infix[i]))
        { // Operand
            stack[++top] = temp; // Push the operand node onto the stack
        }
        else
        { // Operator
            temp->rightChild = stack[top--]; // Pop two nodes for the operator
            temp->leftChild = stack[top--];  // Assign them as children of the operator node
            stack[++top] = temp; // Push the operator node back onto the stack
        }
    }
    root = stack[top--]; // The last node on the stack is the root of the expression tree

    // The root can now be used for further operations (e.g., traversals).
    printf("Inorder traversal Expression of given tree : ");
    inorderTraversal(root); // Perform inorder traversal to display the expression tree in infix form
    printf("\n"); // Newline for better output formatting
    
    return 0;
}
