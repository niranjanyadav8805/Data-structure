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

void bubble_sort_asc(int a[],int n)
{
   int t;
   for(int i=n-1;i>0;i--)
   {
      for(int j=0;j<i;j++)
      {
         if(a[j] > a[j+1])
         {
            t=a[j];
            a[j]=a[j+1];
            a[j+1]=t;
         }
      }
   }
}

void bubble_sort_dsc(int a[],int n)
{
   int t;
   for(int i=n-1;i>0;i--)
   {
      for(int j=0;j<i;j++)
      {
         if(a[j] < a[j+1])
         {
            t=a[j];
            a[j]=a[j+1];
            a[j+1]=t;
         }
      }
   }
}


int main()
{
   int a[100];
   int n,ch;
  
   printf("How many numbers in array::");
   scanf("%d",&n);

   accept(a,n);
  
while(ch!=4)
{
   printf("-----MENU-----\n");
   printf("1.Display array\n");
   printf("2.Display sorted array in ascending order\n");
   printf("3.Display array in descending order\n");
   printf("4.Exit\n");
   printf("-------\n");
   printf("Enter Your choice::");
   scanf("%d",&ch);
   
   switch(ch)
   {
       case 1:
            printf("Array::\n");
            display(a,n);
            break;
        
       case 2:
            printf("Sorted array in ascending order::\n");
            bubble_sort_asc(a,n);
            display(a,n);
            break;

       case 3:
            printf("Sorted array in descending order::\n");
            bubble_sort_dsc(a,n);
            display(a,n);
            break;
  }
}
            
  return 0;
}
