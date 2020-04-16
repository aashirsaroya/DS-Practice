#include<iostream>
#include<string.h>
#include<stdio.h>
#include<cstdio>
#define NULL 0
using namespace std;
class tree
{
public:
  tree* lchild;
  tree* rchild;
  int data;
  tree()
  {
    lchild = NULL;
    rchild = NULL;
    data = 1;
  }
  tree(int ele)
  {
    lchild = NULL;
    rchild = NULL;
    data = ele;
  }
  tree* create();
  tree* insert(tree*);
  void preorder(tree*);
  void inorder(tree*);
  void postorder(tree*);
  void preorderI(tree*);
  void inorderI(tree*);
  void postorderI(tree*);
  void levelorderI(tree*);
  int depth(tree*);
  bool parent(tree*,int);
  //ancestors
};
tree* root = NULL;
bool tree::parent(tree* root,int ele)
{
   if(root == NULL)
   return false;
  if(ele == root->data)
  return true;
  if(parent(root->lchild,ele)||parent(root->rchild,ele))
  cout<<"Parent Value: "<<root->data<<endl;
  return false;
}
int tree::depth(tree* root)
{
  int ldepth,rdepth;
  if(root == NULL)
  return 0;
  else
  {
  ldepth = depth(root->lchild);
  rdepth = depth(root->rchild);
  if(ldepth > rdepth)
  return (ldepth+1);
  else
  return (rdepth+1);
  }
}
void tree::levelorderI(tree* root)
{
  tree* q[10],*p;
  p = root;
  int f,r;
  f = r = -1;
  q[++r] = root;
  do
  {
    p = q[++f];
    cout<<p->data<<" ";
    if(p->lchild)
    q[++r] = p->lchild;
    if(p->rchild)
    q[++r] = p->rchild;
  }
  while(f!=r);
}
void tree::postorderI(tree* p)
{
  tree *s1[10], *s2[10];
   int t1 = -1, t2 = -1;
   s1[++t1] = p;
   while(t1 >= 0)
   {
       s2[++t2] = s1[t1--];
       if(s2[t2] -> lchild)
           s1[++t1] = s2[t2] -> lchild;
       if(s2[t2] -> rchild)
           s1[++t1] = s2[t2] -> rchild;

   }
   for(int i = t2; i >= 0; i--)
       cout << s2[i] -> data << " ";
}
void tree::inorderI(tree* root)
{
  int top = -1;
  tree* s[10];
  tree *p = root;
  do
   {
     for(;p;p=p->lchild)
     s[++top] = p;
     if(top>=0)
     p = s[top--];
     else
     break;
     cout<<p->data<<" ";
     p = p->rchild;
   }
  while(true);
}
void tree::preorderI(tree* root)
{
  int top = -1;
  tree* s[10];
  tree *p = root;
  do {
    for(;p;p=p->lchild)
    {
      cout<<p->data<<" ";
      s[++top] = p;
    }
    if(top>=0)
    p = s[top--];
    else
    break;
    p = p->rchild;
  } while(true);
}
tree* tree::create()
{
  tree* p;
  int x;
  cout<<"Enter data(-1 for NULL)\n";
  cin>>x;
  if(x == -1)
  return NULL;
  p = new tree;
  p->data = x;
  cout<<"Enter Left child of "<<x<<endl;
  p->lchild = create();
  cout<<"Enter Right Child of "<<x<<endl;
  p->rchild = create();
  return p;
}
tree* tree::insert(tree* root)
{
  int e;
  cout<<"Enter the element to be inserted\n";
  cin>>e;
  tree* t = new tree(e);
  if(root == NULL)
  {
    root = t;
    return root;
  }
  char dir[20];
  int i;
  cout<<"Enter directions in uppercase\n";
  fflush(stdin);

  tree *cur,*prev;
  cur = root;
  prev = NULL;
  for(i=0;i<strlen(dir)&& cur;i++)
  {
    prev = cur;
    if(dir[i] == 'L' )
    cur = cur->lchild;
    else
    cur = cur->rchild;
  }
  if(cur!=NULL || i!=strlen(dir))
  {
    cout<<"Insertion not possible\n";
    delete t;
    return root;
  }
  if(dir[i-1] == 'L')
  prev->lchild = t;
  else
  prev->rchild = t;
  return root;
}
void tree::preorder(tree* root)
{
  tree* t = root;
  if(t)
  {
  cout<<t->data<<" ";
  preorder(t->lchild);
  preorder(t->rchild);
  }
}
void tree::inorder(tree* root)
{
  tree *t = root;
  if(t)
  {
    inorder(t->lchild);
    cout<<t->data<<" ";
    inorder(t->rchild);
  }
}
void tree::postorder(tree* root)
{
  tree *t = root;
  if(t)
  {
    postorder(t->lchild);
    postorder(t->rchild);
    cout<<t->data<<" ";
  }
}
int main()
{
  tree t;
  int ch;
  while(ch!=-1)
  {
    cout<<"Enter\n1.Create tree\n2.Insert an element\n3.Preorder\n4.Inorder\n5.Postorder\n6.PreorderI\n7.InorderI\n8.PostorderI\n9.LevelOrder\n10.depth\n11.Parent\n-1.Exit\n";
    cin>>ch;
    if(ch!=-1)
    {
      switch(ch)
      {
        case 1:
        root = t.create();
        break;
        case 2:
        root = t.insert(root);
        break;
        case 3:
        t.preorder(root);
        break;
        case 4:
        t.inorder(root);
        break;
        case 5:
        t.postorder(root);
        break;
        case 6:
        t.preorderI(root);
        break;
        case 7:
        t.inorderI(root);
        break;
        case 8:
        t.postorderI(root);
        break;
        case 9:
        t.levelorderI(root);
        break;
        case 10:
        int dep;
        dep  = t.depth(root);
        cout<<"Depth: "<<dep<<endl;
        break;
        case 11:
        int pp;
        cout<<"Enter element whose parent you want to find"<<endl;
        cin>>pp;
        bool q;
        q = t.parent(root,pp);
        break;
        default:
        cout<<"Wrong Choice\n";
      }
    }
  }
  return 0;
}
