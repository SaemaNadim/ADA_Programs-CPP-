#include<iostream.h>
#include<conio.h>
int n;
void merge(node *tree[],int s1,int e1,int s2,int e2)
{
 int i=0,j,fs=s1,fe=e2;
 node *Q[20];
 while(s1<=e1&&s2<=e2)
 {
  if(tree[s1]->f->data<tree[s2]->f->data)
  {
   Q[i]=tree[s1];
   i++;
   s1++;
  }
  else
  {
   Q[i]=tree[s2];
   i++;
   s2++;
  }
 }
 if(s2>e2)
 {
  for(j=s1;j<=e1;j++)
  {
   Q[i]=tree[j];
   i++;
  }
 }
 if(s1>e1)
 {
  for(j=s2;j<=e2;j++)
  {
   Q[i]=tree[j];
   i++;
  }
 }
 int k=0;
 for(j=fs;j<=fe;j++)
 {
  tree[j]=Q[k];
  k++;
 }
}

node *merge_sort(node *tree[],int first,int last)
{
 if(first<last)
 {
  int mid=(first+last)/2;
  merge_sort(tree,first,mid);
  merge_sort(tree,mid+1,last);
  merge(tree,first,mid,mid+1,last);
 }
 return tree;
}

node *insert_priority_queue(node *tree[],node *root)
{
 for(int i=0;i<n-2;i++)
 {
  tree[i]=tree[i+2];
 }
 n=n-1;
 for(i=n-1;i>0;i--)
 {
   if(tree[i]->freq->data<root->freq->data)
   {
    int j=n-1;
    while(j>i)
    {
     tree[j]=tree[j-1];
     j--;
    }
    tree[i]=root;
   }
 }
 return tree;
}
void generate_code(node *root,
void Huffman(int A[],int freq[],int n)
{
 struct node
 {
  int data;
  char string[20];
  node *left;
  node *right;
  node *bincode;
  node *f;
  node *symbolindex;
 };
 node *root;
//node *parent=NULL;
//node *ptr=NULL;
 for(i=0;i<n;i++)
 {
  node *P,tree[15];
  P=new node;
  P->bincode->string="";
  P->f->data=freq[i];
  P->left=NULL;
  P->right=NULL;
  P->symbolindex->data=i;
  tree[i]=P;
 }
 tree[]=merge_sort(tree,0,n);
 for(i=0;i<n;i++)
 {
  node *l=tree[0];
  node *r=tree[1];
  node *root=new node;
  root->binarycode->string="";
  root->left=l;
  root->right=r;
  root->freq->data=l->freq->data+r->freq->data;
  insert_priority_queue(tree,root);
 }
 generate_code(root,code,l,r);
}