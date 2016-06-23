#include<iostream>
//create danlianbiao
using namespace std;

struct Node
{   
    int data;
    struct Node* next;
};

Node *Create()
{
    struct Node *head;
    struct Node *tail=head;
    struct Node *p;
    head=NULL;
   // p=new Node;
    int a;
    cin>>a;
   // p->data=a;
    while(a!=0)
    {
        
        p=new Node;
        p->data=a;
        if(head==NULL)
            head=p;
        else
            tail->next=p;
        tail=p;
        cin>>a;
    }
    tail->next=NULL;
    return head;
}

void PrintLianBiao(struct Node *s)
{
    while(s->next!=NULL)
        cout<<s->data<<",";
    cout<<endl;
}

int main()
{
    struct Node* S;
    Create();
    PrintLianBiao(S);
    cout<<endl;
    return 0;    
}
