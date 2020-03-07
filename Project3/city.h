#include<string>
//Bingjian Du 20706578
using namespace std;
class city{
    private:
        string name;
        double x; //Longtitude
        double y;//Latitude
        long long p;//Population
        double r;//Cost of living
        double s;//Average Net salary
        city *NE;
        city *NW;
        city *SE;
        city *SW;
    public:
        city(string name,double x, double y, long long p,double r, double s);
        ~city()=default;
        string get_name();  //functions for editing and accessing private variables
        double get_x();
        double get_y();
        long long get_population();
        double get_cost();
        double get_salary();
        void set_child(string direction,city *child);
        city *get_NE();
        city *get_NW();
        city *get_SE();
        city *get_SW();
};