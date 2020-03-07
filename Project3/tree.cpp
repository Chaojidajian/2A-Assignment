#include<tree.h>
#include<iostream>
//Bingjian Du 20706578
using namespace std;
bool tree::insert(city *n_city,city *parent){//recursive insertion
    if (this->root==nullptr){
        root=n_city;
    }
    if(n_city->get_name()==parent->get_name()){
        return false;
    }
    if(n_city->get_x()>=parent->get_x()&&n_city->get_y()>parent->get_y()){
       if(parent->get_NE=nullptr){
           parent->set_child("NE",n_city);
           return true;
       }else{
           parent=parent->get_NE();
           return this->insert(n_city,parent);
       }
    }
    if(n_city->get_x()<parent->get_x()&&n_city->get_y()>=parent->get_y()){
       if(parent->get_NW=nullptr){
           parent->set_child("NW",n_city);
           return true;
       }else{
           parent=parent->get_NW();
           return this->insert(n_city,parent);
       }
    }
    if(n_city->get_x()<=parent->get_x()&&n_city->get_y()<parent->get_y()){
       if(parent->get_SW=nullptr){
           parent->set_child("SW",n_city);
           return true;
       }else{
           parent=parent->get_SW();
           return this->insert(n_city,parent);
       }
    }
    if(n_city->get_x()>parent->get_x()&&n_city->get_y()<=parent->get_y()){
       if(parent->get_SE=nullptr){
           parent->set_child("SE",n_city);
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
city *tree::get_city(double x, double y){
    city *temp=this->root;
    while(temp!=nullptr){
        if(temp->get_x()==x&&temp->get_y()==y){
            return temp;
        }
        if(temp->get_x()>=x&&temp->get_y()>y){
            temp=temp->get_NE;
            continue;
        }
        if(temp->get_x()<x&&temp->get_y()>=y){
            temp=temp->get_NW;
            continue;
        }
        if(temp->get_x()<=x&&temp->get_y()<y){
            temp=temp->get_SW;
            continue;
        }
        if(temp->get_x()>x&&temp->get_y()<=y){
            temp=temp->get_SE;
            continue;
        }
    }
    return temp;
}
void const tree::search(double x, double y){
    city *temp=this->get_city(x,y);
    if(temp==nullptr){
        cout<<"not found"<<endl;
    }else{
        cout<<"found "<<temp->get_name()<<endl;
    }
}
auto const tree::q_max(double x,double y,string direction,string attr){
    city *temp=this->get_city(x,y);
    if(temp==nullptr){
        cout<<"failure";
    }
    if(temp!=nullptr){
        if(temp->direction)
        cout<<"failure";
    }
}
auto const tree::q_min(double x,double y,string direction,string attr);
auto const tree::q_total(double x,double y,string direction,string attr);
void tree::print();
void tree::clear();
void tree::tree_size();