                                                       //DOUBLY LINKED LIST IMPLEMENTATION//

//AIM:To implement insertion and deletion operations in a Doubly Linked List and display the list in forward and reverse order.//

🧭 Algorithm:

BEGIN
1. Create a structure Node with:
data
prev pointer
next pointer
2. CreateNode(data)
Allocate memory
Initialize data, prev = NULL, next = NULL
Return node
3. InsertAtBeginning(head, data)
Create new node
If list not empty:
newNode → next = head
head → prev = newNode
head = newNode
4. InsertAtEnd(head, data)
Create new node
If head is NULL:
head = newNode
Else:
Traverse to last node
last → next = newNode
newNode → prev = last
5. InsertAtPosition(head, data, pos)
If pos = 1 → InsertAtBeginning
Else traverse to position-1
If position invalid → print error
Insert node by adjusting 4 links
6. DeleteNode(head, value)
If list empty → print error
Traverse until node with value is found
Adjust pointers depending on:
deleting head
deleting last
deleting middle
Free the node
7. DisplayList(head)
Traverse forward
Print prev/data/next for each node
8. DisplayReverse(head)
Traverse to last node
Then traverse backward
Print prev/data/next
    
🧭 Code:
#include <stdio.h>
#include <stdlib.h>

// Create node for linked list
struct Node
{
    int data;
    struct Node *next; // To hold the address of next node
    struct Node *prev; // To hold the address of previous node
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
    newNode->prev = NULL;
    return newNode;
}

void InsertAtBeginning(struct Node **head, int data)
{
    struct Node *newNode = CreateNode(data);
    newNode->next = *head;
    newNode->prev = NULL; // Optional
    if (*head != NULL)
        (*head)->prev = newNode;
    *head = newNode;
    printf("Node with data %d inserted at beginning successfully  .\n", data);
}

void InsertAtEnd(struct Node **head, int data)
{
    struct Node *newNode = CreateNode(data);
    if (*head == NULL)
    {
        *head = newNode;
    }
    else
    {
        struct Node *temp = *head;

        while (temp->next != NULL)
            temp = temp->next;

        temp->next = newNode;
        newNode->prev = temp;
    }
    printf("Node with data %d inserted at the end successfully.\n", data);
}

void InsertAtPosition(struct Node **head, int data, int position)
{
    // Considering that the position starts from 1 (Head at 1)
    if (position < 1)
    {
        printf("Invalid position!\n");
        return;
    }

    if (position == 1)
    {
        InsertAtBeginning(head, data);
        return;
    }

    struct Node *temp = *head;
    for (int k = 1; (k < position - 1 && temp != NULL); k++)
    {
        temp = temp->next;
    }

    if (temp == NULL)
    {
        printf("Given position is out of range!\n");
        return;
    }

    // Only when given position is valid
    struct Node *newNode = CreateNode(data);

    newNode->next = temp->next;
    newNode->prev = temp;

    if (temp->next != NULL)         // Only if NOT inserting at the end
        temp->next->prev = newNode; // Correct linking for DLL

    temp->next = newNode;

    printf("Node with data %d inserted at position %d successfully.\n", data, position);
}

// Delete a node by value
void DeleteNode(struct Node **head, int valueToDelete)
{
    if (*head == NULL)
    {
        printf("Linked List is empty, deletion operation can't be performed");
        return;
    }

    struct Node *temp = *head;

    // If head itself holds the value
    if (temp->data == valueToDelete)
    {
        *head = temp->next;

        if (*head != NULL)
            (*head)->prev = NULL;

        free(temp);
        printf("Data %d deleted from list.\n", valueToDelete);
        return;
    }

    // Search for the value
    struct Node *before = *head;
    while (before->next != NULL)
    {
        if (before->next->data == valueToDelete)
        {
            temp = before->next;
            before->next = temp->next;

            if (temp->next != NULL)
                temp->next->prev = before;

            free(temp);
            printf("Data %d deleted from list.\n", valueToDelete);
            return;
        }
        before = before->next;
    }
    printf("Element %d not found.\n", valueToDelete);
    return;
}

// Display all elements
void DisplayList(struct Node *head)
{
    if (head == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    struct Node *temp;
    temp = head;
    printf("\nLinked List Nodes: ");
    while (temp != NULL)
    {
        printf(" |Prev=%p|%d|Next=%p| -> ", temp->prev, temp->data, temp->next);
        temp = temp->next;
    }
}

// Main function
int main()
{
    struct Node *head = NULL;
    int choice, data, pos;

    while (1)
    {
        printf("\n--- Linked List Menu ---\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Insert at Position\n");
        printf("4. Delete by Value\n");
        printf("5. Display List\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter data to insert: ");
            scanf("%d", &data);
            InsertAtBeginning(&head, data);
            break;
        case 2:
            printf("Enter data to insert: ");
            scanf("%d", &data);
            InsertAtEnd(&head, data);
            break;
        case 3:
            printf("Enter data and position to insert: ");
            scanf("%d %d", &data, &pos);
            InsertAtPosition(&head, data, pos);
            break;
        case 4:
            printf("Enter value to delete: ");
            scanf("%d", &data);
            DeleteNode(&head, data);
            break;
        case 5:
            DisplayList(head);
            break;
        case 6:
            printf("Exiting...\n");
            exit(0);
        default:
            printf("Invalid choice! Try again.\n");
        }
    }
    return 0;
}

