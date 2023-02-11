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

void selec_sort(int a[],int n)
{
    int t;
    for(int i=0;i<n;i++)
    {
       for(int j=i+1;j<n;j++)
       {
          if(a[i] > a[j])
          {
             t=a[i];
             a[i]=a[j];
             a[j]=t;
          }
       }
   }
}
int bi_search(int a[],int n,int key)
{
    int lb=0,ub=n-1,mid;
    while(lb<=ub)
    {
       mid = (lb+ub)/2;
       if(key == a[mid])
       {
           return mid;
       }
       else if(key < a[mid])
       {
           ub = mid-1;
       }
       else
       {
           lb = mid+1;
       }
    }
   return -1;
}

int main()
{
   int a[50];
   int n,pos,key;

   printf("How many numbers you want in array::");
   scanf("%d",&n);

   accept(a,n);

   selec_sort(a,n);

   printf("Array::\n");
   display(a,n);

  printf("Which number to search::");
  scanf("%d",&key);

  pos = bi_search(a,n,key);

  if(pos == -1)
  {
     printf("%d is not found!!",key);
  }
  else
  {
     printf("%d is found at %d position!!",key,pos);
  }

 return 0;
}
