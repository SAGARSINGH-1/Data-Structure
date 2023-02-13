#include <stdio.h>
#include <stdlib.h>
struct node
{
    struct node *prev;
    int data;
    struct node *next;
};
struct node *head;

// Insertion in Doubly Link list...

void beg_insert()
{
    struct node *ptr;
    ptr = (struct node *)malloc(sizeof(struct node));
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
            ptr->prev = NULL;
            ptr->next = NULL;
        }
        else
        {
            ptr->next = head;
            ptr->prev = NULL;
            head->prev = ptr;
            head = ptr;
        }
    }
}

void end_insert()
{
    struct node *ptr;
    ptr = (struct node *)malloc(sizeof(struct node));
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
            ptr->prev = NULL;
            ptr->next = NULL;
        }
        else
        {
            struct node *temp = head;
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = ptr;
            ptr->prev = temp;
            ptr->next = NULL;
        }
    }
}

void spec_insert()
{
    struct node *ptr;
    ptr = (struct node *)malloc(sizeof(struct node));
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
            ptr->prev = NULL;
            ptr->next = NULL;
        }
        else
        {
            struct node *temp = head;
            int n, i;
            printf("Enter the position : ");
            scanf("%d", &n);
            if (n == 1)
            {
                ptr->next = head;
                head->prev = ptr;
                head = ptr;
                ptr->prev = NULL;
            }
            else
            {
                if (temp->next == NULL)
                {
                    temp->next = ptr;
                    ptr->prev = temp;
                    ptr->next = NULL;
                }
                temp = head;
                for (i = 1; i < n - 1 && temp->next != NULL; i++)
                {
                    temp = temp->next;
                }

                if (temp->next == NULL && n > i)
                {
                    ptr->prev = temp;
                    ptr->next = NULL;
                    temp->next = ptr;
                }
                ptr->prev = temp;
                ptr->next = temp->next;
                temp->next->prev = ptr;
                temp->next = ptr;
            }
        }
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
        while (ptr != NULL)
        {
            printf("%d", ptr->data);
            printf(" ");
            ptr = ptr->next;
        }
    }
}

// Deletion in Doubly link list....

void beg_delete()
{
    if (head == NULL)
    {
        printf("Underflow...");
        exit(0);
    }
    else
    {
        struct node *ptr = head;
        if (ptr->next == NULL)
        {
            head = NULL;
            free(head);
            printf("First node has been deleted");
        }
        else
        {
            head = ptr->next;
            ptr->next->prev = NULL;
            free(ptr);
            printf("First node has been deleted");
        }
    }
}

void end_delete()
{
    if (head == NULL)
    {
        printf("Underflow...");
        exit(0);
    }
    else
    {
        struct node *ptr = head;
        if (ptr->next == NULL)
        {
            head = NULL;
            free(head);
            printf("First node has been deleted");
        }
        else
        {
            while (ptr->next != NULL)
            {
                ptr = ptr->next;
            }
            ptr->prev->next = NULL;
            free(ptr);
            printf("Node has been deleted");
        }
    }
}

void spec_delete()
{
    struct node *ptr, *temp;
    int val;
    printf("\nEnter the data after which the node is to be deleted : ");
    scanf("%d", &val);
    ptr = head;
    while (ptr->data != val)
        ptr = ptr->next;
    if (ptr->next == NULL)
    {
        ptr->prev->next=NULL;
        free(ptr);
        printf("Last Node has been deleted...");
    }
    else if (ptr->next->next == NULL)
    {
        ptr->next = NULL;
    }
    else
    {
        temp = ptr->next;
        ptr->next = temp->next;
        temp->next->prev = ptr;
        free(temp);
        printf("\nnode deleted\n");
    }
}

void main()
{
    int a;
    int b = 10;
    while (b > 4)
    {
        printf("\nInsertion : \n1.At Begining \n2.At End \n3.At Specific \n4.Display\n");
        printf("\nDeletion : \n5.At Begining \n6.At End \n7.At Specific\n");
        printf("\nEnter the choice : \n");
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
