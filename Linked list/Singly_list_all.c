#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *head;

// Insertion all operation's

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

// Deletion all operation's

void beg_delete()
{
    if (head == NULL)
    {
        printf("Underflow..");
        exit(0);
    }
    else
    {
        struct node *temp = head;
        head = temp->next;
        free(temp);
        printf("Node deleted from begining");
    }
}

void end_delete()
{
    if (head == NULL)
    {
        printf("Underflow..");
        exit(0);
    }
    else if (head->next == NULL)
    {
        head = NULL;
        free(head);
        printf("\nOnly node of the list deleted ...\n");
    }
    else
    {
        struct node *temp = head;
        struct node *loc;
        while (temp->next != NULL)
        {
            loc = temp;
            temp = temp->next;
        }
        loc->next = NULL;
        free(temp);
        printf("Node deleted from end");
    }
}

void spec_delete()
{
    if (head == NULL)
    {
        printf("Underflow..");
        exit(0);
    }
    else if (head->next == NULL)
    {
        head = NULL;
        free(head);
        printf("\nOnly node of the list deleted ...\n");
    }
    else
    {
        int n;
        printf("Enter the position : ");
        scanf("%d", &n);
        if (n == 1)
        {
            struct node *temp = head;
            head = temp->next;
            free(temp);
            printf("The node will be deleted and head point another node");
        }
        else{
        struct node *temp = head;
        struct node *loc;
        for (int i = 0; i < n - 1; i++)
        {
            loc = temp;
            temp = temp->next;
        }
        loc->next = temp->next;
        free(temp);
        printf("Node deleted from specified position");
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
        printf("\nInsertion : \n1.At Begining \n2.At End \n3.At Specific \n4.Display\n");
        printf("\nDeletion : \n5.At Begining \n6.At End \n7.At Specific\n");
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
        case 5:
            beg_delete();
            break;
        case 6:
            end_delete();
            break;
        case 7:
            spec_delete();
            break;

        default:
            printf("bhag bsdk");
            break;
        }
    }
}
