//CRICULAR QUEUE//

//*Aim :- To perform circular queue operations using array*//

🧭 Algorithm:
BEGIN

Initialize front = -1, rear = -1, and read queue size n.

Repeat until user enters “no”:
 a. Display menu with choices: Enqueue or Dequeue.
 b. If Enqueue selected:
  i. If (rear + 1) % max_size == front, print Queue Overflow.
  ii. Else if front == -1, set front = 0, rear = 0.
  iii. Else, set rear = (rear + 1) % max_size.
  iv. Insert new element at queue[rear].
 c. If Dequeue selected:
  i. If front == -1, print Queue Underflow.
  ii. Else, set item = queue[front].
  iii. If front == rear, set both front and rear to -1.
  iv. Else, set front = (front + 1) % max_size.
  v. Display deleted item.
 d. Ask user if they want to continue.

End when user types “no”.
END

🧭 Code:
#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *front = NULL;
struct Node *rear = NULL;

// Enqueue operation
void enqueue(int item)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));

    if (newNode == NULL)
    {
        printf("Memory allocation failed!\n");
        return;
    }

    newNode->data = item;

    if (front == NULL && rear == NULL) //Queue empty
    {
        front = rear = newNode;
        newNode->next = front; //Circular link
    }
    else
    {
        rear->next = newNode;
        rear = newNode;
        rear->next = front; // Maintain circular link
    }

    printf("%d inserted into circular queue.\n", item);
}

// Dequeue operation
void dequeue()
{
    if (front == NULL)
    {
        printf("Queue Underflow!\n");
        return;
    }

    struct Node *temp = front;

    if (front == rear) // Only one node
    {
        front = rear = NULL;
    }
    else
    {
        front = front->next;
        rear->next = front; // Maintain circular link
    }

    printf("Deleted element: %d\n", temp->data);
    free(temp);
}

// Display operation
void display()
{
    if (front == NULL)
    {
        printf("Queue is empty.\n");
        return;
    }

    struct Node *temp = front;

    printf("Circular Queue elements: ");
    do
    {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != front);

    printf("\n");
}

int main()
{
    int choice, data;

    while (1)
    {
        printf("\n--- Queue Using Linked List Menu ---\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter data to insert: ");
            scanf("%d", &data);
            enqueue(data);
            break;

        case 2:
            dequeue();
            break;

        case 3:
            display();
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
