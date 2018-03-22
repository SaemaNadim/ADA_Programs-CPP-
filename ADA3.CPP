#include<iostream.h>
#include<conio.h>
int B[3];
int* MaxMin(int A[20],int first,int last)
{
 int max,min,mid,min1,min2,max1,max2,*C,*D;
 if(first==last)
 {
  max=A[first];
  min=A[first];
  B[0]=max;// cout<<" 1  "<<B[0];
  B[1]=min;// cout<<" 2  "<<B[1];
  return B;
 }
 else if(first==last-1)
 {
  if(A[first]>A[last])
  {
   max=A[first];
   min=A[last];
  }
  else
  {
   max=A[last];
   min=A[first];
  }
  B[0]=max; // cout<<" 3  "<<B[0];
  B[1]=min; // cout<<" 4  "<<B[1];
  return B;
 }
 else
 {
//  cout<<"first1 "<<first;
  mid=(first+last)/2; // cout<<"mid  "<<mid;
  C=MaxMin(A,first,mid);
 //cout<<"first2 "<<first;
  max1=C[0];  //  cout<<"M1 "<<C[0];
  min1=C[1];   // cout<<"m1 "<<min1;
  D=MaxMin(A,mid+1,last);
  max2=D[0];   // cout<<"M2 "<<max2;
  min2=D[1];   // cout<<"m2 "<<min2;
  if(max1>max2)
   max=max1;
  else
   max=max2;   // cout<<"MM "<<max;
  if(min1<min2)
   min=min1;
  else
   min=min2;     // cout<<"mm "<<min;
  B[0]=max;     // cout<<" 5  "<<B[0];
  B[1]=min;     // cout<<" 6  "<<B[1];
  return B;
 }
}
void main()
{
 clrscr();
 int n,A[20],*B;
 cout<<"Enter the number of elements you want to enter\n";
 cin>>n;
 cout<<"Enter the numbers\n";
 for(int i=0;i<n;i++)
 {
  cin>>A[i];
 }
 cout<<"The maximum and minimum element is:\n";
 B=MaxMin(A,0,n-1);
 cout<<B[0]<<" and "<<B[1];
 getch();
}

