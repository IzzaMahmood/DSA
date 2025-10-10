#include<iostream>
using namespace std;
struct Node{
int data;
Node*prev;
Node*next;
};
void addAtBeginning(Node*&head,int value){
Node*newNode=new Node{value,NULL,head};
if(head!=NULL)head->prev=newNode;
head=newNode;
}
void addAfterValue(Node*&head,int value,int after){
Node*temp=head;
while(temp!=NULL&&temp->data!=after)temp=temp->next;
if(temp==NULL)return;
Node*newNode=new Node{value,temp,temp->next};
if(temp->next!=NULL)temp->next->prev=newNode;
temp->next=newNode;
}
void deleteAtBeginning(Node*&head){
if(head==NULL)return;
Node*temp=head;
head=head->next;
if(head!=NULL)head->prev=NULL;
delete temp;
}
void deleteAfterValue(Node*&head,int after){
Node*temp=head;
while(temp!=NULL&&temp->data!=after)temp=temp->next;
if(temp==NULL||temp->next==NULL)return;
Node*toDelete=temp->next;
temp->next=toDelete->next;
if(toDelete->next!=NULL)toDelete->next->prev=temp;
delete toDelete;
}
void display(Node*head){
Node*temp=head;
while(temp!=NULL){
cout<<temp->data<<" ";
temp=temp->next;
}
cout<<endl;
}
int main(){
Node*head=NULL;
int n,x;
cout<<"Enter number of nodes:";
cin>>n;
for(int i=0;i<n;i++){
cin>>x;
addAtBeginning(head,x);
}
display(head);
addAfterValue(head,99,45);
display(head);
deleteAtBeginning(head);
display(head);
deleteAfterValue(head,45);
display(head);
return 0;
}

