#include<iostream>
using namespace std;
class queue
{
public:
  int f,r;
  int max;
  int a[20];
  queue()
  {
    f = r = -1;
    max = 20;
  }
  queue(int m)
  {
    f = r = -1;
    max = m;
  }
  void enqueue(int);
  int dequeue();
  void display();
};
void queue::enqueue(int e)
{
  if(r == max-1)
  cout<<"Queue is Full\n";
  else
  {
    a[++r] = e;
  }
}
int queue::dequeue()
{
  if(f == r)
   return -999;
  else
  {
    return (a[f++]);
  }
}
void queue::display()
{
  if(f==r)
  cout<<"Queue is Empty\n";
  else
  {

    while(f!=r)
    {
        cout<<a[f]<<" ";
        f++;
    }
    cout<<endl;
  }
}
int main()
{
  cout<<"Enter maxsize of queue\n";
  int maxsize;
  cin>>maxsize;
  queue q(maxsize);
  int ch;
    while(ch!=-1)
    {
      cout<<"Enter\n1.Enqueue\n2.Dequeue\n3.Display\n-1.Exit\n";
      cin>>ch;
      if(ch!=-1)
      {
  switch(ch)
  {
    case 1:
    int ele;
    cout<<"Enter element to be inserted in the Queue\n";
    cin>>ele;
       q.enqueue(ele);
       break;
    case 2:
    int popp;
    popp = q.dequeue(); 
    if(popp!=-999)
    cout<<popp<<" is popped from the Queue\n";
    else
    cout<<"Queue is Empty\n";
    break;
    case 3:
    cout<<"The contents of the queue are as follows\n";
    q.display();
    break;
    default:
    cout<<"Wrong choice\n";
  }
}
}
}
