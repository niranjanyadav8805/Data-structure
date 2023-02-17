#include<stdio.h>
#include<stdlib.h>
#define NEWNODE (struct node *)malloc( sizeof(struct node) )

struct node 
{
   int data;
   struct node *next;
};

struct node * create(int n)
{
   struct node *f,*l,*t;
   f=NEWNODE;
   printf("Enter data::");
   scanf("%d",&f->data);
   f->next=NULL;
   l=f;

   for(int i=2;i<=n;i++)
   {
       t=NEWNODE;
       printf("Enter data::");
       scanf("%d",&t->data);
       t->next=NULL;
       l->next=t;
       l=l->next;
  }
 return f;
}

void display(struct node *f)
{
    struct node *t;
    for(t=f;t!=NULL;t=t->next)
    {
         printf("%d->",t->data);
    }
    printf("NULL\n");
}

struct node * insert(struct node *f,int pos)
{
    struct node *t,*s;
    t=NEWNODE;
    printf("Enter data::");
    scanf("%d",&t->data);
    t->next=NULL;

    if(pos==1)
    {
       t->next=f;
       f=t;
       printf("Data is inserted successfully!! \n");
       return f;
    }
    else
    {
        s=f;
        for(int i=1;s!=NULL && i<=pos-2;i++)
        {
             s=s->next; 
        }
        if(s==NULL)
        {
            printf("INVALID POSITION!!\n");
            return f;
        }
        else
        {
            t->next=s->next;
            s->next=t;
            printf("Data is inserted successfully!! \n");
            return f;
        }
    }
}

struct node * delete(struct node *f,int pos)
{
   struct node *t,*s;
   
   if(pos==1)
   {
      t=f;
      f=f->next;
      free(t);
      printf("Data is deleted successfully!! \n");
      return f;
   }
   else
   {
      s=f;
      for(int i=1;s!=NULL && i<=pos-2;i++) 
      {
           s=s->next;
      }
      if(s==NULL)
      {
         printf("Invalid position!!\n");
         return f;
      }
      else
      {
          t=s->next;
          s->next=t->next;
          free(t);
          printf("Data is deleted successfully!! \n");
          return f;
      }
   }
}

int length(struct node *f)          
{
   struct node *t;
   int cnt=0;

   for(t=f;t!=NULL;t=t->next)
   {
      cnt++;
   }
 return cnt;
}

int add(struct node *f)           
{
  struct node *t;
  int sum=0;

  for(t=f;t!=NULL;t=t->next)
  {
     sum = sum + t->data;
  }
 return sum;
}

int search(struct node *f, int key)    
{
   struct node *t;
   int pos=1;

   for(t=f;t!=NULL;t=t->next)
   {
       if(t->data == key)
       {
             return pos;
       }
     pos++;
   }
 return -1;
} 

struct node * erase(struct node *f)
{
   struct node *t;
   while(f!=NULL)
   {
      t=f;
      f=f->next;
      free(t);
   }
  return f;
}
   
int main()
{
   struct node *head=NULL;
   int n,ch,pos,cnt,sum,key,r;

   printf("\n-----Singly Linked List-----\n");

   printf("Create Linked list\n");
   printf("How many nodes::");
   scanf("%d",&n);
   head=create(n);

   while(1)
  {
      printf("\nMENU \n");
      printf("-----------\n");
      printf("1.Insert into Linked list\n");
      printf("2.Delete from Linked list\n");
      printf("3.Display Linked list\n");
      printf("4.Length of Linked list\n");
      printf("5.Sum of linked list\n");
      printf("6.Search element in linked list\n");
      printf("7.EXIT\n");
      printf("Enter your choice::");
      scanf("%d",&ch);
    
      switch(ch)
      {
            case 1:
                 printf("Enter the position to insert::");
                 scanf("%d",&pos);
                 head=insert(head,pos);
                 break;
            case 2:
                 printf("Enter the position for delete::");
                 scanf("%d",&pos);
                 head=delete(head,pos);
                 break;
            case 3:
                 printf("Linked list::");
                 display(head);
                 break;
            case 4:
                 cnt=length(head);
                 printf("No of nodes::%d",cnt);
                 break;
            case 5:
                 sum=add(head);
                 printf("Sum of linked list::%d",sum);
                 break;
            case 6:
                  printf("Which data you want to search::");
                  scanf("%d",&key);
                  r=search(head,key);
                  if(r==-1)
                  {
                       printf("%d is not found in linked list!!\n",key);
                  }
                  else
                  {
                       printf("%d is found at %d position!!\n",key,r);
                  }
                  break;
             case 7:
                 head=erase(head);
                 printf("Linked list deleted permenantly!!");
                 exit(0);
            default:
                 printf("Invalid choice!! \n");
      }
   }

 return 0;
}
