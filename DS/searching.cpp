#include<iostream>
using namespace std;
int main()
{
  int n;
  cout<<"Enter n\n";
  cin>>n;
  int a[n];
  cout<<"Enter the elements of the array\n";
  for(int i=0;i<n;i++)
  cin>>a[i];
  cout<<"Enter key\n";
  int low,high,mid,f,key;
  cin>>key;
  low = 0;
  high = n-1;
  f = 0;
  do {
    mid = (low + high)/2;
    if(a[mid] == key)
    {
      f = 1;
      break;
    }
    if(a[mid] < key)
    low = mid + 1;
    if(a[mid] > key)
    high = mid - 1;
  } while(low<=high && a[mid]!=key);
  if(f == 1)
  cout<<"Search Successful\n";
  else
  cout<<"Search Unsuccessful\n";
  return 0;
}
