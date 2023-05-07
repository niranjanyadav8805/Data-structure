#include<iostream>
using namespace std;

class node{
    public:
        int data;
        node * next;
        node()
        {
            data=0;
            next=NULL;
        }
        node(int data)
        {
            this->data=data;
            this->next=NULL;
        }
};

class linkedlist{
        node * head;
    public:
        linkedlist()
        {
            head=NULL;
        }
        void create_ll(int n);
        void insert(int pos);
        void delete_ll(int pos);
        void display_ll();
        int length();
        int sum();
        int search(int data);
        void erase();
};

void linkedlist::create_ll(int n)
{
        node *f=new node();
        node *l=new node();
        head=f;
        cout << "Enter data::";
        cin >> f->data;
        f->next=NULL;
        l=f;
        for(int i=2;i<=n;i++)
        {
            node *t=new node();
            cout << "Enter data::";
            cin >> t->data;
            t->next=NULL;
            l->next=t;
            l=l->next;
        }
}

void linkedlist::insert(int pos)
{
     node *f=new node();
     node *s= new node();
     node *t=new node();
     cout << "Enter data::";
     cin >> t->data;
     t->next=NULL;
     f=head;

     if(pos==1)
     {
         t->next=f;
         head=t;
         cout << t->data << " is inserted successfully!!\n";
         return ;
     }
     else
     {
        s=f;
        for(int i=1;i<=pos-2 && s!=NULL;i++)
        {
            s=s->next;
        }
        if(s==NULL)
        {
            cout << "Invalid location!!\n";
        }
        else
        {
            t->next=s->next;
            s->next=t;
            cout << t->data << " is inserted successfully!!\n";
            return;
        }
     }
}

void linkedlist::delete_ll(int pos)
{
    int data;
    node *f=new node();
    node *t=new node();
    node *s=new node();
    f=head;

    if(pos==1)
    {
        t=f;
        data=t->data;
        f=f->next;
        head=f;
        t->next=NULL;
        free(t);
        cout << data << " is deleted successfully!!\n";
        return ;
    }
    else
    {
        s=f;
        for(int i=1;i<=pos-2 && s!=NULL ;i++)
        {
            s=s->next;
        }
        if(s==NULL)
        {
            cout << "Invalid location!!\n";
        }
        else
        {
            t=s->next;
            data=t->data;
            s->next=t->next;
            free(t);
            cout << data << " is successfully deleted!!\n";
            return;
        }
    }
}

void linkedlist::display_ll()
{
      node *t=new node();
      t=head;
      while(t!=NULL)
      {
         cout << t->data << "->";
         t=t->next;
      }
      cout << "NULL\n";
}

int linkedlist::length()
{
    int count=0;
    node *f=new node();
    f=head;
    while(f!=NULL)
    {
        count=count+1;
        f=f->next;
    }
    return count;
}

int linkedlist::sum()
{
    int sum=0;
    node *f=new node();
    f=head;
    while(f!=NULL)
    {
        sum=sum+f->data;
        f=f->next;
    }
    return sum;
}

int linkedlist::search(int data)
{
    node *f=new node();
    f=head;
    for(;f!=NULL;f=f->next)
    {
        if(f->data == data)
        {return 1;
        }
    }
    return 0;
}

void linkedlist::erase()
{
    node *f=new node();
    node *t=new node();
    f=head;
    while(f!=NULL)
    {
        t=f;
        f=f->next;
        free(t);
    }
    cout << "Linked list is deleted permanantly!!\n";
}

int main()
{
    linkedlist l1;
    int choice,n,pos1,pos2,element,s;
    cout << "\n--------SINGLY LINKED LIST---------\n";

    cout << "Create Linked list\n";
    cout << "How many nodes::";
    cin >> n;
    l1.create_ll(n);

    while(1)
    {
        cout << "\nMENU \n";
        cout << "1.Insert into Linked list\n";
        cout << "2.Delete from linked list\n";
        cout << "3.Display Linked list\n";
        cout << "4.Length of linked list\n";
        cout << "5.Sum of linked list\n";
        cout << "6.Search an element in linked list\n";
        cout << "7.Exit\n";
        cout << "Enter your choice::";
        cin >> choice;

        switch(choice)
        {
            case 1:
                 cout << "Enter position::";
                 cin >> pos1;
                 l1.insert(pos1);
                 break;

            case 2:
                 cout << "Enter position::";
                 cin >> pos2;
                 l1.delete_ll(pos2);
                 break;

            case 3:
                 cout << "Linked list::";
                 l1.display_ll();
                 break;

            case 4:
                 cout << "Length of linked list::" << l1.length() << endl;
                 break;

            case 5:
                 cout << "Sum of elements in liked list::" << l1.sum() << endl;
                 break;

            case 6:
                 cout << "Which element you want to search::";
                 cin >> element;
                 s=l1.search(element);
                 if(s==1)
                 {
                    cout << element << " is present in linked list!!\n";
                 }
                 else{
                    cout << element << " is not present in linked list!!\n";
                 }
                 break;

            case 7:
                l1.erase();
                exit(0);
                break; 

            default:
                 cout << "Invalid choice!!\n";                              
        }
    } 

    return 0;
}
