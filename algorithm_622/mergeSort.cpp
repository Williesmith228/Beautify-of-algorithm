#include <iostream>
#include <stdlib.h>
using namespace std;
void mergeSort(int A[],int p,int r);
void mergeArray(int a[],int p,int mid,int r);



void mergeSort(int A[],int p,int r)
{
    if(p<r)
    {
        int mid=(p+r)/2;
        mergeSort(A,p,mid);
        mergeSort(A,mid+1,r);
        mergeArray(A,p,mid,r);
    }

}

void mergeArray(int a[],int p,int mid, int r)
{
    int *temp=new int[100];
    int i=p,j=mid+1;
    int k=0; 
    while(i<=mid && j<=r)
    {
        if(a[i]<=a[j])
        {
            temp[k++]=a[i++];
        }
        else
        {
            temp[k++]=a[j++];
        }
        
    }
    while(i<=mid)
        temp[k++]=a[i++];
    while(j<=r)
        temp[k++]=a[j++];
    for(i=0;i<k;i++)
    {
       a[p+i]=temp[i];
    
    }
    delete []temp;
}

int main()
{
    srand(unsigned(time(0)));
    int a[10];
    for(int i=0;i<10;i++)
    {
        a[i]=rand()%21+1;
        cout<<a[i]<<" ";
    }
    cout<<endl;  
    mergeSort(a,0,9);
    for(int i=0;i<10;i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;
    return 0;
}
