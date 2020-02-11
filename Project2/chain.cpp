#include "chain.h"
chain::chain(){
    this->head=nullptr;
    this->tail=nullptr;
}
chain::~chain(){
    while(this->head!=nullptr){
        user *temp=head;
        head=head->get_next();
        delete temp;
        temp=nullptr;
    }
}
user *chain::get_head(){
    return this->head;
}
void chain::set_head(user *n){
    this->head=n;
}
user *chain::get_tail(){
    return this->tail;
}
void chain::set_tail(user *n){
    this->tail=n;
}