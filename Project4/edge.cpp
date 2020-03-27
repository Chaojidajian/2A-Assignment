#include "edge.h"
//Bingjian Du 20706578
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
int edge::get_x(){
    return this->x;
}
int edge::get_y(){
    return this->y;
}