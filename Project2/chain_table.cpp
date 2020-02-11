#include "chain_table.h"
#include <iostream>
using namespace std;
//print function search name??found caller space?? caller;number partial same
vector<chain> chain_table::get_data(){
    return this->data;
}
void chain_table::define(int m){
    chain temp;
    for(auto i=0;i<m;i++){
        data.push_back(temp);
    }
    this->data.resize(m);
    this->m=m;
}
void chain_table::insert(string number,string name){
    user *temp= new user(number,name);
    int k=stoi(number);
    size_t position=k%m; 
    if(data[position].get_head()==nullptr){
        data[position].set_head(temp);
        data[position].set_tail(temp);
        cout<<"success"<<endl;
    }else{
        bool temp1=true;
        for(user *temp=data[position].get_head();temp->get_next()!=nullptr;temp=temp->get_next()){
            if(temp->get_number()==number||temp->get_caller()==name){
                temp1=false;
            }
        }
        if(temp1){
            user *temp2=data[position].get_tail(); //point to tail
            temp->set_prev(temp2);
            temp2->set_next(temp);
            data[position].set_tail(temp);//set new tail
            cout<<"success"<<endl;
        }else{
            cout<<"failure"<<endl;
        }
    }
}
int chain_table::search(string number){
    size_t position=stoi(number);
    user *temp=data[position].get_head();
    if(temp!=nullptr){
        do{
            if(temp->get_number()==number){
                cout<<"found "<<temp->get_caller()<<" in "<<position<<endl;
                return 0;
            }
            temp=temp->get_next();
        }while(temp!=nullptr);
    }
    cout<<"not found"<<endl;
    return 1;
}
int chain_table::delete_data(string number){
    bool temp=true;
    size_t position=stoi(number);
    user *temp1=data[position].get_head();
    if(temp1!=nullptr){
        do{
            if(temp1->get_number()==number){
                if(temp1==data[position].get_head()){
                    if(temp1->get_next()!=nullptr){
                    data[position].set_head(temp1->get_next());
                    temp1->get_next()->set_prev(nullptr);
                    }else{
                        data[position].set_head(nullptr);
                        data[position].set_tail(nullptr);
                    }
                }
                else if(temp1==data[position].get_tail()){
                    data[position].set_tail(temp1->get_prev());
                    temp1->get_prev()->set_next(nullptr);
                }else{
                    temp1->get_prev()->set_next(temp1->get_next());
                    temp1->get_next()->set_prev(temp1->get_prev());
                }
                delete temp1;
                temp1=nullptr;
                cout<<"success"<<endl;
                return 0;
            }
        }while(temp1!=nullptr);
        
    }
    cout<<"failure"<<endl;
    return 1;
}
void chain_table::print(string i){
    ;
}