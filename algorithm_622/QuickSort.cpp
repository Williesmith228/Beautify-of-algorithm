#include <iostream>
#include <stdlib.h>
using namespace std;
void QuickSort(int a[],int,int);
int Partion(int a[],int, int);

void QuickSort(int a[],int p,int r)
{
if(p<r){
    int q=Partion(a,p,r);
    QuickSort(a,p,q-1);
    QuickSort(a,q+1,r);
}
}

int Partion(int a[],int p,int r)
{
    int i=p-1,j;
    int temp,x=a[r];
    for(j=p;j<r;j++)
    {
        if(a[j]<x){
            i+=1;
            temp=a[i];
            a[i]=a[j];
            a[j]=temp;
        }
    }
    i++;
    a[r]=a[i];
    a[i]=x;         
    return i;
}
int main()
{
    srand(unsigned(time(0)));
    int A[10];
    for(int i=0;i<10;i++)
    {
        A[i]=rand()%21+1;
        cout<<A[i]<<" ";
    }
    cout<<endl;
    QuickSort(A,0,9);
    for(int i=0;i<10;i++)
    {
        cout<<A[i]<<" ";
    }
    cout<<endl;
    return 0;
}   
