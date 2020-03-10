#include"tree.h"
#include<iostream>
//Bingjian Du 20706578
using namespace std;
tree::tree(){
    this->size=0;
}
void tree::set_root(city *a){//this is to set the root
    this->root=a;
    this->size++;
}
bool tree::insert(city *n_city,city *parent){//recursive insertion
    if(n_city->get_name()==parent->get_name()){
        return false;
    }
    if(n_city->get_x()>=parent->get_x()&&n_city->get_y()>parent->get_y()){
       if(parent->get_NE()==nullptr){
           parent->set_child("NE",n_city);
           this->size++;
           return true;
       }else{
           parent=parent->get_NE();
           return this->insert(n_city,parent);
       }
    }
    if(n_city->get_x()<parent->get_x()&&n_city->get_y()>=parent->get_y()){
       if(parent->get_NW()==nullptr){
           parent->set_child("NW",n_city);
           this->size++;
           return true;
       }else{
           parent=parent->get_NW();
           return this->insert(n_city,parent);
       }
    }
    if(n_city->get_x()<=parent->get_x()&&n_city->get_y()<parent->get_y()){
       if(parent->get_SW()==nullptr){
           parent->set_child("SW",n_city);
           this->size++;
           return true;
       }else{
           parent=parent->get_SW();
           return this->insert(n_city,parent);
       }
    }
    if(n_city->get_x()>parent->get_x()&&n_city->get_y()<=parent->get_y()){
       if(parent->get_SE()==nullptr){
           parent->set_child("SE",n_city);
           this->size++;
           return true;
       }else{
           parent=parent->get_SE();
           return this->insert(n_city,parent);
       }
    }
    return false;
}
city *tree::get_root(){
    return this->root;
}
city *tree::get_city(double x, double y){ //find the point to the city given specific x,y
    city *temp=this->root;
    while(temp!=nullptr){
        if(temp->get_x()==x&&temp->get_y()==y){
            return temp;
        }
        if(temp->get_x()>=x&&temp->get_y()>y){
            temp=temp->get_NE();
            continue;
        }
        if(temp->get_x()<x&&temp->get_y()>=y){
            temp=temp->get_NW();
            continue;
        }
        if(temp->get_x()<=x&&temp->get_y()<y){
            temp=temp->get_SW();
            continue;
        }
        if(temp->get_x()>x&&temp->get_y()<=y){
            temp=temp->get_SE();
            continue;
        }
    }
    return temp;
}
void tree::search(double x, double y){//search if a city exists
    city *temp=this->get_city(x,y);
    if(temp==nullptr){
        cout<<"not found"<<endl;
    }else{
        cout<<"found "<<temp->get_name()<<endl;
    }
}
void tree::print(city *node) const{ //recursive print
    if(node!=nullptr){
        this->print(node->get_NE());
        this->print(node->get_NW());
        cout<<node->get_name()<<" ";
        this->print(node->get_SW());
        this->print(node->get_SE());
    }else{
        ;
    }
}
void tree::clear(city *node){
    if(node!=nullptr){
        this->clear(node->get_NE());
        this->clear(node->get_NW());
        this->clear(node->get_SW());
        this->clear(node->get_SE());
        city *temp=node->get_NE();
        delete temp;
        node->set_child("NE",nullptr);
        temp=node->get_NW();
        delete temp;
        node->set_child("NW",nullptr);
        temp=node->get_SW();
        delete temp;
        node->set_child("SW",nullptr);
        temp=node->get_SE();
        delete temp;
        node->set_child("SE",nullptr);   
    }  
}
void tree::tree_size(){
    cout<<this->size<<endl;
}
void tree::set_size(int i){
    this->size=i;
}
void tree::q_max(double x,double y,string direction,string attr) {
    city *temp=this->get_city(x,y);
    long result=0;
    if(temp==nullptr){
        cout<<"failure"<<endl;
    }else{
        if(direction=="NE"){
            if(temp->get_NE()==nullptr){
                cout<<"failure"<<endl;
            }else{
                temp=temp->get_NE();
                cal_max(temp,result,attr);
                cout<<"max "<<result<<endl;
            }
        }else if(direction=="NW"){
            if(temp->get_NW()==nullptr){
                cout<<"failure"<<endl;
            }else{
                temp=temp->get_NW();
                cal_max(temp,result,attr);
                cout<<"max "<<result<<endl;
            }
        }else if(direction=="SE"){
            if(temp->get_SE()==nullptr){
                cout<<"failure"<<endl;
            }else{
                temp=temp->get_SE();
                cal_max(temp,result,attr);
                cout<<"max "<<result<<endl;
            }
        }else if(direction=="SW"){
            if(temp->get_SW()==nullptr){
                cout<<"failure"<<endl;
            }else{
                temp=temp->get_SW();
                cal_max(temp,result,attr);
                cout<<"max "<<result<<endl;
            }
        }else{

        }
    }
}
void tree::q_min(double x,double y,string direction,string attr) {
    city *temp=this->get_city(x,y);
    long result=0;
    if(temp==nullptr){
        cout<<"failure"<<endl;
    }else{
        if(direction=="NE"){
            if(temp->get_NE()==nullptr){
                cout<<"failure"<<endl;
            }else{
                temp=temp->get_NE();
                cal_min(temp,result,attr);
                cout<<"min "<<result<<endl;
            }
        }else if(direction=="NW"){
            if(temp->get_NW()==nullptr){
                cout<<"failure"<<endl;
            }else{
                temp=temp->get_NW();
                cal_min(temp,result,attr);
                cout<<"min "<<result<<endl;
            }
        }else if(direction=="SE"){
            if(temp->get_SE()==nullptr){
                cout<<"failure"<<endl;
            }else{
                temp=temp->get_SE();
                cal_min(temp,result,attr);
                cout<<"min "<<result<<endl;
            }
        }else if(direction=="SW"){
            if(temp->get_SW()==nullptr){
                cout<<"failure"<<endl;
            }else{
                temp=temp->get_SW();
                cal_min(temp,result,attr);
                cout<<"min "<<result<<endl;
            }
        }else{

        }
    }
}
void tree::q_total(double x,double y,string direction,string attr) {
    city *temp=this->get_city(x,y);
    long result=0;
    if(temp==nullptr){
        cout<<"failure"<<endl;
    }else{
        if(direction=="NE"){
            if(temp->get_NE()==nullptr){
                cout<<"failure"<<endl;
            }else{
                temp=temp->get_NE();
                cal_total(temp,result,attr);
                cout<<"total "<<result<<endl;
            }
        }else if(direction=="NW"){
            if(temp->get_NW()==nullptr){
                cout<<"failure"<<endl;
            }else{
                temp=temp->get_NW();
                cal_total(temp,result,attr);
                cout<<"total "<<result<<endl;
            }
        }else if(direction=="SE"){
            if(temp->get_SE()==nullptr){
                cout<<"failure"<<endl;
            }else{
                temp=temp->get_SE();
                cal_total(temp,result,attr);
                cout<<"total "<<result<<endl;
            }
        }else if(direction=="SW"){
            if(temp->get_SW()==nullptr){
                cout<<"failure"<<endl;
            }else{
                temp=temp->get_SW();
                cal_total(temp,result,attr);
                cout<<"total "<<result<<endl;
            }
        }else{

        }
    }
}
void tree::cal_max(city *a,long &result,string attr){
    if(attr=="p"){
        if(a!=nullptr){
            this->cal_max(a->get_NE(),result,attr);
            this->cal_max(a->get_NW(),result,attr);
            this->cal_max(a->get_SW(),result,attr);
            this->cal_max(a->get_SE(),result,attr);
            if(result<a->get_population()){
                result=a->get_population();
            }
        }
    }else if(attr=="r"){
        if(a!=nullptr){
            this->cal_max(a->get_NE(),result,attr);
            this->cal_max(a->get_NW(),result,attr);
            this->cal_max(a->get_SW(),result,attr);
            this->cal_max(a->get_SE(),result,attr);
            if(result<a->get_cost()){
                result=a->get_cost();
            }
        }
    }else if(attr=="s"){
        if(a!=nullptr){
            this->cal_max(a->get_NE(),result,attr);
            this->cal_max(a->get_NW(),result,attr);
            this->cal_max(a->get_SW(),result,attr);
            this->cal_max(a->get_SE(),result,attr);
            if(result<a->get_salary()){
                result=a->get_salary();
            }
        }
    }else{
        ;
    }
}
void tree::cal_min(city *a,long &result,string attr){
    if(attr=="p"){
        if(a!=nullptr){
            this->cal_min(a->get_NE(),result,attr);
            this->cal_min(a->get_NW(),result,attr);
            this->cal_min(a->get_SW(),result,attr);
            this->cal_min(a->get_SE(),result,attr);
            if(result>a->get_population()){
                result=a->get_population();
            }
        }
    }else if(attr=="r"){
        if(a!=nullptr){
            this->cal_min(a->get_NE(),result,attr);
            this->cal_min(a->get_NW(),result,attr);
            this->cal_min(a->get_SW(),result,attr);
            this->cal_min(a->get_SE(),result,attr);
            if(result>a->get_cost()){
                result=a->get_cost();
            }
        }
    }else if(attr=="s"){
        if(a!=nullptr){
            this->cal_min(a->get_NE(),result,attr);
            this->cal_min(a->get_NW(),result,attr);
            this->cal_min(a->get_SW(),result,attr);
            this->cal_min(a->get_SE(),result,attr);
            if(result>a->get_salary()){
                result=a->get_salary();
            }
        }
    }else{
        ;
    }
}
void tree::cal_total(city *a,long &result,string attr){
    if(attr=="p"){
        if(a!=nullptr){
            this->cal_total(a->get_NE(),result,attr);
            this->cal_total(a->get_NW(),result,attr);
            this->cal_total(a->get_SW(),result,attr);
            this->cal_total(a->get_SE(),result,attr);
            result+=a->get_population();
        }
    }else if(attr=="r"){
        if(a!=nullptr){
            this->cal_total(a->get_NE(),result,attr);
            this->cal_total(a->get_NW(),result,attr);
            this->cal_total(a->get_SW(),result,attr);
            this->cal_total(a->get_SE(),result,attr);
            result+=a->get_cost();
        }
    }else if(attr=="s"){
        if(a!=nullptr){
            this->cal_total(a->get_NE(),result,attr);
            this->cal_total(a->get_NW(),result,attr);
            this->cal_total(a->get_SW(),result,attr);
            this->cal_total(a->get_SE(),result,attr);
            result+=a->get_salary();
        }
    }else{
        ;
    }
}