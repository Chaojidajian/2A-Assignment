#include<iostream>
#include"node.h"
using namespace std;
//Bingjian Du 20706578
class edge{ //representing an edge
    private:
        double weight;
        node *city1;
        node *city2;
    public:
        edge();
        edge(double w,node* city1, node* city2);
        node* get_city1();//accessing private variables
        node* get_city2();
        double get_weight();
        ~edge()=default;
};