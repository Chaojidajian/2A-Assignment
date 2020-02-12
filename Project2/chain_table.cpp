#include "chain_table.h"
#include <iostream>
using namespace std;
//print function i  m twice?
vector<chain> chain_table::get_data(){
    return this->data;
}
chain_table::chain_table(){
}
chain_table::~chain_table(){
    m=0;
    this->data.resize(m);
}
long long chain_table::get_size(){
    return this->m;
}
void chain_table::define(string k){
    m=stoll(k);
    this->data.resize(m);
    chain temp;
    for(auto i=0;i<m;i++){
        data.push_back(temp);
    }
    cout<<"success"<<endl;
}
void chain_table::insert(string number,string name){
    user *temp= new user(number,name);
    long long k=stoll(number);
    if(m!=0){
        size_t position=k%m; 
        if(data[position].get_head()==nullptr){
            data[position].set_head(temp);
            data[position].set_tail(temp);
            std::cout<<"success"<<endl;
        }else{
            bool temp1=true;
            user *temp2=data[position].get_head();
            do{
                if(temp2->get_number()==number){
                    temp1=false;
                    break;
                }
                if(temp2->get_number()>number){
                    break;
                }
                temp2=temp2->get_next();
            }while(temp2!=nullptr);
            if(temp1){
                if(temp2==nullptr){
                    user *temp3=data[position].get_tail(); //point to tail
                    temp->set_prev(temp3);
                    temp3->set_next(temp);
                    data[position].set_tail(temp);//set new tail
                    std::cout<<"success"<<endl;
                }else if(temp2==data[position].get_head()){
                    temp->set_prev(temp2->get_prev());
                    temp->set_next(temp2);
                    temp2->set_prev(temp);
                    data[position].set_head(temp);
                    std::cout<<"success"<<endl;
                }else{
                    temp->set_prev(temp2->get_prev());
                    temp->set_next(temp2);
                    temp2->set_prev(temp);
                    std::cout<<"success"<<endl;
                }
            }else{
                std::cout<<"failure"<<endl;
            }
        }
    }else{
        std::cout<<"failure"<<endl;
    }
}
bool chain_table::search(string number){
    size_t position=stoll(number);
    position=position%m;
    user *temp=data[position].get_head();
    if(temp!=nullptr){
        do{
            if(temp->get_number()==number){
                std::cout<<"found "<<temp->get_caller()<<" in "<<position<<endl;
                return 0;
            }
            temp=temp->get_next();
        }while(temp!=nullptr);
    }
    std::cout<<"not found"<<endl;
    return 1;
}
int chain_table::delete_data(string number){
    bool temp=true;
    size_t position=stoll(number);
    position=position%m;
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
                std::cout<<"success"<<endl;
                return 0;
            }
            temp1=temp1->get_next();
        }while(temp1!=nullptr);
        
    }
    std::cout<<"failure"<<endl;
    return 1;
}
void chain_table::print(string i){
    size_t k=stoll(i)-1;
    if(data[k].get_head()==nullptr){
        ;
    }else{
        user* temp=data[k].get_head();
        while(temp!=data[k].get_tail()){
            std::cout<<temp->get_number()<<" ";
            temp=temp->get_next();
        }
        std::cout<<data[k].get_tail()->get_number()<<endl;
    }
}