#include "edge.h"
edge::edge(){
    this->weight=0;
    this->x=-1;
    this->y=-1;
}
edge::edge(double w,int u, int v){
    this->weight=w;
    this->x=u;
    this->y=v;
}
double edge::get_weight(){
    return this->weight;
}
bool edge::operator<(const edge &a){
    return this->weight<a.weight;
}
