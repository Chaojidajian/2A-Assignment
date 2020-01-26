#include "list.h"
#include<iostream>
using namespace std;
Node::Node(int i){
    data=i;
    next=nullptr;
    prev=nullptr;
}
linked_list::linked_list(){
    head= nullptr;
    tail= nullptr;
    length=0;
}
linked_list::~linked_list(){
    Node *next;
    while(head!=nullptr){
        next=head->next;
        delete head;
        head=next;
   } 
}
void linked_list::enqueue_front(int i){
    Node *temp1=new Node(i);
    if(head==nullptr){
        head=temp1;
        tail=temp1;
    }
    else{
        temp1->next=head;
        head->prev=temp1;
        head=temp1;
    }
    length++;
    cout<<"failure"<<endl;
}
void linked_list::enqueue_back(int i){
    Node *temp1=new Node(i);
    if(head==nullptr){
        head=temp1;
        tail=temp1;
    }
    else{
        temp1->prev=tail;
        tail->next=temp1;
        tail=temp1;
    }
    length++;
    cout<<"failure"<<endl;
}
void linked_list::dequeue_front(){
    if(head==nullptr){
        cout<<"failure"<<endl;
    }else{
        Node *temp1=head;
        head->next->prev=nullptr;
        head=head->next;
        delete temp1;
        temp1=nullptr;
        length--;
        cout<<"success"<<endl;
    }
}
void linked_list::dequeue_back(){
    if(tail==nullptr){
        cout<<"failure"<<endl;
    }else{
        Node *temp1=tail;
        tail->prev->next=nullptr;
        tail=tail->prev;
        delete temp1;
        temp1=nullptr;
        length--;
        cout<<"success"<<endl;
    }
}
void linked_list::front(int i){
    if(head->data==i){
        cout<<"success"<<endl;
    }else{
        cout<<"failure"<<endl;
    }
}
void linked_list::back(int i){
    if(tail->data==i){
        cout<<"success"<<endl;
    }else{
        cout<<"failure"<<endl;
    }
}
void linked_list::empty(){
    if(head==nullptr){
        cout<<"success"<<endl;
    }else{
        cout<<"failure"<<endl;
    }
}
void linked_list::size(){
    cout<<"size is "<<length<<endl;
}
void linked_list::print(){
    if(head==nullptr){
        ;
    }else{
        Node *temp1=head;
        while(temp1!=nullptr){
            cout<<temp1->data<<" ";
            if(temp1->next==nullptr){
                break;
            }
            temp1=temp1->next;
        }
        cout<<endl;
        temp1=tail;
        while(temp1!=nullptr){
            cout<<temp1->data<<" ";
            if(temp1->prev==nullptr){
                break;
            }
            temp1=temp1->prev;
        }
        cout<<endl;
    }
}