                                                  //STACK//

//*Aim: To find the position of a given number in a sorted list using the Binary Search method efficiently.*//
🧭ALGORITHM:
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
#define MAX 100

int stack[MAX];
int top = -1;

void push(int x)
{
    
    if (top >= MAX - 1)
    {
        printf("Stack overflow\n");
    }
    else
    {
        top++;
        stack[top] = x; 
    }
}

int pop()
{

    if (top < 0)
    {
        printf("Stack underflow\n");
        return -1;
    }
    else
    {
        int value = stack[top];
        top--; 
        return value;
    }
}

int peek()
{

    if (top < 0)
    {
        printf("Stack is empty\n");
        return -1;
    }
    else
    {
        return stack[top];
    }
}

int empty()
{
   
    return top == -1;
}

void display()
{
    
    if (empty())
    {
        printf("Stack is empty\n");
    }
    else
    {
        printf("Stack elements: ");
        for (int i = top; i >= 0; i--)
            printf("%d ", stack[i]);
        printf("\n");
    }
}

int main()
{
    int choice, value;
    int n;

    printf("Enter total size of stack (max %d): ", MAX);
    scanf("%d", &n);

    
    if (n > MAX)
    {
        printf("Size exceeds limit\n");
        return 0;
    }

   
    while (1)
    {
        printf("\n1. Push\n2. Pop\n3. Peek\n4. Display\n5. Exit\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                // Push operation
                printf("Enter value to push: ");
                scanf("%d", &value);
                push(value);
                break;

            case 2:
                // Pop operation
                value = pop();
                if (value != -1)
                    printf("Popped value: %d\n", value);
                break;

            case 3:
                // Peek operation
                value = peek();
                if (value != -1)
                    printf("Top value: %d\n", value);
                break;

            case 4:
                // Display operation
                display();
                break;

            case 5:
                // Exit the program
                return 0;

            default:
                printf("Invalid choice\n");
        }
    }
}


Output:
Enter the size of stack : 5

1.Push
2.Pop
3.Exit
Please choose stack operation to perform : 1
Enter the elements to push : 9
Current stack elements are-
>>9(Top)

1.Push
2.Pop
3.Exit
Please choose stack operation to perform : 1
Enter the elements to push : 19
Current stack elements are-
>>9>>19(Top)

1.Push
2.Pop
3.Exit
Please choose stack operation to perform : 2
Current stack elements are-
>>9(Top)

1.Push
2.Pop
3.Exit
Please choose stack operation to perform : 2
Stack is Underflow
Current stack elements are-
>>9(Top)

Result:
This program successfully demonstrates stack operations using an array, allowing the user to push, pop, and display stack elements.
