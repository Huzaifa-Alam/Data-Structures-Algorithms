
#include <stdio.h>
#include <stdlib.h>

struct BST {
    int data;
    struct BST *left, *right;
};

struct BST *root = NULL;

// Function to create a new node in the BST
struct BST *createNode(int data) {
    struct BST *newNode = (struct BST *)malloc(sizeof(struct BST));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        return NULL;
    }
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to insert data into the BST
struct BST *insertInNode(struct BST *root, int data) {
    if (root == NULL) {
        root = createNode(data);
        return root;
    }
    if (data < root->data) {
        root->left = insertInNode(root->left, data);  // Insert in left subtree
    } else if (data > root->data) {
        root->right = insertInNode(root->right, data); // Insert in right subtree
    }
    return root;
}

// Inorder Traversal (Always Ascending)
void inOrder(struct BST *root) {
    if (root == NULL) {
        return;
    }
    inOrder(root->left);              // Traverse the left subtree
    printf("%d, ", root->data);        // Visit the current node
    inOrder(root->right);              // Traverse the right subtree
}


int main() {
    int user;

    // Loop for user inputs
    while (1) {
        printf("Insert value in Binary Search Tree (-1 to exit): ");
        scanf("%d", &user);
        
        if (user == -1) {
            break;  // Exit the loop if user inputs -1
        }
        
        root = insertInNode(root, user);
    }

    printf("BST created successfully.\n");

    printf("Inorder traversal of Binary tree: ");
    inOrder(root);
    printf("\n");

    return 0;
}
