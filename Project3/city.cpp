#include "city.h"
//Bingjian Du 20706578
city::city(string name,double x, double y, long p,long r, long s){
    this->name=name;
    this->x=x;
    this->y=y;
    this->p=p;
    this->r=r;
    this->s=s;
    this->NE=nullptr;
    this->SE=nullptr;
    this->NW=nullptr;
    this->SW=nullptr;
}
string city::get_name(){
    return this->name;
}
double city::get_x(){
    return this->x;
}
double city::get_y(){
    return this->y;
}
long city::get_population(){
    return this->p;
}
long city::get_cost(){
    return this->r;
}
long city::get_salary(){
    return this->s;
}
void city::set_child(string direction,city *child){
    if(direction=="NE"){
        this->NE=child;
    }
    if(direction=="SE"){
        this->SE=child;
    }
    if(direction=="NW"){
        this->NW=child;
    }
    if(direction=="SW"){
        this->SW=child;
    }
}
city *city::get_NE(){
    return this->NE;
}
city *city::get_NW()
{
    return this->NW;
}
city *city::get_SE(){
    return this->SE;
}
city *city::get_SW(){
    return this->SW;
}