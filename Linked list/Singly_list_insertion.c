#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *head;

void beg_insert()
{
    int item;
    struct node *ptr;
    ptr = (struct node *)malloc(sizeof(struct node *));
    printf("Enter the node data : ");
    scanf("%d", &item);
    ptr->data = item;
    ptr->next = head;
    head = ptr;
}

void end_insert()
{
    int item;
    struct node *ptr;
    ptr = (struct node *)malloc(sizeof(struct node *));
    printf("Enter the data :");
    scanf("%d", &item);
    ptr->data = item;
    ptr->next = NULL;
    struct node *loc = head;
    while (loc->next != NULL)
    {
        loc = loc->next;
    }
    loc->next = ptr;
}

void spec_insert()
{
    int item, n;
    struct node *ptr;
    ptr = (struct node *)malloc(sizeof(struct node *));
    printf("Enter the data :");
    scanf("%d", &item);
    printf("Enter the position :");
    scanf("%d", &n);
    ptr->data = item;
    struct node *temp = head;
    for (int i = 0; i < n - 1; i++)
    {
        temp = temp->next;
    }
    ptr->next = temp->next;
    temp->next = ptr;
}

void display()
{
    struct node *ptr;
    ptr = head;
    if (ptr == NULL)
    {
        printf("kuchu nahi aay\n");
    }
    else
    {
        printf("\nprinting values : ");
        while (ptr != NULL)
        {
            printf("%d", ptr->data);
            printf(" ");
            ptr = ptr->next;
        }
    }
}

void main()
{
    int a;
    int b = 10;
    while (b > 4)
    {
        printf("\nEnter the choice : \n");
        printf("Insertion : \n1.At Begining \n2.At End \n3.At Specific \n4.Display\n");
        scanf("%d", &a);

        switch (a)
        {
        case 1:
            beg_insert();
            break;
        case 2:
            end_insert();
            break;
        case 3:
            spec_insert();
            break;
        case 4:
            display();
            break;

        default:
            printf("bhag bsdk");
            break;
        }
    }
}
