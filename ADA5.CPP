#include<iostream.h>
#include<conio.h>
int P[20],rank[20],i=0;
void MakeSet(int x)
{ int A[20];
 A[i]=x;
 P[x]=x;
 rank[x]=0;
 i++;
}
int FindSet(int x)
{
 if(x!=P[x])
 {
  P[x]=FindSet(P[x]);
 }
 return P[x];
}
void setunion(int x,int y)
{
 int rep1=FindSet(x);
 int rep2=FindSet(y);
 if(rank[rep1]>rank[rep2])
 {
  P[rep2]=rep1;
 }
 else if(rank[rep1]<rank[rep2])
 {
  P[rep1]=rep2;
 }
 else
 {
  P[rep2]=rep1;
  rank[rep1]=rank[rep1]+1;
 }
}
void main()
{
 clrscr();
 int x,y,n,i,j,k;
 char ch,ch1;
 for(k=0;k<20;k++)
 {
  P[k]=-1;
 }
 do
 {
  cout<<"Enter 1 to make sets\n";
  cout<<"Enter 2 to find sets\n";
  cout<<"Enter 3 for union of the sets and display it\n";
  cin>>y;
  if(y==1)
  {
   do
   {
    cout<<"Enter the representative element of the set\n";
    cin>>x;
    MakeSet(x);
    cout<<"The disjoint set is :";
    cout<<P[x];
    cout<<"\nDo you want to make more disjoint sets?\n";
    cin>>ch;
   }while(ch=='y'||ch=='Y');
  }
  else if(y==2)
  {
   cout<<"Enter the element\n";
   cin>>n;
   cout<<"The representative element of the set containing "<<n<<" is: ";
   cout<<FindSet(n);
  }
  else if(y==3)
  {
   cout<<"Enter the two elements whose set you want to make union of.\n";
   cin>>i>>j;
   setunion(i,j);
   cout<<"The union is performed and the representative element is ";
   cout<<FindSet(j);
   cout<<"The representative elsement of all sets are shown below:\n";
   for(int k=0;k<20;k++)
   {
    if(P[k]!=-1)
    {
     cout<<"The parent of "<<k<<" is "<<P[k]<<"\n";
    }
   }
  }
  cout<<"Do you want to perform more operations?\n";
  cin>>ch1;
 }while(ch1=='y'||ch1=='Y');
 getch();
}


