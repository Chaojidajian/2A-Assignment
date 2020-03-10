#include "city.h"
#include <string>
//Bingjian Du 20706578
class tree{
    private:
        city *root;
        int size;
    public:
        bool insert(city *new_city,city *parent); //functions for the corresponding command
        void search(double x, double y);
        city *get_root();
        void set_root(city *a);
        void q_max(double x,double y,string direction,string attr) ;
        void q_min(double x,double y,string direction,string attr) ;
        void q_total(double x,double y,string direction,string attr) ;
        void cal_max(city *a,long &result,string attr) ;
        void cal_min(city *a,long &result,string attr) ;
        void cal_total(city *a,long &result,string attr) ;
        void print(city *node) const;
        void clear(city *node);
        void tree_size();
        void set_size(int i);
        tree();
        ~tree()=default;
        city *get_city(double x, double y);
};