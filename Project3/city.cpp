#include "city.h"
//Bingjian Du 20706578
city::city(string name,double x, double y, long long p,double r, double s){
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
long long city::get_population(){
    return this->p;
}
double city::get_cost(){
    return this->r;
}
double city::get_salary(){
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
    if(direction=="NE"){
        this->NW=child;
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