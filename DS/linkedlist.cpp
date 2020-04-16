#include<iostream>
#define NULL 0
using namespace std;
class node
{
public:
  node* next;
  int data;
  node* insert(node*);
  node* insert_begin(node*);
  node* del(node*);
  void display(node*);
  node* reverse(node*);
  node* sort(node*);
  node* altdel(node*);
  node* insert_sorted(node*);
};
node* head  = NULL;
node* node::insert(node* head)
{
  node* temp = new node;
  cout<<"Enter the number\n";
  cin>>temp->data;
  temp->next = NULL;
  if(head  == NULL)
  {
    head = temp;
    return head;
  }
  node* t = head;
  while(t->next != NULL)
  t = t->next;
  t->next = temp;
  return head;
}
node* node::insert_begin(node* head)
{
  node* temp = new node;
  cout<<"Enter data to be inserted in the beginning\n";
  cin>>temp->data;
  temp->next = NULL;
  if(head == NULL)
  {
    head = temp;
    return head;
  }
    temp->next = head;
    head = temp;
    return head;
}
node* node::del(node* head)
{
  if(head == NULL)
  {
    cout<<"List is Empty\n";
    return head;
  }
  int ele;
  cout<<"Enter the element to be deld\n";
  cin>>ele;
  node* t = head;
  node* p = head;
  while(t->data!=ele && t!=NULL)
  {
    p = t;
    t = t->next;
  }
  if(t == head)
  {
    head = t->next;
    delete t;
    return head;
  }
  p->next = t->next;
  delete t;
  return head;
}
void node::display(node* head)
{
  node* d = head;
  while(d->next!=NULL)
  {
    cout<<d->data<<"->";
    d = d->next;
  }
  cout<<d->data<<endl;
}
node* node::reverse(node* head)
{
  if(head == NULL)
  {
    cout<<"List is Empty\n";
    return head;
  }
  node *t = head;
  node* r = NULL;
  node* p = NULL;
  while(t!=NULL)
  {
    r = p;
    p = t;
    t = t->next;
    p->next = r;
  }
  head = p;
  return head;
}
node* node::sort(node* head)
{
  for(node *i=head;;i=i->next)
  {
    for(node *j=i->next;;j=j->next)
    {
      if((i->data)>(j->data))
      {
        int t = i->data;
        i->data = j->data;
        j->data = t;
      }
    }
  }
  return head;
}
node* node::insert_sorted(node* head)
{
  node* temp = new node;
  cout<<"Enter element to be inserted in the sorted list\n";
  cin>>temp->data;
  temp->next = NULL;
  node* p = NULL;
  if(head == NULL)
  {
    head = temp;
    return head;
  }
  node *t = head;
  while(t->next!=NULL)
  {
    if((temp->data)<(t->data)){
      break;
    }
    p = t;
  }
  temp->next = p->next;
  p->next = temp;
  return head;
}
int main()
{
  node n;
  int ch;
  while(ch!=-1)
  {
    cout<<"Enter\n1.Insert\n2.Insert in the beginning\n3.del\n4.Display\n5.Reverse\n6.Sort\n7.Insert into Sorted List\n-1.Exit\n";
    cin>>ch;
    if(ch!=-1)
    {
      switch(ch)
      {
        case 1:
        head = n.insert(head);
        break;
        case 2:
        head =  n.insert_begin(head);
        break;
        case 3:
        head = n.del(head);
        break;
        case 4:
        n.display(head);
        break;
        case 5:
        head = n.reverse(head);
        break;
        case 6:
        head = n.sort(head);
        break;
        case 7:
        head = n.insert_sorted(head);
        break;
        default:
        cout<<"Wrong Choice\n";
      }
    }
  }
  return 0;
}
