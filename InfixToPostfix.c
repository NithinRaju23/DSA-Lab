//*Aim : To perform infix to postfix conversion using stack*//

🧭 Algorithm:
 BEGIN
 1. INITIALIZE AN EMPTY STACK AND AN EMPTY POSTFIX STRING.
 2. PUSH '(' ONTO THE STACK AND ADD ')' TO THE END OF THE INFIX EXPRESSION
 3. FOR EACH SYMBOL X IN THE INFIX EXPRESSION, DO:
 a. IF X IS AN OPERAND, ADD X TO THE POSTFIX STRING.
 b. IF X IS '(', PUSH IT ONTO THE STACK.
 c. IF X IS AN OPERATOR, THEN:
 WHILE (STACK IS NOT EMPTY) AND (PRECEDENCE OF TOP OF STACK ≥
 PRECEDENCE OF X):
 POP OPERATOR FROM STACK AND ADD IT TO POSTFIX STRING.

 PUSH X ONTO THE STACK.
  d. IF X IS ')', THEN:
 WHILE THE TOP OF THE STACK IS NOT '(':
 POP OPERATOR FROM STACK AND ADD IT TO POSTFIX STRING.
 POP '(' FROM THE STACK AND DISCARD IT.
 4. END FOR
 5. THE RESULTING POSTFIX STRING IS THE FINAL OUTPUT.
END

🧭 Code:
#include <stdio.h>
#include <stdlib.h>

int TOP = -1, MAX;
char *STACK;

void Display()
{
    printf("Current Stack elements are -");
    for (int i = 0; i <= TOP; i++)
    {
        printf("[%c,]", STACK[i]);
    }
    printf("\n");
}

void Push(char item)
{
    if (TOP == MAX - 1)
    {
        printf("Stack is overflow");
    }
    else
    {
        TOP = TOP + 1;
        STACK[TOP] = item;
    }
}

char Pop()
{
    if (TOP == -1)
    {
        printf("Stack is underflow / empty\n");
        return '\0';
    }
    else
    {
        char item = STACK[TOP];
        TOP = TOP - 1;
        return item;
    }
}

char Peek()
{
    if (TOP == -1)
    {
        // printf("Stack is underflow / empty\n");
        return '\0';
    }
    else
    {
        return STACK[TOP];
    }
}

int GetPrecedence(char op)
{
    switch (op)
    {
    case '+':
    case '-':
        return 1; // lowest precedence
    case '*':
    case '/':
        return 2;
    case '^':
        return 3; // highest precedence
    default:
        return 0; // consider it as operand
    }
}

int main()
{
    printf("Enter the size of infix expression: ");
    scanf("%d", &MAX);

    STACK = (char *)malloc(MAX * sizeof(char));
    char infix[MAX];
    char postfix[MAX];

    printf("Please enter the infix string of size %d: ", MAX);
    scanf("%s", infix);

    int TokenPrecedence, j = 0, i = 0;
    char c, temp;

    // Reading one token at a time
    while ((c = infix[i]) != '\0')
    // for (int i = 0; i < MAX; i++)
    {
        // c = infix[i];
        TokenPrecedence = GetPrecedence(c); // Current token at a time
        if (TokenPrecedence > 0)            // Current token is Operator
        {
            while (TokenPrecedence <= GetPrecedence(Peek())) // Current Token <= Stack Top Token
            {
                postfix[j++] = Pop();
            }
            Push(c);
        }
        else // Current token is operand or '(' or ')'
        {
            switch (c)
            {
            case '(':
                Push(c);
                break;
            case ')':
                while (Peek() != '(')
                {
                    postfix[j++] = Pop();
                }
                Pop();
                break;
            default:
                postfix[j++] = c;
                break;
            }
        }
        i++;
    }

    // Pop All remaining tokens from stack
    while (Peek() != '\0')
    {
        char c = Pop();
        postfix[j++] = c;
    }
    postfix[j] = '\0';
    printf("Postfix notation is : %s", postfix);
    return 0;

}
