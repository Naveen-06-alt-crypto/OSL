#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Node structure
struct Node
{
    char name[30];

    int isDir;

    struct Node *child;

    struct Node *sibling;
};

// Create new node
struct Node* newNode(char name[], int isDir)
{
    struct Node *n;

    n = (struct Node*)malloc(sizeof(struct Node));

    strcpy(n->name, name);

    n->isDir = isDir;

    n->child = NULL;

    n->sibling = NULL;

    return n;
}

// Add child node
void addChild(struct Node *parent,
              struct Node *child)
{
    // First child
    if(parent->child == NULL)
    {
        parent->child = child;

        return;
    }

    // Move to last sibling
    struct Node *temp = parent->child;

    while(temp->sibling != NULL)
    {
        temp = temp->sibling;
    }

    temp->sibling = child;
}

// Display directory tree
void printTree(struct Node *node, int depth)
{
    if(node == NULL)
    {
        return;
    }

    // Indentation
    for(int i = 0; i < depth; i++)
    {
        printf("  ");
    }

    // Print node
    if(node->isDir)
    {
        printf("[DIR] %s\n", node->name);
    }
    else
    {
        printf("[FILE] %s\n", node->name);
    }

    // Print child and sibling
    printTree(node->child, depth + 1);

    printTree(node->sibling, depth);
}

int main()
{
    // Create directories
    struct Node *root = newNode("root", 1);

    struct Node *home = newNode("home", 1);

    struct Node *etc = newNode("etc", 1);

    struct Node *alice = newNode("alice", 1);

    // Build tree
    addChild(root, home);

    addChild(root, etc);

    addChild(home, alice);

    // Add files
    addChild(alice,
             newNode("resume.pdf", 0));

    addChild(alice,
             newNode("notes.txt", 0));

    addChild(etc,
             newNode("passwd", 0));

    // Display structure
    printf("Directory Structure:\n");

    printTree(root, 0);

    return 0;
}
