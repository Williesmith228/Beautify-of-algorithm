//Basic idea about quick sort algorithm:
/*
QuickSort(A,p,r)
  if p < r
    then q <- Partion(A,p,r)
      QuickSort(A,p,q-1)
      QuickSort(A,q+1,r)

Partion(A,p,r)
{
  i=p-1;
  x=A[r]
  for j <- p to r-1
    do if A[j] < x
      i+=1
      A[i] <->A[j]
  A[i+1] <-> A[r]
  return i+1
}
*/
#include<iostream>
#include<time.h>
#include<stdlib.h>
#define N 10
using namespace std;

int Partion(int A[],int p,int r)
{
    int i=p-1,j,tmp;
    int x=A[r];
    for(j=p; j<r; j++)
    {
        if(A[j] <= x)
        {
            i+=1;
            tmp=A[i];
            A[i]=A[j];
            A[j]=tmp;
        }
    }
    A[r]=A[i+1];
    A[i+1]=x;
    ++i;
    return i;
}


void QuickSort(int A[],int p,int r)
{
    if(p >= r)
        return;
    int q=Partion(A,p,r);
    if(p < q-1)
        QuickSort(A,p,q-1);
    if(q+1 < r)
        QuickSort(A,q+1,r);
}

int main()

{
    srand(unsigned(time(0)));
    int a[N];
    for(int i=0; i<N; i++)
    {
        a[i]=rand()%11;  // 产生0-10之间的随机数
        cout<<a[i]<<" ";
    }
    cout<<endl;
    QuickSort(a,0,N-1);
    for(int i=0; i<N; i++)
    {
        cout<<a[i]<<" ";
    }
    return 0;
}

