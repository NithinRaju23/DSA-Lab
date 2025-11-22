 //STACK USING LINKED LIST//

//Aim: To perform stack operations using a linked list//

🧭 Algorithm:

PUSH Operation (Insert at Top)

Step 1: Create a new node.
Step 2: If memory not available, display "Stack Overflow".
Step 3: Set new node → data = item.
Step 4: Set new node → next = top.
Step 5: Set top = new node.
Step 6: End PUSH operation.

POP Operation (Delete from Top)

Step 1: Check if top == NULL.
Step 2: If true, display "Stack Underflow".
Step 3: Else set temp = top.
Step 4: Set item = top → data.
Step 5: Move top = top → next.
Step 6: Free temp node.
Step 7: Return deleted item.
Step 8: End POP operation.

PEEK Operation

Step 1: Check if top == NULL.
Step 2: If true, display "Stack is Empty".
Step 3: Else display top → data.
Step 4: End PEEK operation.

DISPLAY Operation

Step 1: Check if top == NULL.
Step 2: If true, display "Stack is Empty".
Step 3: Else, traverse from top to NULL.
Step 4: Print each node’s data.
Step 5: End DISPLAY operation.
  
🧭 Code:
#include <stdio.h>
#include <stdlib.h>

// Create node for linked list
struct Node
{
    int data;
    struct Node *next; // To hold the address of next node
};

// To create a node and it returns address of newly created node
struct Node *CreateNode(int data)
{
    // STACK = (char *)malloc(MAX * sizeof(char));
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (!newNode)
    {
        printf("Memory allocation failed!\n");
        return NULL;
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void push(struct Node **top, int data)
{
    struct Node *newElement = CreateNode(data);
    newElement->next = *top;
    *top = newElement;
    printf("Node with data %d pushed successfully  .\n", data);
}

void pop(struct Node **top)
{
    if (*top == NULL)
    {
        printf("Stack is empty/underflow, pop operation can't be performed");
        return;
    }

    struct Node *temp = *top;
    *top = temp->next;
    printf("Element %d popped from stack.\n", temp->data);
    free(temp);
    return;
}

void DisplayStack(struct Node *top)
{
    if (top == NULL)
    {
        printf("Stack is empty.\n");
        return;
    }

    struct Node *temp;
    temp = top;
    printf("\nElements In Stack: [Top] ");
    while (temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
}

// Main function
int main()
{
    struct Node *top = NULL;
    int choice, data, pos;

    while (1)
    {
        printf("\n--- Linked List Menu ---\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter data to insert: ");
            scanf("%d", &data);
            push(&top, data);
            break;
        case 2:
            pop(&top);
            break;
        case 3:
            DisplayStack(top);
            break;
        case 4:
            printf("Exiting...\n");
            exit(0);
        default:
            printf("Invalid choice! Try again.\n");
        }
    }
    return 0;
}

