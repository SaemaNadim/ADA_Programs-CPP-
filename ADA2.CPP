#include<iostream.h>
#include<conio.h>
void swap(int &i,int &j)
{
 int t=i;
 i=j;
 j=t;
}
int pivot_list(int A[],int first,int last)
{
 int pv=A[first];
 int pp=first;
 for(int i=first+1;i<=last;i++)
 {
  if(A[i]<pv)
  {
   pp++;
   swap(A[pp],A[i]);
  }
 }
 swap(A[first],A[pp]);
 return pp;
}
int* quick_sort(int A[],int first,int last)
{
 int pivot;
 if(first<last)
 {
  pivot=pivot_list(A,first,last);
  quick_sort(A,first,pivot-1);
  quick_sort(A,pivot+1,last);
 }
  return A;
}
void traversal(int A[],int n)
{
 for(int i=0;i<n;i++)
 {
  cout<<A[i]<<" ";
 }
 cout<<endl;
}
void main()
{
 clrscr();
 int i,n,A[20];
 char choice;
 do
 {
  cout<<"Enter the number of terms in the array\n";
  cin>>n;
  cout<<"Enter the values in the array\n";
  for(i=0;i<n;i++)
  cin>>A[i];
  int f=0;
  int l=n-1;
  quick_sort(A,f,l);
  traversal(A,n);
  cout<<"Do you want to perform again.\n";
  cin>>choice;
 }while(choice=='y'||choice=='Y');
getch();
}