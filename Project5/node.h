//Bingjian Du 20706578
#include<string>
#include<vector>
using namespace std;
class node{//representing a vertex
    private:
        string name;
        double distance; //distance to the city we want, initialized as -1
        vector<node*> adjacent; //direct connected cities
        node *parent;
    public:
        node()=default;
        ~node()=default;
        node(string name);
        node(double distance);
        int get_vertex();//accessing private variables
        string get_name();//accessing private variables
        void set_distance(double distance);
        void set_parent(node* parent);
        node *get_parent();
        vector<node*> get_adjacent();
        double get_distance();
        void add_adjacent(node *p);
        void reset();//clean distance and parents
        bool operator<(const node &a);
        friend node operator+(const node &c1, const node &c2);
};