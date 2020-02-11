#include "user.h"
string user::get_number(){
    return this->number;
}
string user::get_caller(){
    return this->caller;
}
user::user(string number, string name){
    this->number=number;
    this->caller=name;
    this->next_caller=nullptr;
    this->prev_caller=nullptr;
}
user *user::get_next(){
    return this->next_caller;
}
void user::set_next(user *n){
    this->next_caller=n;
}
user *user::get_prev(){
    return this->prev_caller;
}
void user::set_prev(user *n){
    this->prev_caller=n;
}