#include "chain_table.h"
#include <iostream>
using namespace std;
//print function search name??found caller space?? caller;number partial same
vector<chain> chain_table::get_data(){
    return this->data;
}
chain_table::chain_table(){
}
chain_table::~chain_table(){
    m=0;
    this->data.resize(m);
}
void chain_table::define(int m){
    this->data.resize(m);
    this->m=m;
    chain temp;
    for(auto i=0;i<m;i++){
        data.push_back(temp);
    }
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
                std::cout<<"success"<<endl;
            }else{
                std::cout<<"failure"<<endl;
            }
        }
    }else{
        std::cout<<"failure"<<endl;
    }
}
int chain_table::search(string number){
    size_t position=stoll(number);
    if(position<m){
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
    }
    std::cout<<"not found"<<endl;
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
                std::cout<<"success"<<endl;
                return 0;
            }
        }while(temp1!=nullptr);
        
    }
    std::cout<<"failure"<<endl;
    return 1;
}
void chain_table::print(string i){
    size_t k=stoi(i);
    if(k>m){
        ;
    }else{
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
}