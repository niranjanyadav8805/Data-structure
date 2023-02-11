#include<stdio.h>

void accept(int a[],int n)
{
    for(int i=0;i<n;i++)
    {
       printf("Enter number::");
       scanf("%d",&a[i]);
    }
}

void sort(int a[],int n)
{
   int temp;
   for(int i=0;i<n;i++)
   {
       for(int j=i+1;j<n;j++) 
       {
           if(a[i] > a[j])
           {
              temp=a[i];
              a[i]=a[j];
              a[j]=temp;
           }
       }
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

int lin_search(int a[],int n,int key)
{
    for(int i=0;i<n;i++)
    {
        if(a[i] == key)
        {
           return i;
        }
    }
return -1;
}

int main()
{
    int a[50];
    int n,key,pos;

    printf("How many numbers in array::");
    scanf("%d",&n);

    accept(a,n);

    sort(a,n);

    printf("Array::\n");
    display(a,n);

    printf("Which number you want to search::");
    scanf("%d",&key);

    pos=lin_search(a,n,key);

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
