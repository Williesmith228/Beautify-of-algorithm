//



/*
#include<iostream>
#include<stdlib.h>
using namespace std;
class BankAccount
{
public:
    BankAccount(int yuan,int jiao,int fen,double rate);
    BankAccount(double new_balance,double rate);
    BankAccount();
    void update();
    double get_balance();
    double get_rate();
    void output();
private:
    double balance;
    double interest_rate;
    double fraction(double percent);
};

int main()
{
    BankAccount account1(100.80,2.3),account2;
    cout<<"account1 initialized as follows:\n";
    account1.output();
    cout<<"account2 initialized as follows:\n";
    account2.output();
    account1 = BankAccount(211,6,5,5.0);
    cout<<"account1 reset to the following:\n";
    account1.output();
    return 0;
}
BankAccount::BankAccount():balance(0),interest_rate(0.0){}
BankAccount::BankAccount(int yuan,int jiao,int fen,double rate)
{
    if((yuan<0)||(jiao<0)||(fen<0)|| rate < 0){
        cout<<"Illegal values for money or interest rate. \n";
        exit(1);
    }
    balance = yuan + 0.1*jiao +0.01*fen;
    interest_rate = rate;
}

BankAccount::BankAccount(double new_balance,double rate){
    if((balance<0)||rate<0){
        cout<<"Illegal values for money or interest rate.\n";
        exit(1);
    }
    balance=new_balance;
    interest_rate=rate;
}
void BankAccount::output()
{
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);
    cout<<"Account balance "<< balance <<endl;
    cout<<"Interest rate "<< interest_rate <<"%"<<endl;
}
*/

//p220 c++基础与案例开发详解
/*
#include<iostream>
using namespace std;
class CComplex{
public:
    CComplex(double,double);  //构造函数
    CComplex(CComplex &c); //拷贝构造函数
    CComplex add(CComplex &x); //对象作为函数返回值
    void Print();
private:
    double real;
    double imag;
};

CComplex::CComplex(double r=0.0,double i=0.0)
{
    real=r;
    imag=i;
    cout<<"调用两个参数的构造函数"<<endl;
}

CComplex::CComplex(CComplex &c)
{
    real=c.real;
    imag=c.imag;
    cout<<"调用拷贝构造函数"<<endl;
}

void CComplex::Print()
{
    cout<<"("<<real<<","<<imag<<")"<<endl;

}

void f(CComplex n)
{
    cout<<"n=";
    n.Print();
}
CComplex CComplex::add(CComplex &x)
{
    CComplex y(real+x.real,imag+x.imag);
    return y;
}

int main()
{
    CComplex a(3.0,4.0),b(5.6,7.9);
    CComplex c(a);
    cout<<"a=";
    a.Print();
    cout<<"c=";
    c.Print();
    f(b);
    c = a.add(b);
    c.Print();
    return 0;
}

*/

//c++基础与案例开发详解
/*
#include<iostream>
#include<string.h>
using namespace std;
class CClass{
public:
    CClass(char *,int);
    ~CClass()
    {
        cout<<"析构班级："<<pname<<endl;
        delete pname;
    }
    void Print();
    CClass(CClass &s);
private:
    char *pname;
    int num;
};
CClass::CClass(CClass &s)
{
    pname=new char[strlen(s.pname)+1];
    if(pname!=NULL)
        strcpy(pname,s.pname);
    num=s.num;
    cout<<"创建班级的拷贝"<<pname<<endl;
}
CClass::CClass(char *cName,int snum)
{
    int length = strlen(cName);
    pname=new char[length+1];
    if(pname!=NULL)
        strcpy(pname,cName);
    num=snum;
    cout<<"创建班级："<<pname<<endl;
}
void CClass::Print()
{
    cout<<pname<<"班级的人数为："<<num<<endl;
}
int main()
{
    CClass c1("计算机111班",56);
    CClass c2(c1);
    c1.Print();
    c2.Print();
    return 0;
}
*/


#include<iostream>
#include<time.h>
#include<stdlib.h>
#define MAXSIZE 6
using namespace std;

void mergeSort(int a[],int p,int r);
void mergeArray(int a[],int p,int m,int r);
void printArray(int a[],int n);
int main()
{
    srand(unsigned(time(0)));
    int arr[MAXSIZE];
//    int arr[MAXSIZE]={1,3,2,5,6,9};
    for(int i=0;i<MAXSIZE;i++)
    {
        arr[i]=rand()%11+1;
    }
    printArray(arr,MAXSIZE);
    mergeSort(arr,0,MAXSIZE-1);
    for(int i=0;i<MAXSIZE;i++)
    {
        cout<<arr[i]<<" ";
    }
    return 0;
}
void mergeSort(int a[],int p,int r)
{

    if(p < r){
        int mid = (p+r)/2;
        mergeSort(a,p,mid);
        mergeSort(a,mid+1,r);
        mergeArray(a,p,mid,r);
    }
}

void printArray(int a[],int n)
{
    n=MAXSIZE;
    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;
}
void mergeArray(int a[],int p,int m, int r)
{
    int *temp=new int[MAXSIZE];
    if(temp==NULL)
    {
        cout<<"数组排序失败";
        return;
    }
    int k=0,i=p,j=m+1;
    while(i<=m && j<=r)
    {
        if(a[i]<=a[j])
            temp[k++]=a[i++];
        else
            temp[k++]=a[j++];
    }
    while (i <= m)
        temp[k++] = a[i++];
    while (j <= r)
        temp[k++] = a[j++];
    for(i=0;i<k;i++)
    {
        a[p+i]=temp[i];  //这里必须是 a[p+i]，不能是a[i],因为数组a此时的地址已经改变，不再是初始地址！！！
    }
    delete[] temp;
}



//博客园 i=i++
//#include<iostream>
//#include<stdlib.h>
//#include<time.h>
//using namespace std;
//#define  MAXSIZE  10
//
////将两个有序数列a[first...mid] 和 a[mid...last] 合并。
//void mergearray(int a[], int first, int mid, int last, int temp[])
//{
//    int i = first, j = mid + 1;
//    int m = mid, n = last;
//    int k = 0;
//
//    while (i <= m && j <= n)
//    {
//        if (a[i] <= a[j])
//            temp[k++] = a[i++];
//        else
//            temp[k++] = a[j++];
//    }
//
//    while (i <= m)
//        temp[k++] = a[i++];
//
//    while (j <= n)
//        temp[k++] = a[j++];
//
//    for (i = 0; i < k; ++i)
//        a[first + i] = temp[i];
//}
//void mergesort(int a[], int first, int last, int temp[])
//{
//    if (first < last)
//    {
//        int mid = (first + last) / 2;
//        mergesort(a, first, mid, temp);     //左边有序
//        mergesort(a, mid + 1, last, temp);  //右边有序
//        mergearray(a, first, mid, last, temp); //再将两个有序数列合并
//    }
//}
//
//bool MergeSort(int a[], int n)
//{
//    int *p = new int[n];
//    if (p == NULL)
//        return false;
//    mergesort(a, 0, n - 1, p);
//    delete[] p;
//    return true;
//}
//
//void  PrintArr(int ar[],int n)
//{
//    for(int i = 0; i < n; ++i)
//        cout<<ar[i]<<" ";
//    cout<<endl;
//}
//
//int main()
//{
//    srand(unsigned(time(0)));
//    int ar[MAXSIZE];
//    for(int i=0;i<MAXSIZE;i++)
//    {
//        ar[i]=rand()%11+1;
//    }
//    PrintArr(ar, MAXSIZE);
//    bool bValue = MergeSort(ar, MAXSIZE);
//    if(!bValue)
//    {
//        cout<<"MergeSort  Failed!! "<<endl;
//    }
//    PrintArr(ar, MAXSIZE);
//}
//



////关于代码注释，请见博客上面的伪代码注释..
//#include<stdio.h>
//int L[100],R[100];
//void merge(int numbers[],int left, int mid, int right)
//        {
//            int n1=mid-left+1;
//            int n2=right-mid;
//            int i,j,k;
//            for(i=1;i<=n1;i++)
//             L[i]=numbers[left+i-1];
//            for( j=1;j<=n2;j++)
//             R[j]=numbers[mid+j];
//            L[n1+1]=99999;
//            R[n2+1]=99999;
//
//            i=1;
//            j=1;
//
//            for(k=left;k<=right;k++)
//            if(L[i]<=R[j])
//               {
//                   numbers[k]=L[i];
//                   i++;
//                   }
//                 else
//                  {
//                       numbers[k]=R[j];
//                       j++;
//                  }
//        }
//
//void mergeSort(int numbers[],int left, int right)
//
//{
//    if(left<right)
//    {
//                int mid;
//            mid = (right + left) / 2;
//            mergeSort(numbers, left, mid);
//            mergeSort(numbers, mid+1, right);
//            merge(numbers,left, mid, right);
//        }
//
//}
//
//int main()
//{
//    int numbers[]={5,2,4,6,1,3,2,6};
//    mergeSort(numbers,0,7);
//    for(int i=0;i<8;i++)
//    printf("%d",numbers[i]);
//    }



