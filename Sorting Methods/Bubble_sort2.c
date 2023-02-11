#include <stdio.h>
void main()
{
    int i, j, n;
    int a[n];
    printf("Enter the number of elements to be sort : ");
    scanf("%d", &n);

    printf("Enter the elements in any order : ");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    for (i = 0; i < n-1; i++)
    {
        for (j = i+1; j < n; j++)
        {
           if(a[i]>a[j])
           {
             int temp = a[i];
             a[i]=a[j];
             a[j]=temp;
           }
        }
    }
    printf("The Sorted elements is : ");
for (i = 0; i < n; i++)
{
    printf("%d", a[i]);
    printf(" ");
}
}


