#include "open_table.h"
#include <iostream>
using namespace std;
open_table::~open_table(){
    m=0;
    this->data.resize(m);
}
vector<user> open_table::get_data(){
    return this->data;
}
void open_table::define(string k){
    m=stoll(k);
    this->data.resize(m);
    user temp;
    for(auto i=0;i<m;i++){
        data.push_back(temp);
    }
    cout<<"success"<<endl;
}
int open_table::insert(string number,string name){
    this->data.clear();
    vector <user> n;
    this->data=n;
    user temp(number,name);
    user temp1;
    if(exists==m){
        cout<<"failure"<<endl;
        return 1;
    }
    long long k=stoll(number);
    size_t position=k%m;
    size_t offset=(k/m)%m;
    if(offset%2==0){
        offset++;
    }
    while(data[position]!=temp1){
        if((data[position])==temp||(position==(position+offset)%m)){
            cout<<"failure"<<endl;
            return 1;
        }
        position=(position+offset)%m;
    }
    data[position]=temp;
    exists++;
    cout<<"success"<<endl;
    return 0;
}
int open_table::search(string number){
    long long k=stoll(number);
    size_t position=k%m;
    size_t offset=(k/m)%m;
    int q=position;
    if(offset%2==0){
            offset++;
    }
    while(data[position].get_number()!=number){
            position=(position+offset)%m;
            if(q==position){
                cout<<"not found"<<endl;
                return 1;
            }
    }
    cout<<"found "<<data[position].get_caller()<<" in "<<position<<endl;
    return 0;
}
int open_table::delete_data(string number){
    long long k=stoll(number);
    user temp1;
    size_t position=k%m;
    size_t offset=(k/m)%m;
    int q=position;
    if(offset%2==0){
            offset++;
    }
    while(data[position].get_number()!=number){
            position=(position+offset)%m;
            if(q==position){
                cout<<"failure"<<endl;
                return 1;
            }
    }
    data[position]=temp1;
    exists--;
    cout<<"success"<<endl;
    return 0;
}