

#include <stdio.h>
#include <stdlib.h>

// Define a tree node structure
typedef struct TreeNode
{
    void *data;                   // Generic data pointer
    struct TreeNode *children;    // Pointer to the first child
    struct TreeNode *nextSibling; // Pointer to the next sibling
} TreeNode;

// Function to create a new tree node
TreeNode *createTreeNode(void *data)
{
    TreeNode *newNode = (TreeNode *)malloc(sizeof(TreeNode));
    if (newNode == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    newNode->data = data;
    newNode->children = NULL;
    newNode->nextSibling = NULL;
    return newNode;
}

// Function to add a child to a tree node
void addChild(TreeNode *parent, TreeNode *child)
{
    if (parent->children == NULL)
    {
        parent->children = child;
    }
    else
    {
        TreeNode *temp = parent->children;
        while (temp->nextSibling)
        {
            temp = temp->nextSibling;
        }
        temp->nextSibling = child;
    }
}

// Example usage
int main()
{
    int data1 = 2, data2 = 3, data3 = 4, data4 = 5, data5 = 6, data6 = 7;

    TreeNode *root = createTreeNode(&data1);
    TreeNode *node1 = createTreeNode(&data2);
    TreeNode *node2 = createTreeNode(&data3);
    TreeNode *node3 = createTreeNode(&data4);
    TreeNode *node4 = createTreeNode(&data5);
    TreeNode *node5 = createTreeNode(&data6);

    addChild(root, node1);
    addChild(root, node2);
    addChild(node1, node3);
    addChild(node1, node4);
    addChild(node2, node5);

    // Free memory
    free(node5);
    free(node4);
    free(node3);
    free(node2);
    free(node1);
    free(root);

    return 0;
}
