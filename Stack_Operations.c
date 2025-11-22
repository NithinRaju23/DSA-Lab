     //STACK//

//*Aim: To find the position of a given number in a sorted list using the Binary Search method efficiently.*//
ALGORITHM:
 PUSH Operation:
Step 1: Check if TOP == MAX - 1.
Step 2: If true, display "Stack Overflow".
Step 3: Else increment TOP by 1.
Step 4: Set stack[TOP] = item.
Step 5: End PUSH operation.
  POP Operation:
Step 1: Check if TOP == -1.
Step 2: If true, display "Stack Underflow".
Step 3: Else set item = stack[TOP].
Step 4: Decrement TOP by 1.
Step 5: Return deleted item.
  PEEK Operation:
Step 1: Check if TOP == -1.
Step 2: If true, display "Stack is Empty".
Step 3: Else set item = stack[TOP].
Step 4: Display item.
Step 5: End PEEK operation.

CODE:
#include <stdio.h>
#include <stdlib.h>

int top = -1;
int size;
char *STACK; // Dynamic Array

void push(char item)
{
    if (top == (size - 1))
    {
        printf("Stack is already full, no additional push allowed - Overflow");
    }
    else
    {
        top = top + 1;
        STACK[top] = item;
    }
}

void pop()
{
    if (top == -1)
    {
        printf("Stack is underflow");
    }
    else
    {
        char temp = STACK[top];
        top = top - 1;
        printf("Element popped %c", temp);
    }
}

void DisplayStack()
{
    if (top == -1)
    {
        printf("Stack is underflow");
        return;
    }
    printf("[Top] \n");
    for (int i = top; i >= 0; i--)
    {
        printf("%c \n", STACK[i]);
    }
}

int main()
{
    int choice;
    char data;

    printf("Enter size of stack: ");
    scanf("%d", &size);
    STACK = (char *)malloc(size * sizeof(char));

    while (1)
    {
        printf("\n--- Stack Menu ---\n");
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
            scanf(" %c", &data);
            push(data);
            break;
        case 2:
            pop();
            break;
        case 3:
            DisplayStack();
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

