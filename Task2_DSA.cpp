#include<iostream>
using namespace std;
struct Node{
int data;
Node*prev;
Node*next;
};
void insert(Node*&head,int value){
Node*newNode=new Node{value,NULL,NULL};
if(head==NULL){
head=newNode;
return;
}
Node*temp=head;
while(temp->next!=NULL)temp=temp->next;
temp->next=newNode;
newNode->prev=temp;
}
int main(){
Node*head=NULL;
int value;
for(int i=1;i<=7;i++){
cin>>value;
if(value<0){
cout<<"Invalid input";
return 0;
}
insert(head,value);
}
int sum=0,maxVal=-1,minVal=1e9,day=1,maxDay=1,minDay=1;
Node*temp=head;
while(temp!=NULL){
sum+=temp->data;
if(temp->data>maxVal){
maxVal=temp->data;
maxDay=day;
}
if(temp->data<minVal){
minVal=temp->data;
minDay=day;
}
temp=temp->next;
day++;
}
cout<<"Total:"<<sum<<endl;
cout<<"Average:"<<(sum/7.0)<<endl;
cout<<"Highest Day:"<<maxDay<<" Value:"<<maxVal<<endl;
cout<<"Lowest Day:"<<minDay<<" Value:"<<minVal<<endl;
temp=head;
for(int i=1;i<5&&temp!=NULL;i++)temp=temp->next;
if(temp!=NULL&&temp->next!=NULL)cout<<"Day after 5th:"<<temp->next->data<<endl;
return 0;
}

