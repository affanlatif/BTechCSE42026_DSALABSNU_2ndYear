#include <stdio.h>

#define MAX 100

int top = -1;
int stack[MAX];

void push(int item)
{
    if (top == MAX - 1)
    {
        printf("Stack Overflow!\n");
    }
    else
    {
        top++;
        stack[top] = item;
        printf("%d pushed successfully.\n", item);
    }
}

void pop()
{
    if (top == -1)
    {
        printf("Stack Underflow!\n");
    }
    else
    {
        printf("%d popped successfully.\n", stack[top]);
        top--;
    }
}

void peek()
{
    if (top == -1)
    {
        printf("Stack is empty.\n");
    }
    else
    {
        printf("Top Element : %d\n", stack[top]);
    }
}

void display()
{
    int i;

    if (top == -1)
    {
        printf("Stack is empty.\n");
    }
    else
    {
        printf("Stack elements (Top to Bottom): ");

        for (i = top; i >= 0; i--)
        {
            printf("%d ", stack[i]);
        }

        printf("\n");
    }
}

int main()
{
    int n, i;
    int choice, item;

    printf("Enter the initial number of elements: ");
    scanf("%d", &n);

    if (n > MAX)
    {
        printf("Stack size exceeds maximum limit (%d).\n", MAX);
        return 0;
    }
    else
    {
        printf("Enter the elements:\n");

        for (i = 0; i < n; i++)
        {
            scanf("%d", &stack[i]);
            top++;
        }

        do
        {
            printf("\n===== STACK MENU =====\n");
            printf("1. Push\n");
            printf("2. Pop\n");
            printf("3. Peek\n");
            printf("4. Display\n");
            printf("5. Exit\n");

            printf("Enter your choice: ");
            scanf("%d", &choice);

            switch (choice)
            {
                case 1:
                    printf("Enter the item: ");
                    scanf("%d", &item);
                    push(item);
                    display();
                    break;

                case 2:
                    pop();
                    display();
                    break;

                case 3:
                    peek();
                    break;

                case 4:
                    display();
                    break;

                case 5:
                    printf("Exiting...\n");
                    break;

                default:
                    printf("Invalid Choice!\n");
            }

        } while (choice != 5);
    }

    return 0;
}