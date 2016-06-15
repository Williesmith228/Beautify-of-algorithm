//Basic idea about quicksort
//从两头寻找
int Partion(int A[], int p, int r)
{
    if(p>r)
        return 1;
    int i=p,j=r;
    int x=A[p];
    while(i!=j)
    {
        while(A[j] >=x && i < j)
        {
            j--;
        }
        while(A[i] <=x && i < j)
        {
            i++;
        }
        if(i < j)
        {
            int temp=A[i];
            A[i]=A[j];
            A[j]=temp;
        }
    }
    A[p]=A[i];
    A[i]=x;

    return i;
}
