#include<iostream>
using namespace std;
struct Player{
string name;
int score;
Player*prev;
Player*next;
};
void insertPlayer(Player*&head,string name,int score){
Player*newNode=new Player{name,score,NULL,NULL};
if(head==NULL){
head=newNode;
return;
}
Player*temp=head;
while(temp!=NULL&&temp->score<score)temp=temp->next;
if(temp==head){
newNode->next=head;
head->prev=newNode;
head=newNode;
}
else if(temp==NULL){
Player*tail=head;
while(tail->next!=NULL)tail=tail->next;
tail->next=newNode;
newNode->prev=tail;
}
else{
newNode->next=temp;
newNode->prev=temp->prev;
temp->prev->next=newNode;
temp->prev=newNode;
}
}
void deletePlayer(Player*&head,string name){
Player*temp=head;
while(temp!=NULL&&temp->name!=name)temp=temp->next;
if(temp==NULL)return;
if(temp==head){
head=head->next;
if(head!=NULL)head->prev=NULL;
delete temp;
return;
}
if(temp->next!=NULL)temp->next->prev=temp->prev;
if(temp->prev!=NULL)temp->prev->next=temp->next;
delete temp;
}
void display(Player*head){
Player*temp=head;
while(temp!=NULL){
cout<<temp->name<<" "<<temp->score<<endl;
temp=temp->next;
}
}
void displayLowest(Player*head){
if(head==NULL)return;
cout<<head->name<<" "<<head->score<<endl;
}
void displaySameScore(Player*head,int score){
Player*temp=head;
while(temp!=NULL){
if(temp->score==score)cout<<temp->name<<" "<<temp->score<<endl;
temp=temp->next;
}
}
void displayBackward(Player*head,string name){
Player*temp=head;
while(temp!=NULL&&temp->name!=name)temp=temp->next;
if(temp==NULL)return;
while(temp!=NULL){
cout<<temp->name<<" "<<temp->score<<endl;
temp=temp->prev;
}
}
int main(){
Player*head=NULL;
insertPlayer(head,"Ali",70);
insertPlayer(head,"Zara",60);
insertPlayer(head,"Omar",80);
display(head);
cout<<"Lowest:"<<endl;
displayLowest(head);
cout<<"Same score 70:"<<endl;
displaySameScore(head,70);
cout<<"Backward from Omar:"<<endl;
displayBackward(head,"Omar");
deletePlayer(head,"Zara");
cout<<"After deletion:"<<endl;
display(head);
return 0;
}

