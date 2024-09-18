#include <stdio.h>
#include <stdlib.h>

// Define the structure for a Binary Tree node
struct BinaryTreeNode {
    int data;
    struct BinaryTreeNode *left;
    struct BinaryTreeNode *right;
};

// Global root for the BST
struct BinaryTreeNode *root = NULL;



// Searching any element in Binary Search Tree Using Looping
void searchInBstloop(struct BinaryTreeNode* root, int search) {
    struct BinaryTreeNode* temp = root; // Initialize temp to root

    while (temp != NULL) {
        if (search == temp->data) {
            printf("Successfully found...\n");
            return;
        }
        if (search < temp->data) {
            temp = temp->left;
        } else {
            temp = temp->right;
        }
    }

    printf("Not found...\n");
}

// Function to create a new node
struct BinaryTreeNode* createNode(int data) {
    struct BinaryTreeNode* newNode = (struct BinaryTreeNode*) malloc(sizeof(struct BinaryTreeNode));
    if (!newNode) {
        printf("Memory allocation failed\n");
        return NULL;
    }
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to insert data into the BST
struct BinaryTreeNode* insertInNode(struct BinaryTreeNode* root, int data) {
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

// Inorder Traversal: This will print the tree nodes in ascending order
void inOrder(struct BinaryTreeNode* root) {
    if (root == NULL) {
        return;
    }
    inOrder(root->left);        // Traverse left subtree
    printf("%d ", root->data);  // Print the current node's data
    inOrder(root->right);       // Traverse right subtree
}

int main() {
    printf("Binary Search Tree Example!\n");

    int user, search;

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

    printf("Enter value to Search in BST: ");
    scanf("%d", &search);
    
    printf("Searching using recursive approach...\n");
    // searchInBstRecursive(root, search);
    
    printf("Searching using loop approach...\n");
    searchInBstloop(root, search);

    return 0;
}
