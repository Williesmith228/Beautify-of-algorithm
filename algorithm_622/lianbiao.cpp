#include <iostream>
#include <stack>
using namespace std;
struct ListNode
{
    int value;
    ListNode* next;
};
/*
void AddToTail(ListNode *pHead,int value)
{
    ListNode *pNew= new ListNode;
    pNew->value=value;
    pNew->next=NULL;
    if(pHead==NULL)
    {
        pHead=pNew;
    }
    else
    {
        ListNode *pNode=pHead;
        while(pNode->next!=NULL)
        {
            pNode=pNode->next;
        }
        pNode->next=pNew;
    }      
}

*/

ListNode* AddToLinkedList(ListNode* pHead, int value, int insertValue)
{
    if(pHead->value==value)
    {
        ListNode *p=new ListNode;
        p->value=insertValue;
        p->next=pHead;
        pHead=p;    
       return pHead;
    }
    ListNode *pNode=pHead,*pNode_insert; 
    while(pNode->next!=NULL && pNode->next->value!=value)
        pNode=pNode->next;
    if(pNode->next==NULL)
    {
        cout<<"No Inserted"<<endl;
        return pHead;
    }
    else
    {
        pNode_insert=new ListNode;
        pNode_insert->value=insertValue;
        pNode_insert->next=pNode->next;
        pNode->next=pNode_insert;
        return pHead;
    }
}
void Print(ListNode *pHead)
{
    while(pHead!=NULL)
    {
        cout<<pHead->value<<" ";
        pHead=pHead->next;
    }
    cout<<endl;
    
}
ListNode* Create(int k)
{
    ListNode *head,*p,*tail;
    head=NULL;
    tail=head;
    int i=0,a;
    while(i++<k)
    {
        cin>>a;      
        p=new ListNode;
        p->value=a;
        if(head==NULL)
            head=p;
        else
            tail->next=p;
        tail=p;
    }
    tail->next=NULL;
    return head;
}
void ReversedLinkedList(ListNode* pHead)
{
    stack<ListNode*> Stack;
    while(pHead!=NULL)
    {
        Stack.push(pHead);
        pHead=pHead->next;   
    }
    while(!Stack.empty())
    {
        cout<<Stack.top()->value<<" ";
        Stack.pop();
    }
    cout<<endl;
}
int main()
{
    struct ListNode *pHead;
    pHead=Create(5);
    Print(pHead);
    ListNode *pHead1=AddToLinkedList(pHead,5,8);
    cout<<endl;
    Print(pHead);
    cout<<endl;
    Print(pHead1);
    ReversedLinkedList(pHead);
    ReversedLinkedList(pHead1);
    return 0;
}


