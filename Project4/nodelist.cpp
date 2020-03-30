#include "nodelist.h"
node *nodelist::get_head(){
    return this->head;
}
node *nodelist::get_tail(){
    return this->tail;
}
void nodelist::set_head(node *a){
    this->head=a;
}
void nodelist::set_tail(node *a){
    this->tail=a;
}
nodelist::nodelist(node *a){
    this->head=a;
    this->tail=a;
}