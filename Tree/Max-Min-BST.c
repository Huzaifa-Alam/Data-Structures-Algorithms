#include <stdio.h>
#include <stdlib.h>

// Define the structure for a Binary Tree node
struct BinaryTreeNode
{
    int data;
    struct BinaryTreeNode *left;
    struct BinaryTreeNode *right;
};

// Global root for the BST
struct BinaryTreeNode *root = NULL;

// Minimum Value in Binary Search tree
int MinInBst(struct BinaryTreeNode *root)
{
    if (root == NULL)
    {
        printf("Tree is empty.\n");
        return -1; // Indicate error
    }
    struct BinaryTreeNode *temp = root;
    while (temp->left != NULL) // Fix the condition
    {
        temp = temp->left;
    }
    return temp->data;
}

// Maximum Value in Binary Search tree

// Function to create a new node
struct BinaryTreeNode *createNode(int data)
{
    struct BinaryTreeNode *newNode = (struct BinaryTreeNode *)malloc(sizeof(struct BinaryTreeNode));
    if (newNode == NULL)
    {
        printf("Memory allocation failed\n");
        return NULL;
    }
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}
// Function to insert data into the BST
struct BinaryTreeNode *insertInNode(struct BinaryTreeNode *root, int data)
{
    if (root == NULL)
    {
        root = createNode(data);
        return root;
    }
    if (data < root->data)
    {
        root->left = insertInNode(root->left, data); // Insert in left subtree
    }
    else if (data > root->data)
    {
        root->right = insertInNode(root->right, data); // Insert in right subtree
    }
    return root;
}

// Inorder Traversal: This will print the tree nodes in ascending order
void inOrder(struct BinaryTreeNode *root)
{
    if (root == NULL)
    {
        return;
    }
    inOrder(root->left);       // Traverse left subtree
    printf("%d ", root->data); // Print the current node's data
    inOrder(root->right);      // Traverse right subtree
}

int main()
{
    int user, search;
    // Loop for user inputs
    while (1)
    {
        printf("Insert value in Binary Search Tree (-1 to exit): ");
        scanf("%d", &user);
        if (user == -1)
        {
            break; // Exit the loop if user inputs -1
        }

        root = insertInNode(root, user);
    }
    printf("BST created successfully.\n");

    printf("Inorder traversal of Binary tree: ");
    inOrder(root);
    printf("\n");

     printf("Minimum of Binary Search tree: %d \n", MinInBst(root));

    return 0;
}
