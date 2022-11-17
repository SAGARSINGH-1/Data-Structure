// #include <process.h>
#include <stdio.h>

void push();
int pop();
int peek();
void traverse();

int stack[5];
int top = -1;

void main()
{
    printf("\n##########.......Stack Operation's using static array......##########\n");
    int choice;
    do
    {
        printf("\n1.Push\n2.Pop\n3.Traverse\n4.Peek\n5.Exit\nEnter your choice : ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            push();
            break;
        case 2:
            printf("\nThe deleted element is %d\n", pop());
            break;
        case 3:
            traverse();
            break;
        case 4:
            printf("\nThe top most element is %d\n", peek());
            break;
        case 5:
            exit(0);
            break;
        default:
            printf("\nInvalid Input........\n");
            break;
        }
    } while (choice != 5);
}

void push()
{
    int item;
    if (top == 4)
    {
        printf("\nThe stack is overflow...");
    }
    else
    {
        printf("Enter the number to be inserted : ");
        scanf("%d", &item);
        top = top + 1;
        stack[top] = item;
    }
}

int pop()
{
    int item;
    if (top == -1)
    {
        printf("\nstack is empty...\n");
        return 0;
    }
    else
    {
        item = stack[top];
        top = top - 1;
        return (item);
    }
}

void traverse()
{
    int i;
    if (top == -1)
    {
        printf("\nStack is empty..\n");
    }
    else
    {
        printf("\nStack elements are : ");
        for (i = 0; i <= top; i++)
        {
            printf("  %d  ", stack[i]);
        }
    }
}

int peek()
{
    if (top == -1)
    {
        printf("Stack is Empty...\n");
        return 0;
    }
    else
    {
        return stack[top];
    }
}