#include <stdio.h>
int type_queue;
void push();
void pop();
void traverse();
int peek();
void deck();
// void circular_queue();
int queue[5];
int rear = 0;
int front = 0;
int main()
{
    printf("\n##########.......Queue Operation's using static array......##########\n");
    int choice;
    while (choice != 5)
    {
        printf("\n1.Push\n2.Pop\n3.Traverse\n4.Peek\n5.Types of Queue\n6.Exit\nEnter your choice : ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            push();
            break;
        case 2:
            pop();
            break;
        case 3:
            traverse();
            break;
        case 4:
            printf("\nThe top most element is %d\n", peek());
            break;
        case 5:
            printf("Types of Queue : \n1.DECK\n2.Circular Queue\n");
            printf("\nEnter another choice : ");
            scanf("%d", &type_queue);
            switch (type_queue)
            {
            case 1:
                deck();
                break;
            // case 2:
            //     circular_queue();
            default:
                printf("Invalid Input....");
                break;
            }
            break;
        case 6:
            exit(0);
            break;
        default:
            printf("\nInvalid Input........\n");
            break;
        }
    }
}

void push()
{
    int ele;
    if (rear == 5)
    {
        printf("\nQueue is overflow\n");
    }
    else
    {
        printf("\nEnter the number to be inserted : \n");
        scanf("%d", &ele);
        queue[rear] = ele;
        rear = rear + 1;
    }
}

void pop()
{
    if (front == rear)
    {
        printf("\nQueue is Empty...\n");
    }
    else
    {
        printf("Element is deleted is :  %d  ", queue[front]);
        for (int i = front; i < rear - 1; i++)
        {
            queue[i] = queue[i + 1];
        }
        rear = rear - 1;
    }
}

void traverse()
{
    if (front == rear)
    {
        printf("\nQueue is Empty\n");
    }
    else
    {
        printf("Queue Elements are : ");
        for (int i = front; i < rear; i++)
        {
            printf(" %d  ", queue[i]);
        }
        printf("\n");
    }
}

int peek()
{
    if (front == rear)
    {
        printf("Queue is Empty...\n");
    }
    else
    {
        return queue[rear - 1];
    }
}

void deck(){
    int ch,ch2,ele2;
    printf("\n1.Insertion in deck\n2.Deletion in deck\n");
    scanf("%d",&ch);
//     if (ch==1)
//     {
//         insertion();
//     }
//     else if (ch==2)
//     {
//         deletion();
//     }
//     else
//     printf("Invalid input...");
//     }
// void insertion(){
//     int a;
}