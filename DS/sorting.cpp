#include<iostream>
using namespace std;
void bubblesort(int a[],int n)
{
  for(int i=0;i<n-1;i++)
  {
    for(int j=0;j<n-i-1;j++)
    {
      if(a[j]>a[j+1])
      {
        int t = a[j];
        a[j] = a[j+1];
        a[j+1] = t;
      }
    }
  }
}
void selectionsort(int a[],int n)
{
  int min_index,i,j;
  for(i=0;i<n-1;i++)
  {
    min_index = i;
    for(j=i+1;j<n;j++)
    {
      if(a[min_index]>a[j])
      min_index = j;
    }
    int t = a[min_index];
    a[min_index] = a[i];
    a[i] = t;
  }
}
void insertionsort(int arr[],int n)
{
  int i, key, j;
    for (i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}
int main()
{
  int n;
  cout<<"Enter n\n";
  cin>>n;
  int a[n];
  cout<<"Enter the elements of the array\n";
  for(int i=0;i<n;i++)
  cin>>a[i];
  //bubblesort(a,n);
  //selectionsort(a,n);
  insertionsort(a,n);
   cout<<"The Sorted Array is:\n";
   for(int i=0;i<n;i++)
   cout<<a[i]<<" ";
   cout<<endl;
   return 0;
}
