#include "city.h"
#include <string>
//Bingjian Du 20706578
class tree{
    private:
        city *root;
        int size;
    public:
        bool insert(city *new_city,city *parent); //functions for the corresponding command
        void const search (double x, double y);
        city *get_root();
        auto const q_max(double x,double y,string direction,string attr);
        auto const q_min(double x,double y,string direction,string attr);
        auto const q_total(double x,double y,string direction,string attr);
        void print();
        void clear();
        void tree_size();
        tree()=default;
        ~tree()=default;
        city *get_city(double x, double y);
};