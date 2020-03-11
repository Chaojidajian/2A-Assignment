#include "city.h"
#include <string>
//Bingjian Du 20706578
class tree{
    private:
        city *root;
        int size;
    public:
        bool insert(city *new_city,city *parent); //functions for the corresponding command
        void search(double x, double y);//function for search
        city *get_root();//return root
        void set_root(city *a);//set root
        void q_max(double x,double y,string direction,string attr) ;//corresponds to q_max
        void q_min(double x,double y,string direction,string attr) ;//corresponds to q_min
        void q_total(double x,double y,string direction,string attr) ;//corresponds to q_total
        void cal_max(city *a,long &result,string attr) ;//recursive calculating max
        void cal_min(city *a,long &result,string attr) ;//recursive calculating min
        void cal_total(city *a,long &result,string attr) ;//recursive calculating total
        void print(city *node) const;//corresponds to print
        void clear(city *node);//corresponds to clear
        void tree_size();//print size
        void set_size(int i);//set size
        tree();
        ~tree()=default;
        city *get_city(double x, double y);
};