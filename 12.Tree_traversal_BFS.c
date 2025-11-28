                                           //BINARY SEARCH TREE & LEVEL ORDER TRAVERSAL//


//Aim:To create a Binary Search Tree (BST) using dynamic insertion and perform Level Order Traversal (BFS) using a queue//

🧭 Algorithm:

1. Creating a Node
Allocate memory for a new node.
Assign the input value to data.
Set left and right child pointers to NULL.
Return the newly created node.
2. Inserting into BST
If the tree is empty (root == NULL):
→ Create a new node and return it.
If value < root->data:
→ Recursively insert in left subtree.
Else
→ Recursively insert in right subtree.
Return the root to maintain tree structure.
3. Queue Operations (for Level Order Traversal)
a. ENQUEUE(node)
If queue is full → return.
If queue is empty (front == -1) → set front = 0.
Increment rear and insert node into queue.
b. DEQUEUE()
If queue empty (front == -1 OR front > rear) → return NULL.
Return queue[front] and increment front.
4. Level Order Traversal (BFS)
If root is NULL → exit.
Enqqeue the root node.
While the queue is not empty:
a. Dequeue a node → call it current.
b. Print current->data.
c. If current has a left child → enqueue it.
d. If current has a right child → enqueue it.
5. Main Program
Read number of elements (MAX).
Allocate memory for queue of size MAX.
Insert each element into BST using insert().
Display tree using levelOrder().
End.

🧭 Code:

#include <stdio.h>
#include <stdlib.h>

struct Node **queue;
int front = -1, rear = -1, MAX;

struct Node
{
    int data;
    struct Node *left, *right;
};

struct Node *createNode(int value)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

struct Node *insert(struct Node *root, int value)
{
    if (root == NULL)
    {
        return createNode(value);
    }

    if (value < root->data)
        root->left = insert(root->left, value);
    else
        root->right = insert(root->right, value);

    return root;
}


void enqueue(struct Node *temp)
{
    if (rear == MAX-1)
        return; // Queue full
    if (front == -1)
        front = 0;
    queue[++rear] = temp;
}

struct Node *dequeue()
{
    if (front == -1 || front > rear)
        return NULL; // Empty
    return queue[front++];
}

void levelOrder(struct Node *root)
{
    if (root == NULL)
        return;

    enqueue(root);

    while (front <= rear)
    {
        struct Node *current = dequeue();
        printf("%d ", current->data);

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

    for (int i = 0; i < MAX; i++)
    {
        scanf("%d", &value);
        root = insert(root, value); 
    }

    printf("\nLevel Order Traversal: ");
    levelOrder(root);

    return 0;
}

OUTPUT:
Example Input:
Enter number of elements: 6
Enter 6 values:
50 40 80 10 50 70


The BST formed:

        50
       /  \
     40    80
    / \    /
  10  50  70


Program Output:

Level Order Traversal: 50 40 80 10 50 70

 RESULT:
The program successfully:
Accepts user input values.
Inserts them into a Binary Search Tree (BST).
Stores nodes in a queue for BFS.
Prints nodes level by level using Level Order Traversal.
For the sample input, the traversal order is:
50 40 80 10 50 70


This matches the expected BFS output.
