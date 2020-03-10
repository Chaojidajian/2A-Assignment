#include<string>
//Bingjian Du 20706578
using namespace std;
class city{
    private:
        string name;
        double x; //Longtitude
        double y;//Latitude
        long p;//Population
        long r;//Cost of living
        long s;//Average Net salary
        city *NE;
        city *NW;
        city *SE;
        city *SW;
    public:
        city(string name,double x, double y, long p,long r, long s);
        ~city()=default;
        string get_name();  //functions for editing and accessing private variables
        double get_x(); //return x
        double get_y(); // return y
        long get_population(); //return population
        long get_cost();//return cost
        long get_salary();//return get_salary
        void set_child(string direction,city *child);
        city *get_NE();
        city *get_NW();
        city *get_SE();
        city *get_SW();
};