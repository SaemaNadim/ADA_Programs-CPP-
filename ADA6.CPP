#include<iostream.h>
#include<conio.h>
int min(int a,int b)
{
 if(a<b)
 return a;
 else
 return b;
}
int timeslot[10],dmax;
void job_scheduling_deadline(int d[],int p[],int n)
{
 int i,t,j,a[10],k;
 for(i=0;i<n;i++)
 a[i]=i+1;
 dmax=d[0];
 for(i=0;i<n;i++)
 {
  if(dmax<d[i])
  {
   dmax=d[i];
  }
 }
 for(i=0;i<n-1;i++)
 {
  for(j=i+1;j<n;j++)
  {
   if(p[i]<p[j])
   {
    t=p[i];
    p[i]=p[j];
    p[j]=t;
    t=d[i];
    d[i]=d[j];
    d[j]=t;
    t=a[i];
    a[i]=a[j];
    a[j]=t;
   }
  }
 }
 for(i=0;i<min(n,dmax);i++)
 { timeslot[i]=0;
//cout<<"a "<<timeslot[i];
 }
 for(i=0;i<n;i++)
 {
  k=min(n-1,d[i]-1);
  while(k>=0)
  {
   if(timeslot[k]==0)
   {
    timeslot[k]=a[i];
    break;
   }
   k--;
  }
 }
}
void main()
{
 clrscr();
 int i,n,d[10],p[10];
 cout<<"Enter the number of jobs you want to enter\n";
 cin>>n;
 cout<<"Enter the deadine and the profit of each job\n";
 for(i=0;i<n;i++)
 {
  cin>>d[i]>>p[i];
 }
 cout<<"The result of the job sequencing is:\n";
 job_scheduling_deadline(d,p,n);
 for(i=0;i<min(dmax,n);i++)
 {
  if(timeslot[i]!=0)
  cout<<"job"<<timeslot[i]<<" ";
 }
 getch();
}