#include<stdio.h>
#include<stdlib.h>
#define NEWNODE (struct node *)malloc( sizeof(struct node) );

struct node
{
   struct node *prev;
   int data;
   struct node *next;
};

struct node * create(int n)          //create linked list
{
   struct node *f,*l,*t;

   f=NEWNODE;
   printf("Enter data::");
   scanf("%d",&f->data);
   f->prev=NULL;
   f->next=NULL;
   l=f;

   for(int i=2;i<=n;i++)
   {
       t=NEWNODE;
       printf("Enter data::");
       scanf("%d",&t->data);
       t->next=NULL;
       l->next=t;
       t->prev=l;
       l=l->next;
   }
  return f;
}

struct node * insert(struct node *f,int pos)
{
   struct node *t,*s;
   t=NEWNODE;
   printf("Enter data::");
   scanf("%d",&t->data);
   t->prev=NULL;
   t->next=NULL;
  
   if(pos==1)
   {
      t->next=f;
      f->prev=t;
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
         printf("Invalid position!!\n");
         return f;
      }
      else
      {
          t->next=s->next;
          t->prev=s;
          if(s->next!=NULL)
          {
             s->next->prev=t;
          }
          s->next=t;
          printf("Data is inserted successfully!! \n");
          return f;
      }
   }
}

struct node *delete_ll(struct node *f,int pos)
{
    int data;
    struct node *s,*t;
    if(pos==1)
    {
        t=f;
        data=t->data;
        f=f->next;
        t->next=NULL;
        f->prev=NULL;
        free(t);
        printf("Data is deleted successfully!! \n");
        return f;
    }    
    else
    {
        s=f;
        for(int i=1;i<=pos-2 && s!=NULL;i++)
        {
            s=s->next;
        }
        if(s==NULL)\
        {
            printf("Invalid position!!\n");
            return f;
        }
        else
        {
            t=s->next;
            s->next=t->next;
            if(t->next!=NULL)
            {
               t->next->prev=s;
            }
            free(t);
            printf("Data is deleted successfully!! \n");
            return f;
        }
    }
}

struct node *display(struct node *f)          //display linked list
{
   struct node *t;
   for(t=f;t!=NULL;t=t->next)
   {
      printf("%d->",t->data);
   }
   printf("NULL\n");
}

struct node *reverse(struct node *f)
{
   struct node *t;
   for(t=f;t->next!=NULL;t=t->next);

   for(;t!=NULL;t=t->prev)
   {
      printf("%d->",t->data);

   }
  printf("NULL\n");
}

int length(struct node *f)
{
     int count=0;
     struct node *t;
     for(t=f;t!=NULL;t=t->next)
     {
        count++;
     }
    return count; 
}

int search(struct node *f,int key)
{
    struct node *t;
    int pos=1;

    for(t=f;t!=NULL;t=t->next)
    {
         if(t->data==key)
         {
             return pos;
         }
         pos++;
    }
    return -1;
}

struct node *erase(struct node *f)
{
    struct node *t;
    while (f!=NULL)
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
   int n,ch,pos1,pos2,cnt,sum,key,r;

   printf("\n-----Doubly Linked List-----\n");

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
      printf("4.Reverse linked list\n");
      printf("5.Length of Linked list\n");
      printf("6.Search element in linked list\n");
      printf("7.EXIT\n");
      printf("Enter your choice::");
      scanf("%d",&ch);
    
      switch(ch)
      {
            case 1:
                 printf("Enter the position to insert::");
                 scanf("%d",&pos1);
                 head=insert(head,pos1);
                 break;
            case 2:
                 printf("Enter the position for delete::");
                 scanf("%d",&pos2);
                 head=delete_ll(head,pos2);
                 break;
            case 3:
                 printf("Linked list::");
                 display(head);
                 break;
            case 4:
                 printf("Reversed linked list::");
                 reverse(head);
                 break;
            case 5:
                 printf("Length of linked list::%d",length(head));
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
