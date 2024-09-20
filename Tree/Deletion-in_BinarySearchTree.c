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

// highest number of left sub tree of root node
int inOrderPredecessor(struct BinaryTreeNode *root)
{
    struct BinaryTreeNode *temp = root->left;
    if (root == NULL || root->left == NULL)
    {              // Check both root and root->left
        return -1; // No predecessor
    }
    while (temp->right != NULL)
    {
        temp = temp->right;
    }
    return temp->data;
}

// --------DELLETION IN BINARY SEARCH TREE--------
struct BinaryTreeNode *deleteFromBST(struct BinaryTreeNode *root, int val)
{
    if (root == NULL)
    {
        printf("Value not found: \n");
        return root;
    }
    if (root->data == val)
    {
        // 0 Child
        if (root->right == NULL && root->left == NULL)
        {
            free(root);
            return NULL;
        }
        // 1 Child
        // Only left child is present
        if (root->left != NULL && root->right == NULL)
        {
            struct BinaryTreeNode *temp = root->left;
            free(root);
            return temp;
        }
        // Only Right child is present
        if (root->left == NULL && root->right != NULL)
        {
            struct BinaryTreeNode *temp = root->right;
            free(root);
            return temp;
        }
        // 2 Children: Replace the current node's data with the in-order predecessor
        if (root->left != NULL && root->right != NULL)
        {
            int minval = inOrderPredecessor(root);          // Find in-order predecessor
            root->data = minval;                            // Copy the predecessor's data to current node
            root->left = deleteFromBST(root->left, minval); // Delete predecessor node


        } // if condition ends heer (root->data == val)
    }
    if (root->data > val)
    {
        root->left = deleteFromBST(root->left, val);
        return root;
    }
    else
    {
        root->right = deleteFromBST(root->right, val);
        return root;
    }
}

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

// MAIN FUNCTION PROGRAM EXECUTES FROM MAIN
int main()
{
    int user, search, delval;
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

    printf("Inorder traversal of Binary tree: ");
    inOrder(root); 
    printf("\n"); 

    printf("inOrder Predecessor of Binary Search tree: %d\n", inOrderPredecessor(root));

    printf("What value do you want to Delete in Binary Search Tree: ");
    scanf("%d", &delval);
    deleteFromBST(root, delval);

    printf("Inorder traversal of Binary tree: ");
    inOrder(root);
    printf("\n");
    return 0;
}






