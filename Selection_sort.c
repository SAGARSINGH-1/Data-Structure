// Online C compiler to run C program online
#include <stdio.h>
    int smallest(int[],int,int);
int main() {
    int a[10]={19,12,13,16,14,22,3453,32,211,1223};
    int i,j,k,pos,temp;
    for(i=0;i<10;i++){
        pos=smallest(a,10,i);
        temp=a[i];
        a[i]=a[pos];
        a[pos]=temp;
    }
    printf("\nprinting sorted elements : \n");
    for(i=0;i<10;i++){
        printf("%d\n",a[i]);
    }

    return 0;
}
int smallest(int a[],int n, int i){
    int small,pos,j;
    small=a[i];
    pos=i;
    for(j=i+1;j<10;j++){
        if(a[j]<small){
            small=a[j];
            pos=j;
        }
    }
    return pos;
}