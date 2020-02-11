#include "open_table.h"
#include    <iostream>
using namespace std;
open_table::~open_table(){
    m=0;
    this->data.resize(m);
}
vector<user> open_table::get_data(){
    return this->data;
}
void open_table::define(int m){
    this->data.resize(m);
    this->m=m;
    user temp;
    for(auto i=0;i<m;i++){
        data.push_back(temp);
    }
    cout<<"success"<<endl;
}
int open_table::insert(string number,string name){
    user temp(number,name);
    user temp1;
    if(exists==m){
        cout<<"failure"<<endl;
        return 1;
    }
    long long k=stoll(number);
    size_t position=k%m;
    while(data[position]!=temp1){
        position=(position/m)%m;
        if(position%2==0){
            position++;
        }
    }
    data[position]=temp;
    exists++;
    cout<<"success"<<endl;
    return 0;
}
int open_table::search(string number){
    size_t position=0;
    while(data[position].get_number()!=number){
            position++;
            if(position>=m){
                cout<<"not found"<<endl;
                return 1;
            }
    }
    cout<<"found "<<data[position].get_caller()<<" in "<<position<<endl;
    return 0;
}
int open_table::delete_data(string number){
    size_t position=0;
    while(data[position].get_number()!=number){
            position++;
            if(position>=m){
                cout<<"failure"<<endl;
                return 1;
            }
    }
    data[position]=user();
    exists--;
    cout<<"success"<<endl;
    return 0;
}