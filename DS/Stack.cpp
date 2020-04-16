#include<iostream>
using namespace std;
class stack
{
public:
  int a[20];
  int max;
  int top;
  stack()
  {
    top = -1;
    max = 20;
  }
  stack(int m)
  {
    top = -1;
    max = m;
  }
  void push(int);
  int pop();
  void display();
};
void stack::push(int e)
{
  if(top == max-1)
  {
    cout<<"Stack is full\n";
  }
  else
  a[++top] = e;
}
int stack::pop()
{
  if(top == -1)
  return -999;
  else
  return (a[top--]);
}
void stack::display()
{
  if(top == -1)
  cout<<"Stack is Empty\n";
  while(top!=-1)
  {
cout<<a[top]<<" ";
    top--;
  }
  cout<<endl;
}
int main()
{
  stack s;
  int ch;
    while(ch!=-1)
    {
      cout<<"Enter\n1.Push\n2.Pop\n3.Display\n-1.Exit\n";
      cin>>ch;
      if(ch!=-1)
      {
  switch(ch)
  {
    case 1:
    int ele;
    cout<<"Enter element to be inserted in the Stack\n";
    cin>>ele;
       s.push(ele);
       break;
    case 2:
    int popp;
    popp = s.pop();
    if(popp!=-999)
    cout<<popp<<" is popped from the Stack\n";
    else
    cout<<"Stack is Empty\n";
    break;
    case 3:
    cout<<"The contents of the stack are as follows\n";
    s.display();
    break;
    default:
    cout<<"Wrong choice\n";
  }
}
}
  return 0;
}
