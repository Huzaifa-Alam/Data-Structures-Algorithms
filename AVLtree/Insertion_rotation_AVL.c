#include <stdio.h>
#include <stdlib.h>

// Structure for a node in the AVL tree
struct node {
    int key; // key value of the node
    struct node *left, *right; // left and right children pointers
    int height; // height of the node
};

// Function to calculate the maximum of two integers
int max(int a, int b) {
    return a > b ? a : b;
}

// Function to create a new node
struct node* create_node(int key) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    if (!newNode) {
        printf("Memory error\n");
        return NULL;
    }
    newNode->key = key;
    newNode->left = newNode->right = NULL;
    newNode->height = 1; // new node is initially set to height 1
    return newNode;
}

// Function to get the height of a node
int getHeight(struct node *n) {
    if (n == NULL)
        return 0;
    return n->height;
}

// Function to get the balance factor of a node
int getBalanceFactor(struct node *n) {
    if (n == NULL)
        return 0;
    return getHeight(n->left) - getHeight(n->right);
}

// Function to perform a right rotation
struct node* rightRotate(struct node *y) {
    struct node *x = y->left;
    struct node *T2 = x->right;

    // Perform rotation
    x->right = y;
    y->left = T2;

    // Update heights
    y->height = max(getHeight(y->right), getHeight(y->left)) + 1;
    x->height = max(getHeight(x->right), getHeight(x->left)) + 1;

    // Return new root
    return x;
}

// Function to perform a left rotation
struct node* leftRotate(struct node *x) {
    struct node *y = x->right;
    struct node *T2 = y->left;

    // Perform rotation
    y->left = x;
    x->right = T2;

    // Update heights
    x->height = max(getHeight(x->right), getHeight(x->left)) + 1;
    y->height = max(getHeight(y->right), getHeight(y->left)) + 1;

    // Return new root
    return y;
}

// Function to insert a node into the AVL tree
struct node* insert(struct node* node, int key) {
    // 1. Perform the normal BST insertion
    if (node == NULL)
        return create_node(key);

    if (key < node->key)
        node->left = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);
    else // Duplicate keys are not allowed in AVL tree
        return node;

    // 2. Update height of this ancestor node
    node->height = 1 + max(getHeight(node->left), getHeight(node->right));

    // 3. Get the balance factor of this ancestor node
    int bf = getBalanceFactor(node);

    // 4. Balance the node if it has become unbalanced

    // Left Left Case
    if (bf > 1 && key < node->left->key)
        return rightRotate(node);

    // Right Right Case
    if (bf < -1 && key > node->right->key)
        return leftRotate(node);

    // Left Right Case
    if (bf > 1 && key > node->left->key) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    // Right Left Case
    if (bf < -1 && key < node->right->key) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    // Return the unchanged node pointer
    return node;
}

// Function for preorder traversal of the AVL tree
void preOrder(struct node *node) {
    if (node != NULL) {
        printf("%d ", node->key);
        preOrder(node->left);
        preOrder(node->right);
    }
}

// Main function
int main() {
    printf("Hello AVL Tree\n");

    struct node *root = NULL;

    // Insert nodes into the AVL tree
    root = insert(root, 9);
    root = insert(root, 5);
    root = insert(root, 10);
    root = insert(root, 0);
    root = insert(root, 6);
    root = insert(root, 11);
    root = insert(root, 15);
    root = insert(root, -1);
    root = insert(root, 1);

    // Preorder traversal of the AVL tree
    printf("Preorder traversal of AVL tree is: \n");
    preOrder(root);
    printf("\n");

    return 0;
}
