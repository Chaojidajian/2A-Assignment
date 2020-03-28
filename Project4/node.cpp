#include "node.h"
//Bingjian Du 20706578
node::node(int vertex){
    this->vertex=vertex;
    this->head=nullptr;
    this->next=nullptr;
}
node *node::get_next(){
    return this->next;
}
node *node::get_head(){
    return this->head;
}
void node::set_next(node *a){
    this->next=a;
}
void node::set_head(node *a){
    this->head=a;
}
int node::get_vertex(){
    return this->vertex;
}
bool node::operator==(const node &a){
    return this->vertex==a.vertex;
}
bool node::operator!=(const node &a){
    return this->vertex!=a.vertex;
}