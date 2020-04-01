#include "nodelist.h"
node *nodelist::get_head(){
    return this->head;
}
node *nodelist::get_tail(){
    return this->tail;
}
node *nodelist::get_current(){
    return this->current;
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
    this->current=a;
}