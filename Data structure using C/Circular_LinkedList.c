#include<stdio.h>
#include<stdlib.h>
#define NEWNODE (struct node *)malloc( sizeof(struct node));

struct node
{
    int data;
    struct node *next;
};

struct node * create(int n)
{
   struct node *f,*l,*t;
   f = NEWNODE;
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
  l->next=f;
  return f;
}

struct node *insert(struct node *f,int pos)
{
    struct node *l,*s,*t;
    t=NEWNODE;
    printf("Enter data::");
    scanf("%d",&t->data);
    t->next=NULL;

    if(pos==1)
    {
        for(l=f;l->next!=f;l=l->next);
        t->next=f;
        l->next=t;
        f=t;
        printf("Data is inserted successfully!!\n");
        return f;
    }
    else
    {
        s=f;
        for(int i=1;i<=pos-2 && s->next!=f;i++)
        {
            s=s->next;
        }
        if(s==NULL)
        {
            printf("Invalid location!!\n");
            return f;
        }
        else
        {
            if(s->next==f)
            {
                s->next=t;
                t->next=f;
                printf("Data is inserted successfully!!\n");
                return f;
            }
            else
            {
                t->next=s->next;
                s->next=t;
                printf("Data is inserted successfully!!\n");
                return f;
            }
        }
    }
}

struct node *delete_ll(struct node *f,int pos)
{
    struct node *l,*s,*t;

    if(pos==1)
    {
        for(l=f;l->next!=f;l=l->next);
        t=f;
        f=f->next;
        t->next=NULL;
        l->next=f;
        free(t);
        printf("Data is deleted successfully!!\n");
        return f;
    }
    else
    {
       s=f;
       for(int i=1;i<=pos-2 && s->next!=f; i++)
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
          if(t->next==f)
          {
             s->next=f;
             t->next=NULL;
             free(t);
             printf("Data is deleted successfully!!\n");
             return f;
          }
          else
          {
             s->next=t->next;
             t->next=NULL;
             free(t);
             printf("Data is deleted successfully!!\n");
             return f;
          }
       }
    }
}

void display(struct node *f)
{
   struct node *t;
   t=f;
   do
   {
       printf("%d->",t->data);
       t=t->next;
   }while(t!=f);
   printf("Head\n");
}

struct node * erase(struct node *f)
{
   struct node *t;
   t=f;
   f=f->next;
   t->next=NULL;

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
    int choice,n,pos1,pos2;

    printf("-----Circular Linked list-----\n");
  
    printf("Create linked list\n");
    printf("How many nodes::");
    scanf("%d",&n);
    head=create(n);

    while (1)
    {
        printf("\nMENU\n");
        printf("1.Insert into linked list\n");
        printf("2.Delete from linked list\n");
        printf("3.Dispaly Linked list\n");
        printf("4.Exit\n");
        printf("Enter your choice::");
        scanf("%d",&choice);

        switch (choice)
        {
        case 1:
            printf("Enter position::");
            scanf("%d",&pos1);
            head=insert(head,pos1);
            break;

        case 2:
             printf("Enter position::");
             scanf("%d",&pos2);
             head=delete_ll(head,pos2);
             break;

        case 3:
             printf("Linked list::");
             display(head);
             break;

        case 4:
             head=erase(head);
             printf("lInked list is deleted permanently!!\n");
             exit(0);                 
        
        default:
             printf("Invalid choice!!\n");
        }

    }
    return 0;
}
