#include <iostream>
#include <string>
using namespace std;

class CStudent
{
public:
    CStudent(int,string);
    ~CStudent();
    static int GetTotal();
    void Print();
private:
    int id;
    string name;
    static int noofStds;
}；

CStudent::CStudent(int i,string a)
{
    name=a;
    id=i;
    noofStds++;
}
CStudent::~CStudent()
{
    noofStds--;

}

int CStudent::GetTotal()
{
    return noofStds;

}

void CStudent::Print()
{
    cout<<"姓名："<<name<<" ,"<<"学号："<<id<<endl;   

}
int CStudent::noofStds=0;
void func();
int main()
{
    cout<<"学生数为："<<CStudent::GetTotal()<<endl;
    CStudent s1(11011,"张三");
    s1.Print();
    cout<<"学生数为："<<CStudent::GetTotal()<<endl;   
    CStudent s2(11102,"李四");
    s2.Print();
    cout<<"学生数为："<<CStudent::GetTotal()<<endl;
    func();
    cout<<"学生数为："<<CStudent::GetTotal()<<endl;
    return 0;



}
void func()
{
    CStudent s3(11103,"王五");
    s3.Print();
    cout<<"学生数为："<<CStudent::GetTotal()<<endl;
    


}

