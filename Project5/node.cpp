#include "node.h"
#include<string>
#include<cmath>
using namespace std;
//Bingjian Du 20706578
node::node(string name){
    this->name=name;
    this->distance=-1; 
}
node operator+(const node &c1, const node &c2){
    return node(c1.distance+c2.distance);
}
string node::get_name(){
    return this->name;
}
vector<node*> node::get_adjacent(){
    return this->adjacent;
}
void node::set_distance(double distance){
    this->distance=distance;
}
void node::add_adjacent(node *p){
    this->adjacent.push_back(p);
}
void node::reset(){
    this->distance=-1; 
}
double node::get_distance(){
    return this->distance;
}
bool node::operator<(const node &a){
    if(a.distance==-1){
        return true;
    }else{
        return this->distance<a.distance;
    }
}
void node::set_parent(node* parent){
    this->parent=parent;
}
node *node::get_parent(){
    return this->parent;
}