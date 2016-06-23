#include<iostream>
using namespace std;
class CComplex
{
public:
    CComplex (double,double);
    ~CComplex();
    CComplex(CComplex &c);
    CComplex add(CComplex &x);
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
CComplex::~CComplex()
{
    cout<<"调用析构函数"<<endl;

}
CComplex CComplex::add(CComplex &x)
{
    CComplex y(real+x.real,imag+x.imag);
    return y;
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

int main()
{
    CComplex a(3.0,4.0),b(5.6,7.9);
    CComplex c(a);
    cout<<"a=";
    a.Print();
    cout<<"c=";
    c.Print();
    f(b);
    CComplex d;
    d=a.add(b);
   
    d.Print();
    return 0;

}
