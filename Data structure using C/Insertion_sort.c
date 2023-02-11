#include<stdio.h>

void accept(int a[],int n)
{
    for(int i=0;i<n;i++)
    {
       printf("Enter number::");
       scanf("%d",&a[i]);
    }
}

void display(int a[],int n)
{
    for(int i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }
  printf("\n");
}

void insertion(int a[],int n)
{
    int t,i,j;
    for(i=1;i<n;i++)
    {
        t=a[i];
        for(j=i-1;j>=0;j--)
        {
           if(a[j] > t)
           {
               a[j+1] = a[j];
           }
           else
           {
               break;
           }
        }
       a[j+1] = t;
    }
}

int main()
{
   int a[100];
   int n;
   printf("How many numbers in array::");
   scanf("%d",&n);

   accept(a,n);

   printf("Before array::\n");
   display(a,n);  

   insertion(a,n);

   printf("After sorting::\n");
   display(a,n);

  return 0;
}
