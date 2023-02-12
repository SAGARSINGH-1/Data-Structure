#include <stdio.h>

struct node
{
    int data;
    struct node *next;
};
struct node *head;

// Insertion in Circular link list

void beg_insert()
{
    struct node *ptr;
    ptr = (struct node *)malloc(sizeof(struct node *));
    if (ptr == NULL)
    {
        printf("Underflow....");
        exit(0);
    }
    else
    {
        int item;
        printf("Enter the data : ");
        scanf("%d", &item);
        ptr->data = item;
        if (head == NULL)
        {
            head = ptr;
            ptr->next = head;
        }
        else
        {
            ptr->next = head;
            struct node *temp = head;
            while (temp->next != head)
            {
                temp = temp->next;
            }
            temp->next = ptr;
            head = ptr;
        }
    }
}

void end_insert()
{
    struct node *ptr, *temp = head;
    ptr = (struct node *)malloc(sizeof(struct node *));
    if (ptr == NULL)
    {
        printf("Underflow....");
        exit(0);
    }
    else
    {
        int item;
        printf("Enter the data : ");
        scanf("%d", &item);
        ptr->data = item;
        ptr->next = head;
        if (head == NULL)
        {
            head = ptr;
        }
        else
        {
            while (temp->next != head)
            {
                temp = temp->next;
            }
            temp->next = ptr;
        }
    }
}

void spec_insert()
{
    int item, n;
    struct node *ptr;
    ptr = (struct node *)malloc(sizeof(struct node *));
    if (ptr == NULL)
    {
        printf("Underflow....");
        exit(0);
    }
    printf("Enter the data :");
    scanf("%d", &item);
    if (head == NULL)
    {
        head = ptr;
        ptr->next = head;
    }
    else
    {
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
        while (ptr->next != head)
        {
            printf("%d", ptr->data);
            printf(" ");
            ptr = ptr->next;
        }
        printf("%d\n", ptr->data);
    }
}

// Deletion in Circular link list

void beg_delete()
{
    if (head == NULL)
    {
        printf("Underflow...");
        exit(0);
    }
    else
    {
        struct node *ptr = head, *temp = head;
        if (temp->next == head)
        {
            head = NULL;
            free(head);
            printf("First node has been deleted");
        }
        else
        {
            while (temp->next != head)
            {
                temp = temp->next;
            }
            temp->next = ptr->next;
            head = ptr->next;
            free(ptr);
            printf("First node has been deleted");
        }
        temp = head;
        while (temp->next != head)
        {
            temp = temp->next;
        }
        temp->next = head;
    }
}

void end_delete()
{
    struct node *ptr, *temp = head;
    if (head == NULL)
    {
        printf("Underflow...");
        exit(0);
    }
    else
    {
        if (temp->next == head)
        {
            head = NULL;
            free(head);
            printf("Only one node exist and it will deleted..");
        }
        else
        {
            while (temp->next != head)
            {
                ptr = temp;
                temp = temp->next;
            }
            ptr->next = head;
            free(temp);
            printf("node has been deleted..");
        }
    }
}

void spec_delete()
{
    if (head == NULL)
    {
        printf("Underflow..");
        exit(0);
    }
    else if (head->next == head)
    {
        head = NULL;
        free(head);
        printf("\nOnly one node of the list deleted ...\n");
    }
    else
    {
        int n;
        struct node *temp = head;
        printf("Enter the position : ");
        scanf("%d", &n);
        if (n == 1)
        {
            head = temp->next;
            free(head);
            printf("The node will be deleted and head point another node");
        }
        else
        {
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
