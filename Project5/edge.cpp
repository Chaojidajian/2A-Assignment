#include "edge.h"
//Bingjian Du 20706578
edge::edge(){
    this->weight=-1;
}
edge::edge(double w,node* city1, node* city2){
    this->weight=w;
    this->city1=city1;
    this->city2=city2;
}
double edge::get_weight(){
    return this->weight;
}
node* edge::get_city1(){
    return this->city1;
}
node* edge::get_city2(){
    return this->city2;
}