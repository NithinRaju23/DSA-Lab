
#include <stdio.h>
#include <stdlib.h>
struct Node **queue;
int front = -1, rear = -1, MAX;
// Structure representing each node of the binary search tree
struct Node
{
    int data;
    struct Node *left, *right;
};
// Create a new tree node with the given value
struct Node *createNode(int value)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}
// Insert a value into the BST and return the updated root
struct Node *insert(struct Node *root, int value)
{
    // If the tree is empty, the new node becomes the root
    if (root == NULL)
    {
        return createNode(value);
    }
    // Insert in left or right subtree based on value comparison
    if (value < root->data)
        root->left = insert(root->left, value);
    else
        root->right = insert(root->right, value);

    return root;
}
// Add a node to the queue (used for BFS traversal)
void enqueue(struct Node *temp)
{
    if (rear == MAX - 1)
        return; // Queue is full
    if (front == -1)
        front = 0;
    queue[++rear] = temp;
}
// Remove and return the next node from the queue
struct Node *dequeue()
{
    if (front == -1 || front > rear)
        return NULL; // Queue is empty

    return queue[front++];
}
// Perform Level Order Traversal (Breadth-First Search)
void levelOrder(struct Node *root)
{
    if (root == NULL)
        return;
    enqueue(root);
    while (front <= rear)
    {
        struct Node *current = dequeue();
        printf("%d ", current->data);

        // Add left and right children to the queue if they exist
        if (current->left != NULL)
            enqueue(current->left);
        if (current->right != NULL)
            enqueue(current->right);
    }
}
int main()
{
    int value;
    struct Node *root = NULL;
    printf("Enter number of elements: ");
    scanf("%d", &MAX);
    queue = (struct Node **)malloc(MAX * sizeof(struct Node *));
    printf("Enter %d values:\n", MAX);
    // Insert each value into the BST
    for (int i = 0; i < MAX; i++)
    {
        scanf("%d", &value);
        root = insert(root, value);
    }
    printf("\nLevel Order Traversal: ");
    levelOrder(root);
    return 0;
}
